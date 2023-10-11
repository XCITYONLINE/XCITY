// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponSystem/Public/WeaponComponents/ShootComponentBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShootComponentBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_WeaponSystem();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UInteractibleWeaponInterface_NoRegister();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UShootComponentBase();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UShootComponentBase_NoRegister();
// End Cross Module References
	void UShootComponentBase::StaticRegisterNativesUShootComponentBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UShootComponentBase);
	UClass* Z_Construct_UClass_UShootComponentBase_NoRegister()
	{
		return UShootComponentBase::StaticClass();
	}
	struct Z_Construct_UClass_UShootComponentBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UShootComponentBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_WeaponSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShootComponentBase_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UShootComponentBase_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "WeaponComponents/ShootComponentBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/WeaponComponents/ShootComponentBase.h" },
	};
#endif
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UShootComponentBase_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInteractibleWeaponInterface_NoRegister, (int32)VTABLE_OFFSET(UShootComponentBase, IInteractibleWeaponInterface), false },  // 2661966974
		};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShootComponentBase_Statics::InterfaceParams) < 64);
	const FCppClassTypeInfoStatic Z_Construct_UClass_UShootComponentBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UShootComponentBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UShootComponentBase_Statics::ClassParams = {
		&UShootComponentBase::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		UE_ARRAY_COUNT(InterfaceParams),
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShootComponentBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UShootComponentBase_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UShootComponentBase()
	{
		if (!Z_Registration_Info_UClass_UShootComponentBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UShootComponentBase.OuterSingleton, Z_Construct_UClass_UShootComponentBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UShootComponentBase.OuterSingleton;
	}
	template<> WEAPONSYSTEM_API UClass* StaticClass<UShootComponentBase>()
	{
		return UShootComponentBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UShootComponentBase);
	UShootComponentBase::~UShootComponentBase() {}
	struct Z_CompiledInDeferFile_FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UShootComponentBase, UShootComponentBase::StaticClass, TEXT("UShootComponentBase"), &Z_Registration_Info_UClass_UShootComponentBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UShootComponentBase), 2621815300U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_2892022808(TEXT("/Script/WeaponSystem"),
		Z_CompiledInDeferFile_FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
