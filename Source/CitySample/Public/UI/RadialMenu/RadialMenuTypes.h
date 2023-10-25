// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RadialMenuTypes.generated.h"

class UTexture2D;

/**
 * Stores all info that we need from slot.
 */
USTRUCT()
struct CITYSAMPLE_API FRadialMenuSlotInfo
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

USTRUCT(Blueprintable, BlueprintType)
struct CITYSAMPLE_API FRadialMenuSlotData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Radial Menu Slot Data")
	TObjectPtr<UTexture2D> IdleImage;

	UPROPERTY(EditAnywhere, Category = "Radial Menu Slot Data")
	TObjectPtr<UTexture2D> HoveredImage;

	FRadialMenuSlotData() {}
};