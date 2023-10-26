// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "RadialMenuSlotInterface.generated.h"

UINTERFACE(MinimalAPI)
class URadialMenuSlotInterface : public UInterface
{
	GENERATED_BODY()
};

class CITYSAMPLE_API IRadialMenuSlotInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category = "Radial Menu Slot Interface")
	void BeginFocus();
	
	UFUNCTION(BlueprintNativeEvent, Category = "Radial Menu Slot Interface")
	void EndFocus();
	
	UFUNCTION(BlueprintNativeEvent, Category = "Radial Menu Slot Interface")
	void OnSelected();
	
	UFUNCTION(BlueprintNativeEvent, Category = "Radial Menu Slot Interface")
	void InitializeSlot(const int32& Index);

	UFUNCTION(BlueprintNativeEvent, Category = "Radial Menu Slot Interface")
	void RefreshSlot();
};
