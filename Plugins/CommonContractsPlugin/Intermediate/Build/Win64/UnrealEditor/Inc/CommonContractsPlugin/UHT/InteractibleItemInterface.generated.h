// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Contracts/InteractibleItemInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
#ifdef COMMONCONTRACTSPLUGIN_InteractibleItemInterface_generated_h
#error "InteractibleItemInterface.generated.h already included, missing '#pragma once' in InteractibleItemInterface.h"
#endif
#define COMMONCONTRACTSPLUGIN_InteractibleItemInterface_generated_h

#define FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_SPARSE_DATA
#define FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnItemSleep_Implementation(UPrimitiveComponent* SleepingComponent, FName BoneName) {}; \
	virtual void OnDrop_Implementation() {}; \
	virtual void OnUnselect_Implementation() {}; \
	virtual void OnTake_Implementation(AActor* OwnerActor) {}; \
	virtual void OnStopAlternativeInteract_Implementation() {}; \
	virtual void OnStartAlternativeInteract_Implementation() {}; \
	virtual void OnStopMainInteract_Implementation() {}; \
	virtual void OnStartMainInteract_Implementation() {}; \
	virtual void OnStopHover_Implementation() {}; \
	virtual void OnStartHover_Implementation() {}; \
 \
	DECLARE_FUNCTION(execOnItemSleep); \
	DECLARE_FUNCTION(execOnDrop); \
	DECLARE_FUNCTION(execOnUnselect); \
	DECLARE_FUNCTION(execOnTake); \
	DECLARE_FUNCTION(execOnStopAlternativeInteract); \
	DECLARE_FUNCTION(execOnStartAlternativeInteract); \
	DECLARE_FUNCTION(execOnStopMainInteract); \
	DECLARE_FUNCTION(execOnStartMainInteract); \
	DECLARE_FUNCTION(execOnStopHover); \
	DECLARE_FUNCTION(execOnStartHover);


#define FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_ACCESSORS
#define FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_CALLBACK_WRAPPERS
#define FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	COMMONCONTRACTSPLUGIN_API UInteractibleItemInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	COMMONCONTRACTSPLUGIN_API UInteractibleItemInterface(UInteractibleItemInterface&&); \
	COMMONCONTRACTSPLUGIN_API UInteractibleItemInterface(const UInteractibleItemInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(COMMONCONTRACTSPLUGIN_API, UInteractibleItemInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractibleItemInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractibleItemInterface) \
	COMMONCONTRACTSPLUGIN_API virtual ~UInteractibleItemInterface();


#define FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInteractibleItemInterface(); \
	friend struct Z_Construct_UClass_UInteractibleItemInterface_Statics; \
public: \
	DECLARE_CLASS(UInteractibleItemInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/CommonContractsPlugin"), COMMONCONTRACTSPLUGIN_API) \
	DECLARE_SERIALIZER(UInteractibleItemInterface)


#define FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInteractibleItemInterface() {} \
public: \
	typedef UInteractibleItemInterface UClassType; \
	typedef IInteractibleItemInterface ThisClass; \
	static void Execute_K2_OnAlternativeInteract(UObject* O, bool bIsInteract); \
	static void Execute_K2_OnDrop(UObject* O); \
	static void Execute_K2_OnHover(UObject* O, bool bIsHover); \
	static void Execute_K2_OnMainInteract(UObject* O, bool bIsInteract); \
	static void Execute_K2_OnTake(UObject* O); \
	static void Execute_K2_OnUnselect(UObject* O); \
	static void Execute_OnDrop(UObject* O); \
	static void Execute_OnItemSleep(UObject* O, UPrimitiveComponent* SleepingComponent, FName BoneName); \
	static void Execute_OnStartAlternativeInteract(UObject* O); \
	static void Execute_OnStartHover(UObject* O); \
	static void Execute_OnStartMainInteract(UObject* O); \
	static void Execute_OnStopAlternativeInteract(UObject* O); \
	static void Execute_OnStopHover(UObject* O); \
	static void Execute_OnStopMainInteract(UObject* O); \
	static void Execute_OnTake(UObject* O, AActor* OwnerActor); \
	static void Execute_OnUnselect(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_10_PROLOG
#define FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_SPARSE_DATA \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_ACCESSORS \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_CALLBACK_WRAPPERS \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMMONCONTRACTSPLUGIN_API UClass* StaticClass<class UInteractibleItemInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
