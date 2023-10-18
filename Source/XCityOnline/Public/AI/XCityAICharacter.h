// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
