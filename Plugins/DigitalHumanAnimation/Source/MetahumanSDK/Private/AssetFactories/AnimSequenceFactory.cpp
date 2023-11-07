#include "AssetFactories/AnimSequenceFactory.h"

#include "Animation/AnimationAsset.h"
#include "Animation/AnimSequence.h"
#include "Animation/AnimTypes.h"
#include "Animation/AnimCurveTypes.h"
#include "Animation/AnimCompressionTypes.h"
#include "Animation/PoseAsset.h"
#include "Animation/Skeleton.h"
#include "Animation/SmartName.h"
#include "Animation/AnimBoneCompressionSettings.h"
#include "Animation/AnimCurveCompressionCodec_CompressedRichCurve.h"
#include "Animation/AnimCurveCompressionSettings.h"
#include "AnimationUtils.h"
#include "Curves/RichCurve.h"

#include "Serialization/MemoryWriter.h"
#include "UObject/Package.h"

#if WITH_EDITOR
#include "Modules/ModuleManager.h"
#include "AssetToolsModule.h"
#include "IAssetTools.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Misc/ScopedSlowTask.h"
#endif

#include "MetahumanSDKMappingsAsset.h"
#include "Request/MetahumanSDKResponses.h"
#include "MetahumanSDKSettings.h"
#include "Codecs/MetahumanSDKBoneCompressionCodec.h"
#include "Helpers/AnimUtilityLibrary.h"
#include "Animation/OpenAnimCompressionTypes.h"

#include "Interfaces/ITargetPlatformManagerModule.h"
#include "Animation/AnimData/AnimDataModel.h"
#include "Animation/AnimCompressionTypes.h"
#include "Animation/OpenAnimSequence.h"
#include "UObject/GCObjectScopeGuard.h"

#define LOCTEXT_NAMESPACE "MetahumanSDKAnimSequenceFactory"
DEFINE_LOG_CATEGORY_STATIC(LogMetahumanSDKAnimSequenceFactory, Log, All);


FAnimSequenceFactory::FAnimSequenceFactory() = default;

FAnimSequenceFactory::FAnimSequenceFactory(FVTableHelper& Helper)
{
    FAnimSequenceFactory();
}

FAnimSequenceFactory::~FAnimSequenceFactory() = default;


UAnimSequence* FAnimSequenceFactory::CreateAnimSequence(USkeleton* Skeleton, ERichCurveInterpMode CurveInterpMode, const FATLMappingsInfo& MappingsInfo, FATLResponse* AtlResponse, FString& Error, UObject* InParent /*= nullptr*/, const FString& AnimSequenceName/* = TEXT("")*/)
{
    QUICK_SCOPE_CYCLE_COUNTER(MetahumanSDK_CreateAnimSequence);        
    TRACE_CPUPROFILER_EVENT_SCOPE_STR("CreateAnimSequence PoseInfos, BonesMappings");
    
    if ( !IsInputValid(Skeleton, AtlResponse) ) return nullptr;   

    const double StartTime = FPlatformTime::Seconds();

    const TArray<FPoseInfo> PoseInfos = ConvertMappingsAssetToPoseInfos(AtlResponse, MappingsInfo);

    TMap<FString, FString> BonesMapping;
    if(IsValid(MappingsInfo.GetBoneMappingAsset()))
    {
        BonesMapping.Append(MappingsInfo.GetBoneMappingAsset()->BoneMappings);
    }
    
    UAnimSequence* Result = CreateAnimSequence(Skeleton, CurveInterpMode, AtlResponse, PoseInfos, BonesMapping, Error, InParent, AnimSequenceName, MappingsInfo.ShouldSetUpForMetahumans());

    const double EndTime = FPlatformTime::Seconds();
    UE_LOG(LogMetahumanSDKAnimSequenceFactory, Log, TEXT("Creating AnimSequence took %f seconds to complete"), EndTime - StartTime);

    return Result;
}

UAnimSequence* FAnimSequenceFactory::CreateAnimSequence(USkeleton* Skeleton, ERichCurveInterpMode CurveInterpMode, FATLResponse* AtlResponse,
                                                        const TArray<FPoseInfo>& PoseInfos, const TMap<FString, FString>& BoneNamesMapping, FString& Error, UObject* InParent, const FString& AnimSequenceName, bool bSetUpForMetahumans)
{
    TRACE_CPUPROFILER_EVENT_SCOPE_STR("CreateAnimSequence Impl");

    const FSmartNameMapping* SkeletonCurveNames = Skeleton->GetSmartNameContainer(USkeleton::AnimCurveMappingName);
    ensure(SkeletonCurveNames != nullptr);
	
    const double TimesecStep = 1.0f / AtlResponse->FPS;
    
#if WITH_EDITOR
    FScopedSlowTask SlowTask(AtlResponse->Frames.Num(), INVTEXT("Processing animation frames.."));
    SlowTask.MakeDialog();
#endif

    FRawCurveTracks AnimCurveTracks;
    TMap<FName, FRawAnimSequenceTrack> BoneTracks;

    // Frames processing
    for (int32 FrameIndex = 0; FrameIndex < AtlResponse->Frames.Num(); ++FrameIndex)
    {
#if WITH_EDITOR
        if ( !FApp::IsGame() )
        {
            SlowTask.EnterProgressFrame(1);
        }        
#endif

        TMap<FName, float> CurveWeightedValues;
        const FATLFrameInfo& CurrentAtlFrameInfo = AtlResponse->Frames[FrameIndex];

        // BlendShapes processing        
        for (int32 BlendShapeIndex = 0; BlendShapeIndex < AtlResponse->BlendShapeNames.Num(); ++BlendShapeIndex)
        {
            FPoseInfo CurrentPoseInfo = GetCurrentPoseInfo(PoseInfos, BlendShapeIndex, *AtlResponse->BlendShapeNames[BlendShapeIndex]);            

            // We may not have all Curves from ATL in the Skeleton (case: controls by itself) 
            if ( !SkeletonCurveNames->Exists(CurrentPoseInfo.CurveName) ) continue;
            
            const float CurrentAtlBlendShapeValue = CurrentAtlFrameInfo.CurveValues[BlendShapeIndex] / 100.0f;
            UpdateWeightedValues(CurveWeightedValues, CurrentPoseInfo, CurrentAtlBlendShapeValue);
        }
		
        if (bSetUpForMetahumans) CorrectMetahumanMouth(CurveWeightedValues, CurrentAtlFrameInfo, AtlResponse);

        UpdateAnimCurveTracks(AnimCurveTracks, CurveWeightedValues, FrameIndex * TimesecStep, SkeletonCurveNames, CurveInterpMode);
        UpdateBoneTracks(BoneTracks, Skeleton, BoneNamesMapping, AtlResponse->BonesNames, CurrentAtlFrameInfo.BoneRotations);
    }
    
    const int32 NumFrames = AtlResponse->Frames.Num();    
    const float SequenceLength = TimesecStep * NumFrames;

    UPackage* AnimAsset = CreateAnimAsset(InParent, AnimSequenceName);
    
    UOpenAnimSequence* AnimSequence = NewObject<UOpenAnimSequence>(AnimAsset, *AnimSequenceName, RF_Public | RF_Standalone);    
    {
        AnimSequence->SetSkeleton(Skeleton);
        AnimSequence->SetSequenceLength(SequenceLength);        
    }
	
#if WITH_EDITOR
    PopulateEditorAnimation(AnimSequence, AnimCurveTracks, BoneTracks, NumFrames, AtlResponse->FPS);   
#else
    PopulatePackagedAnimation(AnimSequence, AnimCurveTracks, BoneTracks, NumFrames);
#endif

	return AnimSequence;
}

bool FAnimSequenceFactory::IsInputValid(const USkeleton* Skeleton, const FATLResponse* AtlResponse)
{
    check( AtlResponse != nullptr && AtlResponse->FPS > 0 );

    if ( !IsValid( Skeleton ) )
    {
        UE_LOG(LogMetahumanSDKAnimSequenceFactory, Error, TEXT("%s -- No Skeleton provided!"), *FString(__FUNCTION__));
        return false;
    }

    return true;
}

FPoseInfo FAnimSequenceFactory::GetCurrentPoseInfo(const TArray<FPoseInfo>& PoseInfos, const int32 PoseIdx, const FName BlendShapeName)
{
    FPoseInfo PoseInfo;
    if ( PoseInfos.IsValidIndex(PoseIdx) )
    {
        PoseInfo = PoseInfos[PoseIdx];
    }
    else
    {
        PoseInfo.CurveName = BlendShapeName;
        PoseInfo.AffectedCurveNames.Add(PoseInfo.CurveName);
        PoseInfo.AffectedCurveWeights.Add(1.0f);
    }

    return PoseInfo;
}

void FAnimSequenceFactory::UpdateWeightedValues(TMap<FName, float>& AllWeightedValues, const FPoseInfo& PoseInfo, const float CurrentBlendShape)
{    
    TRACE_CPUPROFILER_EVENT_SCOPE_STR("UpdateWeightedValues");

    // for All poses related to current BlendShapeIndex calculate weighted blendshape value 
    for (int32 CurveIndex = 0; CurveIndex < PoseInfo.AffectedCurveNames.Num(); ++CurveIndex)
    {
        const FName CurveName = PoseInfo.AffectedCurveNames[CurveIndex];

        // Todo calculate average with counter in case if we have many BlendShapes in this key which affects our curve 
        const float CurrentBlendShapeValue = AllWeightedValues.FindRef(CurveName) + PoseInfo.AffectedCurveWeights[CurveIndex] * CurrentBlendShape;
        AllWeightedValues.Add(CurveName, FMath::Clamp(CurrentBlendShapeValue, 0.0f, 1.0f));
    }
}

void FAnimSequenceFactory::CorrectMetahumanMouth(TMap<FName, float>& AllBlendShapes, const FATLFrameInfo& CurrentAtlFrameInfo, const FATLResponse* FAtlResponse)
{
    TRACE_CPUPROFILER_EVENT_SCOPE_STR("CorrectMetahumanMouth");

    const float MouthCloseValue = FMath::Clamp(CurrentAtlFrameInfo.CurveValues[FAtlResponse->BlendShapeNames.IndexOfByKey(TEXT("MouthClose"))] / 100.0f, 0.0f, 1.0f);
    const float JawOpenValue = FMath::Clamp(CurrentAtlFrameInfo.CurveValues[FAtlResponse->BlendShapeNames.IndexOfByKey(TEXT("JawOpen"))] / 100.0f, 0.0f, 1.0f);

    float MouthLipsOverrideValue;
    if (JawOpenValue > KINDA_SMALL_NUMBER)
    {
        // MouthLipsOverrideValue = FMath::Clamp(MouthCloseValue * (1.0f - JawOpenValue), 0.0f, 1.0f);
        MouthLipsOverrideValue = FMath::Clamp(MouthCloseValue / JawOpenValue, 0.0f, 1.0f);
    }
    else
    {
        MouthLipsOverrideValue = FMath::Clamp(0.0f, 0.0f, 1.0f);
    }

    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthLipsTogetherDL"), MouthLipsOverrideValue);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthLipsTogetherDR"), MouthLipsOverrideValue);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthLipsTogetherUL"), MouthLipsOverrideValue);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthLipsTogetherUR"), MouthLipsOverrideValue);

    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthLipsStickyLPh1"), MouthLipsOverrideValue * 0.6f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthLipsStickyLPh2"), MouthLipsOverrideValue * 0.4f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthLipsStickyLPh3"), MouthLipsOverrideValue * 0.2f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthLipsStickyRPh1"), MouthLipsOverrideValue * 0.6f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthLipsStickyRPh2"), MouthLipsOverrideValue * 0.4f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthLipsStickyRPh3"), MouthLipsOverrideValue * 0.2f);

    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthStickyDC"), MouthLipsOverrideValue * 0.33f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthStickyDINL"), MouthLipsOverrideValue * 0.33f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthStickyDINR"), MouthLipsOverrideValue * 0.33f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthStickyDOUTL"), MouthLipsOverrideValue * 0.33f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthStickyDOUTR"), MouthLipsOverrideValue * 0.33f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthStickyUC"), MouthLipsOverrideValue * 0.33f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthStickyUINL"), MouthLipsOverrideValue * 0.33f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthStickyUINR"), MouthLipsOverrideValue * 0.33f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthStickyUOUTL"), MouthLipsOverrideValue * 0.33f);
    AllBlendShapes.Add(TEXT("CTRL_expressions_mouthStickyUOUTR"), MouthLipsOverrideValue * 0.33f);
}

void FAnimSequenceFactory::UpdateAnimCurveTracks(FRawCurveTracks& AnimCurveTracks, const TMap<FName, float>& CurveWeightedValues, const float InTime,
    const FSmartNameMapping* SkeletonCurveNames, const ERichCurveInterpMode CurveInterpMode)
{
    TRACE_CPUPROFILER_EVENT_SCOPE_STR("UpdateAnimCurveTracks");

    // set curve keys for current frame
    for (const TTuple<FName, float>& BlendShapeNameAndValue : CurveWeightedValues)
    {
        const FName CurveName = BlendShapeNameAndValue.Key;
        const float CurveValue = BlendShapeNameAndValue.Value;
        
        FSmartName SmartName;
        if (!SkeletonCurveNames->FindSmartName(CurveName, SmartName))
        {
            UE_LOG(LogMetahumanSDKAnimSequenceFactory, Verbose, TEXT("Blendshape %s not found in provided skeleton!"), *CurveName.ToString());
            continue;
        }
        
        // Get curve
        FFloatCurve* Curve = static_cast<FFloatCurve*>(AnimCurveTracks.GetCurveData(SmartName.UID, ERawCurveTrackTypes::RCT_Float));
        if (Curve == nullptr)
        {
            AnimCurveTracks.AddCurveData(SmartName);
            Curve = static_cast<FFloatCurve*>(AnimCurveTracks.GetCurveData(SmartName.UID, ERawCurveTrackTypes::RCT_Float));
            Curve->Name_DEPRECATED = SmartName;
        }
        
        // Add current key with blend shape value
        FRichCurve& RichCurve = Curve->FloatCurve;
        const FKeyHandle KeyHandle = RichCurve.AddKey(InTime, CurveValue, false);
        
        constexpr  ERichCurveTangentMode NewTangentMode = RCTM_Auto;
        constexpr  ERichCurveTangentWeightMode NewTangentWeightMode = RCTWM_WeightedNone;
        
        // TODO: Set these values properly if we decide to support ERichCurveTangentMode and ERichCurveTangentWeightMode
        RichCurve.SetKeyInterpMode(KeyHandle, CurveInterpMode, true);
        RichCurve.SetKeyTangentMode(KeyHandle, NewTangentMode, true);
        RichCurve.SetKeyTangentWeightMode(KeyHandle, NewTangentWeightMode, true);
        
        FRichCurveKey& NewKey = RichCurve.GetKey(KeyHandle);
        NewKey.ArriveTangent = 0.f;
        NewKey.LeaveTangent = 0.f;
        NewKey.ArriveTangentWeight = 0.f;
        NewKey.LeaveTangentWeight = 0.f;    
    }
}

void FAnimSequenceFactory::UpdateBoneTracks(TMap<FName, FRawAnimSequenceTrack>& BoneTracks, const USkeleton* Skeleton, const TMap<FString, FString>&
                                            BoneNamesMapping, const TArray<FString>& AtlAllBoneNames, const TArray<FVector>& AtlBoneRotations)
{
    TRACE_CPUPROFILER_EVENT_SCOPE_STR("UpdateBoneTracks");

    // Set bone keys for current frame
    const TArray<FTransform> BonesPoses = Skeleton->GetReferenceSkeleton().GetRefBonePose();
    for(int BoneIndex = 0; BoneIndex < AtlAllBoneNames.Num(); ++BoneIndex)
    {
        FString AtlBoneName = AtlAllBoneNames[BoneIndex];
        const bool bHasBoneNameInMap = BoneNamesMapping.Contains(AtlBoneName) && BoneNamesMapping[AtlBoneName].Len();
        FName BoneName = FName( bHasBoneNameInMap ? BoneNamesMapping[AtlBoneName] : AtlBoneName );

        const int32 BoneSkeletonIndex = Skeleton->GetReferenceSkeleton().FindBoneIndex(BoneName);
        if (BoneSkeletonIndex == INDEX_NONE)
        {
            continue;
        }
            
        if( !BoneTracks.Contains(BoneName) )
        {
            BoneTracks.Add(BoneName, FRawAnimSequenceTrack());
        }

        FRawAnimSequenceTrack& CurrentBoneTrack = BoneTracks[BoneName];

        auto RotationDelta = FQuat::MakeFromEuler( AtlBoneRotations[BoneIndex] );
        auto OriginalRotation = BonesPoses[BoneSkeletonIndex].GetRotation();
        auto Rotation = OriginalRotation * RotationDelta;

        CurrentBoneTrack.RotKeys.Add(FQuat4f(Rotation));
        CurrentBoneTrack.ScaleKeys.Add(FVector3f(BonesPoses[BoneSkeletonIndex].GetScale3D()));
        CurrentBoneTrack.PosKeys.Add(FVector3f(BonesPoses[BoneSkeletonIndex].GetLocation()));
    }
}

void FAnimSequenceFactory::AddExtraKeyToBoneTracks(TMap<FName, FRawAnimSequenceTrack>& BoneTracks, const USkeleton* Skeleton)
{
    for(auto& CurrentBoneTrack : BoneTracks)
    {
        const TArray<FTransform> BonePose = Skeleton->GetReferenceSkeleton().GetRefBonePose();
    
        const int32 BoneSkeletonIndex = Skeleton->GetReferenceSkeleton().FindBoneIndex(CurrentBoneTrack.Key);
        if (BoneSkeletonIndex != INDEX_NONE)
        {
            CurrentBoneTrack.Value.RotKeys.Add(FQuat4f(BonePose[BoneSkeletonIndex].GetRotation()));
            CurrentBoneTrack.Value.ScaleKeys.Add(FVector3f(BonePose[BoneSkeletonIndex].GetScale3D()));
            CurrentBoneTrack.Value.PosKeys.Add(FVector3f(BonePose[BoneSkeletonIndex].GetLocation()));
        }
    }
}

UPackage* FAnimSequenceFactory::CreateAnimAsset(UObject* InParent, const FString& AnimSequenceName)
{
    TRACE_CPUPROFILER_EVENT_SCOPE_STR("CreateAnimAsset");
    UPackage* ReturnPackage;
    if ( IsValid(InParent) )
    {
        ReturnPackage = Cast<UPackage>(InParent);

#if WITH_EDITOR
        // we have to check InParent is not valid as this will tell us whether we import asset via editor asset factory or not
        if (MetahumanSDKDevSettings::bCreateAssetsInEditor && !IsValid(InParent))
        {
            FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");

            FString DefaultSuffix;
            FString AssetName;
            FString PackageName;
            const FString BasePackageName(FString::Printf(TEXT("/MetahumanSDK/DebugAssets/ATL/AnimSequence"), *AnimSequenceName));
            AssetToolsModule.Get().CreateUniqueAssetName(BasePackageName, DefaultSuffix, /*out*/ PackageName, /*out*/ AssetName);

            // Create a unique package name and asset name
            ReturnPackage = CreatePackage(*PackageName);
            ReturnPackage->SetFlags(RF_Standalone | RF_Public);
            ReturnPackage->FullyLoad();
        }
#endif        
    }
    else
    {
        ReturnPackage = GetTransientPackage();
    }

    return ReturnPackage;
}

#if WITH_EDITOR
void FAnimSequenceFactory::PopulateEditorAnimation(UAnimSequence* AnimSequence, const FRawCurveTracks& AnimCurveTracks, const TMap<FName, FRawAnimSequenceTrack>& BoneTracks, const
    int32 NumFrames, const int32 Fps)
{
    // Create in-editor data   
    IAnimationDataController& AnimController = AnimSequence->GetController();
   
    AnimController.SetModel(AnimSequence->GetDataModelInterface());   
    
    AnimController.OpenBracket(LOCTEXT("MetahumanSDKAnimSequenceFactory", "Adding float curve."), false);    
    {
        AnimController.InitializeModel();
        AnimController.SetFrameRate(FFrameRate(Fps, 1.f));
        AnimController.SetNumberOfFrames(NumFrames);

        for(auto FloatCurve: AnimCurveTracks.FloatCurves)
        {
            const FAnimationCurveIdentifier CurveId(FloatCurve.Name_DEPRECATED, ERawCurveTrackTypes::RCT_Float);
            AnimController.AddCurve(CurveId, FloatCurve.GetCurveTypeFlags());
            AnimController.SetCurveKeys(CurveId, FloatCurve.FloatCurve.Keys);
        }
	        
        for(auto& Track : BoneTracks)
        {
            AnimController.AddBoneCurve(Track.Key);
            AnimController.SetBoneTrackKeys(Track.Key, Track.Value.PosKeys, Track.Value.RotKeys, Track.Value.ScaleKeys);
        }
            
        AnimController.NotifyPopulated();
    }
    AnimController.CloseBracket(false);
}
#else
void FAnimSequenceFactory::PopulatePackagedAnimation(UAnimSequence* AnimSequence, const FRawCurveTracks& AnimCurveTracks, const TMap<FName, FRawAnimSequenceTrack>& BoneTracks, const
                                                     int32 NumFrames)
{
    // Prepare animation compression payload
    FOpenCompressibleAnimData CompressibleAnimData(
        nullptr,
        FAnimationUtils::GetDefaultAnimationCurveCompressionSettings(),
        AnimSequence->GetSkeleton(),
        EAnimInterpolationType::Linear,
        AnimSequence->GetPlayLength(),
        NumFrames,
        nullptr
        );
    
    CompressibleAnimData.RawFloatCurves = AnimCurveTracks.FloatCurves;
    
    // Compress blendshapes
    TArray<uint8> CompressedCurveData;
    FAnimUtilityLibrary::CompressCurves(CompressibleAnimData, CompressedCurveData);
    AnimSequence->CompressedData.CurveCompressionCodec = CompressibleAnimData.CurveCompressionSettings->Codec;
    AnimSequence->CompressedData.CompressedCurveByteStream = CompressedCurveData;
    AnimSequence->CompressedData.CompressedCurveNames.Empty();
    for(auto FloatCurve: AnimCurveTracks.FloatCurves)
    {
        AnimSequence->CompressedData.CompressedCurveNames.Add(FloatCurve.Name);
    }
    
    // create runtime codec
    auto Codec = NewObject<UMetahumanSDKBoneCompressionCodec>();
    BoneTracks.GenerateValueArray(Codec->Tracks);
    Codec->NumberOfKeys = CompressibleAnimData.NumberOfKeys;
    
    // make compression settings with this codec only and bind it to asset
    AnimSequence->BoneCompressionSettings = NewObject<UAnimBoneCompressionSettings>();
    AnimSequence->BoneCompressionSettings->Codecs.Add(Codec);
    AnimSequence->CompressedData.BoneCompressionCodec = Codec;
    
    // fake-fill some compressed data to pass model validation
    FUECompressedAnimDataMutable AnimDataMutable;
    AnimDataMutable.CompressedNumberOfKeys = CompressibleAnimData.NumberOfKeys;
    AnimSequence->CompressedData.CompressedDataStructure = Codec->AllocateAnimData();
    
    AnimSequence->CompressedData.CompressedTrackToSkeletonMapTable.Empty();
    for (auto &Track: BoneTracks)
    {
        AnimSequence->CompressedData.CompressedTrackToSkeletonMapTable.Add(AnimSequence->GetSkeleton()->GetReferenceSkeleton().FindBoneIndex(Track.Key));
    }
}
#endif

TArray<FPoseInfo> FAnimSequenceFactory::ConvertMappingsAssetToPoseInfos(const FATLResponse* ATLResponse, const FATLMappingsInfo& Mappings)
{
    TRACE_CPUPROFILER_EVENT_SCOPE_STR("ConvertMappingsAssetToPoseInfos");
    
    TArray<FPoseInfo> OutPoseInfos;

    const UMetahumanSDKMappingsAsset* MappingsAsset = Mappings.GetMappingsAsset();
    const UPoseAsset* PoseAsset = Mappings.GetPoseAsset();    

    // handle mappings asset
    if (IsValid(MappingsAsset))
    {
        for (int32 Curve_Idx = 0; Curve_Idx < ATLResponse->BlendShapeNames.Num(); ++Curve_Idx)
        {
            const FName AtlCurveName = *ATLResponse->BlendShapeNames[Curve_Idx];

            FPoseInfo PoseInfo;
            {
                const FName MappingTargetName = *MappingsAsset->BlendShapeMappings.FindRef(AtlCurveName.ToString());

                if (MappingsAsset->BlendShapeMappings.Contains(AtlCurveName.ToString()) && MappingTargetName.ToString().Len() > 0 && MappingTargetName != AtlCurveName)
                {
                    // collect curves affected by pose
                    PoseInfo.CurveName = MappingTargetName;
                    PoseInfo.AffectedCurveNames.Add(PoseInfo.CurveName);
                    PoseInfo.AffectedCurveWeights.Add(1.0f);
                }
                else
                {
                    // collect curves affected by pose
                    PoseInfo.CurveName = AtlCurveName;
                    PoseInfo.AffectedCurveNames.Add(AtlCurveName);
                    PoseInfo.AffectedCurveWeights.Add(1.0f);
                }

                check(PoseInfo.AffectedCurveNames.Num() == PoseInfo.AffectedCurveWeights.Num());
            }

            OutPoseInfos.Add(PoseInfo);
        }
    }
    // handle pose asset
    else if (IsValid(PoseAsset))
    {
        const TArray<FSmartName>& CurveNames = PoseAsset->GetCurveNames();
        const TArray<FSmartName>& PoseNames = PoseAsset->GetPoseNames();
        
        TMap<FName, int32> PoseNamesFastLookup;
        for (int32 PoseIndex = 0; PoseIndex < PoseNames.Num(); ++PoseIndex)
        {
            PoseNamesFastLookup.Add(PoseNames[PoseIndex].DisplayName, PoseIndex);
        }

        for (int32 BlendShapeIndex = 0; BlendShapeIndex < ATLResponse->BlendShapeNames.Num(); ++BlendShapeIndex)
        {
            const FName AtlCurveName = *ATLResponse->BlendShapeNames[BlendShapeIndex];

            FPoseInfo PoseInfo;
            {
                if (PoseNamesFastLookup.Contains(AtlCurveName))
                {
                    const int32 PoseIndex = PoseNamesFastLookup[AtlCurveName];

                    // collect curves affected by pose
                    PoseInfo.CurveName = AtlCurveName;

                    const TArray<float>& CurveValues = PoseAsset->GetCurveValues(PoseIndex);
                    for (int32 CurveIndex = 0; CurveIndex < CurveValues.Num(); ++CurveIndex)
                    {
                        if (CurveValues[CurveIndex] > 0)
                        {
                            PoseInfo.AffectedCurveNames.Add(CurveNames[CurveIndex].DisplayName);
                            PoseInfo.AffectedCurveWeights.Add(CurveValues[CurveIndex]);
                        }
                    }
                }
                else
                {
                    PoseInfo.CurveName = AtlCurveName;
                    PoseInfo.AffectedCurveNames.Add(AtlCurveName);
                    PoseInfo.AffectedCurveWeights.Add(1.0f);
                }

                check(PoseInfo.AffectedCurveNames.Num() == PoseInfo.AffectedCurveWeights.Num());
            }

            OutPoseInfos.Add(PoseInfo);
        }
    }

    return OutPoseInfos;
}
