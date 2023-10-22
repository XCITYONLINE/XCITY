// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "WeaponsDataStruct.generated.h"

UENUM(Blueprintable)
enum EShootMode : uint8
{
	ESM_None =     0		UMETA(Hidden),
	ESM_Single =   1 << 0	UMETA(DisplayName = "Single Shoot"),
	ESM_Semi =	   1 << 1	UMETA(DisplayName = "Semi Shoot"),
	ESM_FullAuto = 1 << 2	UMETA(DisplayName = "Full Auto Shoot"),
	ESM_MAX =      1 << 3	UMETA(Hidden)
};

UENUM(Blueprintable)
enum EWeaponType : uint8
{
	EWT_None =            0			UMETA(Hidden),
	EWT_Pistol =	      1 << 0	UMETA(DisplayName = "Pistol"),
	EWT_Rifle =			  1 << 1	UMETA(DisplayName = "Rifle"),
	EWT_CombatRifle =	  1 << 2	UMETA(DisplayName = "Combat Rifle"),
	EWT_Snipe =           1 << 3	UMETA(DisplayName = "Snipe"),
	EWT_Hand =			  1 << 4	UMETA(DisplayName = "Hand Item"),
	EWT_Shotgun =		  1 << 5	UMETA(DisplayName = "Shotgun"),
	EWT_GrenadeLauncher = 1 << 6	UMETA(DisplayName = "Grenade Launcher"),
	EWT_ThrowItem =		  1 << 7	UMETA(DisplayName = "Throw Item"),
	EWT_MAX =			  2 << 0	UMETA(Hidden)
};

USTRUCT(Blueprintable, BlueprintType)
struct WEAPONSYSTEM_API FProjectileSettings
{
	GENERATED_BODY()

public:

	FProjectileSettings()
	: Damage(0.0f), ProjectileInitialSpeed(0.0f), ProjectileMaxSpeed(0.0f), CollisionChannel(ECC_Visibility)
	{
	}

	bool IsValid() const
	{
		return !(Damage == 0.0f ||
			ProjectileInitialSpeed == 0.0f ||
			ProjectileMaxSpeed == 0.0f);
	}

	bool operator==(const FProjectileSettings& RValue) const
	{
		return Damage == RValue.Damage &&
			ProjectileInitialSpeed == RValue.ProjectileInitialSpeed &&
				ProjectileMaxSpeed == RValue.ProjectileMaxSpeed &&
					CollisionChannel == RValue.CollisionChannel;
	}

	FProjectileSettings& operator=(const FProjectileSettings& InDefinition)
	{
		if (this == &InDefinition) {
			return *this;
		}

		Damage = InDefinition.Damage;
		ProjectileInitialSpeed = InDefinition.ProjectileInitialSpeed;
		ProjectileMaxSpeed = InDefinition.ProjectileMaxSpeed;
		CollisionChannel = InDefinition.CollisionChannel;
		
		return *this;
	}

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile settings")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile settings")
	float ProjectileInitialSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile settings")
	float ProjectileMaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile settings")
	TEnumAsByte<ECollisionChannel> CollisionChannel;
};

USTRUCT(Blueprintable, BlueprintType)
struct WEAPONSYSTEM_API FShootSettingsDesc
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
	int32 InitialAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings")
	int32 AmmoPerStore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings")
	FName FireSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings")
	bool bAim;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings")
	TArray<TEnumAsByte<EShootMode>> ShootModes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category = "Shoot settings")
	int32 SemiShootsCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category = "Projectile settings")
	FProjectileSettings ProjectileSettings;
};

USTRUCT(Blueprintable, BlueprintType)
struct WEAPONSYSTEM_API FWeaponsDataStruct : public FTableRowBase
{
	GENERATED_BODY()

public:

	FWeaponsDataStruct();

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	class USkeletalMesh* WeaponSkeletal;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	class UStaticMesh* WeaponStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSubclassOf<UAnimInstance> WeaponAnimInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TObjectPtr<UTexture2D> WeaponIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TEnumAsByte<EWeaponType> WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	FVector AttachOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings")
	bool bUseAlternativeMode;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings|Main|Shoot Component Class")
	TSubclassOf<class UShootComponentBase> MainShootComponentClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings|Main|Ammo Actor Class")
	TSubclassOf<class AAmmoProjectileBase> MainAmmoProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings|Main|Shoot settings")
	FShootSettingsDesc MainShootSettings;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings|Alternative|Shoot Component Class",
		meta = (EditCondition = "bUseAlternativeMode", EditConditionHide))
	TSubclassOf<class UShootComponentBase> AlternativeShootComponentClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings|Alternative|Ammo Actor Class",
		meta = (EditCondition = "bUseAlternativeMode", EditConditionHide))
	TSubclassOf<class AAmmoProjectileBase> AlternativeAmmoProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot settings|Alternative|Shoot settings",
		meta = (EditCondition = "bUseAlternativeMode", EditConditionHide))
	FShootSettingsDesc AlternativeShootSettings;
};
