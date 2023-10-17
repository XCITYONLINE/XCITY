// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WeaponComponents/ShootComponentBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WEAPONSYSTEM_ShootComponentBase_generated_h
#error "ShootComponentBase.generated.h already included, missing '#pragma once' in ShootComponentBase.h"
#endif
#define WEAPONSYSTEM_ShootComponentBase_generated_h

#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_12_DELEGATE \
WEAPONSYSTEM_API void FOnReload_DelegateWrapper(const FMulticastScriptDelegate& OnReload);


#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_13_DELEGATE \
WEAPONSYSTEM_API void FOnFire_DelegateWrapper(const FMulticastScriptDelegate& OnFire);


#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_14_DELEGATE \
WEAPONSYSTEM_API void FOnReloadFireMiss_DelegateWrapper(const FMulticastScriptDelegate& OnReloadFireMiss);


#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_15_DELEGATE \
WEAPONSYSTEM_API void FOnAimModeChanged_DelegateWrapper(const FMulticastScriptDelegate& OnAimModeChanged, bool Value);


#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_SPARSE_DATA
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_ACCESSORS
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUShootComponentBase(); \
	friend struct Z_Construct_UClass_UShootComponentBase_Statics; \
public: \
	DECLARE_CLASS(UShootComponentBase, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WeaponSystem"), NO_API) \
	DECLARE_SERIALIZER(UShootComponentBase) \
	virtual UObject* _getUObject() const override { return const_cast<UShootComponentBase*>(this); }


#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UShootComponentBase(UShootComponentBase&&); \
	NO_API UShootComponentBase(const UShootComponentBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UShootComponentBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UShootComponentBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UShootComponentBase) \
	NO_API virtual ~UShootComponentBase();


#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_17_PROLOG
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_SPARSE_DATA \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_ACCESSORS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_INCLASS_NO_PURE_DECLS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WEAPONSYSTEM_API UClass* StaticClass<class UShootComponentBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
