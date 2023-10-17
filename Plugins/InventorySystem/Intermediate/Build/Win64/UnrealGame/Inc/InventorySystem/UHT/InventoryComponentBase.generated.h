// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Conponents/InventoryComponentBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class IInteractibleItemInterface;
#ifdef INVENTORYSYSTEM_InventoryComponentBase_generated_h
#error "InventoryComponentBase.generated.h already included, missing '#pragma once' in InventoryComponentBase.h"
#endif
#define INVENTORYSYSTEM_InventoryComponentBase_generated_h

#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_12_DELEGATE \
INVENTORYSYSTEM_API void FOnInventorySizeChanged_DelegateWrapper(const FMulticastScriptDelegate& OnInventorySizeChanged, TArray<TScriptInterface<IInteractibleItemInterface> > const& Value);


#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_13_DELEGATE \
INVENTORYSYSTEM_API void FOnInventoryItemSelected_DelegateWrapper(const FMulticastScriptDelegate& OnInventoryItemSelected, TScriptInterface<IInteractibleItemInterface> const& Value);


#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_SPARSE_DATA
#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_ACCESSORS
#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryComponentBase(); \
	friend struct Z_Construct_UClass_UInventoryComponentBase_Statics; \
public: \
	DECLARE_CLASS(UInventoryComponentBase, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/InventorySystem"), NO_API) \
	DECLARE_SERIALIZER(UInventoryComponentBase) \
	virtual UObject* _getUObject() const override { return const_cast<UInventoryComponentBase*>(this); }


#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryComponentBase(UInventoryComponentBase&&); \
	NO_API UInventoryComponentBase(const UInventoryComponentBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryComponentBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryComponentBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UInventoryComponentBase) \
	NO_API virtual ~UInventoryComponentBase();


#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_15_PROLOG
#define FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_SPARSE_DATA \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_ACCESSORS \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_INCLASS_NO_PURE_DECLS \
	FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INVENTORYSYSTEM_API UClass* StaticClass<class UInventoryComponentBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
