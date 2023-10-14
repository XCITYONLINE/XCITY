// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DataStructs/WeaponsDataStruct.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WEAPONSYSTEM_WeaponsDataStruct_generated_h
#error "WeaponsDataStruct.generated.h already included, missing '#pragma once' in WeaponsDataStruct.h"
#endif
#define WEAPONSYSTEM_WeaponsDataStruct_generated_h

#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_DataStructs_WeaponsDataStruct_h_23_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FProjectileSettings_Statics; \
	static class UScriptStruct* StaticStruct();


template<> WEAPONSYSTEM_API UScriptStruct* StaticStruct<struct FProjectileSettings>();

#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_DataStructs_WeaponsDataStruct_h_79_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FShootSettingsDesc_Statics; \
	static class UScriptStruct* StaticStruct();


template<> WEAPONSYSTEM_API UScriptStruct* StaticStruct<struct FShootSettingsDesc>();

#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_DataStructs_WeaponsDataStruct_h_118_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FWeaponsDataStruct_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> WEAPONSYSTEM_API UScriptStruct* StaticStruct<struct FWeaponsDataStruct>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_DataStructs_WeaponsDataStruct_h


#define FOREACH_ENUM_ESHOOTMODE(op) \
	op(ESM_Single) \
	op(ESM_Semi) \
	op(ESM_FullAuto) \
	op(ESM_MAX) 

enum EShootMode : uint8;
template<> WEAPONSYSTEM_API UEnum* StaticEnum<EShootMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
