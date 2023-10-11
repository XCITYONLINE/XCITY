// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Contracts/InteractibleWeaponInterface.h"
#include "GameFramework/Actor.h"

#include "InteractibleWeaponBase.generated.h"

UCLASS()
class WEAPONSYSTEM_API AInteractibleWeaponBase : public AActor, public IInteractibleWeaponInterface
{
	GENERATED_BODY()
	
public:	

	AInteractibleWeaponBase();
	
	//IInteractibleWeaponInterface implements
	virtual void OnFireStart_Implementation() override;
	virtual void OnFireStop_Implementation() override;
	virtual void OnReload_Implementation() override;
	virtual bool IsReloading_Implementation() override;
	virtual void InitializeWeapon_Implementation() override;
	virtual int GetAmmo_Implementation() override;
	virtual void SetAmmo_Implementation(const int& InNewAmmoValue) override;
	virtual void AddAmmo_Implementation(const int& InAmmoValue) override;

	virtual void Internal_Initialize_Implementation(const FWeaponsDataStruct& InInitialWeaponStruct) override;
	//~

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName WeaponID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* WeaponStaticMeshComponent;
	
protected:

	virtual void BeginPlay() override;

private:
	
	UFUNCTION()
	void OnLoadComplete();

	TObjectPtr<UShootComponentBase> ShootComponentObject;
};
