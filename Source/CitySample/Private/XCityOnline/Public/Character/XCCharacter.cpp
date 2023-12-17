// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/Character/XCCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ReplicaPlayerComponent.h"
#include "XCityOnline/Public/Components/CameraManagerComponent.h"
#include "XCityOnline/Public/Components/RadialMenuComponent.h"
#include "Conponents/FindObjectsComponent.h"
#include "Conponents/InventoryComponentBase.h"
#include "Contracts/InteractibleItemInterface.h"
#include "Contracts/InteractibleWeaponInterface.h"
#include "Kismet/KismetMathLibrary.h"
#include "XCityOnline/Public/Data/CameraSystemTypes.h"
#include "XCityOnline/Public/UI/XCityHUD.h"
#include "XCityOnline/Public/UI/RadialMenu/RadialMenuWidget.h"

#include "Vehicles/CitySampleVehicleBase.h"
#include "MotionWarpingComponent.h"

AXCCharacter::AXCCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraManagerComponent = CreateDefaultSubobject<UCameraManagerComponent>(TEXT("CameraManager"));
	CameraManagerComponent->SetupAttachments(this);

	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarpingComponent"));
	MotionWarpingComponent->bSearchForWindowsInAnimsWithinMontages = true;

}

bool AXCCharacter::IsDriving() const
{
	if (ACitySampleVehicleBase* const ParentVehicle = Cast<ACitySampleVehicleBase>(GetAttachParentActor()))
	{
		//return (ParentVehicle->GetOccupantInSeat(ECitySampleVehicleSeat::Driver) == this);
	}

	return false;
}

void AXCCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitCameraManager();
}

void AXCCharacter::InitCameraManager()
{
	SetCameraManagerMode(ECameraMode::ECM_Default);
}

void AXCCharacter::SetCameraManagerMode(const ECameraMode& InNewCameraMode)
{
	if (IsValid(CameraManagerComponent.Get()))
	{
		CameraManagerComponent->SetCameraMode(InNewCameraMode);
	}
}

void AXCCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdateCameraTransformByMode();
}

void AXCCharacter::UpdateCameraTransformByMode()
{
	if (IsValid(CameraManagerComponent.Get()))
	{
		CameraManagerComponent->UpdateCameraOffset();
	}
}


void AXCCharacter::SetupPlayerInputComponent(UInputComponent* Input)
{
	Super::SetupPlayerInputComponent(Input);

	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->ClearAllMappings();
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}

	Super::NotifyControllerChanged();

	if (UEnhancedInputComponent* EnhancedInput =
		Cast<UEnhancedInputComponent>(Input); IsValid(EnhancedInput))
	{
		if (IsValid(TalkAction))
		{
			EnhancedInput->BindAction(TalkAction, ETriggerEvent::Started, this, &AXCCharacter::OnTalkInputChanged);
			EnhancedInput->BindAction(TalkAction, ETriggerEvent::Completed, this, &AXCCharacter::OnTalkInputCompleted);
		}

	}
}


void AXCCharacter::OnTalkInputChanged(const FInputActionValue& Value)
{
	UActorComponent* ActorComponent = GetComponentByClass<UReplicaPlayerComponent>();
	if (UReplicaPlayerComponent* ReplicaComponent = Cast<UReplicaPlayerComponent>(ActorComponent))
	{
		ReplicaComponent->OnReplicaChange();
	}
}

void AXCCharacter::OnTalkInputCompleted(const FInputActionValue& Value)
{
	UActorComponent* ActorComponent = GetComponentByClass<UReplicaPlayerComponent>();
	if (UReplicaPlayerComponent* ReplicaComponent = Cast<UReplicaPlayerComponent>(ActorComponent))
	{
		ReplicaComponent->OnReplicaComplete();
	}
}