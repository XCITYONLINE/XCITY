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
	void OnStartHover();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Iteractible Item")
	void OnStopHover();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Iteractible Item")
	void OnStartMainInteract();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Iteractible Item")
	void OnStopMainInteract();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Iteractible Item")
	void OnStartAlternativeInteract();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Iteractible Item")
	void OnStopAlternativeInteract();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Iteractible Item")
	void OnTake(AActor* OwnerActor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Iteractible Item")
	void OnUnselect();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Iteractible Item")
	void OnDrop();

protected:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Iteractible Item")
	void K2_OnHover(const bool bIsHover);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Iteractible Item")
	void K2_OnMainInteract(const bool bIsInteract);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Iteractible Item")
	void K2_OnAlternativeInteract(const bool bIsInteract);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Iteractible Item")
	void K2_OnTake();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Iteractible Item")
	void K2_OnUnselect();
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Iteractible Item")
	void K2_OnDrop();
};
