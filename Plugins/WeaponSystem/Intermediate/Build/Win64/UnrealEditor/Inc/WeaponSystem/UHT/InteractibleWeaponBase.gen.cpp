// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponSystem/Public/WeaponActors/InteractibleWeaponBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInteractibleWeaponBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_WeaponSystem();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_AInteractibleWeaponBase();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_AInteractibleWeaponBase_NoRegister();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UInteractibleWeaponInterface_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AInteractibleWeaponBase::execOnLoadComplete)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnLoadComplete();
		P_NATIVE_END;
	}
	void AInteractibleWeaponBase::StaticRegisterNativesAInteractibleWeaponBase()
	{
		UClass* Class = AInteractibleWeaponBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnLoadComplete", &AInteractibleWeaponBase::execOnLoadComplete },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AInteractibleWeaponBase_OnLoadComplete_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractibleWeaponBase_OnLoadComplete_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInteractibleWeaponBase_OnLoadComplete_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInteractibleWeaponBase, nullptr, "OnLoadComplete", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractibleWeaponBase_OnLoadComplete_Statics::Function_MetaDataParams), Z_Construct_UFunction_AInteractibleWeaponBase_OnLoadComplete_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AInteractibleWeaponBase_OnLoadComplete()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInteractibleWeaponBase_OnLoadComplete_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AInteractibleWeaponBase);
	UClass* Z_Construct_UClass_AInteractibleWeaponBase_NoRegister()
	{
		return AInteractibleWeaponBase::StaticClass();
	}
	struct Z_Construct_UClass_AInteractibleWeaponBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponID_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_WeaponID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponStaticMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponStaticMeshComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AInteractibleWeaponBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_WeaponSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AInteractibleWeaponBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AInteractibleWeaponBase_OnLoadComplete, "OnLoadComplete" }, // 249655452
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractibleWeaponBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "WeaponActors/InteractibleWeaponBase.h" },
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponID_MetaData[] = {
		{ "Category", "InteractibleWeaponBase" },
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponID = { "WeaponID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInteractibleWeaponBase, WeaponID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponID_MetaData), Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponID_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponStaticMeshComponent_MetaData[] = {
		{ "Category", "InteractibleWeaponBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponStaticMeshComponent = { "WeaponStaticMeshComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInteractibleWeaponBase, WeaponStaticMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponStaticMeshComponent_MetaData), Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponStaticMeshComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AInteractibleWeaponBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponStaticMeshComponent,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInteractibleWeaponInterface_NoRegister, (int32)VTABLE_OFFSET(AInteractibleWeaponBase, IInteractibleWeaponInterface), false },  // 2239350536
		};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::InterfaceParams) < 64);
	const FCppClassTypeInfoStatic Z_Construct_UClass_AInteractibleWeaponBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInteractibleWeaponBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::ClassParams = {
		&AInteractibleWeaponBase::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AInteractibleWeaponBase_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AInteractibleWeaponBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AInteractibleWeaponBase()
	{
		if (!Z_Registration_Info_UClass_AInteractibleWeaponBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AInteractibleWeaponBase.OuterSingleton, Z_Construct_UClass_AInteractibleWeaponBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AInteractibleWeaponBase.OuterSingleton;
	}
	template<> WEAPONSYSTEM_API UClass* StaticClass<AInteractibleWeaponBase>()
	{
		return AInteractibleWeaponBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AInteractibleWeaponBase);
	AInteractibleWeaponBase::~AInteractibleWeaponBase() {}
	struct Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_InteractibleWeaponBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_InteractibleWeaponBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AInteractibleWeaponBase, AInteractibleWeaponBase::StaticClass, TEXT("AInteractibleWeaponBase"), &Z_Registration_Info_UClass_AInteractibleWeaponBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AInteractibleWeaponBase), 2474344122U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_InteractibleWeaponBase_h_2970750524(TEXT("/Script/WeaponSystem"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_InteractibleWeaponBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_InteractibleWeaponBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
