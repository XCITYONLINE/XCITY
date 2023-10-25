// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RadialMenuTypes.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/RadialMenuSlotInterface.h"
#include "RadialMenuSlot.generated.h"

class UImage;
class URadialMenuComponent;

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
	virtual void InitializeSlot_Implementation(const int32& Index) override;
	virtual void RefreshSlot_Implementation() override;
	// ~IRadialMenuSlotInterface end

	FORCEINLINE UImage* GetSlotImage() const { return SlotImage; }
	FORCEINLINE class UVerticalBox* GetSlotVerticalBox() const { return SlotVerticalBox; }
	FORCEINLINE URadialMenuComponent* GetRadialMenuComponent() const { return RadialMenuComponent; }
	
protected:
	virtual void NativeConstruct() override;
	
	URadialMenuSlot(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(meta = (BindWidget))
	UImage* SlotImage;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	UVerticalBox* SlotVerticalBox;

	UPROPERTY()
	URadialMenuComponent* RadialMenuComponent;

	UPROPERTY()
	int32 SlotIndex;
	
	UPROPERTY(EditAnywhere, Category = "Radial Menu Slot")
	FRadialMenuSlotData RadialMenuSlotData;
};
