// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"

#include "XCityAICharacter.generated.h"

UCLASS()
class XCITYONLINE_API AXCityAICharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AXCityAICharacter();

protected:

	virtual void BeginPlay() override;

public:	

	UFUNCTION()
	void ObstacleNotify(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult & SweepResult);
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* SphereCollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CheckObstacleRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<ECollisionChannel> CollisionChannel;
};
