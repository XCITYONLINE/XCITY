// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponSystem/Public/Settings/WeaponSystemSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWeaponSystemSettings() {}
// Cross Module References
	DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
	ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
	UPackage* Z_Construct_UPackage__Script_WeaponSystem();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UWeaponSystemSettings();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UWeaponSystemSettings_NoRegister();
// End Cross Module References
	void UWeaponSystemSettings::StaticRegisterNativesUWeaponSystemSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UWeaponSystemSettings);
	UClass* Z_Construct_UClass_UWeaponSystemSettings_NoRegister()
	{
		return UWeaponSystemSettings::StaticClass();
	}
	struct Z_Construct_UClass_UWeaponSystemSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponDataTable_MetaData[];
#endif
		static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_WeaponDataTable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UWeaponSystemSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_WeaponSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponSystemSettings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UWeaponSystemSettings_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Weapon settings" },
		{ "IncludePath", "Settings/WeaponSystemSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/WeaponSystemSettings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UWeaponSystemSettings_Statics::NewProp_WeaponDataTable_MetaData[] = {
		{ "Category", "Weapons data table" },
		{ "ModuleRelativePath", "Public/Settings/WeaponSystemSettings.h" },
	};
#endif
	const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UWeaponSystemSettings_Statics::NewProp_WeaponDataTable = { "WeaponDataTable", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponSystemSettings, WeaponDataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponSystemSettings_Statics::NewProp_WeaponDataTable_MetaData), Z_Construct_UClass_UWeaponSystemSettings_Statics::NewProp_WeaponDataTable_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UWeaponSystemSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponSystemSettings_Statics::NewProp_WeaponDataTable,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UWeaponSystemSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWeaponSystemSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UWeaponSystemSettings_Statics::ClassParams = {
		&UWeaponSystemSettings::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UWeaponSystemSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponSystemSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponSystemSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UWeaponSystemSettings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponSystemSettings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UWeaponSystemSettings()
	{
		if (!Z_Registration_Info_UClass_UWeaponSystemSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWeaponSystemSettings.OuterSingleton, Z_Construct_UClass_UWeaponSystemSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UWeaponSystemSettings.OuterSingleton;
	}
	template<> WEAPONSYSTEM_API UClass* StaticClass<UWeaponSystemSettings>()
	{
		return UWeaponSystemSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWeaponSystemSettings);
	UWeaponSystemSettings::~UWeaponSystemSettings() {}
	struct Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Settings_WeaponSystemSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Settings_WeaponSystemSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UWeaponSystemSettings, UWeaponSystemSettings::StaticClass, TEXT("UWeaponSystemSettings"), &Z_Registration_Info_UClass_UWeaponSystemSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWeaponSystemSettings), 865012643U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Settings_WeaponSystemSettings_h_1724942101(TEXT("/Script/WeaponSystem"),
		Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Settings_WeaponSystemSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Settings_WeaponSystemSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
