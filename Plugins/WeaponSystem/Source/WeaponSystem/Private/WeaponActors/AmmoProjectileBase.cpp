// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponActors/AmmoProjectileBase.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "XCityWeaponFXComponent.h"

const float AAmmoProjectileBase::LifeSpanTime = 60.0f;

AAmmoProjectileBase::AAmmoProjectileBase()
{
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComp");
	//StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("AmmoMesh");
	//RootComponent = StaticMeshComponent;
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

	check(WeaponFXComponent);

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

	//if (AActor* HitActor = HitResult.GetActor(); IsValid(HitActor))
	//{
	//	UGameplayStatics::ApplyDamage(
	//		HitActor,
	//		InitialProjectileSettings.Damage,
	//		PlayerController,
	//		this,
	//		UDamageType::StaticClass());

		//if (OnProjectileHit.IsBound())
		//{
		//	OnProjectileHit.Broadcast(HitResult);
		//}
		
		//K2_HitNotify(HitResult);
		//WeaponFXComponent->PlayImpactFX(HitResult);
		//Destroy();
	//}
}

void AAmmoProjectileBase::OnBulletHit(
	UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!GetWorld()) return;

	ProjectileMovementComponent->StopMovementImmediately();

	UGameplayStatics::ApplyDamage(                 //
		OtherActor,                                 //
		InitialProjectileSettings.Damage,           //
		GetController(),                            //
		this,
		UDamageType::StaticClass());                 //
		

	K2_HitNotify(Hit);
	WeaponFXComponent->PlayImpactFX(Hit);
	Destroy();
}

AController* AAmmoProjectileBase::GetController() const
{
	const auto Pawn = Cast<APawn>(GetOwner());
	return Pawn ? Pawn->GetController() : nullptr;
}