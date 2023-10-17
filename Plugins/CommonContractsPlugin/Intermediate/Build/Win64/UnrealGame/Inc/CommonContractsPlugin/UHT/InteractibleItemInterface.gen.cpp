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
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_CommonContractsPlugin();
// End Cross Module References
	DEFINE_FUNCTION(IInteractibleItemInterface::execOnDrop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnDrop_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleItemInterface::execOnUnselect)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnUnselect_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleItemInterface::execOnTake)
	{
		P_GET_OBJECT(AActor,Z_Param_OwnerActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnTake_Implementation(Z_Param_OwnerActor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleItemInterface::execOnStopAlternativeInteract)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStopAlternativeInteract_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleItemInterface::execOnStartAlternativeInteract)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStartAlternativeInteract_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleItemInterface::execOnStopMainInteract)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStopMainInteract_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleItemInterface::execOnStartMainInteract)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStartMainInteract_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleItemInterface::execOnStopHover)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStopHover_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleItemInterface::execOnStartHover)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStartHover_Implementation();
		P_NATIVE_END;
	}
	struct InteractibleItemInterface_eventK2_OnAlternativeInteract_Parms
	{
		bool bIsInteract;
	};
	struct InteractibleItemInterface_eventK2_OnHover_Parms
	{
		bool bIsHover;
	};
	struct InteractibleItemInterface_eventK2_OnMainInteract_Parms
	{
		bool bIsInteract;
	};
	struct InteractibleItemInterface_eventOnTake_Parms
	{
		AActor* OwnerActor;
	};
	void IInteractibleItemInterface::K2_OnAlternativeInteract(bool bIsInteract)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_K2_OnAlternativeInteract instead.");
	}
	void IInteractibleItemInterface::K2_OnDrop()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_K2_OnDrop instead.");
	}
	void IInteractibleItemInterface::K2_OnHover(bool bIsHover)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_K2_OnHover instead.");
	}
	void IInteractibleItemInterface::K2_OnMainInteract(bool bIsInteract)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_K2_OnMainInteract instead.");
	}
	void IInteractibleItemInterface::K2_OnTake()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_K2_OnTake instead.");
	}
	void IInteractibleItemInterface::K2_OnUnselect()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_K2_OnUnselect instead.");
	}
	void IInteractibleItemInterface::OnDrop()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnDrop instead.");
	}
	void IInteractibleItemInterface::OnStartAlternativeInteract()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnStartAlternativeInteract instead.");
	}
	void IInteractibleItemInterface::OnStartHover()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnStartHover instead.");
	}
	void IInteractibleItemInterface::OnStartMainInteract()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnStartMainInteract instead.");
	}
	void IInteractibleItemInterface::OnStopAlternativeInteract()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnStopAlternativeInteract instead.");
	}
	void IInteractibleItemInterface::OnStopHover()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnStopHover instead.");
	}
	void IInteractibleItemInterface::OnStopMainInteract()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnStopMainInteract instead.");
	}
	void IInteractibleItemInterface::OnTake(AActor* OwnerActor)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnTake instead.");
	}
	void IInteractibleItemInterface::OnUnselect()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnUnselect instead.");
	}
	void UInteractibleItemInterface::StaticRegisterNativesUInteractibleItemInterface()
	{
		UClass* Class = UInteractibleItemInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnDrop", &IInteractibleItemInterface::execOnDrop },
			{ "OnStartAlternativeInteract", &IInteractibleItemInterface::execOnStartAlternativeInteract },
			{ "OnStartHover", &IInteractibleItemInterface::execOnStartHover },
			{ "OnStartMainInteract", &IInteractibleItemInterface::execOnStartMainInteract },
			{ "OnStopAlternativeInteract", &IInteractibleItemInterface::execOnStopAlternativeInteract },
			{ "OnStopHover", &IInteractibleItemInterface::execOnStopHover },
			{ "OnStopMainInteract", &IInteractibleItemInterface::execOnStopMainInteract },
			{ "OnTake", &IInteractibleItemInterface::execOnTake },
			{ "OnUnselect", &IInteractibleItemInterface::execOnUnselect },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsInteract_MetaData[];
#endif
		static void NewProp_bIsInteract_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsInteract;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::NewProp_bIsInteract_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::NewProp_bIsInteract_SetBit(void* Obj)
	{
		((InteractibleItemInterface_eventK2_OnAlternativeInteract_Parms*)Obj)->bIsInteract = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::NewProp_bIsInteract = { "bIsInteract", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InteractibleItemInterface_eventK2_OnAlternativeInteract_Parms), &Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::NewProp_bIsInteract_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::NewProp_bIsInteract_MetaData), Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::NewProp_bIsInteract_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::NewProp_bIsInteract,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "K2_OnAlternativeInteract", nullptr, nullptr, Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::PropPointers), sizeof(InteractibleItemInterface_eventK2_OnAlternativeInteract_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleItemInterface_eventK2_OnAlternativeInteract_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract_Statics::FuncParams);
		}
		return ReturnFunction;
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
	struct Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsHover_MetaData[];
#endif
		static void NewProp_bIsHover_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsHover;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::NewProp_bIsHover_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::NewProp_bIsHover_SetBit(void* Obj)
	{
		((InteractibleItemInterface_eventK2_OnHover_Parms*)Obj)->bIsHover = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::NewProp_bIsHover = { "bIsHover", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InteractibleItemInterface_eventK2_OnHover_Parms), &Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::NewProp_bIsHover_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::NewProp_bIsHover_MetaData), Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::NewProp_bIsHover_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::NewProp_bIsHover,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "K2_OnHover", nullptr, nullptr, Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::PropPointers), sizeof(InteractibleItemInterface_eventK2_OnHover_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleItemInterface_eventK2_OnHover_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsInteract_MetaData[];
#endif
		static void NewProp_bIsInteract_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsInteract;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::NewProp_bIsInteract_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::NewProp_bIsInteract_SetBit(void* Obj)
	{
		((InteractibleItemInterface_eventK2_OnMainInteract_Parms*)Obj)->bIsInteract = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::NewProp_bIsInteract = { "bIsInteract", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InteractibleItemInterface_eventK2_OnMainInteract_Parms), &Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::NewProp_bIsInteract_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::NewProp_bIsInteract_MetaData), Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::NewProp_bIsInteract_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::NewProp_bIsInteract,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "K2_OnMainInteract", nullptr, nullptr, Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::PropPointers), sizeof(InteractibleItemInterface_eventK2_OnMainInteract_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleItemInterface_eventK2_OnMainInteract_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract_Statics::FuncParams);
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
	struct Z_Construct_UFunction_UInteractibleItemInterface_K2_OnUnselect_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_K2_OnUnselect_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_K2_OnUnselect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "K2_OnUnselect", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_K2_OnUnselect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_K2_OnUnselect_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_K2_OnUnselect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_K2_OnUnselect_Statics::FuncParams);
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
	struct Z_Construct_UFunction_UInteractibleItemInterface_OnStartAlternativeInteract_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_OnStartAlternativeInteract_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_OnStartAlternativeInteract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "OnStartAlternativeInteract", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_OnStartAlternativeInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_OnStartAlternativeInteract_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_OnStartAlternativeInteract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_OnStartAlternativeInteract_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_OnStartHover_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_OnStartHover_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_OnStartHover_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "OnStartHover", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_OnStartHover_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_OnStartHover_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_OnStartHover()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_OnStartHover_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_OnStartMainInteract_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_OnStartMainInteract_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_OnStartMainInteract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "OnStartMainInteract", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_OnStartMainInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_OnStartMainInteract_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_OnStartMainInteract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_OnStartMainInteract_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_OnStopAlternativeInteract_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_OnStopAlternativeInteract_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_OnStopAlternativeInteract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "OnStopAlternativeInteract", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_OnStopAlternativeInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_OnStopAlternativeInteract_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_OnStopAlternativeInteract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_OnStopAlternativeInteract_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_OnStopHover_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_OnStopHover_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_OnStopHover_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "OnStopHover", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_OnStopHover_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_OnStopHover_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_OnStopHover()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_OnStopHover_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_OnStopMainInteract_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_OnStopMainInteract_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_OnStopMainInteract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "OnStopMainInteract", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_OnStopMainInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_OnStopMainInteract_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_OnStopMainInteract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_OnStopMainInteract_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerActor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::NewProp_OwnerActor = { "OwnerActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractibleItemInterface_eventOnTake_Parms, OwnerActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::NewProp_OwnerActor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "OnTake", nullptr, nullptr, Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::PropPointers), sizeof(InteractibleItemInterface_eventOnTake_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleItemInterface_eventOnTake_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_OnTake()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_OnTake_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleItemInterface_OnUnselect_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleItemInterface_OnUnselect_Statics::Function_MetaDataParams[] = {
		{ "Category", "Iteractible Item" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleItemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleItemInterface_OnUnselect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleItemInterface, nullptr, "OnUnselect", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleItemInterface_OnUnselect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleItemInterface_OnUnselect_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleItemInterface_OnUnselect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleItemInterface_OnUnselect_Statics::FuncParams);
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
		{ &Z_Construct_UFunction_UInteractibleItemInterface_K2_OnAlternativeInteract, "K2_OnAlternativeInteract" }, // 401095788
		{ &Z_Construct_UFunction_UInteractibleItemInterface_K2_OnDrop, "K2_OnDrop" }, // 527304145
		{ &Z_Construct_UFunction_UInteractibleItemInterface_K2_OnHover, "K2_OnHover" }, // 3747610671
		{ &Z_Construct_UFunction_UInteractibleItemInterface_K2_OnMainInteract, "K2_OnMainInteract" }, // 3470118454
		{ &Z_Construct_UFunction_UInteractibleItemInterface_K2_OnTake, "K2_OnTake" }, // 97462198
		{ &Z_Construct_UFunction_UInteractibleItemInterface_K2_OnUnselect, "K2_OnUnselect" }, // 2312649067
		{ &Z_Construct_UFunction_UInteractibleItemInterface_OnDrop, "OnDrop" }, // 1551419500
		{ &Z_Construct_UFunction_UInteractibleItemInterface_OnStartAlternativeInteract, "OnStartAlternativeInteract" }, // 1209241289
		{ &Z_Construct_UFunction_UInteractibleItemInterface_OnStartHover, "OnStartHover" }, // 1255829080
		{ &Z_Construct_UFunction_UInteractibleItemInterface_OnStartMainInteract, "OnStartMainInteract" }, // 1450483969
		{ &Z_Construct_UFunction_UInteractibleItemInterface_OnStopAlternativeInteract, "OnStopAlternativeInteract" }, // 5251797
		{ &Z_Construct_UFunction_UInteractibleItemInterface_OnStopHover, "OnStopHover" }, // 2555600596
		{ &Z_Construct_UFunction_UInteractibleItemInterface_OnStopMainInteract, "OnStopMainInteract" }, // 1730157635
		{ &Z_Construct_UFunction_UInteractibleItemInterface_OnTake, "OnTake" }, // 1898092501
		{ &Z_Construct_UFunction_UInteractibleItemInterface_OnUnselect, "OnUnselect" }, // 3575280180
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
	static FName NAME_UInteractibleItemInterface_K2_OnAlternativeInteract = FName(TEXT("K2_OnAlternativeInteract"));
	void IInteractibleItemInterface::Execute_K2_OnAlternativeInteract(UObject* O, bool bIsInteract)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		InteractibleItemInterface_eventK2_OnAlternativeInteract_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_K2_OnAlternativeInteract);
		if (Func)
		{
			Parms.bIsInteract=bIsInteract;
			O->ProcessEvent(Func, &Parms);
		}
	}
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
	static FName NAME_UInteractibleItemInterface_K2_OnHover = FName(TEXT("K2_OnHover"));
	void IInteractibleItemInterface::Execute_K2_OnHover(UObject* O, bool bIsHover)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		InteractibleItemInterface_eventK2_OnHover_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_K2_OnHover);
		if (Func)
		{
			Parms.bIsHover=bIsHover;
			O->ProcessEvent(Func, &Parms);
		}
	}
	static FName NAME_UInteractibleItemInterface_K2_OnMainInteract = FName(TEXT("K2_OnMainInteract"));
	void IInteractibleItemInterface::Execute_K2_OnMainInteract(UObject* O, bool bIsInteract)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		InteractibleItemInterface_eventK2_OnMainInteract_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_K2_OnMainInteract);
		if (Func)
		{
			Parms.bIsInteract=bIsInteract;
			O->ProcessEvent(Func, &Parms);
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
	static FName NAME_UInteractibleItemInterface_K2_OnUnselect = FName(TEXT("K2_OnUnselect"));
	void IInteractibleItemInterface::Execute_K2_OnUnselect(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_K2_OnUnselect);
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
	static FName NAME_UInteractibleItemInterface_OnStartAlternativeInteract = FName(TEXT("OnStartAlternativeInteract"));
	void IInteractibleItemInterface::Execute_OnStartAlternativeInteract(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_OnStartAlternativeInteract);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleItemInterface*)(O->GetNativeInterfaceAddress(UInteractibleItemInterface::StaticClass())))
		{
			I->OnStartAlternativeInteract_Implementation();
		}
	}
	static FName NAME_UInteractibleItemInterface_OnStartHover = FName(TEXT("OnStartHover"));
	void IInteractibleItemInterface::Execute_OnStartHover(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_OnStartHover);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleItemInterface*)(O->GetNativeInterfaceAddress(UInteractibleItemInterface::StaticClass())))
		{
			I->OnStartHover_Implementation();
		}
	}
	static FName NAME_UInteractibleItemInterface_OnStartMainInteract = FName(TEXT("OnStartMainInteract"));
	void IInteractibleItemInterface::Execute_OnStartMainInteract(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_OnStartMainInteract);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleItemInterface*)(O->GetNativeInterfaceAddress(UInteractibleItemInterface::StaticClass())))
		{
			I->OnStartMainInteract_Implementation();
		}
	}
	static FName NAME_UInteractibleItemInterface_OnStopAlternativeInteract = FName(TEXT("OnStopAlternativeInteract"));
	void IInteractibleItemInterface::Execute_OnStopAlternativeInteract(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_OnStopAlternativeInteract);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleItemInterface*)(O->GetNativeInterfaceAddress(UInteractibleItemInterface::StaticClass())))
		{
			I->OnStopAlternativeInteract_Implementation();
		}
	}
	static FName NAME_UInteractibleItemInterface_OnStopHover = FName(TEXT("OnStopHover"));
	void IInteractibleItemInterface::Execute_OnStopHover(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_OnStopHover);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleItemInterface*)(O->GetNativeInterfaceAddress(UInteractibleItemInterface::StaticClass())))
		{
			I->OnStopHover_Implementation();
		}
	}
	static FName NAME_UInteractibleItemInterface_OnStopMainInteract = FName(TEXT("OnStopMainInteract"));
	void IInteractibleItemInterface::Execute_OnStopMainInteract(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_OnStopMainInteract);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleItemInterface*)(O->GetNativeInterfaceAddress(UInteractibleItemInterface::StaticClass())))
		{
			I->OnStopMainInteract_Implementation();
		}
	}
	static FName NAME_UInteractibleItemInterface_OnTake = FName(TEXT("OnTake"));
	void IInteractibleItemInterface::Execute_OnTake(UObject* O, AActor* OwnerActor)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		InteractibleItemInterface_eventOnTake_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_OnTake);
		if (Func)
		{
			Parms.OwnerActor=OwnerActor;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInteractibleItemInterface*)(O->GetNativeInterfaceAddress(UInteractibleItemInterface::StaticClass())))
		{
			I->OnTake_Implementation(OwnerActor);
		}
	}
	static FName NAME_UInteractibleItemInterface_OnUnselect = FName(TEXT("OnUnselect"));
	void IInteractibleItemInterface::Execute_OnUnselect(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleItemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleItemInterface_OnUnselect);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleItemInterface*)(O->GetNativeInterfaceAddress(UInteractibleItemInterface::StaticClass())))
		{
			I->OnUnselect_Implementation();
		}
	}
	struct Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInteractibleItemInterface, UInteractibleItemInterface::StaticClass, TEXT("UInteractibleItemInterface"), &Z_Registration_Info_UClass_UInteractibleItemInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInteractibleItemInterface), 3338019103U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_1693287534(TEXT("/Script/CommonContractsPlugin"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InteractibleItemInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
