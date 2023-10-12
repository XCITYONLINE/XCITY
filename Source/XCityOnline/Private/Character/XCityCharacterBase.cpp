// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/XCityCharacterBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CameraManagerComponent.h"

AXCityCharacterBase::AXCityCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraManagerComponent = CreateDefaultSubobject<UCameraManagerComponent>(TEXT("CameraManager"));
	CameraManagerComponent->SetupAttachments(this);
}

void AXCityCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	InitCameraManager();

	if (const APlayerController* PlayerController =
		Cast<APlayerController>(GetOwner()); IsValid(PlayerController))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
			PlayerController->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
			IsValid(InputSubsystem) && IsValid(MappingContext))
		{
			InputSubsystem->AddMappingContext(MappingContext, 0);
		}
	}
}

void AXCityCharacterBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	UpdateCameraTransformByMode();
}

void AXCityCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput =
		Cast<UEnhancedInputComponent>(PlayerInputComponent); IsValid(EnhancedInput))
	{
		if (IsValid(LookAction))
		{
			EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AXCityCharacterBase::LookInput);
		}
	}
}

void AXCityCharacterBase::LookInput(const FInputActionValue& Value)
{
	const FVector2D MouseVector = Value.Get<FVector2D>();

	APawn::AddControllerPitchInput(MouseVector.Y * -1);
	APawn::AddControllerYawInput(MouseVector.X);
}

void AXCityCharacterBase::InitCameraManager()
{
	SetCameraManagerMode(ECameraMode::ECM_Default);
}

void AXCityCharacterBase::SetCameraManagerMode(const ECameraMode& InNewCameraMode)
{
	if (IsValid(CameraManagerComponent.Get()))
	{
		CameraManagerComponent->SetCameraMode(InNewCameraMode);
	}
}

void AXCityCharacterBase::UpdateCameraTransformByMode()
{
	if (IsValid(CameraManagerComponent.Get()))
	{
		CameraManagerComponent->UpdateCameraOffset();
	}
}
