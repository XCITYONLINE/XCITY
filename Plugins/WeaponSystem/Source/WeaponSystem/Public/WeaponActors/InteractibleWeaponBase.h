// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Components/BoxComponent.h"
#include "Contracts/InteractibleItemInterface.h"
#include "Contracts/InteractibleWeaponInterface.h"
#include "GameFramework/Actor.h"
#include "DataStructs/WeaponsDataStruct.h"

#include "InteractibleWeaponBase.generated.h"

class UXCityWeaponFXComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAlternativeFireChanged, bool, Value);

class UNiagaraSystem;
class UNiagaraComponent;

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
	virtual void OnTake_Implementation(AActor* OwnerActor) override;
	virtual void OnUnselect_Implementation() override;
	virtual void OnDrop_Implementation() override;
	virtual void OnItemSleep_Implementation(UPrimitiveComponent* SleepingComponent, FName BoneName) override;
	virtual bool Internal_GetItemSettings(UObject* ContextObject, UStruct* InStruct, void* OutData) override;
	//~
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName WeaponID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent> BoxCollision;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> WeaponSkeletalMeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	FName MuzzleSocketName = "MuzzleSocket";

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
	float TraceMaxDistance = 35000.0f;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnAlternativeFireChanged OnAlternativeFireChanged;

public:

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MainFire;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> AlternativeFire;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> Reload;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> AimMode;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<class UInputMappingContext> MappingContext;

	UPROPERTY(BlueprintReadOnly, Category = "Initial Data")
	FWeaponsDataStruct InitialWeaponStruct;

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

	//UPROPERTY(VisibleAnywhere, Category = "Weapon")
	//FName MuzzleSocketName = "MuzzleSocket";

	UPROPERTY(VisibleAnywhere, Category = "VFX")
	UXCityWeaponFXComponent* WeaponFXComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	UNiagaraSystem* MuzzleFX;

	virtual void BeginPlay() override;

	void MakeShot();

	UNiagaraComponent* SpawnMuzzleFX();

private:

	UPROPERTY()
	UNiagaraComponent* MuzzleFXComponent;
	
	UFUNCTION()
	void OnLoadComplete();
	
	void CreateShootComponent(
		const FWeaponsDataStruct& InInitialWeaponStruct,
		TObjectPtr<UShootComponentBase>& OutShootComponent,
		const bool bAlternative);

	APlayerController* GetPlayerController() const;
	bool GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const;
	FVector GetMuzzleWorldLocation() const;
	bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;
	void MakeHit(FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd);

	void AddMappingContext() const;
	void RemoveMappingContext();
	void BindInputActions();
	void InitMuzzleFX();
	void SetMuzzleFXVisibility(bool Visible);
	
	TObjectPtr<UShootComponentBase> MainShootComponentObject;
	TObjectPtr<UShootComponentBase> AlternativeShootComponentObject;
	TObjectPtr<UShootComponentBase> SelectedShootComponent;
};
