// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/XCityCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CameraManagerComponent.h"

AXCityCharacter::AXCityCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraManagerComponent = CreateDefaultSubobject<UCameraManagerComponent>(TEXT("CameraManager"));

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent.Get(), SpringArmComponent->SocketName);
}

void AXCityCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (!PlayerController) return;

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = PlayerController->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (!InputSubsystem) return;

	InputSubsystem->AddMappingContext(MappingContext.Get(), 0);
}

void AXCityCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdateCameraTransformByMode();
}

void AXCityCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EnhancedInput) return;

	if (LookAction.IsValid())
	{
		EnhancedInput->BindAction(LookAction.Get(), ETriggerEvent::Triggered, this, &AXCityCharacter::LookInput);
	}
}

void AXCityCharacter::SetCameraManagerMode(const ECameraMode& InNewCameraMode)
{
	IPlayerCameraManagerInterface::SetCameraManagerMode(InNewCameraMode);

	CameraManagerComponent->SetCameraMode(InNewCameraMode);
}

void AXCityCharacter::InitCameraManager()
{
	SetCameraManagerMode(ECameraMode::ECM_Default);
}

void AXCityCharacter::UpdateCameraTransformByMode()
{
	CameraManagerComponent->UpdateCameraOffset(SpringArmComponent);
}

void AXCityCharacter::LookInput(const FInputActionValue& Value)
{
	const FVector2D MouseVector = Value.Get<FVector2D>();

	APawn::AddControllerPitchInput(MouseVector.Y * -1);
	APawn::AddControllerYawInput(MouseVector.X);
}
