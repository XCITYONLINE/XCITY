// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/RadialMenuComponent.h"
#include <Conponents/InventoryComponentBase.h>
#include "UI/RadialMenu/RadialMenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "Character/XCityCharacterBase.h"
#include "UI/RadialMenu/RadialMenuSlot.h"
#include "UI/RadialMenu/WeaponRadialMenuSlot.h"

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

	UInventoryComponentBase* InventoryComponentBase = GetInventoryComponentBase();
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
	
	for (int32 i = 0; i < Items.Num(); i++)
	{
		FWeaponsDataStruct WeaponsDataStruct;
		
		if (Items[i]->GetItemSettings<FWeaponsDataStruct>(this, WeaponsDataStruct))
		{
			if (WeaponsDataStruct.WeaponType == InWeaponType)
			{
				OutItemsByType.Add(i, Items[i]);
			}
		}
	}
}

void URadialMenuComponent::EnableRadialMenu(const FInputActionValue& Value)
{
	check(RadialMenuWidget);
	
	RadialMenuWidget->AddToViewport();

	if (Cast<ACharacter>(GetOwner()))
	{
		APlayerController* PlayerController = Cast<APlayerController>(GetOwner()->GetOwner());
		if (!IsValid(PlayerController))
		{
			return;
		}
		
		PlayerController->SetInputMode(FInputModeGameAndUI());
		PlayerController->SetShowMouseCursor(true);
	}
}

void URadialMenuComponent::DisableRadialMenu(const FInputActionValue& Value)
{
	check(RadialMenuWidget);
	
	RadialMenuWidget->RemoveFromParent();

	if (Cast<ACharacter>(GetOwner()))
	{
		APlayerController* PlayerController = Cast<APlayerController>(GetOwner()->GetOwner());
		if (!IsValid(PlayerController))
		{
			return;
		}
		
		PlayerController->SetInputMode(FInputModeGameOnly());
		PlayerController->SetShowMouseCursor(false);
	}

	SelectItem();
}

void URadialMenuComponent::BeginPlay()
{
	Super::BeginPlay();

	const AXCityCharacterBase* CharacterBase = Cast<AXCityCharacterBase>(GetOwner());
	if (!IsValid(CharacterBase))
	{
		return;
	}

	if (IsValid(RadialMenuWidgetClass))
	{
		RadialMenuWidget = CreateWidget<URadialMenuWidget>(Cast<APlayerController>(CharacterBase->GetOwner()), RadialMenuWidgetClass);
	}
	
	GetInventoryComponentBase()->OnInventorySizeChanged.AddUniqueDynamic(this, &URadialMenuComponent::OnInventorySizeChanged);
}

void URadialMenuComponent::OnInventorySizeChanged(const TArray<TScriptInterface<IInteractibleItemInterface>>& Value)
{
	RadialMenuWidget->RefreshRadialMenu();
}

void URadialMenuComponent::SelectItem()
{
	check(RadialMenuWidget);
	
	URadialMenuSlot* Slot = RadialMenuWidget->GetSelectedRadialMenuSlot();
	if (!IsValid(Slot))
	{
		return;
	}

	UWeaponRadialMenuSlot* WeaponRadialMenuSlot = Cast<UWeaponRadialMenuSlot>(Slot);
	if (!IsValid(WeaponRadialMenuSlot))
	{
		return;
	}

	AXCityCharacterBase* CharacterBase = Cast<AXCityCharacterBase>(GetOwner());
	if (!IsValid(CharacterBase))
	{
		return;
	}

	TMap<int32, TScriptInterface<IInteractibleItemInterface>> Items;
	CharacterBase->GetItemsByType(WeaponRadialMenuSlot->GetWeaponType(), Items);
	if (Items.Num() > 0)
	{
		if (Items.Find(WeaponRadialMenuSlot->GetSelectedWeaponIndex()))
		{
			FWeaponsDataStruct WeaponsDataStruct;
			Items[WeaponRadialMenuSlot->GetSelectedWeaponIndex()]->GetItemSettings<FWeaponsDataStruct>(Items[WeaponRadialMenuSlot->GetSelectedWeaponIndex()].GetObject(), WeaponsDataStruct);
			
			CharacterBase->AttachToHand(
			WeaponsDataStruct.WeaponStaticMesh,
			WeaponsDataStruct.WeaponSkeletal,
			WeaponsDataStruct.WeaponAnimInstance,
			false,
			WeaponsDataStruct.AttachOffset,
			true,
			Items[WeaponRadialMenuSlot->GetSelectedWeaponIndex()].GetObject()
				);

			CharacterBase->K2_AttachTo(Items[WeaponRadialMenuSlot->GetSelectedWeaponIndex()].GetObject());
			CharacterBase->SetSelectedInventoryItem(Items[WeaponRadialMenuSlot->GetSelectedWeaponIndex()]);
		}
	}
}

UInventoryComponentBase* URadialMenuComponent::GetInventoryComponentBase() const
{
	const AXCityCharacterBase* CharacterBase = Cast<AXCityCharacterBase>(GetOwner());
	if (!IsValid(CharacterBase))
	{
		return nullptr;
	}
	
	UActorComponent* FoundComponent = CharacterBase->FindComponentByClass<UInventoryComponentBase>();
	UInventoryComponentBase* InventoryComponentBase = Cast<UInventoryComponentBase>(FoundComponent);

	return InventoryComponentBase;
}