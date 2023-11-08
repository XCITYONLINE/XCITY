// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/Components/RadialMenuComponent.h"
#include "EnhancedInputComponent.h"
#include "Blueprint/UserWidget.h"
#include "Conponents/InventoryComponentBase.h"
#include "GameFramework/Character.h"
#include "XCityOnline/Public/Character/XCityCharacterBase.h"
#include "XCityOnline/Public/UI/XCityHUD.h"
#include "XCityOnline/Public/UI/RadialMenu/RadialMenuWidget.h"
#include "XCityOnline/Public/UI/RadialMenu/WeaponRadialMenuSlot.h"

URadialMenuComponent::URadialMenuComponent()
{
	
}

void URadialMenuComponent::GetItemsByType(const EWeaponType& InWeaponType,
	TMap<int32, TScriptInterface<IInteractibleItemInterface>>& OutItemsByType)
{
	if (!IsValid(GetOwner()) || !IsValid(InventoryComponentBase))
	{
		return;
	}

	TArray<TScriptInterface<IInteractibleItemInterface>> Items;
	InventoryComponentBase->GetAllInventoryItems_Implementation(Items);
	if (Items.IsEmpty())
	{
		return;
	}

	int32 Index = 0;
	for (int32 i = 0; i < Items.Num(); i++)
	{
		FWeaponsDataStruct WeaponsDataStruct;
		
		if (Items[i]->GetItemSettings<FWeaponsDataStruct>(this, WeaponsDataStruct))
		{
			if (WeaponsDataStruct.WeaponType == InWeaponType)
			{
				OutItemsByType.Add(Index, Items[i]);
				Index++;
			}
		}
	}
}

void URadialMenuComponent::EnableRadialMenu(const FInputActionValue& Value)
{
	check(RadialMenuWidget);
	
	RadialMenuWidget->SetVisibility(ESlateVisibility::Visible);

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
	
	RadialMenuWidget->SetVisibility(ESlateVisibility::Hidden);

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

void URadialMenuComponent::RadialMenuSlotRight(const FInputActionValue& Value)
{
	check(RadialMenuWidget);

	if (RadialMenuWidget->GetSelectedRadialMenuSlot())
	{
		Cast<UWeaponRadialMenuSlot>(RadialMenuWidget->GetSelectedRadialMenuSlot())->SwitchWeaponIndex(true);
	}
}

void URadialMenuComponent::RadialMenuSlotLeft(const FInputActionValue& Value)
{
	check(RadialMenuWidget);

	if (RadialMenuWidget->GetSelectedRadialMenuSlot())
	{
		Cast<UWeaponRadialMenuSlot>(RadialMenuWidget->GetSelectedRadialMenuSlot())->SwitchWeaponIndex(false);
	}
}

void URadialMenuComponent::SetupInput(UEnhancedInputComponent* EnhancedInputComponent)
{
	if (!IsValid(EnhancedInputComponent))
	{
		return;
	}

	if (IsValid(EnableRadialMenuInput))
	{
		EnhancedInputComponent->BindAction(EnableRadialMenuInput, ETriggerEvent::Started, this, &URadialMenuComponent::EnableRadialMenu);
		EnhancedInputComponent->BindAction(EnableRadialMenuInput, ETriggerEvent::Completed, this, &URadialMenuComponent::DisableRadialMenu);
	}

	if (IsValid(RadialMenuSlotRightInput))
	{
		EnhancedInputComponent->BindAction(RadialMenuSlotRightInput, ETriggerEvent::Started, this, &URadialMenuComponent::RadialMenuSlotRight);
	}

	if (IsValid(RadialMenuSlotLeftInput))
	{
		EnhancedInputComponent->BindAction(RadialMenuSlotLeftInput, ETriggerEvent::Started, this, &URadialMenuComponent::RadialMenuSlotLeft);
	}
}

void URadialMenuComponent::BeginPlay()
{
	Super::BeginPlay();

	const AXCityCharacterBase* CharacterBase = Cast<AXCityCharacterBase>(GetOwner());
	if (!IsValid(CharacterBase))
	{
		return;
	}

	UActorComponent* FoundComponent = CharacterBase->FindComponentByClass<UInventoryComponentBase>();
	InventoryComponentBase = Cast<UInventoryComponentBase>(FoundComponent);
	check(InventoryComponentBase);
	
	InventoryComponentBase->OnInventorySizeChanged.AddUniqueDynamic(this, &URadialMenuComponent::OnInventorySizeChanged);

	const auto Controller = Cast<APlayerController>(CharacterBase->GetOwner());
	const auto XCityHUD = Cast<AXCityHUD>(Controller->GetHUD());
	check(XCityHUD);
	RadialMenuWidget = XCityHUD->GetRadialMenuWidget();
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

	const UWeaponRadialMenuSlot* WeaponRadialMenuSlot = Cast<UWeaponRadialMenuSlot>(Slot);
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
	GetItemsByType(WeaponRadialMenuSlot->GetWeaponType(), Items);
	CharacterBase->ReInitializeItemObject();
	if (Items.Num() > 0)
	{
		if (Items.Find(WeaponRadialMenuSlot->GetSelectedWeaponIndex()))
		{
			FWeaponsDataStruct WeaponsDataStruct;
			Items[WeaponRadialMenuSlot->GetSelectedWeaponIndex()]->GetItemSettings<FWeaponsDataStruct>(Items[WeaponRadialMenuSlot->GetSelectedWeaponIndex()].GetObject(), WeaponsDataStruct);
			
			CharacterBase->SetSelectedInventoryItem(Items[WeaponRadialMenuSlot->GetSelectedWeaponIndex()]);
			InventoryComponentBase->SelectItem_Implementation(Items[WeaponRadialMenuSlot->GetSelectedWeaponIndex()]);
			CharacterBase->ReInitializeItemObject();
		}
	}
}