// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReplicaNPC/Public/ReplicaSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReplicaSettings() {}
// Cross Module References
	REPLICANPC_API UClass* Z_Construct_UClass_UReplicaSettings_NoRegister();
	REPLICANPC_API UClass* Z_Construct_UClass_UReplicaSettings();
	DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
	UPackage* Z_Construct_UPackage__Script_ReplicaNPC();
// End Cross Module References
	void UReplicaSettings::StaticRegisterNativesUReplicaSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UReplicaSettings);
	UClass* Z_Construct_UClass_UReplicaSettings_NoRegister()
	{
		return UReplicaSettings::StaticClass();
	}
	struct Z_Construct_UClass_UReplicaSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_API_Key_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_API_Key;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UReplicaSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_ReplicaNPC,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplicaSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "DisplayName", "Replica Settings" },
		{ "IncludePath", "ReplicaSettings.h" },
		{ "ModuleRelativePath", "Public/ReplicaSettings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplicaSettings_Statics::NewProp_API_Key_MetaData[] = {
		{ "Category", "Replica API key" },
		{ "ModuleRelativePath", "Public/ReplicaSettings.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UReplicaSettings_Statics::NewProp_API_Key = { "API_Key", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UReplicaSettings, API_Key), METADATA_PARAMS(Z_Construct_UClass_UReplicaSettings_Statics::NewProp_API_Key_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaSettings_Statics::NewProp_API_Key_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UReplicaSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReplicaSettings_Statics::NewProp_API_Key,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UReplicaSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UReplicaSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UReplicaSettings_Statics::ClassParams = {
		&UReplicaSettings::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UReplicaSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UReplicaSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UReplicaSettings()
	{
		if (!Z_Registration_Info_UClass_UReplicaSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UReplicaSettings.OuterSingleton, Z_Construct_UClass_UReplicaSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UReplicaSettings.OuterSingleton;
	}
	template<> REPLICANPC_API UClass* StaticClass<UReplicaSettings>()
	{
		return UReplicaSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UReplicaSettings);
	struct Z_CompiledInDeferFile_FID_ReplicaSample_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ReplicaSample_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UReplicaSettings, UReplicaSettings::StaticClass, TEXT("UReplicaSettings"), &Z_Registration_Info_UClass_UReplicaSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UReplicaSettings), 3167336649U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ReplicaSample_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaSettings_h_1886021577(TEXT("/Script/ReplicaNPC"),
		Z_CompiledInDeferFile_FID_ReplicaSample_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ReplicaSample_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
