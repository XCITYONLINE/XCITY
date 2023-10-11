// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WeaponActors/AmmoProjectileBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FHitResult;
#ifdef WEAPONSYSTEM_AmmoProjectileBase_generated_h
#error "AmmoProjectileBase.generated.h already included, missing '#pragma once' in AmmoProjectileBase.h"
#endif
#define WEAPONSYSTEM_AmmoProjectileBase_generated_h

#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_11_DELEGATE \
WEAPONSYSTEM_API void FOnProjectileHit_DelegateWrapper(const FMulticastScriptDelegate& OnProjectileHit, FHitResult const& Value);


#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_SPARSE_DATA
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_ACCESSORS
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_CALLBACK_WRAPPERS
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAmmoProjectileBase(); \
	friend struct Z_Construct_UClass_AAmmoProjectileBase_Statics; \
public: \
	DECLARE_CLASS(AAmmoProjectileBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WeaponSystem"), NO_API) \
	DECLARE_SERIALIZER(AAmmoProjectileBase)


#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAmmoProjectileBase(AAmmoProjectileBase&&); \
	NO_API AAmmoProjectileBase(const AAmmoProjectileBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAmmoProjectileBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAmmoProjectileBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAmmoProjectileBase) \
	NO_API virtual ~AAmmoProjectileBase();


#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_13_PROLOG
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_SPARSE_DATA \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_ACCESSORS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_CALLBACK_WRAPPERS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_INCLASS_NO_PURE_DECLS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WEAPONSYSTEM_API UClass* StaticClass<class AAmmoProjectileBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
