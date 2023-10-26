// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RadialMenuSlot.h"
#include "DataStructs/WeaponsDataStruct.h"
#include "WeaponRadialMenuSlot.generated.h"

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API UWeaponRadialMenuSlot : public URadialMenuSlot
{
	GENERATED_BODY()

public:
	FORCEINLINE EWeaponType GetWeaponType() const
	{
		return SlotWeaponType;
	}

	FORCEINLINE int32 GetSelectedWeaponIndex() const
	{
		return SelectedWeaponIndex;
	}

	void SwitchWeaponIndex(const bool& bRight);
	
protected:
	// IRadialMenuSlotInterface start
	virtual void InitializeSlot_Implementation(const int32& Index) override;
	virtual void RefreshSlot_Implementation() override;
	// ~IRadialMenuSlotInterface end

	UPROPERTY(BlueprintReadOnly, Category = "Weapon Radial Menu Slot")
	TEnumAsByte<EWeaponType> SlotWeaponType;

	UPROPERTY(BlueprintReadOnly, Category = "Weapon Radial Menu Slot")
	int32 SelectedWeaponIndex;
	
	UPROPERTY(meta = (BindWidget))
	UImage* WeaponIconImage;

private:
	void SetWeaponTypeByIndex();
	
};