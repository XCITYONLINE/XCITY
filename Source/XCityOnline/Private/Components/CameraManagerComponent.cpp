// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/CameraManagerComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Data/CameraModeData.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Settings/CameraSystemSettings.h"

UCameraManagerComponent::UCameraManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	CurrentCameraMode = nullptr;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
}

void UCameraManagerComponent::SetupAttachments(const AActor* ParentActor) const
{
	if (!IsValid(ParentActor))
	{
		return;
	}

	SpringArmComponent->SetupAttachment(ParentActor->GetRootComponent());
	CameraComponent->SetupAttachment(SpringArmComponent, SpringArmComponent->SocketName);
}

void UCameraManagerComponent::UpdateCameraOffset() const
{
	if (!CurrentCameraMode.IsValid() || !IsValid(SpringArmComponent))
	{
		return;
	}

	const FVector CurrentOffset = SpringArmComponent->SocketOffset;
	const FVector TargetOffset = CurrentCameraMode->LocationSocketOffset;

	const FVector TargetVector = UKismetMathLibrary::VInterpTo_Constant(
		CurrentOffset,
		TargetOffset,
		GetWorld()->GetDeltaSeconds(),
		CurrentCameraMode->InterpSpeed
		);

	
	SpringArmComponent->SocketOffset = TargetVector;
}

void UCameraManagerComponent::SetCameraMode(const ECameraMode& CameraMode)
{
	CurrentCameraMode =
		*UCameraSystemSettings::GetCameraSystemSettings()->CameraModes.Find(CameraMode);
}