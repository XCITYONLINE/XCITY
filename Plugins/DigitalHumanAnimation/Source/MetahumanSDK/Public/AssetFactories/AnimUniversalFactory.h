#pragma once

#include "CoreMinimal.h"
#include "Curves/RealCurve.h"
#include "AssetFactories/AnimCreationTypes.h"

class USkeleton;
class UAnimSequence;

class FFeedbackContext;

class FAnimUniversalFactory
{
public:
	UAnimSequence* CreateAnimation(const FAnimUserInfo& AnimUserInfo, TSharedPtr<FBaseAnimationResource> AnimCreationResource);

private:
	bool IsInputValid();

	// inside Frame logic
	void CreateAnimTrack(const float InTime, const FName BlendShapeName, const float BlendShapeValue, TMap<FName, float>& CachedPoseMappingCurves);
	void AddCurveToAnimTrack(const float InTime, const FName& CurveName, const float& CurveValue);
	void CorrectMetahumanMouth(const float FrameTime, const TArray<float>& BlendShapeValues);

#if WITH_EDITOR
	void PopulateEditorAnimation(UAnimSequence* AnimSequence, const int32 NumFrames);
#else
	void PopulatePackagedAnimation(UAnimSequence* AnimSequence, const int32 NumFrames);
#endif
	
private:
	FAnimUserInfo UserInfo;
	TSharedPtr<FBaseAnimationResource> AnimResource;
	static inline const FAnimPersistentInfo PersistentInfo = FAnimPersistentInfo();

	TArray<FName> SkeletonCurveNames;	
	FRawCurveTracks AnimCurveTracks;
};
