// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RadialMenuTypes.h"
#include "Blueprint/UserWidget.h"

#include "RadialMenuWidget.generated.h"

class URadialMenuSlot;

UCLASS()
class CITYSAMPLE_API URadialMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	void RefreshRadialMenu();

	FORCEINLINE URadialMenuSlot* GetSelectedRadialMenuSlot() const
	{
		return CurrentSelectedSlot;
	}
	
protected:
	
	URadialMenuWidget(const FObjectInitializer& ObjectInitializer);

	// UUserWidget start
	virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeConstruct() override;
	// ~UUserWidget end

	/** Canvas to store widget visual */
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UCanvasPanel> RadialMenuCanvas;

	/** Slot with this class will be spawned at runtime */
	UPROPERTY(EditAnywhere, Category = "Radial Menu")
	TSubclassOf<URadialMenuSlot> RadialMenuSlotClass;

	/** How many slots we have */
	UPROPERTY(EditAnywhere, Category = "Radial Menu")
	int32 RadialMenuParts;

	/** Relative slot distance from center */
	UPROPERTY(EditAnywhere, Category = "Radial Menu")
	float SlotDistanceFromCenter;
	
private:
	/** Inits radial menu, spawn slots and set their position correct on the screen */
	void InitRadialMenu();

	/**
	 * @param Angle slot's angle
	 * @return slot from storage with this angle setting
	 */
	const FRadialMenuSlotInfo& GetSlotByAngle(const float& Angle) const;

	/**
	 * Handles logic to init new slot logic in radial menu
	 * calls begin focus method and setup's this slot as current
	 * in this widget class
	 * @param NewSlot in new slot
	 */
	void OnSelectedNewSlot(URadialMenuSlot* NewSlot);

	void SetupSlotVisual(const FRadialMenuSlotInfo& SlotInfo) const;
	
	UPROPERTY()
	TArray<FRadialMenuSlotInfo> RadialMenuSlotInfos;

	UPROPERTY()
	TObjectPtr<URadialMenuSlot> CurrentSelectedSlot;

	float OverallRadialMenuAngle;
};
