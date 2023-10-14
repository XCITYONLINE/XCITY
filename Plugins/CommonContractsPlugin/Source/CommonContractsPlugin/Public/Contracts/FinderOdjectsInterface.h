// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractibleItemInterface.h"
#include "UObject/Interface.h"

#include "FinderOdjectsInterface.generated.h"

UINTERFACE(MinimalAPI)
class UFinderObjectsInterface : public UInterface
{
	GENERATED_BODY()
};


class COMMONCONTRACTSPLUGIN_API IFinderObjectsInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Finder")
	bool TryFindInteractibleObjects(TArray<TScriptInterface<IInteractibleItemInterface>>& OutObjects);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Finder")
	void ResetPreviousItems();
};
