// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/RadialMenuComponent.h"
#include <Conponents/InventoryComponentBase.h>
#include "Character/XCityCharacterBase.h"

URadialMenuComponent::URadialMenuComponent()
{
	
}

void URadialMenuComponent::GetItemsByType(const EWeaponType& InWeaponType,
	TMap<int32, TScriptInterface<IInteractibleItemInterface>>& OutItemsByType) const
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

	UActorComponent* FoundComponent = CharacterBase->FindComponentByClass<UInventoryComponentBase>();
	UInventoryComponentBase* InventoryComponentBase =Cast<UInventoryComponentBase>(FoundComponent);
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
