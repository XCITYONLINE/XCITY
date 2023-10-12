// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponComponents/ShootComponentBase.h"
#include "WeaponActors/AmmoProjectileBase.h"

UShootComponentBase::UShootComponentBase()
{
	PrimaryComponentTick.bCanEverTick = true;
	
	bIsFireProcessActive = false;
	bIsReloadProcessActive = false;
	bIsFireProcessHold = false;
	bIsAim = false;
	
	CurrentAmmo = 0;
	CurrentAmmoPerStore = 0;
	CurrentShootModeIndex = 0;
	CurrentSemiShootIndex = 0;
}

void UShootComponentBase::Internal_Initialize_Implementation(const FWeaponsDataStruct& InInitialWeaponStruct)
{
	InitialWeaponSettings = InInitialWeaponStruct;
	CurrentAmmo = InitialWeaponSettings.ShootSettings.InitialAmmo;
	CurrentAmmoPerStore = InitialWeaponSettings.ShootSettings.AmmoPerStore;
}

void UShootComponentBase::OnFireStart_Implementation()
{
	bIsFireProcessHold = true;
	
	if (!CheckPossibilityShot())
	{
		K2_OnFireMiss();
		return;
	}

	AActor* OwnerActor = GetOwner();
	if (!IsValid(OwnerActor))
	{
		K2_OnFireMiss();
		return;
	}

	if (OwnerActor->Implements<UInteractibleWeaponInterface>())
	{
		const FTransform MuzzleSocketTransform = IInteractibleWeaponInterface::Execute_GetFireSocketTransform(
			OwnerActor,
			InitialWeaponSettings.ShootSettings.FireSocketName);
		
		AAmmoProjectileBase* SpawnProjectile = GetWorld()->SpawnActorDeferred<AAmmoProjectileBase>(
			InitialWeaponSettings.AmmoProjectileClass,
			MuzzleSocketTransform,
			GetOwner());

		if (!IsValid(SpawnProjectile))
		{
			return;
		}

		if (!SpawnProjectile->TryInitializeProjectile(InitialWeaponSettings.ShootSettings.ProjectileSettings))
		{
			SpawnProjectile->Destroy();
			return;
		}

		SpawnProjectile->FinishSpawning(MuzzleSocketTransform);

		K2_OnFire();
		OnAfterFireProcessStart();
		
		return;
	}

	K2_OnFireMiss();
}

bool UShootComponentBase::CheckPossibilityShot() const
{
	return !(bIsFireProcessActive || bIsReloadProcessActive || CurrentAmmoPerStore == 0 || !bIsFireProcessHold);
}

void UShootComponentBase::OnAfterFireProcessStart()
{
	if (const UWorld* World = GetWorld(); IsValid(World))
	{
		World->GetTimerManager().SetTimer(
			OnAfterFireTimerHandle,
			FTimerDelegate::CreateWeakLambda(this, [this]
			{
				FireProcessByShootMode();
			}),
			InitialWeaponSettings.ShootSettings.FireRate,
			false);

		ShootDataOperations();
	}
}

void UShootComponentBase::FireProcessByShootMode()
{
	bIsFireProcessActive = false;
	
	if (const TEnumAsByte<EShootMode>* CurrentShootMode =
		InitialWeaponSettings.ShootSettings.ShootModes.FindByKey(CurrentShootModeIndex); CurrentShootMode)
	{
		switch (CurrentShootMode->GetValue())
		{
			case ESM_Single:
				{
					bIsFireProcessHold = false;
					break;
				}
			
			case ESM_Semi:
				{
					if (CurrentSemiShootIndex <= InitialWeaponSettings.ShootSettings.SemiShootsCount)
					{
						CurrentSemiShootIndex++;
						IInteractibleWeaponInterface::Execute_OnFireStart(this);
					}
					else
					{
						CurrentSemiShootIndex = 0;
						bIsFireProcessHold = false;
					}
					
					break;
				}
			
			case ESM_FullAuto:
				{
					IInteractibleWeaponInterface::Execute_OnFireStart(this);
					break;
				}
		}
	}
}

void UShootComponentBase::ShootDataOperations()
{
	bIsFireProcessActive = true;
	if (--CurrentAmmoPerStore <= 0)
	{
		IInteractibleWeaponInterface::Execute_OnReload(this);
		return;
	}
}

void UShootComponentBase::OnReload_Implementation()
{
	bIsReloadProcessActive = true;
	bIsFireProcessHold = false;
	
	if (const UWorld* World = GetWorld(); IsValid(World))
	{
		OnAfterFireTimerHandle.Invalidate();
		
		World->GetTimerManager().SetTimer(
			OnReloadTimerHandle,
			FTimerDelegate::CreateWeakLambda(this, [this]
			{
				ReloadedDataOperations();
			}),
			InitialWeaponSettings.ShootSettings.ReloadTime,
			false);

		K2_OnReload();
	}
}

void UShootComponentBase::ReloadedDataOperations()
{
	bIsReloadProcessActive = false;
	bIsFireProcessActive = false;

	const int32 StoreSize = InitialWeaponSettings.ShootSettings.AmmoPerStore;
	const int32 AmmoDifference = StoreSize - CurrentAmmoPerStore;
	
	if (CurrentAmmo >= AmmoDifference)
	{
		CurrentAmmo -= AmmoDifference;
		CurrentAmmoPerStore = StoreSize;
	}
	else if (CurrentAmmo < AmmoDifference)
	{
		CurrentAmmoPerStore += CurrentAmmo;
		CurrentAmmo = 0;
	}
}

void UShootComponentBase::ToggleWeaponMode_Implementation()
{
	if (InitialWeaponSettings.ShootSettings.ShootModes.Num() <= 0)
	{
		CurrentShootModeIndex = 0;
		return;
	}
	
	CurrentShootModeIndex++;
	if (const TEnumAsByte<EShootMode>* NextShootMode =
		InitialWeaponSettings.ShootSettings.ShootModes.FindByKey(CurrentShootModeIndex); !NextShootMode)
	{
		CurrentShootModeIndex = 0;
	}
}

void UShootComponentBase::SetAimMode_Implementation(const bool bAim)
{
	bIsAim = bAim;
	K2_OnAimModeChanged(bIsAim);
}

bool UShootComponentBase::IsAimMode_Implementation()
{
	return bIsAim;
}

void UShootComponentBase::OnFireStop_Implementation()
{
	bIsFireProcessHold = false;
}

bool UShootComponentBase::IsReloading_Implementation()
{
	return bIsReloadProcessActive;
}

int32 UShootComponentBase::GetAmmo_Implementation()
{
	return CurrentAmmo;
}

void UShootComponentBase::SetAmmo_Implementation(const int32 InNewAmmoValue)
{
	CurrentAmmo = InNewAmmoValue;
}

void UShootComponentBase::AddAmmo_Implementation(const int32 InAmmoValue)
{
	CurrentAmmo += InAmmoValue;
}

int32 UShootComponentBase::GetAmmoPerStore_Implementation()
{
	return CurrentAmmoPerStore;
}
