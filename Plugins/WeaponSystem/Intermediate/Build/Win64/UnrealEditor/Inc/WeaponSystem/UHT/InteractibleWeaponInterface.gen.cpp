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
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	UPackage* Z_Construct_UPackage__Script_WeaponSystem();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UInteractibleWeaponInterface();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UInteractibleWeaponInterface_NoRegister();
	WEAPONSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FWeaponsDataStruct();
// End Cross Module References
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execInternal_Initialize)
	{
		P_GET_STRUCT_REF(FWeaponsDataStruct,Z_Param_Out_InInitialWeaponStruct);
		P_GET_UBOOL(Z_Param_bAlternative);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Internal_Initialize_Implementation(Z_Param_Out_InInitialWeaponStruct,Z_Param_bAlternative);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execIsAimMode)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsAimMode_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execSetAimMode)
	{
		P_GET_UBOOL(Z_Param_bAim);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetAimMode_Implementation(Z_Param_bAim);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execGetFireSocketTransform)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_InSocketName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FTransform*)Z_Param__Result=P_THIS->GetFireSocketTransform_Implementation(Z_Param_Out_InSocketName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execToggleWeaponMode)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ToggleWeaponMode_Implementation();
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
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execGetAmmoPerStore)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetAmmoPerStore_Implementation();
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
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execOnUseAlternativeFire)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnUseAlternativeFire_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractibleWeaponInterface::execOnUseMainFire)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnUseMainFire_Implementation();
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
	struct InteractibleWeaponInterface_eventGetAmmoPerStore_Parms
	{
		int32 ReturnValue;

		/** Constructor, initializes return property only **/
		InteractibleWeaponInterface_eventGetAmmoPerStore_Parms()
			: ReturnValue(0)
		{
		}
	};
	struct InteractibleWeaponInterface_eventGetFireSocketTransform_Parms
	{
		FName InSocketName;
		FTransform ReturnValue;
	};
	struct InteractibleWeaponInterface_eventInternal_Initialize_Parms
	{
		FWeaponsDataStruct InInitialWeaponStruct;
		bool bAlternative;
	};
	struct InteractibleWeaponInterface_eventIsAimMode_Parms
	{
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		InteractibleWeaponInterface_eventIsAimMode_Parms()
			: ReturnValue(false)
		{
		}
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
	struct InteractibleWeaponInterface_eventSetAimMode_Parms
	{
		bool bAim;
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
	int32 IInteractibleWeaponInterface::GetAmmoPerStore()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetAmmoPerStore instead.");
		InteractibleWeaponInterface_eventGetAmmoPerStore_Parms Parms;
		return Parms.ReturnValue;
	}
	FTransform IInteractibleWeaponInterface::GetFireSocketTransform(FName const& InSocketName)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetFireSocketTransform instead.");
		InteractibleWeaponInterface_eventGetFireSocketTransform_Parms Parms;
		return Parms.ReturnValue;
	}
	void IInteractibleWeaponInterface::InitializeWeapon()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_InitializeWeapon instead.");
	}
	void IInteractibleWeaponInterface::Internal_Initialize(FWeaponsDataStruct const& InInitialWeaponStruct, bool bAlternative)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_Internal_Initialize instead.");
	}
	bool IInteractibleWeaponInterface::IsAimMode()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_IsAimMode instead.");
		InteractibleWeaponInterface_eventIsAimMode_Parms Parms;
		return Parms.ReturnValue;
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
	void IInteractibleWeaponInterface::OnUseAlternativeFire()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnUseAlternativeFire instead.");
	}
	void IInteractibleWeaponInterface::OnUseMainFire()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnUseMainFire instead.");
	}
	void IInteractibleWeaponInterface::SetAimMode(bool bAim)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_SetAimMode instead.");
	}
	void IInteractibleWeaponInterface::SetAmmo(const int32 InNewAmmoValue)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_SetAmmo instead.");
	}
	void IInteractibleWeaponInterface::ToggleWeaponMode()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ToggleWeaponMode instead.");
	}
	void UInteractibleWeaponInterface::StaticRegisterNativesUInteractibleWeaponInterface()
	{
		UClass* Class = UInteractibleWeaponInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddAmmo", &IInteractibleWeaponInterface::execAddAmmo },
			{ "GetAmmo", &IInteractibleWeaponInterface::execGetAmmo },
			{ "GetAmmoPerStore", &IInteractibleWeaponInterface::execGetAmmoPerStore },
			{ "GetFireSocketTransform", &IInteractibleWeaponInterface::execGetFireSocketTransform },
			{ "InitializeWeapon", &IInteractibleWeaponInterface::execInitializeWeapon },
			{ "Internal_Initialize", &IInteractibleWeaponInterface::execInternal_Initialize },
			{ "IsAimMode", &IInteractibleWeaponInterface::execIsAimMode },
			{ "IsReloading", &IInteractibleWeaponInterface::execIsReloading },
			{ "OnFireStart", &IInteractibleWeaponInterface::execOnFireStart },
			{ "OnFireStop", &IInteractibleWeaponInterface::execOnFireStop },
			{ "OnReload", &IInteractibleWeaponInterface::execOnReload },
			{ "OnUseAlternativeFire", &IInteractibleWeaponInterface::execOnUseAlternativeFire },
			{ "OnUseMainFire", &IInteractibleWeaponInterface::execOnUseMainFire },
			{ "SetAimMode", &IInteractibleWeaponInterface::execSetAimMode },
			{ "SetAmmo", &IInteractibleWeaponInterface::execSetAmmo },
			{ "ToggleWeaponMode", &IInteractibleWeaponInterface::execToggleWeaponMode },
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
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractibleWeaponInterface_eventGetAmmoPerStore_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "GetAmmoPerStore", nullptr, nullptr, Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore_Statics::PropPointers), sizeof(InteractibleWeaponInterface_eventGetAmmoPerStore_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleWeaponInterface_eventGetAmmoPerStore_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InSocketName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_InSocketName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::NewProp_InSocketName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::NewProp_InSocketName = { "InSocketName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractibleWeaponInterface_eventGetFireSocketTransform_Parms, InSocketName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::NewProp_InSocketName_MetaData), Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::NewProp_InSocketName_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractibleWeaponInterface_eventGetFireSocketTransform_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::NewProp_InSocketName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "GetFireSocketTransform", nullptr, nullptr, Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::PropPointers), sizeof(InteractibleWeaponInterface_eventGetFireSocketTransform_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleWeaponInterface_eventGetFireSocketTransform_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform_Statics::FuncParams);
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAlternative_MetaData[];
#endif
		static void NewProp_bAlternative_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAlternative;
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_InInitialWeaponStruct = { "InInitialWeaponStruct", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractibleWeaponInterface_eventInternal_Initialize_Parms, InInitialWeaponStruct), Z_Construct_UScriptStruct_FWeaponsDataStruct, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_InInitialWeaponStruct_MetaData), Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_InInitialWeaponStruct_MetaData) }; // 4134014018
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_bAlternative_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_bAlternative_SetBit(void* Obj)
	{
		((InteractibleWeaponInterface_eventInternal_Initialize_Parms*)Obj)->bAlternative = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_bAlternative = { "bAlternative", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InteractibleWeaponInterface_eventInternal_Initialize_Parms), &Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_bAlternative_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_bAlternative_MetaData), Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_bAlternative_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_InInitialWeaponStruct,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize_Statics::NewProp_bAlternative,
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
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((InteractibleWeaponInterface_eventIsAimMode_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InteractibleWeaponInterface_eventIsAimMode_Parms), &Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "IsAimMode", nullptr, nullptr, Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics::PropPointers), sizeof(InteractibleWeaponInterface_eventIsAimMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleWeaponInterface_eventIsAimMode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode_Statics::FuncParams);
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
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseAlternativeFire_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseAlternativeFire_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseAlternativeFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "OnUseAlternativeFire", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseAlternativeFire_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseAlternativeFire_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseAlternativeFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseAlternativeFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseMainFire_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseMainFire_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseMainFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "OnUseMainFire", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseMainFire_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseMainFire_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseMainFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseMainFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAim_MetaData[];
#endif
		static void NewProp_bAim_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAim;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::NewProp_bAim_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::NewProp_bAim_SetBit(void* Obj)
	{
		((InteractibleWeaponInterface_eventSetAimMode_Parms*)Obj)->bAim = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::NewProp_bAim = { "bAim", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InteractibleWeaponInterface_eventSetAimMode_Parms), &Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::NewProp_bAim_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::NewProp_bAim_MetaData), Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::NewProp_bAim_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::NewProp_bAim,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "SetAimMode", nullptr, nullptr, Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::PropPointers), sizeof(InteractibleWeaponInterface_eventSetAimMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleWeaponInterface_eventSetAimMode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode_Statics::FuncParams);
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
	struct Z_Construct_UFunction_UInteractibleWeaponInterface_ToggleWeaponMode_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractibleWeaponInterface_ToggleWeaponMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Public/Contracts/InteractibleWeaponInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractibleWeaponInterface_ToggleWeaponMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractibleWeaponInterface, nullptr, "ToggleWeaponMode", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractibleWeaponInterface_ToggleWeaponMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractibleWeaponInterface_ToggleWeaponMode_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInteractibleWeaponInterface_ToggleWeaponMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractibleWeaponInterface_ToggleWeaponMode_Statics::FuncParams);
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
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_GetAmmoPerStore, "GetAmmoPerStore" }, // 1006445304
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_GetFireSocketTransform, "GetFireSocketTransform" }, // 2392197127
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_InitializeWeapon, "InitializeWeapon" }, // 2831802670
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_Internal_Initialize, "Internal_Initialize" }, // 1978617827
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_IsAimMode, "IsAimMode" }, // 2246906246
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_IsReloading, "IsReloading" }, // 174040517
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStart, "OnFireStart" }, // 1129078472
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_OnFireStop, "OnFireStop" }, // 3275243451
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_OnReload, "OnReload" }, // 2626629546
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseAlternativeFire, "OnUseAlternativeFire" }, // 876068275
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_OnUseMainFire, "OnUseMainFire" }, // 2676361660
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_SetAimMode, "SetAimMode" }, // 753475212
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_SetAmmo, "SetAmmo" }, // 2105852026
		{ &Z_Construct_UFunction_UInteractibleWeaponInterface_ToggleWeaponMode, "ToggleWeaponMode" }, // 2755618952
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
	static FName NAME_UInteractibleWeaponInterface_GetAmmoPerStore = FName(TEXT("GetAmmoPerStore"));
	int32 IInteractibleWeaponInterface::Execute_GetAmmoPerStore(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		InteractibleWeaponInterface_eventGetAmmoPerStore_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_GetAmmoPerStore);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			Parms.ReturnValue = I->GetAmmoPerStore_Implementation();
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UInteractibleWeaponInterface_GetFireSocketTransform = FName(TEXT("GetFireSocketTransform"));
	FTransform IInteractibleWeaponInterface::Execute_GetFireSocketTransform(UObject* O, FName const& InSocketName)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		InteractibleWeaponInterface_eventGetFireSocketTransform_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_GetFireSocketTransform);
		if (Func)
		{
			Parms.InSocketName=InSocketName;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			Parms.ReturnValue = I->GetFireSocketTransform_Implementation(InSocketName);
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
	void IInteractibleWeaponInterface::Execute_Internal_Initialize(UObject* O, FWeaponsDataStruct const& InInitialWeaponStruct, bool bAlternative)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		InteractibleWeaponInterface_eventInternal_Initialize_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_Internal_Initialize);
		if (Func)
		{
			Parms.InInitialWeaponStruct=InInitialWeaponStruct;
			Parms.bAlternative=bAlternative;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			I->Internal_Initialize_Implementation(InInitialWeaponStruct,bAlternative);
		}
	}
	static FName NAME_UInteractibleWeaponInterface_IsAimMode = FName(TEXT("IsAimMode"));
	bool IInteractibleWeaponInterface::Execute_IsAimMode(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		InteractibleWeaponInterface_eventIsAimMode_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_IsAimMode);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			Parms.ReturnValue = I->IsAimMode_Implementation();
		}
		return Parms.ReturnValue;
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
	static FName NAME_UInteractibleWeaponInterface_OnUseAlternativeFire = FName(TEXT("OnUseAlternativeFire"));
	void IInteractibleWeaponInterface::Execute_OnUseAlternativeFire(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_OnUseAlternativeFire);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			I->OnUseAlternativeFire_Implementation();
		}
	}
	static FName NAME_UInteractibleWeaponInterface_OnUseMainFire = FName(TEXT("OnUseMainFire"));
	void IInteractibleWeaponInterface::Execute_OnUseMainFire(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_OnUseMainFire);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			I->OnUseMainFire_Implementation();
		}
	}
	static FName NAME_UInteractibleWeaponInterface_SetAimMode = FName(TEXT("SetAimMode"));
	void IInteractibleWeaponInterface::Execute_SetAimMode(UObject* O, bool bAim)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		InteractibleWeaponInterface_eventSetAimMode_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_SetAimMode);
		if (Func)
		{
			Parms.bAim=bAim;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			I->SetAimMode_Implementation(bAim);
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
	static FName NAME_UInteractibleWeaponInterface_ToggleWeaponMode = FName(TEXT("ToggleWeaponMode"));
	void IInteractibleWeaponInterface::Execute_ToggleWeaponMode(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractibleWeaponInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInteractibleWeaponInterface_ToggleWeaponMode);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInteractibleWeaponInterface*)(O->GetNativeInterfaceAddress(UInteractibleWeaponInterface::StaticClass())))
		{
			I->ToggleWeaponMode_Implementation();
		}
	}
	struct Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInteractibleWeaponInterface, UInteractibleWeaponInterface::StaticClass, TEXT("UInteractibleWeaponInterface"), &Z_Registration_Info_UClass_UInteractibleWeaponInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInteractibleWeaponInterface), 2132437005U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_575373842(TEXT("/Script/WeaponSystem"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_Contracts_InteractibleWeaponInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
