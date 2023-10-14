// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataStructs/WeaponsDataStruct.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "AmmoProjectileBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnProjectileHit, const FHitResult&, Value);

UCLASS()
class WEAPONSYSTEM_API AAmmoProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	

	AAmmoProjectileBase();
	
	virtual void BeginPlay() override;
	virtual void TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;

	virtual bool TryInitializeProjectile(const FProjectileSettings& InInitialProjectileSettings);

public:

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnProjectileHit OnProjectileHit;

	UFUNCTION(BlueprintImplementableEvent)
	void K2_StartFly();

	UFUNCTION(BlueprintImplementableEvent)
	void K2_HitNotify(const FHitResult& OutImpactResult);

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	UStaticMeshComponent* StaticMeshComponent;

private:

	void CheckHitProcess();

private:
	
	FVector PreviousLocation;
	FProjectileSettings InitialProjectileSettings;

	static const float LifeSpanTime;
};
