// Fill out your copyright notice in the Description page of Project Settings.

#include "Settings/WeaponSystemSettings.h"

UWeaponSystemSettings::UWeaponSystemSettings()
{
	WeaponDataTable = nullptr;
}

UWeaponSystemSettings* UWeaponSystemSettings::GetWeaponSystemSettings()
{
	return GetMutableDefault<UWeaponSystemSettings>();
}
