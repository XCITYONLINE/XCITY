// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/RadialMenuComponent.h"

#include <Conponents/InventoryComponentBase.h>

#include "Character/XCityCharacterBase.h"


// Sets default values for this component's properties
URadialMenuComponent::URadialMenuComponent()
{
	
}

void URadialMenuComponent::GetItemsByType(const EWeaponType& InWeaponType,
	TMap<int32, TScriptInterface<IInteractibleItemInterface>>& OutItemsByType)
{
	if (!IsValid(GetOwner()))
	{
		return;
	}
	
	const AXCityCharacterBase* CharacterBase = Cast<AXCityCharacterBase>(GetOwner());
	if (!IsValid(CharacterBase))
	{
		return;
	}

	UInventoryComponentBase* InventoryComponentBase = CharacterBase->GetInventoryComponent();
	if (!IsValid(InventoryComponentBase))
	{
		return;
	}

	TArray<TScriptInterface<IInteractibleItemInterface>> Items;
	InventoryComponentBase->GetAllInventoryItems_Implementation(Items);
	if (Items.IsEmpty())
	{
		return;
	}

	for (auto Item : Items)
	{
		//Item->GetItemSettings()
	}
}