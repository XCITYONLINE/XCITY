// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "WeaponsDataStruct.generated.h"

UENUM(Blueprintable)
enum EShootMode : uint8
{
	ESM_None = 0			UMETA(Hidden),
	ESM_Single = 1 << 0		UMETA(DisplayName="Single Shoot"),
	ESM_Semi = 1 << 1		UMETA(DisplayName="Semi Shoot"),
	ESM_FullAuto = 1 << 2	UMETA(DisplayName="Full Auto Shoot"),
	ESM_MAX = 1 << 3		UMETA(Hidden)
};

USTRUCT(Blueprintable)
struct FShootSettingsDesc
{
	GENERATED_BODY()

public:
	
	FShootSettingsDesc();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings")
	float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings")
	float ReloadTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings")
	int InitialAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings")
	int AmmoPerStore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings")
	bool bIsAutoFire;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings")
	TArray<TEnumAsByte<EShootMode>> ShootModes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category = "Shoot settings")
	int SemiShootsCount;
};

USTRUCT()
struct WEAPONSYSTEM_API FWeaponsDataStruct : public FTableRowBase
{
	GENERATED_BODY()

public:

	FWeaponsDataStruct();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	class UStaticMesh* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot Component Class")
	TSubclassOf<class UShootComponentBase> ShootComponentClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot Component Class")
	TSubclassOf<class UShootComponentBase> ShootComponentClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings")
	FShootSettingsDesc ShootSettings;
};
