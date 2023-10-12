// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponActors/InteractibleWeaponBase.h"
#include "DataStructs/WeaponsDataStruct.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "Settings/WeaponSystemSettings.h"
#include "WeaponComponents/ShootComponentBase.h"

AInteractibleWeaponBase::AInteractibleWeaponBase()
{
	WeaponStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = WeaponStaticMeshComponent;
	
	PrimaryActorTick.bCanEverTick = true;
	
	WeaponID = FName();
	ShootComponentObject = nullptr;
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
	if (!FoundRow || !IsValid(FoundRow->ShootComponentClass))
	{
		return;
	}

	IInteractibleWeaponInterface::Execute_Internal_Initialize(this, *FoundRow);
}

void AInteractibleWeaponBase::Internal_Initialize_Implementation(const FWeaponsDataStruct& InInitialWeaponStruct)
{
	if (IsValid(InInitialWeaponStruct.WeaponMesh))
	{
		WeaponStaticMeshComponent->SetStaticMesh(InInitialWeaponStruct.WeaponMesh);
	}
	
	UActorComponent* SpawnedComponent = AddComponentByClass(
			InInitialWeaponStruct.ShootComponentClass,
			true,
			FTransform::Identity,
			false
			);
		
	if (!IsValid(SpawnedComponent))
	{
		return;
	}
		
	SpawnedComponent->RegisterComponent();
	AddInstanceComponent(SpawnedComponent);

	ShootComponentObject = Cast<UShootComponentBase>(SpawnedComponent);
	if (ShootComponentObject->Implements<UInteractibleWeaponInterface>())
	{
		IInteractibleWeaponInterface::Execute_Internal_Initialize(ShootComponentObject.Get(), InInitialWeaponStruct);
	}
}

void AInteractibleWeaponBase::OnInteract_Implementation()
{
	IInteractibleItemInterface::Execute_K2_OnInteract(this);
}

void AInteractibleWeaponBase::OnTake_Implementation()
{
	IInteractibleItemInterface::Execute_K2_OnTake(this);
}

void AInteractibleWeaponBase::OnDrop_Implementation()
{
	IInteractibleItemInterface::Execute_K2_OnDrop(this);
}

void AInteractibleWeaponBase::OnFireStart_Implementation()
{
	if (IsValid(ShootComponentObject.Get()))
	{
		IInteractibleWeaponInterface::Execute_OnFireStart(ShootComponentObject.Get());
	}
}

void AInteractibleWeaponBase::OnFireStop_Implementation()
{
	if (IsValid(ShootComponentObject.Get()))
	{
		IInteractibleWeaponInterface::Execute_OnFireStop(ShootComponentObject.Get());
	}
}

void AInteractibleWeaponBase::OnReload_Implementation()
{
	if (IsValid(ShootComponentObject.Get()))
	{
		IInteractibleWeaponInterface::Execute_OnReload(ShootComponentObject.Get());
	}
}

bool AInteractibleWeaponBase::IsReloading_Implementation()
{
	if (IsValid(ShootComponentObject.Get()))
	{
		return IInteractibleWeaponInterface::Execute_IsReloading(ShootComponentObject.Get());
	}

	return false;
}

int32 AInteractibleWeaponBase::GetAmmo_Implementation()
{
	if (IsValid(ShootComponentObject.Get()))
	{
		return IInteractibleWeaponInterface::Execute_GetAmmo(ShootComponentObject.Get());
	}

	return 0;
}

void AInteractibleWeaponBase::SetAmmo_Implementation(const int32 InNewAmmoValue)
{
	if (IsValid(ShootComponentObject.Get()))
	{
		IInteractibleWeaponInterface::Execute_SetAmmo(ShootComponentObject.Get(), InNewAmmoValue);
	}
}

void AInteractibleWeaponBase::AddAmmo_Implementation(const int32 InAmmoValue)
{
	if (IsValid(ShootComponentObject.Get()))
	{
		IInteractibleWeaponInterface::Execute_AddAmmo(ShootComponentObject.Get(), InAmmoValue);
	}
}

FTransform AInteractibleWeaponBase::GetFireSocketTransform_Implementation(const FName& InSocketName)
{
	if (IsValid(WeaponStaticMeshComponent))
	{
		return WeaponStaticMeshComponent->GetSocketTransform(InSocketName);
	}

	return FTransform();
}

int32 AInteractibleWeaponBase::GetAmmoPerStore_Implementation()
{
	if (IsValid(ShootComponentObject.Get()))
	{
		IInteractibleWeaponInterface::Execute_GetAmmoPerStore(ShootComponentObject.Get());
	}
	
	return 0;
}

void AInteractibleWeaponBase::ToggleWeaponMode_Implementation()
{
	if (IsValid(ShootComponentObject.Get()))
	{
		IInteractibleWeaponInterface::Execute_ToggleWeaponMode(ShootComponentObject.Get());
	}
}

void AInteractibleWeaponBase::SetAimMode_Implementation(const bool bAim)
{
	if (IsValid(ShootComponentObject.Get()))
	{
		IInteractibleWeaponInterface::Execute_SetAimMode(ShootComponentObject.Get(), bAim);
	}
}

bool AInteractibleWeaponBase::IsAimMode_Implementation()
{
	if (IsValid(ShootComponentObject.Get()))
	{
		return IInteractibleWeaponInterface::Execute_IsAimMode(ShootComponentObject.Get());
	}
	
	return false;
}
