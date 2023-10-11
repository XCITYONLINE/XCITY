// Fill out your copyright notice in the Description page of Project Settings.

#include "DataStructs/WeaponsDataStruct.h"

FShootSettingsDesc::FShootSettingsDesc()
{
	FireRate = 0.2f;
	ReloadTime = 3.0f;
	InitialAmmo = 20;
	AmmoPerStore = 8;
	bIsAutoFire = false;
	ShootModes.Add(EShootMode::ESM_Single);
	SemiShootsCount = 3;
}

FWeaponsDataStruct::FWeaponsDataStruct()
{
	WeaponMesh = nullptr;
	ShootComponentClass = nullptr;
	
	ShootSettings = FShootSettingsDesc();
}
