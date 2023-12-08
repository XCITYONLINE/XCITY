// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponActors/AmmoProjectileBase.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "XCityWeaponFXComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"

const float AAmmoProjectileBase::LifeSpanTime = 60.0f;

AAmmoProjectileBase::AAmmoProjectileBase()
{
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComp");
	
	CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	CollisionComponent->InitSphereRadius(5.0f);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	CollisionComponent->bReturnMaterialOnMove = true;
	SetRootComponent(CollisionComponent);

	PrimaryActorTick.bCanEverTick = true;
	
	PreviousLocation = FVector::ZeroVector;
	InitialProjectileSettings = FProjectileSettings();

	WeaponFXComponent = CreateDefaultSubobject<UXCityWeaponFXComponent>("WeaponFXComponent");
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

	check(ProjectileMovementComponent);
	check(WeaponFXComponent);

	//ProjectileMovementComponent->Velocity = ShotDirection * ProjectileMovementComponent->InitialSpeed;

	K2_StartFly();

	PreviousLocation = GetActorLocation();

	CollisionComponent->OnComponentHit.AddDynamic(this, &AAmmoProjectileBase::OnBulletHit);
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

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(GetOwner());
	CollisionParams.bReturnPhysicalMaterial = true;

	FHitResult HitResult;
	const FVector& CurrentProjectileLocation = GetActorLocation();

	//FVector ViewLocation, TraceStart, TraceEnd;
	//FRotator ViewRotation;

	//PlayerController->GetPlayerViewPoint(ViewLocation, ViewRotation);

	//TraceStart = ViewLocation;
	//const FVector ShootDirection = ViewRotation.Vector();
	//TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;

	//ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;

	const bool WasBlocked = UKismetSystemLibrary::LineTraceSingle(
		this,
		CurrentProjectileLocation,
		PreviousLocation,
		ETraceTypeQuery { InitialProjectileSettings.CollisionChannel.GetValue() },
		true,
		{ GetOwner(), this },
		EDrawDebugTrace::ForDuration,
		HitResult,
		true
		);
	
	if (!WasBlocked || !HitResult.bBlockingHit)
	{
		return;
	}
}

void AAmmoProjectileBase::OnBulletHit(
	UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!GetWorld()) return;

	ProjectileMovementComponent->StopMovementImmediately();

	FVector TraceFXEnd = Hit.Location;
	UGameplayStatics::ApplyDamage(                  //
		OtherActor,                                 //
		InitialProjectileSettings.Damage,           //
		GetPlayerController(),                      //
		this,
		UDamageType::StaticClass());                //
		
	TraceFXEnd = Hit.ImpactPoint;

	K2_HitNotify(Hit);
	SpawnTraceFX(PreviousLocation, TraceFXEnd);
	WeaponFXComponent->PlayImpactFX(Hit);
	Destroy();
}

AController* AAmmoProjectileBase::GetPlayerController() const
{
	const auto Player = Cast<ACharacter>(GetOwner());
	if (!Player) return nullptr;

	return Player->GetController<APlayerController>();
}

bool AAmmoProjectileBase::GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const
{
	const auto Controller = GetPlayerController();
	if (!Controller) return false;

	Controller->GetPlayerViewPoint(ViewLocation, ViewRotation);
	return true;
}

bool AAmmoProjectileBase::GetTraceData(FVector& TraceStart, FVector& TraceEnd) const
{
	FVector ViewLocation;
	FRotator ViewRotation;
	if (!GetPlayerViewPoint(ViewLocation, ViewRotation)) return false;

	TraceStart = ViewLocation;
	const FVector ShootDirection = ViewRotation.Vector();
	TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
	return true;
}

void AAmmoProjectileBase::SpawnTraceFX(const FVector& TraceStart, const FVector& TraceEnd)
{
	const auto TraceFXComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), TraceFX, PreviousLocation);
	if (TraceFXComponent)
	{
		TraceFXComponent->SetNiagaraVariableVec3(TraceTargetName, TraceEnd);
	}
}