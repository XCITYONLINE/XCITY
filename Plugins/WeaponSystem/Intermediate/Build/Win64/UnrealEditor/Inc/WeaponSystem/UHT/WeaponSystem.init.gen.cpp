// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWeaponSystem_init() {}
	WEAPONSYSTEM_API UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature();
	WEAPONSYSTEM_API UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_WeaponSystem;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_WeaponSystem()
	{
		if (!Z_Registration_Info_UPackage__Script_WeaponSystem.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/WeaponSystem",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x6B5996FC,
				0x38BCD22B,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_WeaponSystem.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_WeaponSystem.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_WeaponSystem(Z_Construct_UPackage__Script_WeaponSystem, TEXT("/Script/WeaponSystem"), Z_Registration_Info_UPackage__Script_WeaponSystem, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x6B5996FC, 0x38BCD22B));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
