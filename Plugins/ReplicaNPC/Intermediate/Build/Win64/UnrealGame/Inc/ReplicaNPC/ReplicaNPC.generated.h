// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UReplicaNPC;
#ifdef REPLICANPC_ReplicaNPC_generated_h
#error "ReplicaNPC.generated.h already included, missing '#pragma once' in ReplicaNPC.h"
#endif
#define REPLICANPC_ReplicaNPC_generated_h

#define FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_25_DELEGATE \
struct _Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms \
{ \
	FString Url; \
	FString NewContext; \
	TArray<FString> Timeline; \
	TArray<FString> Phonemes; \
	FString SubTitle; \
	FString PlayerText; \
	bool bSuccess; \
}; \
static inline void FOnNPCRequestCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnNPCRequestCompleted, const FString& Url, const FString& NewContext, TArray<FString> const& Timeline, TArray<FString> const& Phonemes, const FString& SubTitle, const FString& PlayerText, bool bSuccess) \
{ \
	_Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms Parms; \
	Parms.Url=Url; \
	Parms.NewContext=NewContext; \
	Parms.Timeline=Timeline; \
	Parms.Phonemes=Phonemes; \
	Parms.SubTitle=SubTitle; \
	Parms.PlayerText=PlayerText; \
	Parms.bSuccess=bSuccess ? true : false; \
	OnNPCRequestCompleted.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_SPARSE_DATA
#define FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execReplica);


#define FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execReplica);


#define FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUReplicaNPC(); \
	friend struct Z_Construct_UClass_UReplicaNPC_Statics; \
public: \
	DECLARE_CLASS(UReplicaNPC, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ReplicaNPC"), NO_API) \
	DECLARE_SERIALIZER(UReplicaNPC)


#define FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_INCLASS \
private: \
	static void StaticRegisterNativesUReplicaNPC(); \
	friend struct Z_Construct_UClass_UReplicaNPC_Statics; \
public: \
	DECLARE_CLASS(UReplicaNPC, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ReplicaNPC"), NO_API) \
	DECLARE_SERIALIZER(UReplicaNPC)


#define FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UReplicaNPC(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UReplicaNPC) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UReplicaNPC); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UReplicaNPC); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UReplicaNPC(UReplicaNPC&&); \
	NO_API UReplicaNPC(const UReplicaNPC&); \
public:


#define FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UReplicaNPC(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UReplicaNPC(UReplicaNPC&&); \
	NO_API UReplicaNPC(const UReplicaNPC&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UReplicaNPC); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UReplicaNPC); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UReplicaNPC)


#define FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_77_PROLOG
#define FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_SPARSE_DATA \
	FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_RPC_WRAPPERS \
	FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_INCLASS \
	FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_SPARSE_DATA \
	FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_INCLASS_NO_PURE_DECLS \
	FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_80_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REPLICANPC_API UClass* StaticClass<class UReplicaNPC>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_replica_npc_unreal_demo_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h


#define FOREACH_ENUM_VOICES(op) \
	op(Amber) \
	op(Ava) \
	op(Deckard) \
	op(Freya) \
	op(Lilith) \
	op(Stone) \
	op(Trey) \
	op(Xander) \
	op(Gar) \
	op(Pimento) \
	op(PinkDragon) 
#define FOREACH_ENUM_CURRENTSTYLES(op) \
	op(Serious) \
	op(Lighthearted) \
	op(Neutral) \
	op(Polite) \
	op(Seductive) \
	op(Default) \
	op(Taunting) \
	op(Conversational) \
	op(Scared) \
	op(Upset) \
	op(Angry) \
	op(Happy) \
	op(Sad) \
	op(Excited) \
	op(Sleepy) \
	op(Melancholy) \
	op(Apathetic) \
	op(Jovial) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
