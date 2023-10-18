// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/XCityAICharacter.h"

AXCityAICharacter::AXCityAICharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AXCityAICharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AXCityAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AXCityAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
