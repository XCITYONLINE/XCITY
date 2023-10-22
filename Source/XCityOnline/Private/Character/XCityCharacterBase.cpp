// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/XCityCharacterBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ReplicaPlayerComponent.h"
#include "Components/CameraManagerComponent.h"
#include "Conponents/FindObjectsComponent.h"
#include "Conponents/InventoryComponentBase.h"
#include "Contracts/InteractibleItemInterface.h"
#include "Contracts/InteractibleWeaponInterface.h"
#include "Kismet/KismetMathLibrary.h"
#include "WeaponActors/InteractibleWeaponBase.h"

AXCityCharacterBase::AXCityCharacterBase(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
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
	if (IsValid(SelectedInventoryItem.GetObject()))
	{
		IInteractibleItemInterface::Execute_OnTake(SelectedInventoryItem.GetObject(), this);
	}
}

void AXCityCharacterBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	UpdateCameraTransformByMode();
	FindObjectsAround(false);
}

void AXCityCharacterBase::UpdateCameraTransformByMode()
{
	if (IsValid(CameraManagerComponent.Get()))
	{
		CameraManagerComponent->UpdateCameraOffset();
	}
}

void AXCityCharacterBase::FindObjectsAround(const bool bForce)
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

	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->ClearAllMappings();
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}
	
	if (UEnhancedInputComponent* EnhancedInput =
		Cast<UEnhancedInputComponent>(PlayerInputComponent); IsValid(EnhancedInput))
	{
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

		if (IsValid(TalkAction))
		{
			EnhancedInput->BindAction(TalkAction, ETriggerEvent::Started, this, &AXCityCharacterBase::OnTalkInputChanged);
			EnhancedInput->BindAction(TalkAction, ETriggerEvent::Completed, this, &AXCityCharacterBase::OnTalkInputCompleted);
		}
	}
}

void AXCityCharacterBase::OnTakeInputChanged(const FInputActionValue& Value)
{
	if (IsValid(InventoryComponent.Get())
		&& IsValid(TriggeredObject.GetObject())
		&& IsValid(FindItemComponent.Get()))
	{
		IInventorySystemInterface::Execute_AddInventoryItem(InventoryComponent.Get(), TriggeredObject);
		IInteractibleItemInterface::Execute_OnTake(TriggeredObject.GetObject(), this);
		IFinderObjectsInterface::Execute_ResetPreviousItems(FindItemComponent.Get());
		
		if (TriggeredObject.GetObject()->Implements<UInteractibleWeaponInterface>())
		{
			FWeaponsDataStruct WeaponsDataStruct;
			if (IsValid(TriggeredObject.GetObject());
				TriggeredObject->GetItemSettings(TriggeredObject.GetObject(), WeaponsDataStruct))
			{
				AttachToHand(
				WeaponsDataStruct.WeaponStaticMesh,
				WeaponsDataStruct.WeaponSkeletal,
				WeaponsDataStruct.WeaponAnimInstance,
				false,
				WeaponsDataStruct.AttachOffset,
				true,
				TriggeredObject.GetObject()
				);

				K2_AttachTo(TriggeredObject.GetObject());
				SelectedInventoryItem = TriggeredObject;
			}
		}
	}
}

void AXCityCharacterBase::OnDropInputChanged(const FInputActionValue& Value)
{
	if (IsValid(InventoryComponent.Get()) && IsValid(SelectedInventoryItem.GetObject()))
	{
		IInventorySystemInterface::Execute_RemoveInventoryItem(InventoryComponent.Get(), SelectedInventoryItem);
		
		DetachToHand(SelectedInventoryItem.GetObject());
		K2_DropTo(SelectedInventoryItem.GetObject());

		IInteractibleItemInterface::Execute_OnUnselect(SelectedInventoryItem.GetObject());
		IInteractibleItemInterface::Execute_OnDrop(SelectedInventoryItem.GetObject());
		
		SelectedInventoryItem = nullptr;
	}
}

void AXCityCharacterBase::OnWheelAxisInputChanged(const FInputActionValue& Value)
{
	if (!IsValid(InventoryComponent.Get()))
	{
		return;
	}

	if (const float WheelAxis = Value.Get<float>(); WheelAxis == 1.0f)
	{
		IInventorySystemInterface::Execute_OnForwardItemChanged(InventoryComponent.Get());
		ReInitializeItemObject();
	}
	else if (WheelAxis == -1.0f)
	{
		IInventorySystemInterface::Execute_OnBackwardItemChanged(InventoryComponent.Get());
		ReInitializeItemObject();
	}
}

void AXCityCharacterBase::ReInitializeItemObject()
{
	if (IsValid(InventoryComponent.Get()))
	{
		ClearHeldObject();
		
		IInventorySystemInterface::Execute_UnselectAllItems(InventoryComponent.Get());
		SelectedInventoryItem = IInventorySystemInterface::Execute_GetSelectedItem(InventoryComponent.Get());
		
		if (IsValid(SelectedInventoryItem.GetObject()))
		{
			IInteractibleItemInterface::Execute_OnTake(SelectedInventoryItem.GetObject(), this);
			K2_AttachTo(SelectedInventoryItem.GetObject());
		}
	}
}

void AXCityCharacterBase::OnTalkInputChanged(const FInputActionValue& Value)
{
	UActorComponent* ActorComponent = GetComponentByClass<UReplicaPlayerComponent>();
	if (UReplicaPlayerComponent* ReplicaComponent = Cast<UReplicaPlayerComponent>(ActorComponent))
	{
		ReplicaComponent->OnReplicaChange();
	}
}

void AXCityCharacterBase::OnTalkInputCompleted(const FInputActionValue& Value)
{
	UActorComponent* ActorComponent = GetComponentByClass<UReplicaPlayerComponent>();
	if (UReplicaPlayerComponent* ReplicaComponent = Cast<UReplicaPlayerComponent>(ActorComponent))
	{
		ReplicaComponent->OnReplicaComplete();
	}
}
