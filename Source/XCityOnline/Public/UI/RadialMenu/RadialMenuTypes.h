// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RadialMenuTypes.generated.h"

/**
 * Stores all info that we need from slot.
 */
USTRUCT()
struct XCITYONLINE_API FRadialMenuSlotInfo
{
	GENERATED_BODY();
	
	UPROPERTY()
	FVector2D AngleRange;

	UPROPERTY()
	TObjectPtr<class URadialMenuSlot> SlotPtr;

	FRadialMenuSlotInfo() {}
	FRadialMenuSlotInfo(const FVector2D& InAngleRange, URadialMenuSlot* InSlot)
	{
		this->AngleRange = InAngleRange;
		this->SlotPtr = InSlot;
	}
};
