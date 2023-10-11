// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponActors/AmmoProjectileBase.h"

#include "Kismet/KismetSystemLibrary.h"

AAmmoProjectileBase::AAmmoProjectileBase()
{
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComp");
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("AmmoMesh");
	RootComponent = StaticMeshComponent;
	
	PrimaryActorTick.bCanEverTick = true;
	PreviousLocation = FVector::ZeroVector;
}

void AAmmoProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	K2_StartFly();

	PreviousLocation = GetActorLocation();
}

void AAmmoProjectileBase::TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaTime, TickType, ThisTickFunction);
	CheckHitProcess();
}

void AAmmoProjectileBase::CheckHitProcess()
{
	const FVector& CurrentProjectileLocation = GetActorLocation();
	FHitResult Hit;
	
	UKismetSystemLibrary::LineTraceSingle(
		this,
		CurrentProjectileLocation,
		PreviousLocation,
		TraceTypeQuery_MAX,
		true,
		{},
		EDrawDebugTrace::None,
		Hit,
		true
		);
	
	if (Hit.bBlockingHit)
	{
		//ToDo: Hit processing here...
	}
	
	if (OnProjectileHit.IsBound())
	{
		OnProjectileHit.Broadcast(Hit);
		K2_HitNotify(Hit);
	}
}
