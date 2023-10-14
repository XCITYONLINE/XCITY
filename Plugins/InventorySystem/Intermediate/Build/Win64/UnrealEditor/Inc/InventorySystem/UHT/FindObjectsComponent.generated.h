// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Conponents/FindObjectsComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef INVENTORYSYSTEM_FindObjectsComponent_generated_h
#error "FindObjectsComponent.generated.h already included, missing '#pragma once' in FindObjectsComponent.h"
#endif
#define INVENTORYSYSTEM_FindObjectsComponent_generated_h

#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_SPARSE_DATA
#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_ACCESSORS
#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFindObjectsComponent(); \
	friend struct Z_Construct_UClass_UFindObjectsComponent_Statics; \
public: \
	DECLARE_CLASS(UFindObjectsComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/InventorySystem"), NO_API) \
	DECLARE_SERIALIZER(UFindObjectsComponent) \
	virtual UObject* _getUObject() const override { return const_cast<UFindObjectsComponent*>(this); }


#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFindObjectsComponent(UFindObjectsComponent&&); \
	NO_API UFindObjectsComponent(const UFindObjectsComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFindObjectsComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFindObjectsComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UFindObjectsComponent) \
	NO_API virtual ~UFindObjectsComponent();


#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_20_PROLOG
#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_SPARSE_DATA \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_ACCESSORS \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_INCLASS_NO_PURE_DECLS \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INVENTORYSYSTEM_API UClass* StaticClass<class UFindObjectsComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h


#define FOREACH_ENUM_EFINDERTRACEMODE(op) \
	op(FTM_None) \
	op(FTM_MultiSphereAround) \
	op(FTM_SingleLineTrace) \
	op(FTM_Max) 

enum EFinderTraceMode : uint8;
template<> INVENTORYSYSTEM_API UEnum* StaticEnum<EFinderTraceMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
