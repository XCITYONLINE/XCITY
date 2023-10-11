// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Contracts/InteractibleWeaponInterface.h"

#include "ShootComponentBase.generated.h"

UCLASS(ClassGroup = (Custom), Blueprintable, meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_API UShootComponentBase : public UActorComponent, public IInteractibleWeaponInterface
{
	GENERATED_BODY()

public:	

	UShootComponentBase();

	//IInteractibleWeaponInterface implements
	virtual void Internal_Initialize_Implementation(const FWeaponsDataStruct& InInitialWeaponStruct) override;
	virtual void OnFireStart_Implementation() override;
	virtual void OnFireStop_Implementation() override;
	virtual void OnReload_Implementation() override;
	virtual bool IsReloading_Implementation() override;
	virtual int GetAmmo_Implementation() override;
	virtual void SetAmmo_Implementation(const int& InNewAmmoValue) override;
	virtual void AddAmmo_Implementation(const int& InAmmoValue) override;
	//~
};
