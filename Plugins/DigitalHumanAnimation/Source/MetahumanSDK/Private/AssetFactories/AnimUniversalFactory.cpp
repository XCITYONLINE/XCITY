#include "AssetFactories/AnimUniversalFactory.h"

#include "UObject/Package.h"
#include "AnimationUtils.h"
#include "Animation/OpenAnimCompressionTypes.h"
#include "Animation/OpenAnimSequence.h"
#include "Codecs/MetahumanSDKBoneCompressionCodec.h"
#include "Helpers/AnimUtilityLibrary.h"

#define LOCTEXT_NAMESPACE "MetahumanSDKAnimSequenceFactory"
DEFINE_LOG_CATEGORY_STATIC(LogMSdkAnimFactory, Warning, All);

UAnimSequence* FAnimUniversalFactory::CreateAnimation(const FAnimUserInfo& AnimUserInfo, TSharedPtr<FBaseAnimationResource> AnimCreationResource)
{
	UserInfo = AnimUserInfo;
	AnimResource = MoveTemp(AnimCreationResource);

	if ( !IsInputValid() ) return nullptr;
	
	UserInfo.Skeleton->GetCurveMetaDataNames(SkeletonCurveNames);

	const double TimesecStep = 1.0f / PersistentInfo.Fps;
	
	// Frames processing
	for (uint32 FrameIndex = 0; FrameIndex < AnimResource->GerFramesNum(); ++FrameIndex)
	{
		const float FrameTime = FrameIndex * TimesecStep;				
		TMap<FName, float> CachedPoseMappingCurves; // Helper cache instead searching Anim Track (useful with Pose asset mapping) 		
		const TArray<float>& BlendShapeValues = AnimResource->GetBlendshapeValues(FrameIndex);
		
		// BlendShapes processing        
		for (uint8 BlendShapeIndex = 0; BlendShapeIndex < BlendShapeValues.Num(); ++BlendShapeIndex)
		{
			const FName CurrentBlendShapeName = PersistentInfo.BlendShapeNames[BlendShapeIndex];

			// We may not have all Curves from ATL in the Skeleton (case: Arkit mapping has control relationship between curves) 
			if ( !SkeletonCurveNames.Contains(CurrentBlendShapeName) ) continue;

			const float CurrentBlendShapeValue = FMath::Clamp(BlendShapeValues[BlendShapeIndex] / 100.0f, 0.0f, 1.0f);			
			if ( !( CurrentBlendShapeValue < 0.f || FMath::IsNearlyZero(CurrentBlendShapeValue, (1.e-3f)) ) )
			{
				CreateAnimTrack(FrameTime, CurrentBlendShapeName, CurrentBlendShapeValue, CachedPoseMappingCurves);	
			}			
		}

		/// Todo optimization thinking		
		if (UserInfo.bEnableMetahumanCorrection) CorrectMetahumanMouth(FrameTime, BlendShapeValues);	
	}
    
	const int32 NumFrames = AnimResource->GerFramesNum();    
	const float SequenceLength = TimesecStep * NumFrames;

	UOpenAnimSequence* AnimSequence = NewObject<UOpenAnimSequence>(GetTransientPackage(), TEXT(""), RF_Public | RF_Standalone);    
	{
		AnimSequence->SetSkeleton(UserInfo.Skeleton);
		AnimSequence->SetSequenceLength(SequenceLength);        
	}
	
#if WITH_EDITOR
	PopulateEditorAnimation(AnimSequence, NumFrames);   
#else
	PopulatePackagedAnimation(AnimSequence, NumFrames);
#endif

	return AnimSequence;
}

bool FAnimUniversalFactory::IsInputValid()
{
	if (UserInfo.Skeleton == nullptr)
	{
		UE_LOG( LogMSdkAnimFactory, Error, TEXT("%s -- Can't create Animation without Skeleton!"), *FString(__FUNCTION__) );
		return false;
	}

	if (AnimResource->GerFramesNum() == 0)
	{
		UE_LOG( LogMSdkAnimFactory, Error, TEXT("%s -- Can't create Animation without Frames!"), *FString(__FUNCTION__) );
		return false;
	}

	return true;
}

void FAnimUniversalFactory::CreateAnimTrack(const float InTime, const FName BlendShapeName, const float BlendShapeValue, TMap<FName, float>& CachedPoseMappingCurves)
{	
	// Mapping Asset	
	if (const UMetahumanSDKMappingsAsset* MappingsAsset = UserInfo.Mapping.GetMappingsAsset(); MappingsAsset != nullptr)
	{
		const FName AffectedBlendShapeName = *MappingsAsset->BlendShapeMappings.FindRef(BlendShapeName.ToString());

		if (MappingsAsset->BlendShapeMappings.Contains(BlendShapeName.ToString()) && AffectedBlendShapeName.ToString().Len() > 0)
		{
			AddCurveToAnimTrack(InTime, AffectedBlendShapeName, BlendShapeValue);
			
			return;
		}
		UE_LOG( LogMSdkAnimFactory, Warning, TEXT("%s -- Mapping Asset doesn't contain valid data for %s! Continue applying Curve Data without mapping.."),
			*FString(__FUNCTION__),  *(BlendShapeName.ToString()) );
	}

	// Pose Asset	 
	if (const UPoseAsset* PoseAsset = UserInfo.Mapping.GetPoseAsset(); PoseAsset != nullptr)
	{
		const int32 PoseIdx = PoseAsset->GetPoseIndexByName(BlendShapeName);
		if ( PoseIdx != INDEX_NONE)
		{
			const TArray<float>& CurveValues = PoseAsset->GetCurveValues(PoseIdx);
			const TArray<FName>& CurveNames = PoseAsset->GetCurveFNames();
			
			/// Todo investigate possible optimization curve values iteration, if needed
			for (int32 CurveIndex = 0; CurveIndex < CurveValues.Num(); ++CurveIndex)
			{
				if (CurveValues[CurveIndex] > 0)
				{
					/// Todo implement UserCurveBlendingOptions (example - calculate average for the current effect and existing one)
					const float CurrentBlendShapeValue = CachedPoseMappingCurves.FindRef(CurveNames[CurveIndex]) + CurveValues[CurveIndex] * BlendShapeValue;
					CachedPoseMappingCurves.Add(BlendShapeName, CurrentBlendShapeValue);
					
					AddCurveToAnimTrack(InTime, CurveNames[CurveIndex], CurrentBlendShapeValue);
				}
			}

			return;
		}
		UE_LOG( LogMSdkAnimFactory, Warning, TEXT("%s -- Pose Asset doesn't contain Pose for %s! Continue applying Curve Data without mapping.."),
			*FString(__FUNCTION__),  *(BlendShapeName.ToString()) );
	}

	AddCurveToAnimTrack(InTime, BlendShapeName, BlendShapeValue);
}

void FAnimUniversalFactory::AddCurveToAnimTrack(const float InTime, const FName& CurveName, const float& CurveValue)
{
	if (!SkeletonCurveNames.Contains(CurveName))
	{
		UE_LOG(LogMSdkAnimFactory, Verbose, TEXT("Blendshape %s not found in provided skeleton!"), *CurveName.ToString());
		return;
	}
    
	// Get curve
	FFloatCurve* Curve = static_cast<FFloatCurve*>(AnimCurveTracks.GetCurveData(CurveName, ERawCurveTrackTypes::RCT_Float));
	if (Curve == nullptr)
	{
		AnimCurveTracks.AddCurveData(CurveName);
		Curve = static_cast<FFloatCurve*>(AnimCurveTracks.GetCurveData(CurveName, ERawCurveTrackTypes::RCT_Float));
		Curve->SetName(CurveName);
	}
    
	// Add current key with blend shape value
	FRichCurve& RichCurve = Curve->FloatCurve;
	const FKeyHandle KeyHandle = RichCurve.AddKey(InTime, CurveValue, false);
    
	constexpr  ERichCurveTangentMode NewTangentMode = RCTM_Auto;
	constexpr  ERichCurveTangentWeightMode NewTangentWeightMode = RCTWM_WeightedNone;
    
	// TODO: Set these values properly if we decide to support ERichCurveTangentMode and ERichCurveTangentWeightMode
	RichCurve.SetKeyInterpMode(KeyHandle, UserInfo.InterpolationMode, true);
	RichCurve.SetKeyTangentMode(KeyHandle, NewTangentMode, true);
	RichCurve.SetKeyTangentWeightMode(KeyHandle, NewTangentWeightMode, true);
    
	FRichCurveKey& NewKey = RichCurve.GetKey(KeyHandle);
	NewKey.ArriveTangent = 0.f;
	NewKey.LeaveTangent = 0.f;
	NewKey.ArriveTangentWeight = 0.f;
	NewKey.LeaveTangentWeight = 0.f;
}

void FAnimUniversalFactory::CorrectMetahumanMouth(const float FrameTime, const TArray<float>& BlendShapeValues)
{
	const float MouthCloseValue = FMath::Clamp(BlendShapeValues[PersistentInfo.BlendShapeNames.IndexOfByKey(TEXT("mouthClose"))] / 100.0f, 0.0f, 1.0f);
    const float JawOpenValue = FMath::Clamp(BlendShapeValues[PersistentInfo.BlendShapeNames.IndexOfByKey(TEXT("jawOpen"))] / 100.0f, 0.0f, 1.0f);

    float MouthLipsOverrideValue;
    if (JawOpenValue > KINDA_SMALL_NUMBER)
    {
        MouthLipsOverrideValue = FMath::Clamp(MouthCloseValue / JawOpenValue, 0.0f, 1.0f);
    }
    else
    {
        MouthLipsOverrideValue = FMath::Clamp(0.0f, 0.0f, 1.0f);
    }

	TMap<FName, float> MetahumanCorrectionCurves;

	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthLipsTogetherDL"), MouthLipsOverrideValue);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthLipsTogetherDR"), MouthLipsOverrideValue);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthLipsTogetherUL"), MouthLipsOverrideValue);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthLipsTogetherUR"), MouthLipsOverrideValue);
	
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthLipsStickyLPh1"), MouthLipsOverrideValue * 0.6f);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthLipsStickyLPh2"), MouthLipsOverrideValue * 0.4f);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthLipsStickyLPh3"), MouthLipsOverrideValue * 0.2f);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthLipsStickyRPh1"), MouthLipsOverrideValue * 0.6f);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthLipsStickyRPh2"), MouthLipsOverrideValue * 0.4f);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthLipsStickyRPh3"), MouthLipsOverrideValue * 0.2f);

	
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthStickyDC"), MouthLipsOverrideValue * 0.33f);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthStickyDINL"), MouthLipsOverrideValue * 0.33f);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthStickyDINR"), MouthLipsOverrideValue * 0.33f);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthStickyDOUTL"), MouthLipsOverrideValue * 0.33f);	
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthStickyDOUTR"), MouthLipsOverrideValue * 0.33f);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthStickyUC"), MouthLipsOverrideValue * 0.33f);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthStickyUINL"), MouthLipsOverrideValue * 0.33f);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthStickyUINR"), MouthLipsOverrideValue * 0.33f);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthStickyUOUTL"), MouthLipsOverrideValue * 0.33f);
	AddCurveToAnimTrack(FrameTime, TEXT("CTRL_expressions_mouthStickyUOUTR"), MouthLipsOverrideValue * 0.33f);
}

#if WITH_EDITOR
void FAnimUniversalFactory::PopulateEditorAnimation(UAnimSequence* AnimSequence, const int32 NumFrames)
{
	// Create in-editor data   
	IAnimationDataController& AnimController = AnimSequence->GetController();
   
	AnimController.SetModel(AnimSequence->GetDataModelInterface());   
    
	AnimController.OpenBracket(LOCTEXT("LogMSdkAnimFactory", "Adding float curve."), false);    
	{
		AnimController.InitializeModel();
		AnimController.SetFrameRate(FFrameRate(PersistentInfo.Fps, 1.f));
		AnimController.SetNumberOfFrames(NumFrames);

		for(auto FloatCurve: AnimCurveTracks.FloatCurves)
		{
			const FAnimationCurveIdentifier CurveId(FloatCurve.GetName(), ERawCurveTrackTypes::RCT_Float);
			AnimController.AddCurve(CurveId, FloatCurve.GetCurveTypeFlags());
			AnimController.SetCurveKeys(CurveId, FloatCurve.FloatCurve.Keys);
		}
            
		AnimController.NotifyPopulated();
	}
	AnimController.CloseBracket(false);
}
#else
void FAnimUniversalFactory::PopulatePackagedAnimation(UAnimSequence* AnimSequence, const int32 NumFrames)
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

	const int32 NumCurves = AnimCurveTracks.FloatCurves.Num();
	AnimSequence->CompressedData.IndexedCurveNames.Reset(NumCurves);
	AnimSequence->CompressedData.IndexedCurveNames.AddUninitialized(NumCurves);
	for (int32 CurveIndex = 0; CurveIndex < NumCurves; ++CurveIndex)
	{
		const FFloatCurve& Curve = AnimCurveTracks.FloatCurves[CurveIndex];
		AnimSequence->CompressedData.IndexedCurveNames[CurveIndex].CurveName = Curve.GetName();
	}
    
	AnimSequence->CompressedData.RebuildCurveIndexTable();
    
    // create runtime codec
    auto Codec = NewObject<UMetahumanSDKBoneCompressionCodec>();
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
}
#endif
