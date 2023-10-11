// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataStructs/WeaponsDataStruct.h"
#include "UObject/Interface.h"

#include "InteractibleWeaponInterface.generated.h"

UINTERFACE(MinimalAPI)
class UInteractibleWeaponInterface : public UInterface
{
	GENERATED_BODY()
};

class WEAPONSYSTEM_API IInteractibleWeaponInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void OnFireStart();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void OnFireStop();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void OnReload();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	bool IsReloading();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void InitializeWeapon();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	int GetAmmo();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void SetAmmo(const int& InNewAmmoValue);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void AddAmmo(const int& InAmmoValue);
	
	UFUNCTION(BlueprintNativeEvent,  Category = "Internal")
	void Internal_Initialize(const FWeaponsDataStruct& InInitialWeaponStruct);
};
