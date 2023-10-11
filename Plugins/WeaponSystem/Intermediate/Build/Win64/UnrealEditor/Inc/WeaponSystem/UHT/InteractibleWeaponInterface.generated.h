// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Contracts/InteractibleWeaponInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FWeaponsDataStruct;
#ifdef WEAPONSYSTEM_InteractibleWeaponInterface_generated_h
#error "InteractibleWeaponInterface.generated.h already included, missing '#pragma once' in InteractibleWeaponInterface.h"
#endif
#define WEAPONSYSTEM_InteractibleWeaponInterface_generated_h

#define FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_SPARSE_DATA
#define FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Internal_Initialize_Implementation(FWeaponsDataStruct const& InInitialWeaponStruct) {}; \
	virtual void AddAmmo_Implementation(const int32 InAmmoValue) {}; \
	virtual void SetAmmo_Implementation(const int32 InNewAmmoValue) {}; \
	virtual int32 GetAmmo_Implementation() { return 0; }; \
	virtual void InitializeWeapon_Implementation() {}; \
	virtual bool IsReloading_Implementation() { return false; }; \
	virtual void OnReload_Implementation() {}; \
	virtual void OnFireStop_Implementation() {}; \
	virtual void OnFireStart_Implementation() {}; \
 \
	DECLARE_FUNCTION(execInternal_Initialize); \
	DECLARE_FUNCTION(execAddAmmo); \
	DECLARE_FUNCTION(execSetAmmo); \
	DECLARE_FUNCTION(execGetAmmo); \
	DECLARE_FUNCTION(execInitializeWeapon); \
	DECLARE_FUNCTION(execIsReloading); \
	DECLARE_FUNCTION(execOnReload); \
	DECLARE_FUNCTION(execOnFireStop); \
	DECLARE_FUNCTION(execOnFireStart);


#define FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_ACCESSORS
#define FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_CALLBACK_WRAPPERS
#define FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	WEAPONSYSTEM_API UInteractibleWeaponInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	WEAPONSYSTEM_API UInteractibleWeaponInterface(UInteractibleWeaponInterface&&); \
	WEAPONSYSTEM_API UInteractibleWeaponInterface(const UInteractibleWeaponInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(WEAPONSYSTEM_API, UInteractibleWeaponInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractibleWeaponInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractibleWeaponInterface) \
	WEAPONSYSTEM_API virtual ~UInteractibleWeaponInterface();


#define FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInteractibleWeaponInterface(); \
	friend struct Z_Construct_UClass_UInteractibleWeaponInterface_Statics; \
public: \
	DECLARE_CLASS(UInteractibleWeaponInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/WeaponSystem"), WEAPONSYSTEM_API) \
	DECLARE_SERIALIZER(UInteractibleWeaponInterface)


#define FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_GENERATED_UINTERFACE_BODY() \
	FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInteractibleWeaponInterface() {} \
public: \
	typedef UInteractibleWeaponInterface UClassType; \
	typedef IInteractibleWeaponInterface ThisClass; \
	static void Execute_AddAmmo(UObject* O, const int32 InAmmoValue); \
	static int32 Execute_GetAmmo(UObject* O); \
	static void Execute_InitializeWeapon(UObject* O); \
	static void Execute_Internal_Initialize(UObject* O, FWeaponsDataStruct const& InInitialWeaponStruct); \
	static bool Execute_IsReloading(UObject* O); \
	static void Execute_OnFireStart(UObject* O); \
	static void Execute_OnFireStop(UObject* O); \
	static void Execute_OnReload(UObject* O); \
	static void Execute_SetAmmo(UObject* O, const int32 InNewAmmoValue); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_11_PROLOG
#define FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_SPARSE_DATA \
	FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_ACCESSORS \
	FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_CALLBACK_WRAPPERS \
	FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WEAPONSYSTEM_API UClass* StaticClass<class UInteractibleWeaponInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
