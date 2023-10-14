// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RadialMenuSlotInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class URadialMenuSlotInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 Radial menu slot Interface
 */
class XCITYONLINE_API IRadialMenuSlotInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/**
	 * Calls when player hovered this slot
	 */
	virtual void BeginFocus();

	/**
	 * Calls when player unhovered this slot
	 */
	virtual void EndFocus();

	/**
	 * Calls when player confirmed this slot
	 */
	virtual void OnSelected();

	/**
	 * Calls when slot is created / or was setup in the player UI
	 */
	virtual void InitializeSlot();
};
