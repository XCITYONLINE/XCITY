#pragma once

#include "CoreMinimal.h"
#include "Curves/RealCurve.h"
#include "MetahumanSDKAPIInput.h"
#include "AnimCreationTypes.h"


class USkeleton;
class UAnimSequence;
class UMetahumanSDKMappingsAsset;
class UPoseAsset;
class FFeedbackContext;
struct FATLResponse;

struct FATLFrameInfo;

class METAHUMANSDK_API FAnimSequenceFactory
{
    FAnimSequenceFactory();
    FAnimSequenceFactory(FVTableHelper& Helper);
    virtual ~FAnimSequenceFactory();

public:
    static UAnimSequence* CreateAnimSequence(USkeleton* Skeleton, ERichCurveInterpMode CurveInterpMode, const FATLMappingsInfo& MappingsInfo,
        FATLResponse* AtlResponse, FString& Error, UObject* InParent = nullptr, const FString& AnimSequenceName = TEXT(""));
    
private:
    static TArray<FPoseInfo> ConvertMappingsAssetToPoseInfos(const FATLResponse* ATLResponse, const FATLMappingsInfo& Mappings);

    static UAnimSequence* CreateAnimSequence(USkeleton* Skeleton, ERichCurveInterpMode CurveInterpMode, FATLResponse* AtlResponse, const TArray<FPoseInfo>& PoseInfos, const TMap<FString, FString>& BoneNamesMapping, FString& Error, UObject* InParent = nullptr, const FString& AnimSequenceName = TEXT(""), bool bSetUpForMetahumans = false);

    static bool IsInputValid(const USkeleton* Skeleton, const FATLResponse* AtlResponse);
    static FPoseInfo GetCurrentPoseInfo(const TArray<FPoseInfo>& PoseInfos, const int32 PoseIdx, const FName BlendshapeName);
    static void UpdateWeightedValues(TMap<FName, float>& AllWeightedValues, const  FPoseInfo& PoseInfo, const float CurrentBlendShape);
    static void CorrectMetahumanMouth(TMap<FName, float>& AllBlendShapes, const FATLFrameInfo& CurrentAtlFrameInfo, const FATLResponse* FAtlResponse);
    static void UpdateAnimCurveTracks(FRawCurveTracks& AnimCurveTracks, const TMap<FName, float>& CurveWeightedValues, const float InTime, const FSmartNameMapping* SkeletonCurveNames,
        const ERichCurveInterpMode CurveInterpMode);
    static void UpdateBoneTracks(TMap<FName, FRawAnimSequenceTrack>& BoneTracks, const USkeleton* Skeleton, const TMap<FString, FString>&
                                 BoneNamesMapping, const TArray<FString>& AtlAllBoneNames, const TArray<FVector>& AtlBoneRotations);
    static void AddExtraKeyToBoneTracks(TMap<FName, FRawAnimSequenceTrack>& BoneTracks, const USkeleton* Skeleton);
    static UPackage* CreateAnimAsset(UObject* InParent, const FString& AnimSequenceName);

#if WITH_EDITOR
    static void PopulateEditorAnimation(UAnimSequence* AnimSequence, const FRawCurveTracks& AnimCurveTracks, const TMap<FName, FRawAnimSequenceTrack>& BoneTracks, const
                                        int32 NumFrames, const int32 Fps);
#else
    static void PopulatePackagedAnimation(UAnimSequence* AnimSequence, const FRawCurveTracks& AnimCurveTracks, const TMap<FName, FRawAnimSequenceTrack>& BoneTracks, const
                                          int32 NumFrames);
#endif
    
};
