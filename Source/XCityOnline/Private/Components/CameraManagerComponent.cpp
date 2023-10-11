// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CameraManagerComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Data/CameraModeData.h"
#include "Camera/CameraComponent.h"
#include "Settings/CameraSystemSettings.h"

// Sets default values for this component's properties
UCameraManagerComponent::UCameraManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	CurrentCameraMode = nullptr;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
}

void UCameraManagerComponent::SetupAttachments(const AActor* ParentActor)
{
	if (!IsValid(ParentActor))
	{
		return;
	}

	SpringArmComponent->SetupAttachment(ParentActor->GetRootComponent());
	CameraComponent->SetupAttachment(SpringArmComponent, SpringArmComponent->SocketName);
}

void UCameraManagerComponent::UpdateCameraOffset()
{
	if (!CurrentCameraMode || !SpringArmComponent) return;

	const FVector CurrentOffset = SpringArmComponent->SocketOffset;
	const FVector TargetOffset = CurrentCameraMode->LocationSocketOffset;

	SpringArmComponent->SocketOffset = FMath::VInterpTo(CurrentOffset, TargetOffset, GetWorld()->GetDeltaSeconds(), LocationInterpSpeed);
}

void UCameraManagerComponent::SetCameraMode(const ECameraMode& CameraMode)
{
	const UCameraSystemSettings* CameraSystemSettings = GetDefault<UCameraSystemSettings>();

	CurrentCameraMode = *CameraSystemSettings->CameraModes.Find(CameraMode);
}