// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RadialMenuTypes.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/RadialMenuSlotInterface.h"
#include "RadialMenuSlot.generated.h"

class UImage;

/**
 * 
 */
UCLASS()
class XCITYONLINE_API URadialMenuSlot : public UUserWidget, public IRadialMenuSlotInterface
{
	GENERATED_BODY()

public:
	// IRadialMenuSlotInterface start
	virtual void OnSelected_Implementation() override;
	virtual void BeginFocus_Implementation() override;
	virtual void EndFocus_Implementation() override;
	virtual void InitializeSlot_Implementation() override;
	// ~IRadialMenuSlotInterface end

	FORCEINLINE UImage* GetSlotImage() const { return SlotImage; }
	
protected:
	URadialMenuSlot(const FObjectInitializer& ObjectInitializer);
	
	// Just test variable, to check, is on focus work correctly
	UPROPERTY(meta = (BindWidget))
	UImage* SlotImage;

	UPROPERTY(EditAnywhere, Category = "Radial Menu Slot")
	FRadialMenuSlotData RadialMenuSlotData;
};
