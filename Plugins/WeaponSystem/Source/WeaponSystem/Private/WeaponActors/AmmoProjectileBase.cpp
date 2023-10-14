// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponActors/AmmoProjectileBase.h"
#include "Kismet/GameplayStatics.h"

const float AAmmoProjectileBase::LifeSpanTime = 60.0f;

AAmmoProjectileBase::AAmmoProjectileBase()
{
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComp");
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("AmmoMesh");
	RootComponent = StaticMeshComponent;
	
	PrimaryActorTick.bCanEverTick = true;
	
	PreviousLocation = FVector::ZeroVector;
	InitialProjectileSettings = FProjectileSettings();
}

bool AAmmoProjectileBase::TryInitializeProjectile(const FProjectileSettings& InInitialProjectileSettings)
{
	if (InInitialProjectileSettings.IsValid())
	{
		InitialProjectileSettings = InInitialProjectileSettings;
	}

	const bool bIsInitialized = InitialProjectileSettings.IsValid() && IsValid(ProjectileMovementComponent);
	if (bIsInitialized)
	{
		ProjectileMovementComponent->InitialSpeed = InitialProjectileSettings.ProjectileInitialSpeed;
		ProjectileMovementComponent->MaxSpeed = InitialProjectileSettings.ProjectileMaxSpeed;

		SetLifeSpan(LifeSpanTime);
	}

	return bIsInitialized;
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
	const UWorld* World = GetWorld();
	APlayerController * PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	
	if (!IsValid(World) || !IsValid(PlayerController))
	{
		return;
	}
	
	FHitResult HitResult;
	const FVector& CurrentProjectileLocation = GetActorLocation();

	const bool WasBlocked = UKismetSystemLibrary::LineTraceSingle(
		this,
		CurrentProjectileLocation,
		PreviousLocation,
		ETraceTypeQuery { InitialProjectileSettings.CollisionChannel.GetValue() },
		true,
		{ GetOwner(), this },
		EDrawDebugTrace::None,
		HitResult,
		true
		);
	
	if (!WasBlocked || !HitResult.bBlockingHit)
	{
		return;
	}

	if (AActor* HitActor = HitResult.GetActor(); IsValid(HitActor))
	{
		UGameplayStatics::ApplyDamage(
			HitActor,
			InitialProjectileSettings.Damage,
			PlayerController,
			this,
			UDamageType::StaticClass());

		if (OnProjectileHit.IsBound())
		{
			OnProjectileHit.Broadcast(HitResult);
		}
		
		K2_HitNotify(HitResult);
		Destroy();
	}
}
