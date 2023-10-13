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
	void OnUseMainFire();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void OnUseAlternativeFire();

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
	int32 GetAmmo();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	int32 GetAmmoPerStore();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void SetAmmo(const int32 InNewAmmoValue);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void AddAmmo(const int32 InAmmoValue);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void ToggleWeaponMode();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	FTransform GetFireSocketTransform(const FName& InSocketName);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void SetAimMode(const bool bAim);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	bool IsAimMode();
	
	UFUNCTION(BlueprintNativeEvent,  Category = "Internal")
	void Internal_Initialize(const FWeaponsDataStruct& InInitialWeaponStruct, const bool bAlternative);
};
