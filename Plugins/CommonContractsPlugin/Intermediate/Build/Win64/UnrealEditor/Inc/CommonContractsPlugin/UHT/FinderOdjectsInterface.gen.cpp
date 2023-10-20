// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CommonContractsPlugin/Public/Contracts/FinderOdjectsInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFinderOdjectsInterface() {}
// Cross Module References
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UFinderObjectsInterface();
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UFinderObjectsInterface_NoRegister();
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UInteractibleItemInterface_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_CommonContractsPlugin();
// End Cross Module References
	DEFINE_FUNCTION(IFinderObjectsInterface::execResetPreviousItems)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetPreviousItems_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IFinderObjectsInterface::execTryFindInteractibleObjects)
	{
		P_GET_TARRAY_REF(TScriptInterface<IInteractibleItemInterface>,Z_Param_Out_OutObjects);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->TryFindInteractibleObjects_Implementation(Z_Param_Out_OutObjects);
		P_NATIVE_END;
	}
	struct FinderObjectsInterface_eventTryFindInteractibleObjects_Parms
	{
		TArray<TScriptInterface<IInteractibleItemInterface> > OutObjects;
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		FinderObjectsInterface_eventTryFindInteractibleObjects_Parms()
			: ReturnValue(false)
		{
		}
	};
	void IFinderObjectsInterface::ResetPreviousItems()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ResetPreviousItems instead.");
	}
	bool IFinderObjectsInterface::TryFindInteractibleObjects(TArray<TScriptInterface<IInteractibleItemInterface> >& OutObjects)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_TryFindInteractibleObjects instead.");
		FinderObjectsInterface_eventTryFindInteractibleObjects_Parms Parms;
		return Parms.ReturnValue;
	}
	void UFinderObjectsInterface::StaticRegisterNativesUFinderObjectsInterface()
	{
		UClass* Class = UFinderObjectsInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ResetPreviousItems", &IFinderObjectsInterface::execResetPreviousItems },
			{ "TryFindInteractibleObjects", &IFinderObjectsInterface::execTryFindInteractibleObjects },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFinderObjectsInterface_ResetPreviousItems_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFinderObjectsInterface_ResetPreviousItems_Statics::Function_MetaDataParams[] = {
		{ "Category", "Finder" },
		{ "ModuleRelativePath", "Public/Contracts/FinderOdjectsInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFinderObjectsInterface_ResetPreviousItems_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFinderObjectsInterface, nullptr, "ResetPreviousItems", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFinderObjectsInterface_ResetPreviousItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFinderObjectsInterface_ResetPreviousItems_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UFinderObjectsInterface_ResetPreviousItems()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFinderObjectsInterface_ResetPreviousItems_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics
	{
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_OutObjects_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_OutObjects;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::NewProp_OutObjects_Inner = { "OutObjects", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UInteractibleItemInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::NewProp_OutObjects = { "OutObjects", nullptr, (EPropertyFlags)0x0014000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FinderObjectsInterface_eventTryFindInteractibleObjects_Parms, OutObjects), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FinderObjectsInterface_eventTryFindInteractibleObjects_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FinderObjectsInterface_eventTryFindInteractibleObjects_Parms), &Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::NewProp_OutObjects_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::NewProp_OutObjects,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::Function_MetaDataParams[] = {
		{ "Category", "Finder" },
		{ "ModuleRelativePath", "Public/Contracts/FinderOdjectsInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFinderObjectsInterface, nullptr, "TryFindInteractibleObjects", nullptr, nullptr, Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::PropPointers), sizeof(FinderObjectsInterface_eventTryFindInteractibleObjects_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::PropPointers) < 2048);
	static_assert(sizeof(FinderObjectsInterface_eventTryFindInteractibleObjects_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFinderObjectsInterface);
	UClass* Z_Construct_UClass_UFinderObjectsInterface_NoRegister()
	{
		return UFinderObjectsInterface::StaticClass();
	}
	struct Z_Construct_UClass_UFinderObjectsInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFinderObjectsInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_CommonContractsPlugin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFinderObjectsInterface_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UFinderObjectsInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFinderObjectsInterface_ResetPreviousItems, "ResetPreviousItems" }, // 606995247
		{ &Z_Construct_UFunction_UFinderObjectsInterface_TryFindInteractibleObjects, "TryFindInteractibleObjects" }, // 1892184651
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFinderObjectsInterface_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFinderObjectsInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Contracts/FinderOdjectsInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFinderObjectsInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IFinderObjectsInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UFinderObjectsInterface_Statics::ClassParams = {
		&UFinderObjectsInterface::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFinderObjectsInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UFinderObjectsInterface_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UFinderObjectsInterface()
	{
		if (!Z_Registration_Info_UClass_UFinderObjectsInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFinderObjectsInterface.OuterSingleton, Z_Construct_UClass_UFinderObjectsInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UFinderObjectsInterface.OuterSingleton;
	}
	template<> COMMONCONTRACTSPLUGIN_API UClass* StaticClass<UFinderObjectsInterface>()
	{
		return UFinderObjectsInterface::StaticClass();
	}
	UFinderObjectsInterface::UFinderObjectsInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFinderObjectsInterface);
	UFinderObjectsInterface::~UFinderObjectsInterface() {}
	static FName NAME_UFinderObjectsInterface_ResetPreviousItems = FName(TEXT("ResetPreviousItems"));
	void IFinderObjectsInterface::Execute_ResetPreviousItems(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UFinderObjectsInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UFinderObjectsInterface_ResetPreviousItems);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IFinderObjectsInterface*)(O->GetNativeInterfaceAddress(UFinderObjectsInterface::StaticClass())))
		{
			I->ResetPreviousItems_Implementation();
		}
	}
	static FName NAME_UFinderObjectsInterface_TryFindInteractibleObjects = FName(TEXT("TryFindInteractibleObjects"));
	bool IFinderObjectsInterface::Execute_TryFindInteractibleObjects(UObject* O, TArray<TScriptInterface<IInteractibleItemInterface> >& OutObjects)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UFinderObjectsInterface::StaticClass()));
		FinderObjectsInterface_eventTryFindInteractibleObjects_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UFinderObjectsInterface_TryFindInteractibleObjects);
		if (Func)
		{
			Parms.OutObjects=OutObjects;
			O->ProcessEvent(Func, &Parms);
			OutObjects=Parms.OutObjects;
		}
		else if (auto I = (IFinderObjectsInterface*)(O->GetNativeInterfaceAddress(UFinderObjectsInterface::StaticClass())))
		{
			Parms.ReturnValue = I->TryFindInteractibleObjects_Implementation(OutObjects);
		}
		return Parms.ReturnValue;
	}
	struct Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UFinderObjectsInterface, UFinderObjectsInterface::StaticClass, TEXT("UFinderObjectsInterface"), &Z_Registration_Info_UClass_UFinderObjectsInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFinderObjectsInterface), 763171924U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_1153125382(TEXT("/Script/CommonContractsPlugin"),
		Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_FinderOdjectsInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
