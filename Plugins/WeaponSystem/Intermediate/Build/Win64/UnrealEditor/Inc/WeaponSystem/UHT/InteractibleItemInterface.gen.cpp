// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponSystem/Public/Contracts/InteractibleItemInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInteractibleItemInterface() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_WeaponSystem();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UInteractibleItemInterface();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UInteractibleItemInterface_NoRegister();
// End Cross Module References
	void UInteractibleItemInterface::StaticRegisterNativesUInteractibleItemInterface()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInteractibleItemInterface);
	UClass* Z_Construct_UClass_UInteractibleItemInterface_NoRegister()
	{
		return UInteractibleItemInterface::StaticClass();
	}
	struct Z_Construct_UClass_UInteractibleItemInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInteractibleItemInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_WeaponSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInteractibleItemInterface_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInteractibleItemInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInteractibleItemInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInteractibleItemInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInteractibleItemInterface_Statics::ClassParams = {
		&UInteractibleItemInterface::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInteractibleItemInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UInteractibleItemInterface_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInteractibleItemInterface()
	{
		if (!Z_Registration_Info_UClass_UInteractibleItemInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInteractibleItemInterface.OuterSingleton, Z_Construct_UClass_UInteractibleItemInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInteractibleItemInterface.OuterSingleton;
	}
	template<> WEAPONSYSTEM_API UClass* StaticClass<UInteractibleItemInterface>()
	{
		return UInteractibleItemInterface::StaticClass();
	}
	UInteractibleItemInterface::UInteractibleItemInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInteractibleItemInterface);
	UInteractibleItemInterface::~UInteractibleItemInterface() {}
	struct Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInteractibleItemInterface, UInteractibleItemInterface::StaticClass, TEXT("UInteractibleItemInterface"), &Z_Registration_Info_UClass_UInteractibleItemInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInteractibleItemInterface), 1624233231U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_2090823654(TEXT("/Script/WeaponSystem"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleItemInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
