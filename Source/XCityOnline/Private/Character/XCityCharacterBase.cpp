// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/XCityCharacterBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CameraManagerComponent.h"
#include "Camera/CameraComponent.h"

AXCityCharacterBase::AXCityCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraManagerComponent = CreateDefaultSubobject<UCameraManagerComponent>(TEXT("CameraManager"));

	// I attaching other components in this code because if i attach them in Camera Manager constructors it does not works
	CameraManagerComponent->SetupAttachments(this);
}

void AXCityCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	InitCameraManager();

	APlayerController* PlayerController = Cast<APlayerController>(GetOwner());
	
	if (IsValid(PlayerController))
	{
		UEnhancedInputLocalPlayerSubsystem* InputSubsystem = PlayerController->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

		if (IsValid(InputSubsystem) && IsValid(MappingContext))
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

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (IsValid(EnhancedInput))
	{
		if (IsValid(LookAction))
		{
			EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AXCityCharacterBase::LookInput);
		}
	}
}

void AXCityCharacterBase::SetCameraManagerMode(const ECameraMode& InNewCameraMode)
{
	IPlayerCameraManagerInterface::SetCameraManagerMode(InNewCameraMode);

	CameraManagerComponent->SetCameraMode(InNewCameraMode);
}

void AXCityCharacterBase::InitCameraManager()
{
	SetCameraManagerMode(ECameraMode::ECM_Default);
}

void AXCityCharacterBase::UpdateCameraTransformByMode()
{
	CameraManagerComponent->UpdateCameraOffset();
}

void AXCityCharacterBase::LookInput(const FInputActionValue& Value)
{
	const FVector2D MouseVector = Value.Get<FVector2D>();

	APawn::AddControllerPitchInput(MouseVector.Y * -1);
	APawn::AddControllerYawInput(MouseVector.X);
}
