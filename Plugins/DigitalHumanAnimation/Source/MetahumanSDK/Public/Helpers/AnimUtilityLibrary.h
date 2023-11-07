#pragma once

#include "CoreMinimal.h"

#include "Animation/OpenAnimCompressionTypes.h"

class METAHUMANSDK_API FAnimUtilityLibrary
{
public:

	static float EvaluateCurveValue(const UAnimSequence* AnimSequence, const SmartName::UID_Type CurveUID, const int32 FrameIdx);

	static void CompressCurves(const FOpenCompressibleAnimData& AnimSeq, TArray<uint8>& CompressedCurveBytes);
};
