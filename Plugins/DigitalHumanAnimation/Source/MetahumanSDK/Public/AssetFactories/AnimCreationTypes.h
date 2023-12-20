#pragma once

#include "CoreMinimal.h"
#include "MetahumanSDKAPIInput.h"

#include "AnimCreationTypes.generated.h"

USTRUCT(BlueprintType, meta = (ToolTip="Info for further creation animation after receiving server data"))
struct METAHUMANSDK_API FAnimUserInfo
{
    GENERATED_BODY()

    FAnimUserInfo() {}

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation Factory")
    USkeleton* Skeleton = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation Factory")
    TEnumAsByte<ERichCurveInterpMode> InterpolationMode = RCIM_Linear;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation Factory")
    FATLMappingsInfo Mapping;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation Factory")
    bool bEnableMetahumanCorrection = false;
};

struct FPoseInfo
{
    FName CurveName;
    TArray<FName> AffectedCurveNames;
    TArray<float> AffectedCurveWeights;
};

// universal container with Frames and Blendshapes for inheritance from different server responses (rest, grpc with different contract and structure)
struct FBaseAnimationResource
{
    virtual ~FBaseAnimationResource() {}
    
    virtual const uint32 GerFramesNum() = 0;
    virtual const TArray<float>& GetBlendshapeValues(const SIZE_T Frame_Idx) = 0; 
};

struct FAnimPersistentInfo
{
    const uint8 Fps = 25;

    const TArray<FName> BlendShapeNames =
    {
        "mouthShrugUpper", "mouthPressRight", "mouthUpperUpRight", "eyeWideLeft", "mouthRollLower", "mouthShrugLower", "jawOpen", "mouthCorrectULeftLower",
        "noseSneerRight", "mouthFunnelUpper", "mouthLowerDownLeft", "eyeBlinkLeft", "browDownRight", "swallow", "eyeLookInLeft", "eyeSquintRight",
        "L_openJaw_mouthSmile", "mouthStretchRight", "eyeBlinkRight", "eyeLookOutRight", "nostrilCompressorLeft", "eyeLookInRight", "jawForward", "browOuterUpLeft",
        "mouthSmileLeft", "browInnerUpLeft", "cheekPuffRight", "cheekPuffLeft", "cheekSquintLeft", "noseSneerLeft", "mouthLowerDownRight", "eyeLookOutLeft",
        "nastrilDilatorLeft", "mouthRollUpper", "mouthUpperUpLeft", "eyeSquintLeft", "mouthCorrectURightLower", "eyeLookUpLeft", "mouthClose", "browInnerUpRight",
        "mouthLeft", "mouthSmileRight", "mouthDimpleLeft", "eyeWideRight", "eyeLookDownRight", "mouthPucker", "mouthRight", "mouthFrownRight",
        "cheekSquintRight", "mouthCorrectURightUpper", "browOuterUpRight", "mouthFrownLeft", "mouthPressLeft", "mouthCorrectULeftUpper", "eyeLookDownLeft", "eyeLookUpRight",
        "nastrilDilatorRight", "mouthStretchLeft", "openJaw50_mouthPucket", "jawRight", "mouthDimpleRight", "mouthFunnelLower", "browDownLeft", "jawLeft",
        "nostrilCompressorRight"
    };
};