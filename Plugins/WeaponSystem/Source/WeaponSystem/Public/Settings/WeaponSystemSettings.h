// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"

#include "WeaponSystemSettings.generated.h"

UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "Weapon settings"))
class WEAPONSYSTEM_API UWeaponSystemSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	UWeaponSystemSettings();
	static UWeaponSystemSettings* GetWeaponSystemSettings();

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Weapons data table")
	TSoftObjectPtr<class UDataTable> WeaponDataTable;
};
