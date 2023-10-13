// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Contracts/InteractibleWeaponInterface.h"
#include "DataStructs/WeaponsDataStruct.h"

#include "ShootComponentBase.generated.h"

UCLASS(ClassGroup = (Custom), Blueprintable, meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_API UShootComponentBase : public UActorComponent, public IInteractibleWeaponInterface
{
	GENERATED_BODY()

public:	

	UShootComponentBase();

	//IInteractibleWeaponInterface implements
	virtual void Internal_Initialize_Implementation(
		const FWeaponsDataStruct& InInitialWeaponStruct, const bool bAlternative) override;
	virtual void OnFireStart_Implementation() override;
	virtual void OnFireStop_Implementation() override;
	virtual void OnReload_Implementation() override;
	virtual bool IsReloading_Implementation() override;
	virtual int32 GetAmmo_Implementation() override;
	virtual int32 GetAmmoPerStore_Implementation() override;
	virtual void SetAmmo_Implementation(const int32 InNewAmmoValue) override;
	virtual void AddAmmo_Implementation(const int32 InAmmoValue) override;
	virtual void ToggleWeaponMode_Implementation() override;
	virtual void SetAimMode_Implementation(const bool bAim) override;
	virtual bool IsAimMode_Implementation() override;
	//~

	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnFire();
	
	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnFireMiss();

	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnReload();

	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnAimModeChanged(const bool bIsAimMode);


private:

	TSubclassOf<AAmmoProjectileBase> AmmoProjectileClass;

	bool bIsFireProcessActive;
	bool bIsReloadProcessActive;
	bool bIsFireProcessHold;
	bool bIsAim;
	
	int32 CurrentAmmo;
	int32 CurrentAmmoPerStore;
	FShootSettingsDesc InitialShootSettings;
	int32 CurrentShootModeIndex;
	int32 CurrentSemiShootIndex;

	FTimerHandle OnAfterFireTimerHandle;
	FTimerHandle OnReloadTimerHandle;

private:

	inline bool CheckPossibilityShot() const;
	void OnAfterFireProcessStart();
	
	void ShootDataOperations();
	void ReloadedDataOperations();

	void FireProcessByShootMode();
};
