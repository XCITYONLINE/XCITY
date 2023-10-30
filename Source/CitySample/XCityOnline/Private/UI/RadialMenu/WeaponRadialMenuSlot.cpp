// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/UI/RadialMenu/WeaponRadialMenuSlot.h"
#include "Components/Image.h"
#include "XCityOnline/Public/Components/RadialMenuComponent.h"
#include "XCityOnline/Public/Interfaces/RadialMenuInterface.h"

void UWeaponRadialMenuSlot::SwitchWeaponIndex(const bool& bRight)
{
	
	
	SelectedWeaponIndex = bRight ? SelectedWeaponIndex + 1 : SelectedWeaponIndex - 1;
	RefreshSlot_Implementation();
}

void UWeaponRadialMenuSlot::InitializeSlot_Implementation(const int32& Index)
{
	Super::InitializeSlot_Implementation(Index);

	// SlotWeaponType = static_cast<EWeaponType>(Index);
	SetWeaponTypeByIndex();

	WeaponIconImage->SetVisibility(ESlateVisibility::Hidden);
	RefreshSlot_Implementation();
}

void UWeaponRadialMenuSlot::RefreshSlot_Implementation()
{
	Super::RefreshSlot_Implementation();

	if (GetRadialMenuComponent()->Implements<URadialMenuInterface>())
	{
		IRadialMenuInterface* RadialMenuInterface = Cast<IRadialMenuInterface>(GetRadialMenuComponent());
		
		TMap<int32, TScriptInterface<IInteractibleItemInterface>> Items;
		RadialMenuInterface->GetItemsByType(SlotWeaponType, Items);
		if (SelectedWeaponIndex == Items.Num())
		{
			SelectedWeaponIndex = 0;
		}

		else if (SelectedWeaponIndex < 0)
		{
			SelectedWeaponIndex = Items.Num() - 1;
		}
		
		if (Items.Num() > SelectedWeaponIndex)
		{
			FWeaponsDataStruct WeaponsDataStruct;
			if (const TScriptInterface<IInteractibleItemInterface>* Interface = Items.Find(SelectedWeaponIndex))
			{
				Interface->GetInterface()->GetItemSettings<FWeaponsDataStruct>(Interface->GetObject(), WeaponsDataStruct);
			}

			if (IsValid(WeaponsDataStruct.WeaponIcon))
			{
				WeaponIconImage->SetVisibility(ESlateVisibility::Visible);
				WeaponIconImage->SetBrushFromTexture(WeaponsDataStruct.WeaponIcon.Get()); 
			}

			else
			{
				WeaponIconImage->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}
}

void UWeaponRadialMenuSlot::SetWeaponTypeByIndex()
{
	switch (SlotIndex)
	{
		case 0:
			SlotWeaponType = EWeaponType::EWT_Rifle;
			break;
		case 1:
			SlotWeaponType = EWeaponType::EWT_Pistol;
			break;
		case 2:
			SlotWeaponType = EWeaponType::EWT_Shotgun;
			break;
		case 3:
			SlotWeaponType = EWeaponType::EWT_Snipe;
			break;
		case 4:
			SlotWeaponType = EWeaponType::EWT_CombatRifle;
			break;
		case 5:
			SlotWeaponType = EWeaponType::EWT_GrenadeLauncher;
			break;
		case 6:
			SlotWeaponType = EWeaponType::EWT_ThrowItem;
			break;
	}
}
