#include "Helpers/AnimationLibrary_BP.h"

#include "Animation/AnimSequence.h"
#include "AnimSequenceFactory.h"
#include "Request/MetahumanSDKResponses.h"

DEFINE_LOG_CATEGORY_STATIC(LogAnimationLibrary_BP, Log, All);

bool UAnimationLibrary_BP::JsonFileToAnimation(const FString& FileName, UAnimSequence*& OutAnimation, const FAnimCreateParameters& AnimParameters)
{
	FString JsonString;
	if (!FFileHelper::LoadFileToString(JsonString, *FileName))
	{
		UE_LOG(LogAnimationLibrary_BP, Error, TEXT("Filename %s does not exist!"), *FileName);		
		return false;
	}

	return JsonStringToAnimation(FPaths::GetBaseFilename(FileName), MoveTemp(JsonString), OutAnimation, AnimParameters);	
}

bool UAnimationLibrary_BP::JsonStringToAnimation(const FString& AssetName, FString JsonString, UAnimSequence*& OutAnimation, const FAnimCreateParameters& AnimParameters)
{
	FATLResponse ATLResponse;
	ATLResponse.ParseResponse(MoveTemp(JsonString));
	if (!ATLResponse.bResponseSuccess)
	{
		UE_LOG(LogAnimationLibrary_BP, Error, TEXT("Invalid json file!"));
		return false;
	}

	FString AnimCreationError;
	UAnimSequence* AnimSequence = FAnimSequenceFactory::CreateAnimSequence(
		AnimParameters.Skeleton,
		AnimParameters.CurveInterpMode,
		FATLMappingsInfo(AnimParameters.ATLMappingsInfo),
		&ATLResponse, AnimCreationError, nullptr, AssetName
	);

	if (!IsValid(AnimSequence))
	{
		UE_LOG(LogAnimationLibrary_BP, Error, TEXT("Can't create AnimSequence:  %s"), *AnimCreationError);
		return false;
	}

	OutAnimation = AnimSequence;
	
	return true;
}
