// Fill out your copyright notice in the Description page of Project Settings.

#include "DataStructs/WeaponsDataStruct.h"

FShootSettingsDesc::FShootSettingsDesc()
{
	FireRate = 0.2f;
	ReloadTime = 3.0f;
	InitialAmmo = 20;
	AmmoPerStore = 8;
	FireSocketName = FName("Muzzle");
	ShootModes.Add(EShootMode::ESM_Single);
	SemiShootsCount = 3;
	bAim = false;
}

FWeaponsDataStruct::FWeaponsDataStruct()
{
	WeaponSkeletal = nullptr;
	WeaponAnimInstance = nullptr;
	MainShootComponentClass = nullptr;
	MainAmmoProjectileClass = nullptr;

	bUseAlternativeMode = false;
	
	MainShootSettings = FShootSettingsDesc();
	AlternativeShootSettings = FShootSettingsDesc();
}
