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
	struct ShootComponentBase_eventK2_OnAimModeChanged_Parms
	{
		bool bIsAimMode;
	};
	static FName NAME_UShootComponentBase_K2_OnAimModeChanged = FName(TEXT("K2_OnAimModeChanged"));
	void UShootComponentBase::K2_OnAimModeChanged(bool bIsAimMode)
	{
		ShootComponentBase_eventK2_OnAimModeChanged_Parms Parms;
		Parms.bIsAimMode=bIsAimMode ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UShootComponentBase_K2_OnAimModeChanged),&Parms);
	}
	static FName NAME_UShootComponentBase_K2_OnFire = FName(TEXT("K2_OnFire"));
	void UShootComponentBase::K2_OnFire()
	{
		ProcessEvent(FindFunctionChecked(NAME_UShootComponentBase_K2_OnFire),NULL);
	}
	static FName NAME_UShootComponentBase_K2_OnFireMiss = FName(TEXT("K2_OnFireMiss"));
	void UShootComponentBase::K2_OnFireMiss()
	{
		ProcessEvent(FindFunctionChecked(NAME_UShootComponentBase_K2_OnFireMiss),NULL);
	}
	static FName NAME_UShootComponentBase_K2_OnReload = FName(TEXT("K2_OnReload"));
	void UShootComponentBase::K2_OnReload()
	{
		ProcessEvent(FindFunctionChecked(NAME_UShootComponentBase_K2_OnReload),NULL);
	}
	void UShootComponentBase::StaticRegisterNativesUShootComponentBase()
	{
	}
	struct Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsAimMode_MetaData[];
#endif
		static void NewProp_bIsAimMode_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAimMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::NewProp_bIsAimMode_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::NewProp_bIsAimMode_SetBit(void* Obj)
	{
		((ShootComponentBase_eventK2_OnAimModeChanged_Parms*)Obj)->bIsAimMode = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::NewProp_bIsAimMode = { "bIsAimMode", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ShootComponentBase_eventK2_OnAimModeChanged_Parms), &Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::NewProp_bIsAimMode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::NewProp_bIsAimMode_MetaData), Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::NewProp_bIsAimMode_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::NewProp_bIsAimMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponComponents/ShootComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UShootComponentBase, nullptr, "K2_OnAimModeChanged", nullptr, nullptr, Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::PropPointers), sizeof(ShootComponentBase_eventK2_OnAimModeChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::PropPointers) < 2048);
	static_assert(sizeof(ShootComponentBase_eventK2_OnAimModeChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UShootComponentBase_K2_OnFire_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UShootComponentBase_K2_OnFire_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//~\n" },
#endif
		{ "ModuleRelativePath", "Public/WeaponComponents/ShootComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShootComponentBase_K2_OnFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UShootComponentBase, nullptr, "K2_OnFire", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShootComponentBase_K2_OnFire_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShootComponentBase_K2_OnFire_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UShootComponentBase_K2_OnFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShootComponentBase_K2_OnFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UShootComponentBase_K2_OnFireMiss_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UShootComponentBase_K2_OnFireMiss_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponComponents/ShootComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShootComponentBase_K2_OnFireMiss_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UShootComponentBase, nullptr, "K2_OnFireMiss", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShootComponentBase_K2_OnFireMiss_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShootComponentBase_K2_OnFireMiss_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UShootComponentBase_K2_OnFireMiss()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShootComponentBase_K2_OnFireMiss_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UShootComponentBase_K2_OnReload_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UShootComponentBase_K2_OnReload_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponComponents/ShootComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShootComponentBase_K2_OnReload_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UShootComponentBase, nullptr, "K2_OnReload", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShootComponentBase_K2_OnReload_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShootComponentBase_K2_OnReload_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UShootComponentBase_K2_OnReload()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShootComponentBase_K2_OnReload_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UShootComponentBase);
	UClass* Z_Construct_UClass_UShootComponentBase_NoRegister()
	{
		return UShootComponentBase::StaticClass();
	}
	struct Z_Construct_UClass_UShootComponentBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
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
	const FClassFunctionLinkInfo Z_Construct_UClass_UShootComponentBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UShootComponentBase_K2_OnAimModeChanged, "K2_OnAimModeChanged" }, // 1434009984
		{ &Z_Construct_UFunction_UShootComponentBase_K2_OnFire, "K2_OnFire" }, // 3271092281
		{ &Z_Construct_UFunction_UShootComponentBase_K2_OnFireMiss, "K2_OnFireMiss" }, // 806001002
		{ &Z_Construct_UFunction_UShootComponentBase_K2_OnReload, "K2_OnReload" }, // 2925127997
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShootComponentBase_Statics::FuncInfo) < 2048);
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
			{ Z_Construct_UClass_UInteractibleWeaponInterface_NoRegister, (int32)VTABLE_OFFSET(UShootComponentBase, IInteractibleWeaponInterface), false },  // 2792749425
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
		FuncInfo,
		nullptr,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
	struct Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UShootComponentBase, UShootComponentBase::StaticClass, TEXT("UShootComponentBase"), &Z_Registration_Info_UClass_UShootComponentBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UShootComponentBase), 2346445352U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_4071802398(TEXT("/Script/WeaponSystem"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
