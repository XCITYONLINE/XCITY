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
	
	AmmoProjectileClass = nullptr;
	InitialShootSettings = FShootSettingsDesc();
}

void UShootComponentBase::Internal_Initialize_Implementation(
	const FWeaponsDataStruct& InInitialWeaponStruct, const bool bAlternative)
{
	InitialShootSettings = bAlternative
	? InInitialWeaponStruct.AlternativeShootSettings
	: InInitialWeaponStruct.MainShootSettings;
	
	CurrentAmmo = InitialShootSettings.InitialAmmo;
	CurrentAmmoPerStore = InitialShootSettings.AmmoPerStore;
	
	AmmoProjectileClass = bAlternative
	? InInitialWeaponStruct.AlternativeAmmoProjectileClass
	: InInitialWeaponStruct.MainAmmoProjectileClass;
}

void UShootComponentBase::OnFireStart_Implementation()
{
	bIsFireProcessHold = true;
	Internal_OnFireStart();
}

void UShootComponentBase::Internal_OnFireStart()
{
	if (!CheckPossibilityShot())
	{
		if (IInteractibleWeaponInterface::Execute_IsReloading(this) && OnReloadFireMiss.IsBound())
		{
			OnReloadFireMiss.Broadcast();
		}

		CurrentSemiShootIndex = 0;
		return;
	}

	AActor* OwnerActor = GetOwner();
	if (!IsValid(OwnerActor))
	{
		if (IInteractibleWeaponInterface::Execute_IsReloading(this) && OnReloadFireMiss.IsBound())
		{
			OnReloadFireMiss.Broadcast();
		}
		
		return;
	}

	if (OwnerActor->Implements<UInteractibleWeaponInterface>())
	{
		FTransform MuzzleSocketTransform = IInteractibleWeaponInterface::Execute_GetFireSocketTransform(
			OwnerActor,
			InitialShootSettings.FireSocketName);
		MuzzleSocketTransform.SetScale3D(FVector(1.0f, 1.0f, 1.0f));
		
		AAmmoProjectileBase* SpawnProjectile = GetWorld()->SpawnActorDeferred<AAmmoProjectileBase>(
			AmmoProjectileClass,
			MuzzleSocketTransform,
			GetOwner());

		if (!IsValid(SpawnProjectile))
		{
			return;
		}

		if (!SpawnProjectile->TryInitializeProjectile(InitialShootSettings.ProjectileSettings))
		{
			SpawnProjectile->Destroy();
			return;
		}

		SpawnProjectile->FinishSpawning(MuzzleSocketTransform);
		
		if (OnFire.IsBound())
		{
			OnFire.Broadcast();
		}
		
		OnAfterFireProcessStart();
		return;
	}

	if (OnReloadFireMiss.IsBound())
	{
		OnReloadFireMiss.Broadcast();
	}
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
			InitialShootSettings.FireRate,
			false);

		ShootDataOperations();
	}
}

void UShootComponentBase::FireProcessByShootMode()
{
	bIsFireProcessActive = false;

	if (CurrentShootModeIndex >= 0 && CurrentShootModeIndex < InitialShootSettings.ShootModes.Num())
	{
		if (const TEnumAsByte<EShootMode> CurrentShootMode =
			InitialShootSettings.ShootModes[CurrentShootModeIndex]; CurrentShootMode)
		{
			switch (CurrentShootMode.GetValue())
			{
			case ESM_Single:
				{
					bIsFireProcessHold = false;
					break;
				}
			
			case ESM_Semi:
				{
					if (CurrentSemiShootIndex < InitialShootSettings.SemiShootsCount - 1)
					{
						CurrentSemiShootIndex++;
						Internal_OnFireStart();
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
					Internal_OnFireStart();
					break;
				}
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
	if (!CheckPossibilityReload())
	{
		return;
	}
	
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
			InitialShootSettings.ReloadTime,
			false);

		if (OnReload.IsBound())
		{
			OnReload.Broadcast();
		}
	}
}

bool UShootComponentBase::CheckPossibilityReload() const
{
	return !(bIsReloadProcessActive || CurrentAmmoPerStore == InitialShootSettings.AmmoPerStore || CurrentAmmo == 0);
}

void UShootComponentBase::ReloadedDataOperations()
{
	bIsReloadProcessActive = false;
	bIsFireProcessActive = false;
	CurrentSemiShootIndex = 0;

	const int32 StoreSize = InitialShootSettings.AmmoPerStore;
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
	if (InitialShootSettings.ShootModes.Num() <= 0)
	{
		CurrentShootModeIndex = 0;
		return;
	}
	
	CurrentShootModeIndex++;
	if (const TEnumAsByte<EShootMode>* NextShootMode =
		InitialShootSettings.ShootModes.FindByKey(CurrentShootModeIndex); !NextShootMode)
	{
		CurrentShootModeIndex = 0;
	}
}

void UShootComponentBase::SetAimMode_Implementation(const bool bAim)
{
	bIsAim = bAim;
	if (OnAimModeChanged.IsBound())
	{
		OnAimModeChanged.Broadcast(bIsAim);
	}
}

bool UShootComponentBase::IsAimMode_Implementation()
{
	return bIsAim;
}

void UShootComponentBase::OnFireStop_Implementation()
{
	bIsFireProcessHold = false;
	CurrentSemiShootIndex = 0;
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
