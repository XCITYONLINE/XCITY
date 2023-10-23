// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/XCityAICharacter.h"
#include "Components/CapsuleComponent.h"
#include "WheeledVehiclePawn.h"

AXCityAICharacter::AXCityAICharacter()
{
	SphereCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("ObstacleCillision"));
	SphereCollisionComponent->SetupAttachment(RootComponent);
	
	PrimaryActorTick.bCanEverTick = true;
	
	CheckObstacleRadius = 200.0f;
	CollisionChannel = ECC_Vehicle;

	SphereCollisionComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &AXCityAICharacter::ObstacleNotify);
	SphereCollisionComponent->SetCollisionResponseToChannel(CollisionChannel, ECR_Block);
	SphereCollisionComponent->SetSphereRadius(CheckObstacleRadius);
}

void AXCityAICharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AXCityAICharacter::ObstacleNotify(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (Cast<AWheeledVehiclePawn>(OtherActor))
	{
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GetMesh()->SetCollisionObjectType(ECC_PhysicsBody);
		GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		GetMesh()->SetAllBodiesBelowSimulatePhysics(TEXT("Pelvis"), true, true);
	}
}
