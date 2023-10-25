// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponActors/InteractibleWeaponBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/BoxComponent.h"
#include "DataStructs/WeaponsDataStruct.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "Kismet/GameplayStatics.h"
#include "Settings/WeaponSystemSettings.h"
#include "WeaponComponents/ShootComponentBase.h"

AInteractibleWeaponBase::AInteractibleWeaponBase()
{
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("RootCollision");
	RootComponent = BoxCollision;
	
	WeaponSkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponSkeletalMeshComponent->SetupAttachment(RootComponent);
	
	PrimaryActorTick.bCanEverTick = true;
	
	WeaponID = FName();
	MainShootComponentObject = nullptr;
	AlternativeShootComponentObject = nullptr;
	SelectedShootComponent = nullptr;
	InitialWeaponStruct = FWeaponsDataStruct();
}

void AInteractibleWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	IInteractibleWeaponInterface::Execute_InitializeWeapon(this);
}

void AInteractibleWeaponBase::InitializeWeapon_Implementation()
{
	const FSoftObjectPath WeaponsTablePath =
		UWeaponSystemSettings::GetWeaponSystemSettings()->WeaponDataTable.ToSoftObjectPath();
		
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	Streamable.RequestAsyncLoad(
	WeaponsTablePath,
	FStreamableDelegate::CreateUObject(this, &AInteractibleWeaponBase::OnLoadComplete));
}

void AInteractibleWeaponBase::OnLoadComplete()
{
	const UDataTable* WeaponsTable = UWeaponSystemSettings::GetWeaponSystemSettings()->WeaponDataTable.Get();
	if (!IsValid(WeaponsTable))
	{
		return;
	}

	const FWeaponsDataStruct* FoundRow = WeaponsTable->FindRow<FWeaponsDataStruct>(WeaponID, "");
	if (!FoundRow || !IsValid(FoundRow->MainShootComponentClass))
	{
		return;
	}

	IInteractibleWeaponInterface::Execute_Internal_Initialize(this, *FoundRow, false);
}

void AInteractibleWeaponBase::Internal_Initialize_Implementation(
	const FWeaponsDataStruct& InInitialWeaponStruct, const bool bAlternative)
{
	if (IsValid(InInitialWeaponStruct.WeaponSkeletal))
	{
		WeaponSkeletalMeshComponent->SetSkeletalMesh(InInitialWeaponStruct.WeaponSkeletal);
	}
	
	InitialWeaponStruct = InInitialWeaponStruct;
	
	CreateShootComponent(InInitialWeaponStruct, MainShootComponentObject, false);
	if (InInitialWeaponStruct.bUseAlternativeMode)
	{
		CreateShootComponent(InInitialWeaponStruct, AlternativeShootComponentObject, true);
	}
	
	IInteractibleWeaponInterface::Execute_OnUseMainFire(this);
}

void AInteractibleWeaponBase::CreateShootComponent(
	const FWeaponsDataStruct& InInitialWeaponStruct,
	TObjectPtr<UShootComponentBase>& OutShootComponent,
	const bool bAlternative)
{
	const TSubclassOf<UShootComponentBase> SelectShootComponent = bAlternative
	? InInitialWeaponStruct.AlternativeShootComponentClass
	: InInitialWeaponStruct.MainShootComponentClass;
	
	UActorComponent* SpawnedShootComponent = AddComponentByClass(
			SelectShootComponent,
			true,
			FTransform::Identity,
			false
			);
		
	if (!IsValid(SpawnedShootComponent))
	{
		return;
	}
		
	SpawnedShootComponent->RegisterComponent();
	AddInstanceComponent(SpawnedShootComponent);

	OutShootComponent = Cast<UShootComponentBase>(SpawnedShootComponent);
	if (OutShootComponent->Implements<UInteractibleWeaponInterface>())
	{
		IInteractibleWeaponInterface::Execute_Internal_Initialize(
			OutShootComponent.Get(),
			InInitialWeaponStruct,
			bAlternative);

		OutShootComponent->OnFire.AddUniqueDynamic(this, &AInteractibleWeaponBase::K2_OnFire);
		OutShootComponent->OnReloadFireMiss.AddUniqueDynamic(this, &AInteractibleWeaponBase::K2_OnFireMiss);
		OutShootComponent->OnReload.AddUniqueDynamic(this, &AInteractibleWeaponBase::K2_OnReload);
		OutShootComponent->OnAimModeChanged.AddUniqueDynamic(this, &AInteractibleWeaponBase::K2_OnAimModeChanged);
	}
}

void AInteractibleWeaponBase::BindInputActions()
{
	if (const APlayerController* OwnerController = UGameplayStatics::GetPlayerController(this, 0))
	{
		UActorComponent* EnhancedComponent =  OwnerController->FindComponentByClass<UEnhancedInputComponent>();
		if (UEnhancedInputComponent* PlayerInputComponent = Cast<UEnhancedInputComponent>(EnhancedComponent))
		{
			if (IsValid(MainFire.Get()))
			{
				PlayerInputComponent->BindAction(
				MainFire,
				ETriggerEvent::Started,
				this,
				&AInteractibleWeaponBase::OnStartMainInteract_Implementation);
				
				PlayerInputComponent->BindAction(
				MainFire,
				ETriggerEvent::Completed,
				this,
				&AInteractibleWeaponBase::OnStopMainInteract_Implementation);
			}

			if (IsValid(AlternativeFire.Get()))
			{
				PlayerInputComponent->BindAction(
				AlternativeFire,
				ETriggerEvent::Started,
				this,
				&AInteractibleWeaponBase::OnStartAlternativeInteract_Implementation);
				
				PlayerInputComponent->BindAction(
				AlternativeFire,
				ETriggerEvent::Completed,
				this,
				&AInteractibleWeaponBase::OnStopAlternativeInteract_Implementation);
			}

			if (IsValid(Reload.Get()))
			{
				PlayerInputComponent->BindAction(
				Reload,
				ETriggerEvent::Triggered,
				this,
				&AInteractibleWeaponBase::OnReload_Implementation);
			}
				
			if (IsValid(AimMode.Get()))
			{
				PlayerInputComponent->BindAction(
				AimMode,
				ETriggerEvent::Started,
				this,
				&AInteractibleWeaponBase::OnStartAlternativeInteract_Implementation);
				
				PlayerInputComponent->BindAction(
				AimMode,
				ETriggerEvent::Completed,
				this,
				&AInteractibleWeaponBase::OnStopAlternativeInteract_Implementation);
			}
		}
	}
}

void AInteractibleWeaponBase::OnUseMainFire_Implementation()
{
	SelectedShootComponent = MainShootComponentObject;
	if (OnAlternativeFireChanged.IsBound())
	{
		OnAlternativeFireChanged.Broadcast(false);
	}
}

void AInteractibleWeaponBase::OnUseAlternativeFire_Implementation()
{
	SelectedShootComponent = AlternativeShootComponentObject;
	if (OnAlternativeFireChanged.IsBound())
	{
		OnAlternativeFireChanged.Broadcast(true);
	}
}

void AInteractibleWeaponBase::OnStartMainInteract_Implementation()
{
	IInteractibleItemInterface::Execute_K2_OnMainInteract(this, true);
	IInteractibleWeaponInterface::Execute_OnFireStart(this);
}

void AInteractibleWeaponBase::OnStopMainInteract_Implementation()
{
	IInteractibleItemInterface::Execute_K2_OnMainInteract(this, false);
	IInteractibleWeaponInterface::Execute_OnFireStop(this);
}

void AInteractibleWeaponBase::OnStartAlternativeInteract_Implementation()
{
	IInteractibleItemInterface::Execute_K2_OnAlternativeInteract(this, true);
	IInteractibleWeaponInterface::Execute_OnUseAlternativeFire(this);
	if (IsValid(SelectedShootComponent))
	{
		IInteractibleWeaponInterface::Execute_OnFireStart(SelectedShootComponent.Get());
		return;
	}
	
	IInteractibleWeaponInterface::Execute_SetAimMode(this, true);
}

void AInteractibleWeaponBase::OnStopAlternativeInteract_Implementation()
{
	IInteractibleItemInterface::Execute_K2_OnAlternativeInteract(this, false);
	IInteractibleWeaponInterface::Execute_OnUseMainFire(this);
	if (IsValid(SelectedShootComponent))
	{
		IInteractibleWeaponInterface::Execute_OnFireStop(SelectedShootComponent.Get());
	}

	IInteractibleWeaponInterface::Execute_SetAimMode(this, false);
}

void AInteractibleWeaponBase::OnTake_Implementation(AActor* OwnerActor)
{
	IInteractibleItemInterface::Execute_K2_OnTake(this);
	
	if (UPrimitiveComponent* ActorPrimitive = Cast<UPrimitiveComponent>(RootComponent))
	{
		SetActorEnableCollision(false);

		ActorPrimitive->BodyInstance.bGenerateWakeEvents = false;
		ActorPrimitive->OnComponentSleep.RemoveAll(this);
		ActorPrimitive->SetSimulatePhysics(false);
	}
	
	SetOwner(OwnerActor);
	AddMappingContext();
	BindInputActions();
}

void AInteractibleWeaponBase::AddMappingContext() const
{
	if (MappingContext)
	{
		if (const APlayerController* OwnerController =
			UGameplayStatics::GetPlayerController(this, 0))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(OwnerController->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(MappingContext, 0);
			}
		}
	}
}

void AInteractibleWeaponBase::OnUnselect_Implementation()
{
	IInteractibleItemInterface::Execute_K2_OnUnselect(this);
	RemoveMappingContext();
}

void AInteractibleWeaponBase::OnDrop_Implementation()
{
	IInteractibleItemInterface::Execute_K2_OnDrop(this);
	
	RemoveMappingContext();
	
	if (UPrimitiveComponent* ActorPrimitive = Cast<UPrimitiveComponent>(RootComponent))
	{
		SetActorEnableCollision(true);
		
		ActorPrimitive->BodyInstance.bGenerateWakeEvents = true;
		ActorPrimitive->OnComponentSleep.AddUniqueDynamic(this, &AInteractibleWeaponBase::OnItemSleep);
		ActorPrimitive->SetSimulatePhysics(true);

		if (IsValid(GetOwner()))
		{
			ActorPrimitive->AddRadialImpulse(
			GetOwner()->GetActorLocation(),
			50.0f,
			200.0f,
			ERadialImpulseFalloff::RIF_Constant,
			true);
		}
	}

	SetOwner(nullptr);
}

void AInteractibleWeaponBase::OnItemSleep_Implementation(UPrimitiveComponent* SleepingComponent, FName BoneName)
{
	if (UPrimitiveComponent* ActorPrimitive = Cast<UPrimitiveComponent>(RootComponent))
	{
		ActorPrimitive->OnComponentSleep.RemoveAll(this);
		ActorPrimitive->SetSimulatePhysics(false);
	}
}

void AInteractibleWeaponBase::RemoveMappingContext()
{
	if (MappingContext)
	{
		if (const APlayerController* OwnerController =
			UGameplayStatics::GetPlayerController(this, 0))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(OwnerController->GetLocalPlayer()))
			{
				FModifyContextOptions ModifyContextOptions;
				ModifyContextOptions.bIgnoreAllPressedKeysUntilRelease = true;
				
				Subsystem->RemoveMappingContext(MappingContext, ModifyContextOptions);

				UActorComponent* EnhancedComponent = OwnerController->FindComponentByClass<UEnhancedInputComponent>();
				if (UEnhancedInputComponent* PlayerInputComponent = Cast<UEnhancedInputComponent>(EnhancedComponent))
				{
					PlayerInputComponent->ClearBindingsForObject(this);
				}
			}
		}
	}
}

void AInteractibleWeaponBase::OnFireStart_Implementation()
{
	if (IsValid(SelectedShootComponent.Get()))
	{
		IInteractibleWeaponInterface::Execute_OnFireStart(SelectedShootComponent.Get());
	}
}

void AInteractibleWeaponBase::OnFireStop_Implementation()
{
	if (IsValid(SelectedShootComponent.Get()))
	{
		IInteractibleWeaponInterface::Execute_OnFireStop(SelectedShootComponent.Get());
	}
}

void AInteractibleWeaponBase::OnReload_Implementation()
{
	if (IsValid(SelectedShootComponent.Get()))
	{
		IInteractibleWeaponInterface::Execute_OnReload(SelectedShootComponent.Get());
	}
}

bool AInteractibleWeaponBase::IsReloading_Implementation()
{
	if (IsValid(SelectedShootComponent.Get()))
	{
		return IInteractibleWeaponInterface::Execute_IsReloading(SelectedShootComponent.Get());
	}

	return false;
}

int32 AInteractibleWeaponBase::GetAmmo_Implementation()
{
	if (IsValid(SelectedShootComponent.Get()))
	{
		return IInteractibleWeaponInterface::Execute_GetAmmo(SelectedShootComponent.Get());
	}

	return 0;
}

void AInteractibleWeaponBase::SetAmmo_Implementation(const int32 InNewAmmoValue)
{
	if (IsValid(SelectedShootComponent.Get()))
	{
		IInteractibleWeaponInterface::Execute_SetAmmo(SelectedShootComponent.Get(), InNewAmmoValue);
	}
}

void AInteractibleWeaponBase::AddAmmo_Implementation(const int32 InAmmoValue)
{
	if (IsValid(SelectedShootComponent.Get()))
	{
		IInteractibleWeaponInterface::Execute_AddAmmo(SelectedShootComponent.Get(), InAmmoValue);
	}
}

FTransform AInteractibleWeaponBase::GetFireSocketTransform_Implementation(const FName& InSocketName)
{
	if (IsValid(WeaponSkeletalMeshComponent))
	{
		return WeaponSkeletalMeshComponent->GetSocketTransform(InSocketName);
	}

	return FTransform();
}

int32 AInteractibleWeaponBase::GetAmmoPerStore_Implementation()
{
	if (IsValid(SelectedShootComponent.Get()))
	{
		IInteractibleWeaponInterface::Execute_GetAmmoPerStore(SelectedShootComponent.Get());
	}
	
	return 0;
}

void AInteractibleWeaponBase::ToggleWeaponMode_Implementation()
{
	if (IsValid(SelectedShootComponent.Get()))
	{
		IInteractibleWeaponInterface::Execute_ToggleWeaponMode(SelectedShootComponent.Get());
	}
}

void AInteractibleWeaponBase::SetAimMode_Implementation(const bool bAim)
{
	if (IsValid(SelectedShootComponent.Get()))
	{
		IInteractibleWeaponInterface::Execute_SetAimMode(SelectedShootComponent.Get(), bAim);
	}
}

bool AInteractibleWeaponBase::IsAimMode_Implementation()
{
	if (IsValid(SelectedShootComponent.Get()))
	{
		return IInteractibleWeaponInterface::Execute_IsAimMode(SelectedShootComponent.Get());
	}
	
	return false;
}

void AInteractibleWeaponBase::OnStartHover_Implementation()
{
	IInteractibleItemInterface::Execute_K2_OnHover(this, true);
}

void AInteractibleWeaponBase::OnStopHover_Implementation()
{
	IInteractibleItemInterface::Execute_K2_OnHover(this, false);
}

bool AInteractibleWeaponBase::Internal_GetItemSettings(UObject* ContextObject, UStruct* InStruct, void* OutData)
{
	if (InStruct == FWeaponsDataStruct::StaticStruct())
	{
		*static_cast<FWeaponsDataStruct*>(OutData) = InitialWeaponStruct;
		return true;
	}

	return false;
}
