// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Contracts/InteractibleItemInterface.h"
#include "UObject/Interface.h"

#include "InventorySystemInterface.generated.h"

UINTERFACE(MinimalAPI)
class UInventorySystemInterface : public UInterface
{
	GENERATED_BODY()
};

class COMMONCONTRACTSPLUGIN_API IInventorySystemInterface
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory Item")
	void OnInitInventorySystem();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory Item")
	void OnForwardItemChanged();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory Item")
	void OnBackwardItemChanged();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory Item")
	void UnselectItem();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory Item")
	void UnselectAllItems();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory Item")
	TScriptInterface<IInteractibleItemInterface> GetSelectedItem();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory Item")
	void GetAllInventoryItems(TArray<TScriptInterface<IInteractibleItemInterface>>& OutInventoryItems);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory Item")
	void AddInventoryItem(TScriptInterface<IInteractibleItemInterface>& InNewInventoryItem);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory Item")
	void SetInventoryItem(TScriptInterface<IInteractibleItemInterface>& InInventoryItem, const int32 InInventoryIndex);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory Item")
	void RemoveInventoryItem(TScriptInterface<IInteractibleItemInterface>& InInventoryItem);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory Item")
	void RemoveInventoryItemByIndex(const int32 InInventoryIndex);
};
