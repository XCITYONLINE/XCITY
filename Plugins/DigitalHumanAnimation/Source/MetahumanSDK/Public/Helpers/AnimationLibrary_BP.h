// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "MetahumanSDKAPIInput.h"

#include "AnimationLibrary_BP.generated.h"

USTRUCT(BlueprintType)
struct METAHUMANSDK_API FAnimCreateParameters
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MetahumanSDKATLOutput")
	USkeleton* Skeleton = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MetahumanSDKATLOutput")
	TEnumAsByte<ERichCurveInterpMode> CurveInterpMode = RCIM_Cubic;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MetahumanSDKATLOutput")
	FATLMappingsInfo ATLMappingsInfo;	
};

/**
 * Animation library for using in the blueprint classes 
 */
UCLASS()
class METAHUMANSDK_API UAnimationLibrary_BP : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/**
	* Convert Json from server to an Animation 
	*/
	UFUNCTION(BlueprintCallable, Category = "Animation Library for Blueprints")
	static bool JsonFileToAnimation(const FString& FileName, UAnimSequence*& OutAnimation, const FAnimCreateParameters& AnimParameters);

	UFUNCTION(BlueprintCallable, Category = "Animation Library for Blueprints")
	static bool JsonStringToAnimation(const FString& AssetName, FString JsonString, UAnimSequence*& OutAnimation, const FAnimCreateParameters& AnimParameters);	
};
