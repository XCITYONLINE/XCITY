#include "Helpers/AnimUtilityLibrary.h"

#include "Animation/AnimSequence.h"

float FAnimUtilityLibrary::EvaluateCurveValue(const UAnimSequence* AnimSequence, const SmartName::UID_Type CurveUID, const int32 FrameIdx)
{
	// Current time has different step in the Editor (0.04) and Packaged build (0.000017)
	// float CurrentTime = FMath::Clamp(
	// 	(float)AnimSequence->GetSamplingFrameRate().AsSeconds(FrameIdx),
	// 0.f,
	// AnimSequence->GetPlayLength()
	// );

	const FAnimKeyHelper AnimKeyHelper(AnimSequence->GetPlayLength(), AnimSequence->GetNumberOfSampledKeys());
	const float CurrentTime = FrameIdx * AnimKeyHelper.TimePerKey();	
	//UE_LOG(LogTemp, Warning, TEXT("FAnimUtilityLibrary::EvaluateCurveValue -- CurrentTime : %f "), CurrentTime);
	
	return AnimSequence->EvaluateCurveData(CurveUID, CurrentTime);
}

void FAnimUtilityLibrary::CompressCurves(const FOpenCompressibleAnimData& AnimSeq, TArray<uint8>& CompressedCurveBytes)
{
    // This mirrors UAnimCurveCompressionCodec_CompressedRichCurve settings
    float MaxCurveError = 0.0f;
    bool UseAnimSequenceSampleRate = true;
    float ErrorSampleRate = 60.0f;

    // This mirrors in part the FCompressedRichCurve
    struct FCurveDesc
    {
        TEnumAsByte<ERichCurveCompressionFormat> CompressionFormat;
        TEnumAsByte<ERichCurveKeyTimeCompressionFormat> KeyTimeCompressionFormat;
        TEnumAsByte<ERichCurveExtrapolation> PreInfinityExtrap;
        TEnumAsByte<ERichCurveExtrapolation> PostInfinityExtrap;
        FCompressedRichCurve::TConstantValueNumKeys ConstantValueNumKeys;
        int32 KeyDataOffset;
    };
    
    int32 NumCurves = AnimSeq.RawFloatCurves.Num();
    
    TArray<FCurveDesc> Curves;
    Curves.Reserve(NumCurves);
    Curves.AddUninitialized(NumCurves);
    
    int32 KeyDataOffset = 0;
    KeyDataOffset += sizeof(FCurveDesc) * NumCurves;
    
    const FAnimKeyHelper Helper(AnimSeq.SequenceLength, AnimSeq.NumberOfKeys);
    
    const float SampleRate = UseAnimSequenceSampleRate ? Helper.KeysPerSecond() : ErrorSampleRate;
    
    TArray<uint8> KeyData;
    
    for (int32 CurveIndex = 0; CurveIndex < NumCurves; ++CurveIndex)
    {
    
        const FFloatCurve& Curve = AnimSeq.RawFloatCurves[CurveIndex];
    
        FRichCurve RawCurve = Curve.FloatCurve;    // Copy
    
        RawCurve.RemoveRedundantAutoTangentKeys(MaxCurveError);
    	
        FCompressedRichCurve CompressedCurve;
        RawCurve.CompressCurve(CompressedCurve, MaxCurveError, SampleRate);
    
        FCurveDesc& CurveDesc = Curves[CurveIndex];
        CurveDesc.CompressionFormat = CompressedCurve.CompressionFormat;
        CurveDesc.KeyTimeCompressionFormat = CompressedCurve.KeyTimeCompressionFormat;
        CurveDesc.PreInfinityExtrap = CompressedCurve.PreInfinityExtrap;
        CurveDesc.PostInfinityExtrap = CompressedCurve.PostInfinityExtrap;
        CurveDesc.ConstantValueNumKeys = CompressedCurve.ConstantValueNumKeys;
        CurveDesc.KeyDataOffset = KeyDataOffset;
    
        KeyDataOffset += CompressedCurve.CompressedKeys.Num();
        KeyData.Append(CompressedCurve.CompressedKeys);
    }
    
    TArray<uint8> TempBytes;
    TempBytes.Reserve(KeyDataOffset);
    
    // Serialize the compression settings into a temporary array. The archive
    // is flagged as persistent so that machines of different endianness produce
    // identical binary results.
    FMemoryWriter Ar(TempBytes, /*bIsPersistent=*/ true);
    
    Ar.Serialize(Curves.GetData(), sizeof(FCurveDesc) * NumCurves);
    Ar.Serialize(KeyData.GetData(), KeyData.Num());
    
    CompressedCurveBytes = TempBytes;
}
