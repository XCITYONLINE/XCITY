// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "RadialMenuTypes.generated.h"

class UTexture2D;

USTRUCT()
struct CITYSAMPLE_API FRadialMenuSlotInfo
{
	GENERATED_BODY();
	
	UPROPERTY()
	FVector2D AngleRange = FVector2D();

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

public:
	
	UPROPERTY(EditAnywhere, Category = "Radial Menu Slot Data")
	TObjectPtr<UTexture2D> IdleImage;

	UPROPERTY(EditAnywhere, Category = "Radial Menu Slot Data")
	TObjectPtr<UTexture2D> HoveredImage;

public:
	
	FRadialMenuSlotData()
	{
		
	}
};
