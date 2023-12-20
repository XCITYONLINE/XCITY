// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DemoLibrary_BP.generated.h"

class UTalkComponent;

/**
 * Demo library for using in the blueprint classes 
 */
UCLASS()
class METAHUMANSDK_API UDemoLibrary_BP : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	* Get Talk Component from first Actor with it. 
	*/	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"), Category = "Demo Library for Blueprints")
	static bool GetNativeTalkComponent(const UObject* WorldContextObject, UTalkComponent*& TalkComponent);	
};
