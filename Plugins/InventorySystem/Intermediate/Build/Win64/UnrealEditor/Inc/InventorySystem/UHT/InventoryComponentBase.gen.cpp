// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InventorySystem/Public/Conponents/InventoryComponentBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryComponentBase() {}
// Cross Module References
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UInteractibleItemInterface_NoRegister();
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UInventorySystemInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryComponentBase();
	INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryComponentBase_NoRegister();
	INVENTORYSYSTEM_API UFunction* Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature();
	INVENTORYSYSTEM_API UFunction* Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_InventorySystem();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics
	{
		struct _Script_InventorySystem_eventOnInventorySizeChanged_Parms
		{
			TArray<TScriptInterface<IInteractibleItemInterface> > Value;
		};
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_Value_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::NewProp_Value_Inner = { "Value", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UInteractibleItemInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0014000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_InventorySystem_eventOnInventorySizeChanged_Parms, Value), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::NewProp_Value_MetaData), Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::NewProp_Value_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::NewProp_Value_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Conponents/InventoryComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_InventorySystem, nullptr, "OnInventorySizeChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::_Script_InventorySystem_eventOnInventorySizeChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::_Script_InventorySystem_eventOnInventorySizeChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnInventorySizeChanged_DelegateWrapper(const FMulticastScriptDelegate& OnInventorySizeChanged, TArray<TScriptInterface<IInteractibleItemInterface> > const& Value)
{
	struct _Script_InventorySystem_eventOnInventorySizeChanged_Parms
	{
		TArray<TScriptInterface<IInteractibleItemInterface> > Value;
	};
	_Script_InventorySystem_eventOnInventorySizeChanged_Parms Parms;
	Parms.Value=Value;
	OnInventorySizeChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics
	{
		struct _Script_InventorySystem_eventOnInventoryItemSelected_Parms
		{
			TScriptInterface<IInteractibleItemInterface> Value;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0014000008000182, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_InventorySystem_eventOnInventoryItemSelected_Parms, Value), Z_Construct_UClass_UInteractibleItemInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::NewProp_Value_MetaData), Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::NewProp_Value_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Conponents/InventoryComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_InventorySystem, nullptr, "OnInventoryItemSelected__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::_Script_InventorySystem_eventOnInventoryItemSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::_Script_InventorySystem_eventOnInventoryItemSelected_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnInventoryItemSelected_DelegateWrapper(const FMulticastScriptDelegate& OnInventoryItemSelected, TScriptInterface<IInteractibleItemInterface> const& Value)
{
	struct _Script_InventorySystem_eventOnInventoryItemSelected_Parms
	{
		TScriptInterface<IInteractibleItemInterface> Value;
	};
	_Script_InventorySystem_eventOnInventoryItemSelected_Parms Parms;
	Parms.Value=Value;
	OnInventoryItemSelected.ProcessMulticastDelegate<UObject>(&Parms);
}
	void UInventoryComponentBase::StaticRegisterNativesUInventoryComponentBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInventoryComponentBase);
	UClass* Z_Construct_UClass_UInventoryComponentBase_NoRegister()
	{
		return UInventoryComponentBase::StaticClass();
	}
	struct Z_Construct_UClass_UInventoryComponentBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnInventorySizeChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInventorySizeChanged;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnInventoryItemSelected_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInventoryItemSelected;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AllItemsValue_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_AllItemsValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventoryComponentBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponentBase_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryComponentBase_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Conponents/InventoryComponentBase.h" },
		{ "ModuleRelativePath", "Public/Conponents/InventoryComponentBase.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_OnInventorySizeChanged_MetaData[] = {
		{ "ModuleRelativePath", "Public/Conponents/InventoryComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_OnInventorySizeChanged = { "OnInventorySizeChanged", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponentBase, OnInventorySizeChanged), Z_Construct_UDelegateFunction_InventorySystem_OnInventorySizeChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_OnInventorySizeChanged_MetaData), Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_OnInventorySizeChanged_MetaData) }; // 142543897
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_OnInventoryItemSelected_MetaData[] = {
		{ "ModuleRelativePath", "Public/Conponents/InventoryComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_OnInventoryItemSelected = { "OnInventoryItemSelected", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponentBase, OnInventoryItemSelected), Z_Construct_UDelegateFunction_InventorySystem_OnInventoryItemSelected__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_OnInventoryItemSelected_MetaData), Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_OnInventoryItemSelected_MetaData) }; // 3472920445
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_AllItemsValue_MetaData[] = {
		{ "Category", "InventoryComponentBase" },
		{ "ModuleRelativePath", "Public/Conponents/InventoryComponentBase.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_AllItemsValue = { "AllItemsValue", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponentBase, AllItemsValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_AllItemsValue_MetaData), Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_AllItemsValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryComponentBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_OnInventorySizeChanged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_OnInventoryItemSelected,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponentBase_Statics::NewProp_AllItemsValue,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UInventoryComponentBase_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInventorySystemInterface_NoRegister, (int32)VTABLE_OFFSET(UInventoryComponentBase, IInventorySystemInterface), false },  // 2141143979
		};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponentBase_Statics::InterfaceParams) < 64);
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventoryComponentBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryComponentBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryComponentBase_Statics::ClassParams = {
		&UInventoryComponentBase::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UInventoryComponentBase_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponentBase_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponentBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryComponentBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponentBase_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UInventoryComponentBase()
	{
		if (!Z_Registration_Info_UClass_UInventoryComponentBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryComponentBase.OuterSingleton, Z_Construct_UClass_UInventoryComponentBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInventoryComponentBase.OuterSingleton;
	}
	template<> INVENTORYSYSTEM_API UClass* StaticClass<UInventoryComponentBase>()
	{
		return UInventoryComponentBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryComponentBase);
	UInventoryComponentBase::~UInventoryComponentBase() {}
	struct Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryComponentBase, UInventoryComponentBase::StaticClass, TEXT("UInventoryComponentBase"), &Z_Registration_Info_UClass_UInventoryComponentBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryComponentBase), 3838188823U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_2841306366(TEXT("/Script/InventorySystem"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_InventoryComponentBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
