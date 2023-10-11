// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponComponents/ShootComponentBase.h"

UShootComponentBase::UShootComponentBase()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UShootComponentBase::Internal_Initialize_Implementation(const FWeaponsDataStruct& InInitialWeaponStruct)
{
	//ToDo: Initialize shoot params...
}

void UShootComponentBase::OnFireStart_Implementation()
{
	IInteractibleWeaponInterface::OnFireStart_Implementation();
}

void UShootComponentBase::OnFireStop_Implementation()
{
	IInteractibleWeaponInterface::OnFireStop_Implementation();
}

void UShootComponentBase::OnReload_Implementation()
{
	IInteractibleWeaponInterface::OnReload_Implementation();
}

bool UShootComponentBase::IsReloading_Implementation()
{
	return IInteractibleWeaponInterface::IsReloading_Implementation();
}

int UShootComponentBase::GetAmmo_Implementation()
{
	return IInteractibleWeaponInterface::GetAmmo_Implementation();
}

void UShootComponentBase::SetAmmo_Implementation(const int& InNewAmmoValue)
{
	IInteractibleWeaponInterface::SetAmmo_Implementation(InNewAmmoValue);
}

void UShootComponentBase::AddAmmo_Implementation(const int& InAmmoValue)
{
	IInteractibleWeaponInterface::AddAmmo_Implementation(InAmmoValue);
}
