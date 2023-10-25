// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Contracts/InteractibleItemInterface.h"
#include "WeaponSystem/Public/DataStructs/WeaponsDataStruct.h"
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RadialMenuInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class URadialMenuInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CITYSAMPLE_API IRadialMenuInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void GetItemsByType(const EWeaponType& InWeaponType, TMap<int32, TScriptInterface<IInteractibleItemInterface>>& OutItemsByType);
};
