// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CameraManagerComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Data/CameraModeData.h"

// Sets default values for this component's properties
UCameraManagerComponent::UCameraManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	CurrentCameraMode = nullptr;
	CameraModes.Empty();
}

void UCameraManagerComponent::UpdateCameraOffset(USpringArmComponent* SpringArm)
{
	if (!CurrentCameraMode || !SpringArm) return;

	const FVector CurrentOffset = SpringArm->SocketOffset;
	const FVector TargetOffset = CurrentCameraMode->LocationSocketOffset;

	SpringArm->SocketOffset = FMath::VInterpTo(CurrentOffset, TargetOffset, GetWorld()->GetDeltaSeconds(), CurrentCameraMode->LocationInterpSpeed);
}

void UCameraManagerComponent::SetCameraMode(const ECameraMode& CameraMode)
{
	CurrentCameraMode = *CameraModes.Find(CameraMode);
}