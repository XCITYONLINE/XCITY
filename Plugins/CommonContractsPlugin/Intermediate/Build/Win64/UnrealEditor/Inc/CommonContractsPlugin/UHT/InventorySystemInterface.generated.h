// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Contracts/InventorySystemInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class IInteractibleItemInterface;
#ifdef COMMONCONTRACTSPLUGIN_InventorySystemInterface_generated_h
#error "InventorySystemInterface.generated.h already included, missing '#pragma once' in InventorySystemInterface.h"
#endif
#define COMMONCONTRACTSPLUGIN_InventorySystemInterface_generated_h

#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_SPARSE_DATA
#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void RemoveInventoryItemByIndex_Implementation(const int32 InInventoryIndex) {}; \
	virtual void RemoveInventoryItem_Implementation(TScriptInterface<IInteractibleItemInterface>& InInventoryItem) {}; \
	virtual void SetInventoryItem_Implementation(TScriptInterface<IInteractibleItemInterface>& InInventoryItem, const int32 InInventoryIndex) {}; \
	virtual void AddInventoryItem_Implementation(TScriptInterface<IInteractibleItemInterface>& InNewInventoryItem) {}; \
	virtual void GetAllInventoryItems_Implementation(TArray<TScriptInterface<IInteractibleItemInterface> >& OutInventoryItems) {}; \
	virtual TScriptInterface<IInteractibleItemInterface> GetSelectedItem_Implementation() { return NULL; }; \
	virtual void UnselectItem_Implementation() {}; \
	virtual void OnBackwardItemChanged_Implementation() {}; \
	virtual void OnForwardItemChanged_Implementation() {}; \
	virtual void OnInitInventorySystem_Implementation() {}; \
 \
	DECLARE_FUNCTION(execRemoveInventoryItemByIndex); \
	DECLARE_FUNCTION(execRemoveInventoryItem); \
	DECLARE_FUNCTION(execSetInventoryItem); \
	DECLARE_FUNCTION(execAddInventoryItem); \
	DECLARE_FUNCTION(execGetAllInventoryItems); \
	DECLARE_FUNCTION(execGetSelectedItem); \
	DECLARE_FUNCTION(execUnselectItem); \
	DECLARE_FUNCTION(execOnBackwardItemChanged); \
	DECLARE_FUNCTION(execOnForwardItemChanged); \
	DECLARE_FUNCTION(execOnInitInventorySystem);


#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_ACCESSORS
#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_CALLBACK_WRAPPERS
#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	COMMONCONTRACTSPLUGIN_API UInventorySystemInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	COMMONCONTRACTSPLUGIN_API UInventorySystemInterface(UInventorySystemInterface&&); \
	COMMONCONTRACTSPLUGIN_API UInventorySystemInterface(const UInventorySystemInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(COMMONCONTRACTSPLUGIN_API, UInventorySystemInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventorySystemInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventorySystemInterface) \
	COMMONCONTRACTSPLUGIN_API virtual ~UInventorySystemInterface();


#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInventorySystemInterface(); \
	friend struct Z_Construct_UClass_UInventorySystemInterface_Statics; \
public: \
	DECLARE_CLASS(UInventorySystemInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/CommonContractsPlugin"), COMMONCONTRACTSPLUGIN_API) \
	DECLARE_SERIALIZER(UInventorySystemInterface)


#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_GENERATED_UINTERFACE_BODY() \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInventorySystemInterface() {} \
public: \
	typedef UInventorySystemInterface UClassType; \
	typedef IInventorySystemInterface ThisClass; \
	static void Execute_AddInventoryItem(UObject* O, TScriptInterface<IInteractibleItemInterface>& InNewInventoryItem); \
	static void Execute_GetAllInventoryItems(UObject* O, TArray<TScriptInterface<IInteractibleItemInterface> >& OutInventoryItems); \
	static TScriptInterface<IInteractibleItemInterface> Execute_GetSelectedItem(UObject* O); \
	static void Execute_OnBackwardItemChanged(UObject* O); \
	static void Execute_OnForwardItemChanged(UObject* O); \
	static void Execute_OnInitInventorySystem(UObject* O); \
	static void Execute_RemoveInventoryItem(UObject* O, TScriptInterface<IInteractibleItemInterface>& InInventoryItem); \
	static void Execute_RemoveInventoryItemByIndex(UObject* O, const int32 InInventoryIndex); \
	static void Execute_SetInventoryItem(UObject* O, TScriptInterface<IInteractibleItemInterface>& InInventoryItem, const int32 InInventoryIndex); \
	static void Execute_UnselectItem(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_11_PROLOG
#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_SPARSE_DATA \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_ACCESSORS \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_CALLBACK_WRAPPERS \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMMONCONTRACTSPLUGIN_API UClass* StaticClass<class UInventorySystemInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
