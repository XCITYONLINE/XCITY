// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "InteractibleItemInterface.generated.h"

UINTERFACE(MinimalAPI)
class UInteractibleItemInterface : public UInterface
{
	GENERATED_BODY()
};

class COMMONCONTRACTSPLUGIN_API IInteractibleItemInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Iteractible Item")
	void OnInteract();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Iteractible Item")
	void OnTake();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Iteractible Item")
	void OnDrop();

protected:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Iteractible Item")
	void K2_OnInteract();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Iteractible Item")
	void K2_OnTake();
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Iteractible Item")
	void K2_OnDrop();
};
