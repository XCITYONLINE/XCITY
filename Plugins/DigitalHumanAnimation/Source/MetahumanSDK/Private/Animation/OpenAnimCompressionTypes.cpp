#include "Animation/OpenAnimCompressionTypes.h"

#include "AnimationUtils.h"

FOpenCompressibleAnimData::FOpenCompressibleAnimData(UAnimBoneCompressionSettings* InBoneCompressionSettings, UAnimCurveCompressionSettings* InCurveCompressionSettings, USkeleton* InSkeleton, EAnimInterpolationType InInterpolation, float InSequenceLength, int32 InNumberOfKeys, const ITargetPlatform* InTargetPlatform)
	: CurveCompressionSettings(InCurveCompressionSettings)
	, BoneCompressionSettings(InBoneCompressionSettings)
	, Interpolation(InInterpolation)
	, SequenceLength(InSequenceLength)
	, NumberOfFrames(InNumberOfKeys)
	, NumberOfKeys(InNumberOfKeys)
	, bIsValidAdditive(false)
	, ErrorThresholdScale(1.f)
	, TargetPlatform(InTargetPlatform)
{
	RefLocalPoses = InSkeleton->GetRefLocalPoses();
	RefSkeleton = InSkeleton->GetReferenceSkeleton();
	FAnimationUtils::BuildSkeletonMetaData(InSkeleton, BoneData);
}

FOpenCompressibleAnimData::FOpenCompressibleAnimData()
: CurveCompressionSettings(nullptr)
, BoneCompressionSettings(nullptr)
, Interpolation((EAnimInterpolationType)0)
, SequenceLength(0.f)
, NumberOfFrames(0)
, NumberOfKeys(0)
, bIsValidAdditive(false)
, ErrorThresholdScale(1.f)
, TargetPlatform(nullptr)
{
}
