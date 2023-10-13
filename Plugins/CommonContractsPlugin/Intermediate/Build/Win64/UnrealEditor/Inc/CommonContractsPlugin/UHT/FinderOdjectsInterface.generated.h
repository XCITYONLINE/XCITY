// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Contracts/FinderOdjectsInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class IInteractibleItemInterface;
#ifdef COMMONCONTRACTSPLUGIN_FinderOdjectsInterface_generated_h
#error "FinderOdjectsInterface.generated.h already included, missing '#pragma once' in FinderOdjectsInterface.h"
#endif
#define COMMONCONTRACTSPLUGIN_FinderOdjectsInterface_generated_h

#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_SPARSE_DATA
#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool TryFindInteractibleObjects_Implementation(TArray<TScriptInterface<IInteractibleItemInterface> >& OutObjects) { return false; }; \
 \
	DECLARE_FUNCTION(execTryFindInteractibleObjects);


#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_ACCESSORS
#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_CALLBACK_WRAPPERS
#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	COMMONCONTRACTSPLUGIN_API UFinderObjectsInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	COMMONCONTRACTSPLUGIN_API UFinderObjectsInterface(UFinderObjectsInterface&&); \
	COMMONCONTRACTSPLUGIN_API UFinderObjectsInterface(const UFinderObjectsInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(COMMONCONTRACTSPLUGIN_API, UFinderObjectsInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFinderObjectsInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFinderObjectsInterface) \
	COMMONCONTRACTSPLUGIN_API virtual ~UFinderObjectsInterface();


#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUFinderObjectsInterface(); \
	friend struct Z_Construct_UClass_UFinderObjectsInterface_Statics; \
public: \
	DECLARE_CLASS(UFinderObjectsInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/CommonContractsPlugin"), COMMONCONTRACTSPLUGIN_API) \
	DECLARE_SERIALIZER(UFinderObjectsInterface)


#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_GENERATED_UINTERFACE_BODY() \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IFinderObjectsInterface() {} \
public: \
	typedef UFinderObjectsInterface UClassType; \
	typedef IFinderObjectsInterface ThisClass; \
	static bool Execute_TryFindInteractibleObjects(UObject* O, TArray<TScriptInterface<IInteractibleItemInterface> >& OutObjects); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_11_PROLOG
#define FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_SPARSE_DATA \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_ACCESSORS \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_CALLBACK_WRAPPERS \
	FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMMONCONTRACTSPLUGIN_API UClass* StaticClass<class UFinderObjectsInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
