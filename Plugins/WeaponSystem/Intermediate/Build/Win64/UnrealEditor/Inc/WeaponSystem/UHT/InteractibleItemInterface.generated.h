// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Contracts/InteractibleItemInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WEAPONSYSTEM_InteractibleItemInterface_generated_h
#error "InteractibleItemInterface.generated.h already included, missing '#pragma once' in InteractibleItemInterface.h"
#endif
#define WEAPONSYSTEM_InteractibleItemInterface_generated_h

#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_SPARSE_DATA
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_ACCESSORS
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	WEAPONSYSTEM_API UInteractibleItemInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	WEAPONSYSTEM_API UInteractibleItemInterface(UInteractibleItemInterface&&); \
	WEAPONSYSTEM_API UInteractibleItemInterface(const UInteractibleItemInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(WEAPONSYSTEM_API, UInteractibleItemInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractibleItemInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractibleItemInterface) \
	WEAPONSYSTEM_API virtual ~UInteractibleItemInterface();


#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInteractibleItemInterface(); \
	friend struct Z_Construct_UClass_UInteractibleItemInterface_Statics; \
public: \
	DECLARE_CLASS(UInteractibleItemInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/WeaponSystem"), WEAPONSYSTEM_API) \
	DECLARE_SERIALIZER(UInteractibleItemInterface)


#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInteractibleItemInterface() {} \
public: \
	typedef UInteractibleItemInterface UClassType; \
	typedef IInteractibleItemInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_10_PROLOG
#define FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_SPARSE_DATA \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_ACCESSORS \
	FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WEAPONSYSTEM_API UClass* StaticClass<class UInteractibleItemInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
