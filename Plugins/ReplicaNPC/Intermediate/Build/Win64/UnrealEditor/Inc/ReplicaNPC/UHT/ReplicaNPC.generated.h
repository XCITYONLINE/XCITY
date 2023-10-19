// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ReplicaNPC.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UReplicaNPC;
#ifdef REPLICANPC_ReplicaNPC_generated_h
#error "ReplicaNPC.generated.h already included, missing '#pragma once' in ReplicaNPC.h"
#endif
#define REPLICANPC_ReplicaNPC_generated_h

#define FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_27_DELEGATE \
REPLICANPC_API void FOnNPCRequestCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnNPCRequestCompleted, const FString& Url, const FString& NewContext, TArray<FString> const& Timeline, TArray<FString> const& Phonemes, const FString& SubTitle, const FString& PlayerText, bool bSuccess);


#define FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_SPARSE_DATA
#define FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execReplica);


#define FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_ACCESSORS
#define FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUReplicaNPC(); \
	friend struct Z_Construct_UClass_UReplicaNPC_Statics; \
public: \
	DECLARE_CLASS(UReplicaNPC, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ReplicaNPC"), NO_API) \
	DECLARE_SERIALIZER(UReplicaNPC)


#define FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UReplicaNPC(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UReplicaNPC(UReplicaNPC&&); \
	NO_API UReplicaNPC(const UReplicaNPC&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UReplicaNPC); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UReplicaNPC); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UReplicaNPC) \
	NO_API virtual ~UReplicaNPC();


#define FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_68_PROLOG
#define FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_SPARSE_DATA \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_ACCESSORS \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_71_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REPLICANPC_API UClass* StaticClass<class UReplicaNPC>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_XCityNew_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h


#define FOREACH_ENUM_VOICES(op) \
	op(Vinnie) \
	op(Kaylee) \
	op(Nathan) \
	op(Olivia) 
#define FOREACH_ENUM_CURRENTSTYLES(op) \
	op(Serious) \
	op(Sassy) \
	op(Defeated) \
	op(Warm) 
#define FOREACH_ENUM_ELANGUAGEMODEL(op) \
	op(OpenAImodel) \
	op(HostedLLMmodel) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
