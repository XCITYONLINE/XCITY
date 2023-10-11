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

void AInteractibleWeaponBase::OnFireStart_Implementation()
{
	IInteractibleWeaponInterface::OnFireStart_Implementation();
}

void AInteractibleWeaponBase::OnFireStop_Implementation()
{
	IInteractibleWeaponInterface::OnFireStop_Implementation();
}

void AInteractibleWeaponBase::OnReload_Implementation()
{
	IInteractibleWeaponInterface::OnReload_Implementation();
}

bool AInteractibleWeaponBase::IsReloading_Implementation()
{
	return IInteractibleWeaponInterface::IsReloading_Implementation();
}

int32 AInteractibleWeaponBase::GetAmmo_Implementation()
{
	return IInteractibleWeaponInterface::GetAmmo_Implementation();
}

void AInteractibleWeaponBase::SetAmmo_Implementation(const int32 InNewAmmoValue)
{
	IInteractibleWeaponInterface::SetAmmo_Implementation(InNewAmmoValue);
}

void AInteractibleWeaponBase::AddAmmo_Implementation(const int32 InAmmoValue)
{
	IInteractibleWeaponInterface::AddAmmo_Implementation(InAmmoValue);
}
