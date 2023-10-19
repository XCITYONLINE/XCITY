// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CommonContractsPlugin/Public/Contracts/InventorySystemInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventorySystemInterface() {}
// Cross Module References
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UInteractibleItemInterface_NoRegister();
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UInventorySystemInterface();
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UInventorySystemInterface_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_CommonContractsPlugin();
// End Cross Module References
	DEFINE_FUNCTION(IInventorySystemInterface::execRemoveInventoryItemByIndex)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_InInventoryIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveInventoryItemByIndex_Implementation(Z_Param_InInventoryIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInventorySystemInterface::execRemoveInventoryItem)
	{
		P_GET_TINTERFACE_REF(IInteractibleItemInterface,Z_Param_Out_InInventoryItem);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveInventoryItem_Implementation(Z_Param_Out_InInventoryItem);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInventorySystemInterface::execSetInventoryItem)
	{
		P_GET_TINTERFACE_REF(IInteractibleItemInterface,Z_Param_Out_InInventoryItem);
		P_GET_PROPERTY(FIntProperty,Z_Param_InInventoryIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetInventoryItem_Implementation(Z_Param_Out_InInventoryItem,Z_Param_InInventoryIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInventorySystemInterface::execAddInventoryItem)
	{
		P_GET_TINTERFACE_REF(IInteractibleItemInterface,Z_Param_Out_InNewInventoryItem);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddInventoryItem_Implementation(Z_Param_Out_InNewInventoryItem);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInventorySystemInterface::execGetAllInventoryItems)
	{
		P_GET_TARRAY_REF(TScriptInterface<IInteractibleItemInterface>,Z_Param_Out_OutInventoryItems);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetAllInventoryItems_Implementation(Z_Param_Out_OutInventoryItems);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInventorySystemInterface::execGetSelectedItem)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TScriptInterface<IInteractibleItemInterface>*)Z_Param__Result=P_THIS->GetSelectedItem_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInventorySystemInterface::execUnselectAllItems)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UnselectAllItems_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInventorySystemInterface::execUnselectItem)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UnselectItem_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInventorySystemInterface::execOnBackwardItemChanged)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnBackwardItemChanged_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInventorySystemInterface::execOnForwardItemChanged)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnForwardItemChanged_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInventorySystemInterface::execOnInitInventorySystem)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnInitInventorySystem_Implementation();
		P_NATIVE_END;
	}
	struct InventorySystemInterface_eventAddInventoryItem_Parms
	{
		TScriptInterface<IInteractibleItemInterface> InNewInventoryItem;
	};
	struct InventorySystemInterface_eventGetAllInventoryItems_Parms
	{
		TArray<TScriptInterface<IInteractibleItemInterface> > OutInventoryItems;
	};
	struct InventorySystemInterface_eventGetSelectedItem_Parms
	{
		TScriptInterface<IInteractibleItemInterface> ReturnValue;
	};
	struct InventorySystemInterface_eventRemoveInventoryItem_Parms
	{
		TScriptInterface<IInteractibleItemInterface> InInventoryItem;
	};
	struct InventorySystemInterface_eventRemoveInventoryItemByIndex_Parms
	{
		int32 InInventoryIndex;
	};
	struct InventorySystemInterface_eventSetInventoryItem_Parms
	{
		TScriptInterface<IInteractibleItemInterface> InInventoryItem;
		int32 InInventoryIndex;
	};
	void IInventorySystemInterface::AddInventoryItem(TScriptInterface<IInteractibleItemInterface>& InNewInventoryItem)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_AddInventoryItem instead.");
	}
	void IInventorySystemInterface::GetAllInventoryItems(TArray<TScriptInterface<IInteractibleItemInterface> >& OutInventoryItems)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetAllInventoryItems instead.");
	}
	TScriptInterface<IInteractibleItemInterface> IInventorySystemInterface::GetSelectedItem()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetSelectedItem instead.");
		InventorySystemInterface_eventGetSelectedItem_Parms Parms;
		return Parms.ReturnValue;
	}
	void IInventorySystemInterface::OnBackwardItemChanged()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnBackwardItemChanged instead.");
	}
	void IInventorySystemInterface::OnForwardItemChanged()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnForwardItemChanged instead.");
	}
	void IInventorySystemInterface::OnInitInventorySystem()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnInitInventorySystem instead.");
	}
	void IInventorySystemInterface::RemoveInventoryItem(TScriptInterface<IInteractibleItemInterface>& InInventoryItem)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_RemoveInventoryItem instead.");
	}
	void IInventorySystemInterface::RemoveInventoryItemByIndex(const int32 InInventoryIndex)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_RemoveInventoryItemByIndex instead.");
	}
	void IInventorySystemInterface::SetInventoryItem(TScriptInterface<IInteractibleItemInterface>& InInventoryItem, const int32 InInventoryIndex)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_SetInventoryItem instead.");
	}
	void IInventorySystemInterface::UnselectAllItems()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_UnselectAllItems instead.");
	}
	void IInventorySystemInterface::UnselectItem()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_UnselectItem instead.");
	}
	void UInventorySystemInterface::StaticRegisterNativesUInventorySystemInterface()
	{
		UClass* Class = UInventorySystemInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddInventoryItem", &IInventorySystemInterface::execAddInventoryItem },
			{ "GetAllInventoryItems", &IInventorySystemInterface::execGetAllInventoryItems },
			{ "GetSelectedItem", &IInventorySystemInterface::execGetSelectedItem },
			{ "OnBackwardItemChanged", &IInventorySystemInterface::execOnBackwardItemChanged },
			{ "OnForwardItemChanged", &IInventorySystemInterface::execOnForwardItemChanged },
			{ "OnInitInventorySystem", &IInventorySystemInterface::execOnInitInventorySystem },
			{ "RemoveInventoryItem", &IInventorySystemInterface::execRemoveInventoryItem },
			{ "RemoveInventoryItemByIndex", &IInventorySystemInterface::execRemoveInventoryItemByIndex },
			{ "SetInventoryItem", &IInventorySystemInterface::execSetInventoryItem },
			{ "UnselectAllItems", &IInventorySystemInterface::execUnselectAllItems },
			{ "UnselectItem", &IInventorySystemInterface::execUnselectItem },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem_Statics
	{
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_InNewInventoryItem;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem_Statics::NewProp_InNewInventoryItem = { "InNewInventoryItem", nullptr, (EPropertyFlags)0x0014000000000180, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySystemInterface_eventAddInventoryItem_Parms, InNewInventoryItem), Z_Construct_UClass_UInteractibleItemInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem_Statics::NewProp_InNewInventoryItem,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Item" },
		{ "ModuleRelativePath", "Public/Contracts/InventorySystemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySystemInterface, nullptr, "AddInventoryItem", nullptr, nullptr, Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem_Statics::PropPointers), sizeof(InventorySystemInterface_eventAddInventoryItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem_Statics::PropPointers) < 2048);
	static_assert(sizeof(InventorySystemInterface_eventAddInventoryItem_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics
	{
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_OutInventoryItems_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_OutInventoryItems;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics::NewProp_OutInventoryItems_Inner = { "OutInventoryItems", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UInteractibleItemInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics::NewProp_OutInventoryItems = { "OutInventoryItems", nullptr, (EPropertyFlags)0x0014000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySystemInterface_eventGetAllInventoryItems_Parms, OutInventoryItems), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics::NewProp_OutInventoryItems_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics::NewProp_OutInventoryItems,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Item" },
		{ "ModuleRelativePath", "Public/Contracts/InventorySystemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySystemInterface, nullptr, "GetAllInventoryItems", nullptr, nullptr, Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics::PropPointers), sizeof(InventorySystemInterface_eventGetAllInventoryItems_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics::PropPointers) < 2048);
	static_assert(sizeof(InventorySystemInterface_eventGetAllInventoryItems_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem_Statics
	{
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0014000000000580, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySystemInterface_eventGetSelectedItem_Parms, ReturnValue), Z_Construct_UClass_UInteractibleItemInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Item" },
		{ "ModuleRelativePath", "Public/Contracts/InventorySystemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySystemInterface, nullptr, "GetSelectedItem", nullptr, nullptr, Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem_Statics::PropPointers), sizeof(InventorySystemInterface_eventGetSelectedItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem_Statics::PropPointers) < 2048);
	static_assert(sizeof(InventorySystemInterface_eventGetSelectedItem_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventorySystemInterface_OnBackwardItemChanged_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySystemInterface_OnBackwardItemChanged_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Item" },
		{ "ModuleRelativePath", "Public/Contracts/InventorySystemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySystemInterface_OnBackwardItemChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySystemInterface, nullptr, "OnBackwardItemChanged", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_OnBackwardItemChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySystemInterface_OnBackwardItemChanged_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInventorySystemInterface_OnBackwardItemChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySystemInterface_OnBackwardItemChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventorySystemInterface_OnForwardItemChanged_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySystemInterface_OnForwardItemChanged_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Item" },
		{ "ModuleRelativePath", "Public/Contracts/InventorySystemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySystemInterface_OnForwardItemChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySystemInterface, nullptr, "OnForwardItemChanged", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_OnForwardItemChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySystemInterface_OnForwardItemChanged_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInventorySystemInterface_OnForwardItemChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySystemInterface_OnForwardItemChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventorySystemInterface_OnInitInventorySystem_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySystemInterface_OnInitInventorySystem_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Item" },
		{ "ModuleRelativePath", "Public/Contracts/InventorySystemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySystemInterface_OnInitInventorySystem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySystemInterface, nullptr, "OnInitInventorySystem", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_OnInitInventorySystem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySystemInterface_OnInitInventorySystem_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInventorySystemInterface_OnInitInventorySystem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySystemInterface_OnInitInventorySystem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem_Statics
	{
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_InInventoryItem;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem_Statics::NewProp_InInventoryItem = { "InInventoryItem", nullptr, (EPropertyFlags)0x0014000000000180, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySystemInterface_eventRemoveInventoryItem_Parms, InInventoryItem), Z_Construct_UClass_UInteractibleItemInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem_Statics::NewProp_InInventoryItem,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Item" },
		{ "ModuleRelativePath", "Public/Contracts/InventorySystemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySystemInterface, nullptr, "RemoveInventoryItem", nullptr, nullptr, Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem_Statics::PropPointers), sizeof(InventorySystemInterface_eventRemoveInventoryItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem_Statics::PropPointers) < 2048);
	static_assert(sizeof(InventorySystemInterface_eventRemoveInventoryItem_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InInventoryIndex_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_InInventoryIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::NewProp_InInventoryIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::NewProp_InInventoryIndex = { "InInventoryIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySystemInterface_eventRemoveInventoryItemByIndex_Parms, InInventoryIndex), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::NewProp_InInventoryIndex_MetaData), Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::NewProp_InInventoryIndex_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::NewProp_InInventoryIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Item" },
		{ "ModuleRelativePath", "Public/Contracts/InventorySystemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySystemInterface, nullptr, "RemoveInventoryItemByIndex", nullptr, nullptr, Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::PropPointers), sizeof(InventorySystemInterface_eventRemoveInventoryItemByIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::PropPointers) < 2048);
	static_assert(sizeof(InventorySystemInterface_eventRemoveInventoryItemByIndex_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics
	{
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_InInventoryItem;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InInventoryIndex_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_InInventoryIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::NewProp_InInventoryItem = { "InInventoryItem", nullptr, (EPropertyFlags)0x0014000000000180, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySystemInterface_eventSetInventoryItem_Parms, InInventoryItem), Z_Construct_UClass_UInteractibleItemInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::NewProp_InInventoryIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::NewProp_InInventoryIndex = { "InInventoryIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySystemInterface_eventSetInventoryItem_Parms, InInventoryIndex), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::NewProp_InInventoryIndex_MetaData), Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::NewProp_InInventoryIndex_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::NewProp_InInventoryItem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::NewProp_InInventoryIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Item" },
		{ "ModuleRelativePath", "Public/Contracts/InventorySystemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySystemInterface, nullptr, "SetInventoryItem", nullptr, nullptr, Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::PropPointers), sizeof(InventorySystemInterface_eventSetInventoryItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::PropPointers) < 2048);
	static_assert(sizeof(InventorySystemInterface_eventSetInventoryItem_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventorySystemInterface_UnselectAllItems_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySystemInterface_UnselectAllItems_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Item" },
		{ "ModuleRelativePath", "Public/Contracts/InventorySystemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySystemInterface_UnselectAllItems_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySystemInterface, nullptr, "UnselectAllItems", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_UnselectAllItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySystemInterface_UnselectAllItems_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInventorySystemInterface_UnselectAllItems()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySystemInterface_UnselectAllItems_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventorySystemInterface_UnselectItem_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySystemInterface_UnselectItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Item" },
		{ "ModuleRelativePath", "Public/Contracts/InventorySystemInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySystemInterface_UnselectItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySystemInterface, nullptr, "UnselectItem", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySystemInterface_UnselectItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySystemInterface_UnselectItem_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInventorySystemInterface_UnselectItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySystemInterface_UnselectItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInventorySystemInterface);
	UClass* Z_Construct_UClass_UInventorySystemInterface_NoRegister()
	{
		return UInventorySystemInterface::StaticClass();
	}
	struct Z_Construct_UClass_UInventorySystemInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventorySystemInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_CommonContractsPlugin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySystemInterface_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UInventorySystemInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventorySystemInterface_AddInventoryItem, "AddInventoryItem" }, // 2526686553
		{ &Z_Construct_UFunction_UInventorySystemInterface_GetAllInventoryItems, "GetAllInventoryItems" }, // 323488484
		{ &Z_Construct_UFunction_UInventorySystemInterface_GetSelectedItem, "GetSelectedItem" }, // 646861682
		{ &Z_Construct_UFunction_UInventorySystemInterface_OnBackwardItemChanged, "OnBackwardItemChanged" }, // 90619530
		{ &Z_Construct_UFunction_UInventorySystemInterface_OnForwardItemChanged, "OnForwardItemChanged" }, // 3646605978
		{ &Z_Construct_UFunction_UInventorySystemInterface_OnInitInventorySystem, "OnInitInventorySystem" }, // 2872555306
		{ &Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItem, "RemoveInventoryItem" }, // 3128962983
		{ &Z_Construct_UFunction_UInventorySystemInterface_RemoveInventoryItemByIndex, "RemoveInventoryItemByIndex" }, // 1754264350
		{ &Z_Construct_UFunction_UInventorySystemInterface_SetInventoryItem, "SetInventoryItem" }, // 1764976191
		{ &Z_Construct_UFunction_UInventorySystemInterface_UnselectAllItems, "UnselectAllItems" }, // 4249189897
		{ &Z_Construct_UFunction_UInventorySystemInterface_UnselectItem, "UnselectItem" }, // 3821138125
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySystemInterface_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySystemInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Contracts/InventorySystemInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventorySystemInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInventorySystemInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventorySystemInterface_Statics::ClassParams = {
		&UInventorySystemInterface::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySystemInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventorySystemInterface_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInventorySystemInterface()
	{
		if (!Z_Registration_Info_UClass_UInventorySystemInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventorySystemInterface.OuterSingleton, Z_Construct_UClass_UInventorySystemInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInventorySystemInterface.OuterSingleton;
	}
	template<> COMMONCONTRACTSPLUGIN_API UClass* StaticClass<UInventorySystemInterface>()
	{
		return UInventorySystemInterface::StaticClass();
	}
	UInventorySystemInterface::UInventorySystemInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventorySystemInterface);
	UInventorySystemInterface::~UInventorySystemInterface() {}
	static FName NAME_UInventorySystemInterface_AddInventoryItem = FName(TEXT("AddInventoryItem"));
	void IInventorySystemInterface::Execute_AddInventoryItem(UObject* O, TScriptInterface<IInteractibleItemInterface>& InNewInventoryItem)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInventorySystemInterface::StaticClass()));
		InventorySystemInterface_eventAddInventoryItem_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInventorySystemInterface_AddInventoryItem);
		if (Func)
		{
			Parms.InNewInventoryItem=InNewInventoryItem;
			O->ProcessEvent(Func, &Parms);
			InNewInventoryItem=Parms.InNewInventoryItem;
		}
		else if (auto I = (IInventorySystemInterface*)(O->GetNativeInterfaceAddress(UInventorySystemInterface::StaticClass())))
		{
			I->AddInventoryItem_Implementation(InNewInventoryItem);
		}
	}
	static FName NAME_UInventorySystemInterface_GetAllInventoryItems = FName(TEXT("GetAllInventoryItems"));
	void IInventorySystemInterface::Execute_GetAllInventoryItems(UObject* O, TArray<TScriptInterface<IInteractibleItemInterface> >& OutInventoryItems)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInventorySystemInterface::StaticClass()));
		InventorySystemInterface_eventGetAllInventoryItems_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInventorySystemInterface_GetAllInventoryItems);
		if (Func)
		{
			Parms.OutInventoryItems=OutInventoryItems;
			O->ProcessEvent(Func, &Parms);
			OutInventoryItems=Parms.OutInventoryItems;
		}
		else if (auto I = (IInventorySystemInterface*)(O->GetNativeInterfaceAddress(UInventorySystemInterface::StaticClass())))
		{
			I->GetAllInventoryItems_Implementation(OutInventoryItems);
		}
	}
	static FName NAME_UInventorySystemInterface_GetSelectedItem = FName(TEXT("GetSelectedItem"));
	TScriptInterface<IInteractibleItemInterface> IInventorySystemInterface::Execute_GetSelectedItem(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInventorySystemInterface::StaticClass()));
		InventorySystemInterface_eventGetSelectedItem_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInventorySystemInterface_GetSelectedItem);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInventorySystemInterface*)(O->GetNativeInterfaceAddress(UInventorySystemInterface::StaticClass())))
		{
			Parms.ReturnValue = I->GetSelectedItem_Implementation();
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UInventorySystemInterface_OnBackwardItemChanged = FName(TEXT("OnBackwardItemChanged"));
	void IInventorySystemInterface::Execute_OnBackwardItemChanged(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInventorySystemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInventorySystemInterface_OnBackwardItemChanged);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInventorySystemInterface*)(O->GetNativeInterfaceAddress(UInventorySystemInterface::StaticClass())))
		{
			I->OnBackwardItemChanged_Implementation();
		}
	}
	static FName NAME_UInventorySystemInterface_OnForwardItemChanged = FName(TEXT("OnForwardItemChanged"));
	void IInventorySystemInterface::Execute_OnForwardItemChanged(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInventorySystemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInventorySystemInterface_OnForwardItemChanged);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInventorySystemInterface*)(O->GetNativeInterfaceAddress(UInventorySystemInterface::StaticClass())))
		{
			I->OnForwardItemChanged_Implementation();
		}
	}
	static FName NAME_UInventorySystemInterface_OnInitInventorySystem = FName(TEXT("OnInitInventorySystem"));
	void IInventorySystemInterface::Execute_OnInitInventorySystem(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInventorySystemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInventorySystemInterface_OnInitInventorySystem);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInventorySystemInterface*)(O->GetNativeInterfaceAddress(UInventorySystemInterface::StaticClass())))
		{
			I->OnInitInventorySystem_Implementation();
		}
	}
	static FName NAME_UInventorySystemInterface_RemoveInventoryItem = FName(TEXT("RemoveInventoryItem"));
	void IInventorySystemInterface::Execute_RemoveInventoryItem(UObject* O, TScriptInterface<IInteractibleItemInterface>& InInventoryItem)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInventorySystemInterface::StaticClass()));
		InventorySystemInterface_eventRemoveInventoryItem_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInventorySystemInterface_RemoveInventoryItem);
		if (Func)
		{
			Parms.InInventoryItem=InInventoryItem;
			O->ProcessEvent(Func, &Parms);
			InInventoryItem=Parms.InInventoryItem;
		}
		else if (auto I = (IInventorySystemInterface*)(O->GetNativeInterfaceAddress(UInventorySystemInterface::StaticClass())))
		{
			I->RemoveInventoryItem_Implementation(InInventoryItem);
		}
	}
	static FName NAME_UInventorySystemInterface_RemoveInventoryItemByIndex = FName(TEXT("RemoveInventoryItemByIndex"));
	void IInventorySystemInterface::Execute_RemoveInventoryItemByIndex(UObject* O, const int32 InInventoryIndex)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInventorySystemInterface::StaticClass()));
		InventorySystemInterface_eventRemoveInventoryItemByIndex_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInventorySystemInterface_RemoveInventoryItemByIndex);
		if (Func)
		{
			Parms.InInventoryIndex=InInventoryIndex;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInventorySystemInterface*)(O->GetNativeInterfaceAddress(UInventorySystemInterface::StaticClass())))
		{
			I->RemoveInventoryItemByIndex_Implementation(InInventoryIndex);
		}
	}
	static FName NAME_UInventorySystemInterface_SetInventoryItem = FName(TEXT("SetInventoryItem"));
	void IInventorySystemInterface::Execute_SetInventoryItem(UObject* O, TScriptInterface<IInteractibleItemInterface>& InInventoryItem, const int32 InInventoryIndex)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInventorySystemInterface::StaticClass()));
		InventorySystemInterface_eventSetInventoryItem_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInventorySystemInterface_SetInventoryItem);
		if (Func)
		{
			Parms.InInventoryItem=InInventoryItem;
			Parms.InInventoryIndex=InInventoryIndex;
			O->ProcessEvent(Func, &Parms);
			InInventoryItem=Parms.InInventoryItem;
		}
		else if (auto I = (IInventorySystemInterface*)(O->GetNativeInterfaceAddress(UInventorySystemInterface::StaticClass())))
		{
			I->SetInventoryItem_Implementation(InInventoryItem,InInventoryIndex);
		}
	}
	static FName NAME_UInventorySystemInterface_UnselectAllItems = FName(TEXT("UnselectAllItems"));
	void IInventorySystemInterface::Execute_UnselectAllItems(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInventorySystemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInventorySystemInterface_UnselectAllItems);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInventorySystemInterface*)(O->GetNativeInterfaceAddress(UInventorySystemInterface::StaticClass())))
		{
			I->UnselectAllItems_Implementation();
		}
	}
	static FName NAME_UInventorySystemInterface_UnselectItem = FName(TEXT("UnselectItem"));
	void IInventorySystemInterface::Execute_UnselectItem(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInventorySystemInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInventorySystemInterface_UnselectItem);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInventorySystemInterface*)(O->GetNativeInterfaceAddress(UInventorySystemInterface::StaticClass())))
		{
			I->UnselectItem_Implementation();
		}
	}
	struct Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInventorySystemInterface, UInventorySystemInterface::StaticClass, TEXT("UInventorySystemInterface"), &Z_Registration_Info_UClass_UInventorySystemInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventorySystemInterface), 2141143979U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_689096285(TEXT("/Script/CommonContractsPlugin"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_Contracts_InventorySystemInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
