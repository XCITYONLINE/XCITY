// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataStructs/WeaponsDataStruct.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "AmmoProjectileBase.generated.h"

class USphereComponent;
class UXCityWeaponFXComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnProjectileHit, const FHitResult&, Value);

class UNiagaraSystem;

UCLASS()
class WEAPONSYSTEM_API AAmmoProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	

	AAmmoProjectileBase();
	
	virtual void BeginPlay() override;
	virtual void TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;

	virtual bool TryInitializeProjectile(const FProjectileSettings& InInitialProjectileSettings);

	void SetShotDirection(const FVector Direction) { ShotDirection = Direction; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "VFX")
	UXCityWeaponFXComponent* WeaponFXComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	UNiagaraSystem* TraceFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	FString TraceTargetName = "TraceTarget";

public:

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnProjectileHit OnProjectileHit;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
	float TraceMaxDistance = 35000.0f;

	UFUNCTION(BlueprintImplementableEvent)
	void K2_StartFly();

	UFUNCTION(BlueprintImplementableEvent)
	void K2_HitNotify(const FHitResult& OutImpactResult);

	bool GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const;
	bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess), Category = "Projectile")
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere, Category = "Projectile")
	USphereComponent* CollisionComponent;

private:

	void CheckHitProcess();
	void SpawnTraceFX(const FVector& TraceStart, const FVector& TraceEnd);

private:
	FVector PreviousLocation;
	FProjectileSettings InitialProjectileSettings;
	FVector ShotDirection;

	static const float LifeSpanTime;

	UFUNCTION()
	void OnBulletHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
		const FHitResult& Hit);

	AController* GetPlayerController() const;
};
