// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponSystem/Public/Contracts/InteractibleWeaponInterface.h"
#include "WeaponSystem/Public/DataStructs/WeaponsDataStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInteractibleWeaponInterface() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_WeaponSystem();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UInteractibleWeaponInterface();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UInteractibleWeaponInterface_NoRegister();
	WEAPONSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FWeaponsDataStruct();
// End Cross Module References
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execInternal_Initialize)
	{
		P_GET_STRUCT_REF(FWeaponsDataStruct,Z_Param_Out_InInitialWeaponStruct);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Internal_Initialize_Implementation(Z_Param_Out_InInitialWeaponStruct);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execAddAmmo)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_InAmmoValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddAmmo_Implementation(Z_Param_InAmmoValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execSetAmmo)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_InNewAmmoValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetAmmo_Implementation(Z_Param_InNewAmmoValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execGetAmmo)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetAmmo_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execInitializeWeapon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InitializeWeapon_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execIsReloading)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsReloading_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execOnReload)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnReload_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execOnFireStop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnFireStop_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execOnFireStart)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnFireStart_Implementation();
		P_NATIVE_END;
	}
	struct InteractibleWeaponInterface_eventAddAmmo_Parms
	{
		int32 InAmmoValue;
	};
	struct InteractibleWeaponInterface_eventGetAmmo_Parms
	{
		int32 ReturnValue;

		/** Constructor, initializes return property only **/
		InteractibleWeaponInterface_eventGetAmmo_Parms()
			: ReturnValue(0)
		{
		}
	};
	struct InteractibleWeaponInterface_eventInternal_Initialize_Parms
	{
		FWeaponsDataStruct InInitialWeaponStruct;
	};
	struct InteractibleWeaponInterface_eventIsReloading_Parms
	{
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		InteractibleWeaponInterface_eventIsReloading_Parms()
			: ReturnValue(false)
		{
		}
	};
	struct InteractibleWeaponInterface_eventSetAmmo_Parms
	{
		int32 InNewAmmoValue;
	};
	void IInteractibleWeaponInterface::AddAmmo(const int32 InAmmoValue)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_AddAmmo instead.");
	}
	int32 IInteractibleWeaponInterface::GetAmmo()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetAmmo instead.");
		InteractibleWeaponInterface_eventGetAmmo_Parms Parms;
		return Parms.ReturnValue;
	}
	void IInteractibleWeaponInterface::InitializeWeapon()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_InitializeWeapon instead.");
	}
	void IInteractibleWeaponInterface::Internal_Initialize(FWeaponsDataStruct const& InInitialWeaponStruct)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_Internal_Initialize instead.");
	}
	bool IInteractibleWeaponInterface::IsReloading()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_IsReloading instead.");
		InteractibleWeaponInterface_eventIsReloading_Parms Parms;
		return Parms.ReturnValue;
	}
	void IInteractibleWeaponInterface::OnFireStart()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnFireStart instead.");
	}
	void IInteractibleWeaponInterface::OnFireStop()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnFireStop instead.");
	}
	void IInteractibleWeaponInterface::OnReload()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnReload instead.");
	}
	void IInteractibleWeaponInterface::SetAmmo(const int32 InNewAmmoValue)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_SetAmmo instead.");
	}
	void UInteractibleWeaponInterface::StaticRegisterNativesUInteractibleWeaponInterface()
	{
		UClass* Class = UInteractibleWeaponInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddAmmo", &IInteractibleWeaponInterface::execAddAmmo },
			{ "GetAmmo", &IInteractibleWeaponInterface::execGetAmmo },
			{ "InitializeWeapon", &IInteractibleWeaponInterface::execInitializeWeapon },
			{ "Internal_Initialize", &IInteractibleWeaponInterface::execInternal_Initialize },
			{ "IsReloading", &IInteractibleWeaponInterface::execIsReloading },
			{ "OnFireStart", &IInteractibleWeaponInterface::execOnFireStart },
			{ "OnFireStop", &IInteractibleWeaponInterface::execOnFireStop },
			{ "OnReload", &IInteractibleWeaponInterface::execOnReload },
			{ "SetAmmo", &IInteractibleWeaponInterface::execSetAmmo },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InAmmoValue_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_InAmmoValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::NewProp_InAmmoValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::NewProp_InAmmoValue = { "InAmmoValue", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractibleWeaponInterface_eventAddAmmo_Parms, InAmmoValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::NewProp_InAmmoValue_MetaData), Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::NewProp_InAmmoValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::NewProp_InAmmoValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "AddAmmo", nullptr, nullptr, Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::PropPointers), sizeof(InteractibleWeaponInterface_eventAddAmmo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleWeaponInterface_eventAddAmmo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractibleWeaponInterface_eventGetAmmo_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "GetAmmo", nullptr, nullptr, Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo_Statics::PropPointers), sizeof(InteractibleWeaponInterface_eventGetAmmo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleWeaponInterface_eventGetAmmo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_InitializeWeapon_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_InitializeWeapon_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_InitializeWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "InitializeWeapon", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_InitializeWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_InitializeWeapon_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_InitializeWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_InitializeWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InInitialWeaponStruct_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InInitialWeaponStruct;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_InInitialWeaponStruct_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_InInitialWeaponStruct = { "InInitialWeaponStruct", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractibleWeaponInterface_eventInternal_Initialize_Parms, InInitialWeaponStruct), Z_Construct_UScriptStruct_FWeaponsDataStruct, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_InInitialWeaponStruct_MetaData), Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_InInitialWeaponStruct_MetaData) }; // 582785028
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_InInitialWeaponStruct,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Internal" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "Internal_Initialize", nullptr, nullptr, Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::PropPointers), sizeof(InteractibleWeaponInterface_eventInternal_Initialize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleWeaponInterface_eventInternal_Initialize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((InteractibleWeaponInterface_eventIsReloading_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InteractibleWeaponInterface_eventIsReloading_Parms), &Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "IsReloading", nullptr, nullptr, Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics::PropPointers), sizeof(InteractibleWeaponInterface_eventIsReloading_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleWeaponInterface_eventIsReloading_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStart_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStart_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "OnFireStart", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStart_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStop_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStop_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "OnFireStop", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStop_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStop_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_OnReload_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_OnReload_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_OnReload_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "OnReload", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_OnReload_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_OnReload_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_OnReload()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_OnReload_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InNewAmmoValue_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_InNewAmmoValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::NewProp_InNewAmmoValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::NewProp_InNewAmmoValue = { "InNewAmmoValue", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractibleWeaponInterface_eventSetAmmo_Parms, InNewAmmoValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::NewProp_InNewAmmoValue_MetaData), Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::NewProp_InNewAmmoValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::NewProp_InNewAmmoValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "SetAmmo", nullptr, nullptr, Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::PropPointers), sizeof(InteractibleWeaponInterface_eventSetAmmo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleWeaponInterface_eventSetAmmo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInteractibleWeaponInterface);
	UClass* Z_Construct_UClass_UInteractibleWeaponInterface_NoRegister()
	{
		return UInteractibleWeaponInterface::StaticClass();
	}
	struct Z_Construct_UClass_UInteractibleWeaponInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInteractibleWeaponInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_WeaponSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInteractibleWeaponInterface_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UInteractibleWeaponInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_AddAmmo, "AddAmmo" }, // 3619774732
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmo, "GetAmmo" }, // 681415270
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_InitializeWeapon, "InitializeWeapon" }, // 2831802670
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize, "Internal_Initialize" }, // 3973905586
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading, "IsReloading" }, // 174040517
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStart, "OnFireStart" }, // 1129078472
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStop, "OnFireStop" }, // 3275243451
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_OnReload, "OnReload" }, // 2626629546
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo, "SetAmmo" }, // 2105852026
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInteractibleWeaponInterface_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInteractibleWeaponInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInteractibleWeaponInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInteractibleWeaponInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInteractibleWeaponInterface_Statics::ClassParams = {
		&UInteractibleWeaponInterface::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInteractibleWeaponInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UInteractibleWeaponInterface_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInteractibleWeaponInterface()
	{
		if (!Z_Registration_Info_UClass_UInteractibleWeaponInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInteractibleWeaponInterface.OuterSingleton, Z_Construct_UClass_UInteractibleWeaponInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInteractibleWeaponInterface.OuterSingleton;
	}
	template<> WEAPONSYSTEM_API UClass* StaticClass<UInteractibleWeaponInterface>()
	{
		return UInteractibleWeaponInterface::StaticClass();
	}
	UInteractibleWeaponInterface::UInteractibleWeaponInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInteractibleWeaponInterface);
	UInteractibleWeaponInterface::~UInteractibleWeaponInterface() {}
	static FName NAME_UInteractibleWeaponInterface_AddAmmo = FName(TEXT("AddAmmo"));
	void IInteractibleWeaponInterface::Execute_AddAmmo(UObject* O, const int32 InAmmoValue)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		InteractibleWeaponInterface_eventAddAmmo_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_AddAmmo);
		if (Func)
		{
			Parms.InAmmoValue=InAmmoValue;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			I->AddAmmo_Implementation(InAmmoValue);
		}
	}
	static FName NAME_UInteractibleWeaponInterface_GetAmmo = FName(TEXT("GetAmmo"));
	int32 IInteractibleWeaponInterface::Execute_GetAmmo(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		InteractibleWeaponInterface_eventGetAmmo_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_GetAmmo);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			Parms.ReturnValue = I->GetAmmo_Implementation();
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UInteractibleWeaponInterface_InitializeWeapon = FName(TEXT("InitializeWeapon"));
	void IInteractibleWeaponInterface::Execute_InitializeWeapon(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_InitializeWeapon);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			I->InitializeWeapon_Implementation();
		}
	}
	static FName NAME_UInteractibleWeaponInterface_Internal_Initialize = FName(TEXT("Internal_Initialize"));
	void IInteractibleWeaponInterface::Execute_Internal_Initialize(UObject* O, FWeaponsDataStruct const& InInitialWeaponStruct)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		InteractibleWeaponInterface_eventInternal_Initialize_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_Internal_Initialize);
		if (Func)
		{
			Parms.InInitialWeaponStruct=InInitialWeaponStruct;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			I->Internal_Initialize_Implementation(InInitialWeaponStruct);
		}
	}
	static FName NAME_UInteractibleWeaponInterface_IsReloading = FName(TEXT("IsReloading"));
	bool IInteractibleWeaponInterface::Execute_IsReloading(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		InteractibleWeaponInterface_eventIsReloading_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_IsReloading);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			Parms.ReturnValue = I->IsReloading_Implementation();
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UInteractibleWeaponInterface_OnFireStart = FName(TEXT("OnFireStart"));
	void IInteractibleWeaponInterface::Execute_OnFireStart(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_OnFireStart);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			I->OnFireStart_Implementation();
		}
	}
	static FName NAME_UInteractibleWeaponInterface_OnFireStop = FName(TEXT("OnFireStop"));
	void IInteractibleWeaponInterface::Execute_OnFireStop(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_OnFireStop);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			I->OnFireStop_Implementation();
		}
	}
	static FName NAME_UInteractibleWeaponInterface_OnReload = FName(TEXT("OnReload"));
	void IInteractibleWeaponInterface::Execute_OnReload(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_OnReload);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			I->OnReload_Implementation();
		}
	}
	static FName NAME_UInteractibleWeaponInterface_SetAmmo = FName(TEXT("SetAmmo"));
	void IInteractibleWeaponInterface::Execute_SetAmmo(UObject* O, const int32 InNewAmmoValue)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		InteractibleWeaponInterface_eventSetAmmo_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_SetAmmo);
		if (Func)
		{
			Parms.InNewAmmoValue=InNewAmmoValue;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			I->SetAmmo_Implementation(InNewAmmoValue);
		}
	}
	struct Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInteractibleWeaponInterface, UInteractibleWeaponInterface::StaticClass, TEXT("UInteractibleWeaponInterface"), &Z_Registration_Info_UClass_UInteractibleWeaponInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInteractibleWeaponInterface), 2661966974U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_34646908(TEXT("/Script/WeaponSystem"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
