// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CommonContractsPlugin/Public/Contracts/InteractibleItemInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInteractibleItemInterface() {}
// Cross Module References
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UInteractibleItemInterface();
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UInteractibleItemInterface_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_CommonContractsPlugin();
// End Cross Module References
	DEFINE_FUNCTION(IInteractibleItemInterface::execOnDrop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnDrop_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleItemInterface::execOnTake)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnTake_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleItemInterface::execOnInteract)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnInteract_Implementation();
		P_NATIVE_END;
	}
	void IInteractibleItemInterface::K2_OnDrop()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_K2_OnDrop instead.");
	}
	void IInteractibleItemInterface::K2_OnInteract()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_K2_OnInteract instead.");
	}
	void IInteractibleItemInterface::K2_OnTake()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_K2_OnTake instead.");
	}
	void IInteractibleItemInterface::OnDrop()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnDrop instead.");
	}
	void IInteractibleItemInterface::OnInteract()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnInteract instead.");
	}
	void IInteractibleItemInterface::OnTake()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnTake instead.");
	}
	void UInteractibleItemInterface::StaticRegisterNativesUInteractibleItemInterface()
	{
		UClass* Class = UInteractibleItemInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnDrop", &IInteractibleItemInterface::execOnDrop },
			{ "OnInteract", &IInteractibleItemInterface::execOnInteract },
			{ "OnTake", &IInteractibleItemInterface::execOnTake },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_K2_OnDrop_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_K2_OnDrop_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_K2_OnDrop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "K2_OnDrop", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnDrop_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_K2_OnDrop_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_K2_OnDrop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_K2_OnDrop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_K2_OnInteract_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_K2_OnInteract_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_K2_OnInteract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "K2_OnInteract", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_K2_OnInteract_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_K2_OnInteract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_K2_OnInteract_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_K2_OnTake_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_K2_OnTake_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_K2_OnTake_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "K2_OnTake", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnTake_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_K2_OnTake_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_K2_OnTake()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_K2_OnTake_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_OnDrop_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_OnDrop_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_OnDrop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "OnDrop", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_OnDrop_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_OnDrop_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_OnDrop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_OnDrop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_OnInteract_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_OnInteract_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_OnInteract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "OnInteract", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_OnInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_OnInteract_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_OnInteract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_OnInteract_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "OnTake", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_OnTake()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInteractibleItemInterface);
	UClass* Z_Construct_UClass_UInteractibleItemInterface_NoRegister()
	{
		return UInteractibleItemInterface::StaticClass();
	}
	struct Z_Construct_UClass_UInteractibleItemInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInteractibleItemInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_CommonContractsPlugin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInteractibleItemInterface_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UInteractibleItemInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInteractibleItemInterface_K2_OnDrop, "K2_OnDrop" }, // 527304145
		{ &Z_Construct_UFunction_UInteractibleItemInterface_K2_OnInteract, "K2_OnInteract" }, // 1694356013
		{ &Z_Construct_UFunction_UInteractibleItemInterface_K2_OnTake, "K2_OnTake" }, // 97462198
		{ &Z_Construct_UFunction_UInteractibleItemInterface_OnDrop, "OnDrop" }, // 1551419500
		{ &Z_Construct_UFunction_UInteractibleItemInterface_OnInteract, "OnInteract" }, // 4078939543
		{ &Z_Construct_UFunction_UInteractibleItemInterface_OnTake, "OnTake" }, // 4058637914
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInteractibleItemInterface_Statics::FuncInfo) < 2048);
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
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
	template<> COMMONCONTRACTSPLUGIN_API UClass* StaticClass<UInteractibleItemInterface>()
	{
		return UInteractibleItemInterface::StaticClass();
	}
	UInteractibleItemInterface::UInteractibleItemInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInteractibleItemInterface);
	UInteractibleItemInterface::~UInteractibleItemInterface() {}
	static FName NAME_UInteractibleItemInterface_K2_OnDrop = FName(TEXT("K2_OnDrop"));
	void IInteractibleItemInterface::Execute_K2_OnDrop(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_K2_OnDrop);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
	}
	static FName NAME_UInteractibleItemInterface_K2_OnInteract = FName(TEXT("K2_OnInteract"));
	void IInteractibleItemInterface::Execute_K2_OnInteract(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_K2_OnInteract);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
	}
	static FName NAME_UInteractibleItemInterface_K2_OnTake = FName(TEXT("K2_OnTake"));
	void IInteractibleItemInterface::Execute_K2_OnTake(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_K2_OnTake);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
	}
	static FName NAME_UInteractibleItemInterface_OnDrop = FName(TEXT("OnDrop"));
	void IInteractibleItemInterface::Execute_OnDrop(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_OnDrop);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleItemInterface*)(O->GetNativeInterfaceAddress(UInteractibleItemInterface::StaticClass())))
		{
			I->OnDrop_Implementation();
		}
	}
	static FName NAME_UInteractibleItemInterface_OnInteract = FName(TEXT("OnInteract"));
	void IInteractibleItemInterface::Execute_OnInteract(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_OnInteract);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleItemInterface*)(O->GetNativeInterfaceAddress(UInteractibleItemInterface::StaticClass())))
		{
			I->OnInteract_Implementation();
		}
	}
	static FName NAME_UInteractibleItemInterface_OnTake = FName(TEXT("OnTake"));
	void IInteractibleItemInterface::Execute_OnTake(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_OnTake);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleItemInterface*)(O->GetNativeInterfaceAddress(UInteractibleItemInterface::StaticClass())))
		{
			I->OnTake_Implementation();
		}
	}
	struct Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInteractibleItemInterface, UInteractibleItemInterface::StaticClass, TEXT("UInteractibleItemInterface"), &Z_Registration_Info_UClass_UInteractibleItemInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInteractibleItemInterface), 2999626947U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_576883956(TEXT("/Script/CommonContractsPlugin"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
