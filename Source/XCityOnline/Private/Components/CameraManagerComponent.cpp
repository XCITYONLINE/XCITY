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
	if (!CurrentCameraMode.IsValid() || !IsValid(SpringArmComponent)) return;

	const FVector CurrentOffset = SpringArmComponent->SocketOffset;
	const FVector TargetOffset = CurrentCameraMode->LocationSocketOffset;

	const float XInterp = FMath::FInterpConstantTo(CurrentOffset.X, TargetOffset.X, GetWorld()->GetDeltaSeconds(), CurrentCameraMode->LocationXInterpSpeed);
	const float YInterp = FMath::FInterpConstantTo(CurrentOffset.Y, TargetOffset.Y, GetWorld()->GetDeltaSeconds(), CurrentCameraMode->LocationYInterpSpeed);
	const float ZInterp = FMath::FInterpConstantTo(CurrentOffset.Z, TargetOffset.Z, GetWorld()->GetDeltaSeconds(), CurrentCameraMode->LocationZInterpSpeed);

	const FVector FinalOffset = FVector(XInterp, YInterp, ZInterp);

	SpringArmComponent->SocketOffset = FinalOffset;
}

void UCameraManagerComponent::SetCameraMode(const ECameraMode& CameraMode)
{
	const UCameraSystemSettings* CameraSystemSettings = GetDefault<UCameraSystemSettings>();

	CurrentCameraMode = *CameraSystemSettings->CameraModes.Find(CameraMode);
}