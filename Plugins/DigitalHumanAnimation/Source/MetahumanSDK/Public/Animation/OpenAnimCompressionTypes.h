#pragma once

#include "Animation/AnimBoneCompressionSettings.h"
#include "Animation/AnimCurveCompressionSettings.h"
#include "Animation/Skeleton.h"
#include "Animation/AnimTypes.h"

// Mirrors FCompressibleAnimData 
struct METAHUMANSDK_API FOpenCompressibleAnimData
{
public:
	FOpenCompressibleAnimData();
	
 	FOpenCompressibleAnimData(UAnimBoneCompressionSettings* InBoneCompressionSettings, UAnimCurveCompressionSettings* InCurveCompressionSettings, USkeleton* InSkeleton, EAnimInterpolationType InInterpolation, float InSequenceLength, int32 InNumberOfKeys, const ITargetPlatform* InTargetPlatform);

	UAnimCurveCompressionSettings* CurveCompressionSettings;

	UAnimBoneCompressionSettings* BoneCompressionSettings;

	// Data from USkeleton
	TArray<FTransform> RefLocalPoses;
	FReferenceSkeleton RefSkeleton;

	EAnimInterpolationType Interpolation;

	TArray<FBoneData> BoneData;

	TArray<FFloatCurve> RawFloatCurves;

	double SequenceLength;

	/** Number of keys within the (non-uniform) RawAnimationData tracks */
	int32 NumberOfFrames;
	int32 NumberOfKeys;

	int32 GetNumberOfFrames() const { return FMath::Max(NumberOfKeys - 1, 1); }

	bool bIsValidAdditive;

	float ErrorThresholdScale;
	
	const ITargetPlatform* TargetPlatform = nullptr;
};
