// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RadialMenu/WeaponRadialMenuSlot.h"

#include "Components/Image.h"
#include "Interfaces/RadialMenuInterface.h"

void UWeaponRadialMenuSlot::InitializeSlot_Implementation(const int32& Index)
{
	Super::InitializeSlot_Implementation(Index);

	// SlotWeaponType = static_cast<EWeaponType>(Index);
	SetWeaponTypeByIndex();

	RefreshSlot_Implementation();
}

void UWeaponRadialMenuSlot::RefreshSlot_Implementation()
{
	Super::RefreshSlot_Implementation();

	if (GetOwningPlayerPawn()->Implements<URadialMenuInterface>())
	{
		IRadialMenuInterface* RadialMenuInterface = Cast<IRadialMenuInterface>(GetOwningPlayerPawn());
		
		TMap<int32, TScriptInterface<IInteractibleItemInterface>> Items;
		RadialMenuInterface->GetItemsByType(SlotWeaponType, Items);

		if (Items.Num() > SelectedWeaponIndex)
		{
			FWeaponsDataStruct WeaponsDataStruct;
			if (Items.Find(SelectedWeaponIndex))
			{
				if (Items[SelectedWeaponIndex].GetInterface())
				{
					Items[SelectedWeaponIndex]->GetItemSettings<FWeaponsDataStruct>(Items[SelectedWeaponIndex].GetObject(), WeaponsDataStruct);
				}
			}

			if (IsValid(WeaponsDataStruct.WeaponIcon))
			{
				WeaponIconImage->SetBrushFromTexture(WeaponsDataStruct.WeaponIcon.Get()); 
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
