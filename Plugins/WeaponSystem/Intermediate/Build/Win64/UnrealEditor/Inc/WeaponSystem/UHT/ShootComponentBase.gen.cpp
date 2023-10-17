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
	WEAPONSYSTEM_API UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature();
	WEAPONSYSTEM_API UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnFire__DelegateSignature();
	WEAPONSYSTEM_API UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnReload__DelegateSignature();
	WEAPONSYSTEM_API UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnReloadFireMiss__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_WeaponSystem_OnReload__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_WeaponSystem_OnReload__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponComponents/ShootComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_WeaponSystem_OnReload__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_WeaponSystem, nullptr, "OnReload__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnReload__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_WeaponSystem_OnReload__DelegateSignature_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnReload__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_WeaponSystem_OnReload__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnReload_DelegateWrapper(const FMulticastScriptDelegate& OnReload)
{
	OnReload.ProcessMulticastDelegate<UObject>(NULL);
}
	struct Z_Construct_UDelegateFunction_WeaponSystem_OnFire__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_WeaponSystem_OnFire__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponComponents/ShootComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_WeaponSystem_OnFire__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_WeaponSystem, nullptr, "OnFire__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnFire__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_WeaponSystem_OnFire__DelegateSignature_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnFire__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_WeaponSystem_OnFire__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnFire_DelegateWrapper(const FMulticastScriptDelegate& OnFire)
{
	OnFire.ProcessMulticastDelegate<UObject>(NULL);
}
	struct Z_Construct_UDelegateFunction_WeaponSystem_OnReloadFireMiss__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_WeaponSystem_OnReloadFireMiss__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponComponents/ShootComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_WeaponSystem_OnReloadFireMiss__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_WeaponSystem, nullptr, "OnReloadFireMiss__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnReloadFireMiss__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_WeaponSystem_OnReloadFireMiss__DelegateSignature_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnReloadFireMiss__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_WeaponSystem_OnReloadFireMiss__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnReloadFireMiss_DelegateWrapper(const FMulticastScriptDelegate& OnReloadFireMiss)
{
	OnReloadFireMiss.ProcessMulticastDelegate<UObject>(NULL);
}
	struct Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics
	{
		struct _Script_WeaponSystem_eventOnAimModeChanged_Parms
		{
			bool Value;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static void NewProp_Value_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((_Script_WeaponSystem_eventOnAimModeChanged_Parms*)Obj)->Value = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_WeaponSystem_eventOnAimModeChanged_Parms), &Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::NewProp_Value_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::NewProp_Value_MetaData), Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::NewProp_Value_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponComponents/ShootComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_WeaponSystem, nullptr, "OnAimModeChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::_Script_WeaponSystem_eventOnAimModeChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::_Script_WeaponSystem_eventOnAimModeChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnAimModeChanged_DelegateWrapper(const FMulticastScriptDelegate& OnAimModeChanged, bool Value)
{
	struct _Script_WeaponSystem_eventOnAimModeChanged_Parms
	{
		bool Value;
	};
	_Script_WeaponSystem_eventOnAimModeChanged_Parms Parms;
	Parms.Value=Value ? true : false;
	OnAimModeChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnFire_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFire;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnReloadFireMiss_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnReloadFireMiss;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnReload_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnReload;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnAimModeChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAimModeChanged;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnFire_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//~\n" },
#endif
		{ "ModuleRelativePath", "Public/WeaponComponents/ShootComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnFire = { "OnFire", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShootComponentBase, OnFire), Z_Construct_UDelegateFunction_WeaponSystem_OnFire__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnFire_MetaData), Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnFire_MetaData) }; // 1074946369
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnReloadFireMiss_MetaData[] = {
		{ "ModuleRelativePath", "Public/WeaponComponents/ShootComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnReloadFireMiss = { "OnReloadFireMiss", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShootComponentBase, OnReloadFireMiss), Z_Construct_UDelegateFunction_WeaponSystem_OnReloadFireMiss__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnReloadFireMiss_MetaData), Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnReloadFireMiss_MetaData) }; // 1024312085
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnReload_MetaData[] = {
		{ "ModuleRelativePath", "Public/WeaponComponents/ShootComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnReload = { "OnReload", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShootComponentBase, OnReload), Z_Construct_UDelegateFunction_WeaponSystem_OnReload__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnReload_MetaData), Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnReload_MetaData) }; // 4054696429
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnAimModeChanged_MetaData[] = {
		{ "ModuleRelativePath", "Public/WeaponComponents/ShootComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnAimModeChanged = { "OnAimModeChanged", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShootComponentBase, OnAimModeChanged), Z_Construct_UDelegateFunction_WeaponSystem_OnAimModeChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnAimModeChanged_MetaData), Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnAimModeChanged_MetaData) }; // 1070559965
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UShootComponentBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnFire,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnReloadFireMiss,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnReload,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShootComponentBase_Statics::NewProp_OnAimModeChanged,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UShootComponentBase_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInteractibleWeaponInterface_NoRegister, (int32)VTABLE_OFFSET(UShootComponentBase, IInteractibleWeaponInterface), false },  // 3400998876
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
		Z_Construct_UClass_UShootComponentBase_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UShootComponentBase_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShootComponentBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UShootComponentBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShootComponentBase_Statics::PropPointers) < 2048);
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
		{ Z_Construct_UClass_UShootComponentBase, UShootComponentBase::StaticClass, TEXT("UShootComponentBase"), &Z_Registration_Info_UClass_UShootComponentBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UShootComponentBase), 53889167U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_4152213795(TEXT("/Script/WeaponSystem"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponComponents_ShootComponentBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
