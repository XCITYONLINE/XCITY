// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Contracts/InteractibleItemInterface.h"
#include "Contracts/InteractibleWeaponInterface.h"
#include "GameFramework/Actor.h"
#include "DataStructs/WeaponsDataStruct.h"

#include "InteractibleWeaponBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAlternativeFireChanged, bool, Value);

UCLASS()
class WEAPONSYSTEM_API AInteractibleWeaponBase : public AActor,
public IInteractibleWeaponInterface,
public IInteractibleItemInterface
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
	virtual int32 GetAmmo_Implementation() override;
	virtual void SetAmmo_Implementation(const int32 InNewAmmoValue) override;
	virtual void AddAmmo_Implementation(const int32 InAmmoValue) override;
	virtual FTransform GetFireSocketTransform_Implementation(const FName& InSocketName) override;
	virtual int32 GetAmmoPerStore_Implementation() override;
	virtual void ToggleWeaponMode_Implementation() override;
	virtual void SetAimMode_Implementation(const bool bAim) override;
	virtual bool IsAimMode_Implementation() override;
	virtual void OnUseMainFire_Implementation() override;
	virtual void OnUseAlternativeFire_Implementation() override;
	virtual void Internal_Initialize_Implementation(
		const FWeaponsDataStruct& InInitialWeaponStruct, const bool bAlternative) override;
	//~

	//IInteractibleItemInterface implements
	virtual void OnStartHover_Implementation() override;
	virtual void OnStopHover_Implementation() override;
	virtual void OnStartMainInteract_Implementation() override;
	virtual void OnStopMainInteract_Implementation() override;
	virtual void OnStartAlternativeInteract_Implementation() override;
	virtual void OnStopAlternativeInteract_Implementation() override;
	virtual void OnTake_Implementation() override;
	virtual void OnUnselect_Implementation() override;
	virtual void OnDrop_Implementation() override;
	//~
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName WeaponID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent> BoxCollision;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> WeaponSkeletalMeshComponent;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnAlternativeFireChanged OnAlternativeFireChanged;

public:

	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnFire();

	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnFireMiss();
	
	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnReload();

	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnAimModeChanged(const bool bIsAim);
	
protected:

	virtual void BeginPlay() override;

private:
	
	UFUNCTION()
	void OnLoadComplete();

	void CreateShootComponent(
		const FWeaponsDataStruct& InInitialWeaponStruct,
		TObjectPtr<UShootComponentBase>& OutShootComponent,
		const bool bAlternative);
	
	TObjectPtr<UShootComponentBase> MainShootComponentObject;
	TObjectPtr<UShootComponentBase> AlternativeShootComponentObject;

	TObjectPtr<UShootComponentBase> SelectedShootComponent;

	
};
