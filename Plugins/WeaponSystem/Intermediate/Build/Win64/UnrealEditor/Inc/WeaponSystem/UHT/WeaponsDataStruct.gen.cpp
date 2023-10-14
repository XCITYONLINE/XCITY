// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponSystem/Public/DataStructs/WeaponsDataStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWeaponsDataStruct() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	UPackage* Z_Construct_UPackage__Script_WeaponSystem();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_AAmmoProjectileBase_NoRegister();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UShootComponentBase_NoRegister();
	WEAPONSYSTEM_API UEnum* Z_Construct_UEnum_WeaponSystem_EShootMode();
	WEAPONSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FProjectileSettings();
	WEAPONSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FShootSettingsDesc();
	WEAPONSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FWeaponsDataStruct();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EShootMode;
	static UEnum* EShootMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EShootMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EShootMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_WeaponSystem_EShootMode, (UObject*)Z_Construct_UPackage__Script_WeaponSystem(), TEXT("EShootMode"));
		}
		return Z_Registration_Info_UEnum_EShootMode.OuterSingleton;
	}
	template<> WEAPONSYSTEM_API UEnum* StaticEnum<EShootMode>()
	{
		return EShootMode_StaticEnum();
	}
	struct Z_Construct_UEnum_WeaponSystem_EShootMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_WeaponSystem_EShootMode_Statics::Enumerators[] = {
		{ "ESM_None", (int64)ESM_None },
		{ "ESM_Single", (int64)ESM_Single },
		{ "ESM_Semi", (int64)ESM_Semi },
		{ "ESM_FullAuto", (int64)ESM_FullAuto },
		{ "ESM_MAX", (int64)ESM_MAX },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_WeaponSystem_EShootMode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ESM_FullAuto.DisplayName", "Full Auto Shoot" },
		{ "ESM_FullAuto.Name", "ESM_FullAuto" },
		{ "ESM_MAX.Hidden", "" },
		{ "ESM_MAX.Name", "ESM_MAX" },
		{ "ESM_None.Hidden", "" },
		{ "ESM_None.Name", "ESM_None" },
		{ "ESM_Semi.DisplayName", "Semi Shoot" },
		{ "ESM_Semi.Name", "ESM_Semi" },
		{ "ESM_Single.DisplayName", "Single Shoot" },
		{ "ESM_Single.Name", "ESM_Single" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_WeaponSystem_EShootMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_WeaponSystem,
		nullptr,
		"EShootMode",
		"EShootMode",
		Z_Construct_UEnum_WeaponSystem_EShootMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_WeaponSystem_EShootMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_WeaponSystem_EShootMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_WeaponSystem_EShootMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_WeaponSystem_EShootMode()
	{
		if (!Z_Registration_Info_UEnum_EShootMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EShootMode.InnerSingleton, Z_Construct_UEnum_WeaponSystem_EShootMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EShootMode.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ProjectileSettings;
class UScriptStruct* FProjectileSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ProjectileSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ProjectileSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FProjectileSettings, (UObject*)Z_Construct_UPackage__Script_WeaponSystem(), TEXT("ProjectileSettings"));
	}
	return Z_Registration_Info_UScriptStruct_ProjectileSettings.OuterSingleton;
}
template<> WEAPONSYSTEM_API UScriptStruct* StaticStruct<FProjectileSettings>()
{
	return FProjectileSettings::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FProjectileSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileInitialSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileInitialSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileMaxSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileMaxSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CollisionChannel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_CollisionChannel;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProjectileSettings_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FProjectileSettings>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_Damage_MetaData[] = {
		{ "Category", "Projectile settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FProjectileSettings, Damage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_Damage_MetaData), Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_Damage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_ProjectileInitialSpeed_MetaData[] = {
		{ "Category", "Projectile settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_ProjectileInitialSpeed = { "ProjectileInitialSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FProjectileSettings, ProjectileInitialSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_ProjectileInitialSpeed_MetaData), Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_ProjectileInitialSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_ProjectileMaxSpeed_MetaData[] = {
		{ "Category", "Projectile settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_ProjectileMaxSpeed = { "ProjectileMaxSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FProjectileSettings, ProjectileMaxSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_ProjectileMaxSpeed_MetaData), Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_ProjectileMaxSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_CollisionChannel_MetaData[] = {
		{ "Category", "Projectile settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_CollisionChannel = { "CollisionChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FProjectileSettings, CollisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_CollisionChannel_MetaData), Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_CollisionChannel_MetaData) }; // 1822723181
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FProjectileSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_Damage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_ProjectileInitialSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_ProjectileMaxSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewProp_CollisionChannel,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FProjectileSettings_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_WeaponSystem,
		nullptr,
		&NewStructOps,
		"ProjectileSettings",
		Z_Construct_UScriptStruct_FProjectileSettings_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileSettings_Statics::PropPointers),
		sizeof(FProjectileSettings),
		alignof(FProjectileSettings),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FProjectileSettings_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileSettings_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FProjectileSettings()
	{
		if (!Z_Registration_Info_UScriptStruct_ProjectileSettings.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ProjectileSettings.InnerSingleton, Z_Construct_UScriptStruct_FProjectileSettings_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ProjectileSettings.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ShootSettingsDesc;
class UScriptStruct* FShootSettingsDesc::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ShootSettingsDesc.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ShootSettingsDesc.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FShootSettingsDesc, (UObject*)Z_Construct_UPackage__Script_WeaponSystem(), TEXT("ShootSettingsDesc"));
	}
	return Z_Registration_Info_UScriptStruct_ShootSettingsDesc.OuterSingleton;
}
template<> WEAPONSYSTEM_API UScriptStruct* StaticStruct<FShootSettingsDesc>()
{
	return FShootSettingsDesc::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FShootSettingsDesc_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FireRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FireRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReloadTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReloadTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InitialAmmo_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_InitialAmmo;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AmmoPerStore_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_AmmoPerStore;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FireSocketName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_FireSocketName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAim_MetaData[];
#endif
		static void NewProp_bAim_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAim;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ShootModes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShootModes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ShootModes;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SemiShootsCount_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_SemiShootsCount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ProjectileSettings;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FShootSettingsDesc>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_FireRate_MetaData[] = {
		{ "Category", "Shoot settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_FireRate = { "FireRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FShootSettingsDesc, FireRate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_FireRate_MetaData), Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_FireRate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ReloadTime_MetaData[] = {
		{ "Category", "Shoot settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ReloadTime = { "ReloadTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FShootSettingsDesc, ReloadTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ReloadTime_MetaData), Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ReloadTime_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_InitialAmmo_MetaData[] = {
		{ "Category", "Shoot settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_InitialAmmo = { "InitialAmmo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FShootSettingsDesc, InitialAmmo), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_InitialAmmo_MetaData), Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_InitialAmmo_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_AmmoPerStore_MetaData[] = {
		{ "Category", "Shoot settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_AmmoPerStore = { "AmmoPerStore", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FShootSettingsDesc, AmmoPerStore), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_AmmoPerStore_MetaData), Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_AmmoPerStore_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_FireSocketName_MetaData[] = {
		{ "Category", "Shoot settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_FireSocketName = { "FireSocketName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FShootSettingsDesc, FireSocketName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_FireSocketName_MetaData), Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_FireSocketName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_bAim_MetaData[] = {
		{ "Category", "Shoot settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_bAim_SetBit(void* Obj)
	{
		((FShootSettingsDesc*)Obj)->bAim = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_bAim = { "bAim", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FShootSettingsDesc), &Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_bAim_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_bAim_MetaData), Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_bAim_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ShootModes_Inner = { "ShootModes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_WeaponSystem_EShootMode, METADATA_PARAMS(0, nullptr) }; // 3046783219
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ShootModes_MetaData[] = {
		{ "Category", "Shoot settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ShootModes = { "ShootModes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FShootSettingsDesc, ShootModes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ShootModes_MetaData), Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ShootModes_MetaData) }; // 3046783219
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_SemiShootsCount_MetaData[] = {
		{ "Category", "Shoot settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_SemiShootsCount = { "SemiShootsCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FShootSettingsDesc, SemiShootsCount), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_SemiShootsCount_MetaData), Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_SemiShootsCount_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ProjectileSettings_MetaData[] = {
		{ "Category", "Projectile settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ProjectileSettings = { "ProjectileSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FShootSettingsDesc, ProjectileSettings), Z_Construct_UScriptStruct_FProjectileSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ProjectileSettings_MetaData), Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ProjectileSettings_MetaData) }; // 1667832687
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_FireRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ReloadTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_InitialAmmo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_AmmoPerStore,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_FireSocketName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_bAim,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ShootModes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ShootModes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_SemiShootsCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewProp_ProjectileSettings,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_WeaponSystem,
		nullptr,
		&NewStructOps,
		"ShootSettingsDesc",
		Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::PropPointers),
		sizeof(FShootSettingsDesc),
		alignof(FShootSettingsDesc),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FShootSettingsDesc()
	{
		if (!Z_Registration_Info_UScriptStruct_ShootSettingsDesc.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ShootSettingsDesc.InnerSingleton, Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ShootSettingsDesc.InnerSingleton;
	}

static_assert(std::is_polymorphic<FWeaponsDataStruct>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FWeaponsDataStruct cannot be polymorphic unless super FTableRowBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_WeaponsDataStruct;
class UScriptStruct* FWeaponsDataStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_WeaponsDataStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_WeaponsDataStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FWeaponsDataStruct, (UObject*)Z_Construct_UPackage__Script_WeaponSystem(), TEXT("WeaponsDataStruct"));
	}
	return Z_Registration_Info_UScriptStruct_WeaponsDataStruct.OuterSingleton;
}
template<> WEAPONSYSTEM_API UScriptStruct* StaticStruct<FWeaponsDataStruct>()
{
	return FWeaponsDataStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponSkeletal_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponSkeletal;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponAnimInstance_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_WeaponAnimInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseAlternativeMode_MetaData[];
#endif
		static void NewProp_bUseAlternativeMode_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseAlternativeMode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MainShootComponentClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_MainShootComponentClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MainAmmoProjectileClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_MainAmmoProjectileClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MainShootSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MainShootSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AlternativeShootComponentClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_AlternativeShootComponentClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AlternativeAmmoProjectileClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_AlternativeAmmoProjectileClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AlternativeShootSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AlternativeShootSettings;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FWeaponsDataStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_WeaponSkeletal_MetaData[] = {
		{ "Category", "Visual" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_WeaponSkeletal = { "WeaponSkeletal", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponsDataStruct, WeaponSkeletal), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_WeaponSkeletal_MetaData), Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_WeaponSkeletal_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_WeaponAnimInstance_MetaData[] = {
		{ "Category", "Visual" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_WeaponAnimInstance = { "WeaponAnimInstance", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponsDataStruct, WeaponAnimInstance), Z_Construct_UClass_UClass, Z_Construct_UClass_UAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_WeaponAnimInstance_MetaData), Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_WeaponAnimInstance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_bUseAlternativeMode_MetaData[] = {
		{ "Category", "Shoot settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_bUseAlternativeMode_SetBit(void* Obj)
	{
		((FWeaponsDataStruct*)Obj)->bUseAlternativeMode = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_bUseAlternativeMode = { "bUseAlternativeMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FWeaponsDataStruct), &Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_bUseAlternativeMode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_bUseAlternativeMode_MetaData), Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_bUseAlternativeMode_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainShootComponentClass_MetaData[] = {
		{ "Category", "Shoot settings|Main|Shoot Component Class" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainShootComponentClass = { "MainShootComponentClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponsDataStruct, MainShootComponentClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UShootComponentBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainShootComponentClass_MetaData), Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainShootComponentClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainAmmoProjectileClass_MetaData[] = {
		{ "Category", "Shoot settings|Main|Ammo Actor Class" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainAmmoProjectileClass = { "MainAmmoProjectileClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponsDataStruct, MainAmmoProjectileClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AAmmoProjectileBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainAmmoProjectileClass_MetaData), Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainAmmoProjectileClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainShootSettings_MetaData[] = {
		{ "Category", "Shoot settings|Main|Shoot settings" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainShootSettings = { "MainShootSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponsDataStruct, MainShootSettings), Z_Construct_UScriptStruct_FShootSettingsDesc, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainShootSettings_MetaData), Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainShootSettings_MetaData) }; // 1850942594
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeShootComponentClass_MetaData[] = {
		{ "Category", "Shoot settings|Alternative|Shoot Component Class" },
		{ "EditCondition", "bUseAlternativeMode" },
		{ "EditConditionHide", "" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeShootComponentClass = { "AlternativeShootComponentClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponsDataStruct, AlternativeShootComponentClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UShootComponentBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeShootComponentClass_MetaData), Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeShootComponentClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeAmmoProjectileClass_MetaData[] = {
		{ "Category", "Shoot settings|Alternative|Ammo Actor Class" },
		{ "EditCondition", "bUseAlternativeMode" },
		{ "EditConditionHide", "" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeAmmoProjectileClass = { "AlternativeAmmoProjectileClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponsDataStruct, AlternativeAmmoProjectileClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AAmmoProjectileBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeAmmoProjectileClass_MetaData), Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeAmmoProjectileClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeShootSettings_MetaData[] = {
		{ "Category", "Shoot settings|Alternative|Shoot settings" },
		{ "EditCondition", "bUseAlternativeMode" },
		{ "EditConditionHide", "" },
		{ "ModuleRelativePath", "Public/DataStructs/WeaponsDataStruct.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeShootSettings = { "AlternativeShootSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponsDataStruct, AlternativeShootSettings), Z_Construct_UScriptStruct_FShootSettingsDesc, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeShootSettings_MetaData), Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeShootSettings_MetaData) }; // 1850942594
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_WeaponSkeletal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_WeaponAnimInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_bUseAlternativeMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainShootComponentClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainAmmoProjectileClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_MainShootSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeShootComponentClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeAmmoProjectileClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewProp_AlternativeShootSettings,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_WeaponSystem,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"WeaponsDataStruct",
		Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::PropPointers),
		sizeof(FWeaponsDataStruct),
		alignof(FWeaponsDataStruct),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FWeaponsDataStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_WeaponsDataStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_WeaponsDataStruct.InnerSingleton, Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_WeaponsDataStruct.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_DataStructs_WeaponsDataStruct_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_DataStructs_WeaponsDataStruct_h_Statics::EnumInfo[] = {
		{ EShootMode_StaticEnum, TEXT("EShootMode"), &Z_Registration_Info_UEnum_EShootMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3046783219U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_DataStructs_WeaponsDataStruct_h_Statics::ScriptStructInfo[] = {
		{ FProjectileSettings::StaticStruct, Z_Construct_UScriptStruct_FProjectileSettings_Statics::NewStructOps, TEXT("ProjectileSettings"), &Z_Registration_Info_UScriptStruct_ProjectileSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FProjectileSettings), 1667832687U) },
		{ FShootSettingsDesc::StaticStruct, Z_Construct_UScriptStruct_FShootSettingsDesc_Statics::NewStructOps, TEXT("ShootSettingsDesc"), &Z_Registration_Info_UScriptStruct_ShootSettingsDesc, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FShootSettingsDesc), 1850942594U) },
		{ FWeaponsDataStruct::StaticStruct, Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics::NewStructOps, TEXT("WeaponsDataStruct"), &Z_Registration_Info_UScriptStruct_WeaponsDataStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FWeaponsDataStruct), 1991016369U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_DataStructs_WeaponsDataStruct_h_31639614(TEXT("/Script/WeaponSystem"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_DataStructs_WeaponsDataStruct_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_DataStructs_WeaponsDataStruct_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_DataStructs_WeaponsDataStruct_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_DataStructs_WeaponsDataStruct_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
