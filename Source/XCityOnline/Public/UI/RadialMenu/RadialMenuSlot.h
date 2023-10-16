// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/RadialMenuSlotInterface.h"
#include "RadialMenuSlot.generated.h"

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

protected:
	// Just test variable, to check, is on focus work correctly
	UPROPERTY(meta = (BindWidget))
	class UImage* SlotImage;
	
private:
	
};
