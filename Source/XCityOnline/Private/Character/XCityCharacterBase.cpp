// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/XCityCharacterBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CameraManagerComponent.h"
#include "Conponents/FindObjectsComponent.h"
#include "Conponents/InventoryComponentBase.h"
#include "Kismet/KismetMathLibrary.h"

AXCityCharacterBase::AXCityCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraManagerComponent = CreateDefaultSubobject<UCameraManagerComponent>(TEXT("CameraManager"));
	CameraManagerComponent->SetupAttachments(this);

	InventoryComponent = CreateDefaultSubobject<UInventoryComponentBase>(TEXT("InventorySystemComponent"));
	FindItemComponent = CreateDefaultSubobject<UFindObjectsComponent>(TEXT("FinderComponent"));
}

void AXCityCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}

	InitCameraManager();
	InitInventorySystem();
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

void AXCityCharacterBase::InitInventorySystem()
{
	if (IsValid(InventoryComponent))
	{
		InventoryComponent->InitializeComponent();
		InventoryComponent->OnInventoryItemSelected.AddUniqueDynamic(
			this, &AXCityCharacterBase::AXCityCharacterBase::OnInventoryItemChanged);
		SelectedInventoryItem = nullptr;
	}
}

void AXCityCharacterBase::OnInventoryItemChanged(
	const TScriptInterface<IInteractibleItemInterface>& InInventoryItemChanged)
{
	SelectedInventoryItem = InInventoryItemChanged;
}

void AXCityCharacterBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	UpdateCameraTransformByMode();
	FindObjectsAround();
}

void AXCityCharacterBase::UpdateCameraTransformByMode()
{
	if (IsValid(CameraManagerComponent.Get()))
	{
		CameraManagerComponent->UpdateCameraOffset();
	}
}

void AXCityCharacterBase::FindObjectsAround()
{
	TArray<TScriptInterface<class IInteractibleItemInterface>> FoundObjects;
	if (IsValid(FindItemComponent.Get()) &&
		IFinderObjectsInterface::Execute_TryFindInteractibleObjects(FindItemComponent.Get(), FoundObjects))
	{
		TriggeredObject = GetCloserObject(FoundObjects);
		if (IsValid(TriggeredObject.GetObject()))
		{
			TriggeredObject = GetCloserObject(FoundObjects);
			IInteractibleItemInterface::Execute_K2_OnHover(TriggeredObject.GetObject(), true);

			return;
		}
	}
}

TScriptInterface<IInteractibleItemInterface> AXCityCharacterBase::GetCloserObject(
	const TArray<TScriptInterface<IInteractibleItemInterface>>& InFoundObjects) const
{
	if (InFoundObjects.IsEmpty())
	{
		return nullptr;
	}

	TArray<float> ToPlayerDistances;
	const FVector MainLocation = GetActorLocation();
	
	for (const TScriptInterface<IInteractibleItemInterface>& CurrentFoundObject : InFoundObjects)
	{
		if (const AActor* FoundObjectActor = Cast<AActor>(CurrentFoundObject.GetObject()))
		{
			ToPlayerDistances.Add(FVector::Distance(MainLocation, FoundObjectActor->GetActorLocation()));
		}
	}

	int32 IndexOfMinValue = INDEX_NONE;
	float MinValue = KINDA_SMALL_NUMBER;
	UKismetMathLibrary::MinOfFloatArray(ToPlayerDistances, IndexOfMinValue, MinValue);

	if (IndexOfMinValue == INDEX_NONE)
	{
		return InFoundObjects[0];
	}

	return InFoundObjects[IndexOfMinValue];
}

void AXCityCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput =
		Cast<UEnhancedInputComponent>(PlayerInputComponent); IsValid(EnhancedInput))
	{
		if (IsValid(LookAction))
		{
			EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AXCityCharacterBase::OnLookInputChanged);
		}

		if (IsValid(MoveAction))
		{
			EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AXCityCharacterBase::OnMoveInputChanged);
		}

		if (IsValid(JumpAction))
		{
			EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &AXCityCharacterBase::OnJumpInputChanged);
			EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &AXCityCharacterBase::OnStopJumpInputChanged);
		}
		
		if (IsValid(MainInteractAction))
		{
			EnhancedInput->BindAction(MainInteractAction, ETriggerEvent::Started, this, &AXCityCharacterBase::OnMainInteractInputChanged);
			EnhancedInput->BindAction(MainInteractAction, ETriggerEvent::Completed, this, &AXCityCharacterBase::OnStopMainInteractInputChanged);
		}

		if (IsValid(AlternativeInteractAction))
		{
			EnhancedInput->BindAction(AlternativeInteractAction, ETriggerEvent::Started, this, &AXCityCharacterBase::OnAlternativeInteractInputChanged);
			EnhancedInput->BindAction(AlternativeInteractAction, ETriggerEvent::Completed, this, &AXCityCharacterBase::OnStopAlternativeInteractInputChanged);
		}

		if (IsValid(TakeAction))
		{
			EnhancedInput->BindAction(TakeAction, ETriggerEvent::Triggered, this, &AXCityCharacterBase::OnTakeInputChanged);
		}

		if (IsValid(DropAction))
		{
			EnhancedInput->BindAction(DropAction, ETriggerEvent::Triggered, this, &AXCityCharacterBase::OnDropInputChanged);
		}

		if (IsValid(WheelAxisAction))
		{
			EnhancedInput->BindAction(WheelAxisAction, ETriggerEvent::Triggered, this, &AXCityCharacterBase::OnWheelAxisInputChanged);
		}
	}
}

void AXCityCharacterBase::OnLookInputChanged(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y * -1.0f);
	}
}

void AXCityCharacterBase::OnMoveInputChanged(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AXCityCharacterBase::OnJumpInputChanged(const FInputActionValue& Value)
{
	K2_OnJumpChanged(true);
}

void AXCityCharacterBase::OnStopJumpInputChanged(const FInputActionValue& Value)
{
	K2_OnJumpChanged(false);
}

void AXCityCharacterBase::OnMainInteractInputChanged(const FInputActionValue& Value)
{
	if (IsValid(SelectedInventoryItem.GetObject()))
	{
		IInteractibleItemInterface::Execute_OnStartMainInteract(SelectedInventoryItem.GetObject());
	}
}

void AXCityCharacterBase::OnStopMainInteractInputChanged(const FInputActionValue& Value)
{
	if (IsValid(SelectedInventoryItem.GetObject()))
	{
		IInteractibleItemInterface::Execute_OnStopMainInteract(SelectedInventoryItem.GetObject());
	}
}

void AXCityCharacterBase::OnAlternativeInteractInputChanged(const FInputActionValue& Value)
{
	if (IsValid(SelectedInventoryItem.GetObject()))
	{
		IInteractibleItemInterface::Execute_OnStartAlternativeInteract(SelectedInventoryItem.GetObject());
	}
	
	if (IsValid(CameraManagerComponent.Get()))
	{
		CameraManagerComponent->SetCameraMode(ECameraMode::ECM_Aim);
	}
}

void AXCityCharacterBase::OnStopAlternativeInteractInputChanged(const FInputActionValue& Value)
{
	if (IsValid(SelectedInventoryItem.GetObject()))
	{
		IInteractibleItemInterface::Execute_OnStopAlternativeInteract(SelectedInventoryItem.GetObject());
	}
	
	if (IsValid(CameraManagerComponent.Get()))
	{
		CameraManagerComponent->SetCameraMode(ECameraMode::ECM_Default);
	}
}

void AXCityCharacterBase::OnTakeInputChanged(const FInputActionValue& Value)
{
	if (IsValid(InventoryComponent.Get()) && IsValid(TriggeredObject.GetObject()))
	{
		IInventorySystemInterface::Execute_AddInventoryItem(InventoryComponent.Get(), TriggeredObject);
		IInteractibleItemInterface::Execute_OnTake(TriggeredObject.GetObject());
		SelectedInventoryItem = TriggeredObject;

		//For attach testing...
		if (AActor* TriggeredActor = Cast<AActor>(TriggeredObject.GetObject()))
		{
			K2_AttachTo(TriggeredActor);
		}
		//~
		
		//ToDo:: Hide logic for selected object here...
		//ToDo:~
	}
}

void AXCityCharacterBase::OnDropInputChanged(const FInputActionValue& Value)
{
	if (IsValid(InventoryComponent.Get()) && IsValid(SelectedInventoryItem.GetObject()))
	{
		IInventorySystemInterface::Execute_RemoveInventoryItem(InventoryComponent.Get(), SelectedInventoryItem);
		SelectedInventoryItem = nullptr;
	}
}

void AXCityCharacterBase::OnWheelAxisInputChanged(const FInputActionValue& Value)
{
	if (!IsValid(InventoryComponent.Get()))
	{
		return;
	}

	if (const float WheelAxis = Value.Get<float>(); WheelAxis > 0)
	{
		IInventorySystemInterface::Execute_OnForwardItemChanged(InventoryComponent.Get());
		return;
	}

	IInventorySystemInterface::Execute_OnBackwardItemChanged(InventoryComponent.Get());
}
