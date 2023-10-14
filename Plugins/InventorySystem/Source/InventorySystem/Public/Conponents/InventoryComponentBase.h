// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Contracts/InventorySystemInterface.h"
#include "Contracts/InteractibleItemInterface.h"

#include "InventoryComponentBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventorySizeChanged, const TArray<TScriptInterface<IInteractibleItemInterface>>&, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryItemSelected, const TScriptInterface<IInteractibleItemInterface>&, Value);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INVENTORYSYSTEM_API UInventoryComponentBase : public UActorComponent,
public IInventorySystemInterface
{
	GENERATED_BODY()

public:	

	UInventoryComponentBase();

	//IInventorySystemInterface implements
	virtual void OnInitInventorySystem_Implementation() override;
	virtual void OnForwardItemChanged_Implementation() override;
	virtual void OnBackwardItemChanged_Implementation() override;
	virtual void AddInventoryItem_Implementation(
		TScriptInterface<IInteractibleItemInterface>& InNewInventoryItem) override;
	virtual void SetInventoryItem_Implementation(
		TScriptInterface<IInteractibleItemInterface>& InInventoryItem, const int32 InInventoryIndex) override;
	virtual void RemoveInventoryItem_Implementation(
		TScriptInterface<IInteractibleItemInterface>& InInventoryItem) override;
	virtual void RemoveInventoryItemByIndex_Implementation(const int32 InInventoryIndex) override;
	virtual TScriptInterface<IInteractibleItemInterface> GetSelectedItem_Implementation() override;
	virtual void GetAllInventoryItems_Implementation(
		TArray<TScriptInterface<IInteractibleItemInterface>>& OutInventoryItems) override;
	virtual void UnselectItem_Implementation() override;
	//~

public:

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnInventorySizeChanged OnInventorySizeChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnInventoryItemSelected OnInventoryItemSelected;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AllItemsValue;

private:

	int32 CurrentInventoryItemIndex;

	TArray<TScriptInterface<IInteractibleItemInterface>> AllInventoryItems;
	TScriptInterface<IInteractibleItemInterface> SelectedItem;
};
