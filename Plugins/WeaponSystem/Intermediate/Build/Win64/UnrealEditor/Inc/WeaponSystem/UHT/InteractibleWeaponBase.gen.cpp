// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponSystem/Public/WeaponActors/InteractibleWeaponBase.h"
#include "WeaponSystem/Public/DataStructs/WeaponsDataStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInteractibleWeaponBase() {}
// Cross Module References
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UInteractibleItemInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	UPackage* Z_Construct_UPackage__Script_WeaponSystem();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_AInteractibleWeaponBase();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_AInteractibleWeaponBase_NoRegister();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_UInteractibleWeaponInterface_NoRegister();
	WEAPONSYSTEM_API UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature();
	WEAPONSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FWeaponsDataStruct();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics
	{
		struct _Script_WeaponSystem_eventOnAlternativeFireChanged_Parms
		{
			bool Value;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((_Script_WeaponSystem_eventOnAlternativeFireChanged_Parms*)Obj)->Value = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_WeaponSystem_eventOnAlternativeFireChanged_Parms), &Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::NewProp_Value_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_WeaponSystem, nullptr, "OnAlternativeFireChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::_Script_WeaponSystem_eventOnAlternativeFireChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::_Script_WeaponSystem_eventOnAlternativeFireChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnAlternativeFireChanged_DelegateWrapper(const FMulticastScriptDelegate& OnAlternativeFireChanged, bool Value)
{
	struct _Script_WeaponSystem_eventOnAlternativeFireChanged_Parms
	{
		bool Value;
	};
	_Script_WeaponSystem_eventOnAlternativeFireChanged_Parms Parms;
	Parms.Value=Value ? true : false;
	OnAlternativeFireChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(AInteractibleWeaponBase::execOnLoadComplete)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnLoadComplete();
		P_NATIVE_END;
	}
	struct InteractibleWeaponBase_eventK2_OnAimModeChanged_Parms
	{
		bool bIsAim;
	};
	static FName NAME_AInteractibleWeaponBase_K2_OnAimModeChanged = FName(TEXT("K2_OnAimModeChanged"));
	void AInteractibleWeaponBase::K2_OnAimModeChanged(bool bIsAim)
	{
		InteractibleWeaponBase_eventK2_OnAimModeChanged_Parms Parms;
		Parms.bIsAim=bIsAim ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_AInteractibleWeaponBase_K2_OnAimModeChanged),&Parms);
	}
	static FName NAME_AInteractibleWeaponBase_K2_OnFire = FName(TEXT("K2_OnFire"));
	void AInteractibleWeaponBase::K2_OnFire()
	{
		ProcessEvent(FindFunctionChecked(NAME_AInteractibleWeaponBase_K2_OnFire),NULL);
	}
	static FName NAME_AInteractibleWeaponBase_K2_OnFireMiss = FName(TEXT("K2_OnFireMiss"));
	void AInteractibleWeaponBase::K2_OnFireMiss()
	{
		ProcessEvent(FindFunctionChecked(NAME_AInteractibleWeaponBase_K2_OnFireMiss),NULL);
	}
	static FName NAME_AInteractibleWeaponBase_K2_OnReload = FName(TEXT("K2_OnReload"));
	void AInteractibleWeaponBase::K2_OnReload()
	{
		ProcessEvent(FindFunctionChecked(NAME_AInteractibleWeaponBase_K2_OnReload),NULL);
	}
	void AInteractibleWeaponBase::StaticRegisterNativesAInteractibleWeaponBase()
	{
		UClass* Class = AInteractibleWeaponBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnLoadComplete", &AInteractibleWeaponBase::execOnLoadComplete },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsAim_MetaData[];
#endif
		static void NewProp_bIsAim_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAim;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::NewProp_bIsAim_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::NewProp_bIsAim_SetBit(void* Obj)
	{
		((InteractibleWeaponBase_eventK2_OnAimModeChanged_Parms*)Obj)->bIsAim = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::NewProp_bIsAim = { "bIsAim", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InteractibleWeaponBase_eventK2_OnAimModeChanged_Parms), &Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::NewProp_bIsAim_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::NewProp_bIsAim_MetaData), Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::NewProp_bIsAim_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::NewProp_bIsAim,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInteractibleWeaponBase, nullptr, "K2_OnAimModeChanged", nullptr, nullptr, Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::PropPointers), sizeof(InteractibleWeaponBase_eventK2_OnAimModeChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::PropPointers) < 2048);
	static_assert(sizeof(InteractibleWeaponBase_eventK2_OnAimModeChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFire_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFire_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInteractibleWeaponBase, nullptr, "K2_OnFire", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFire_Statics::Function_MetaDataParams), Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFire_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFireMiss_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFireMiss_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFireMiss_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInteractibleWeaponBase, nullptr, "K2_OnFireMiss", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFireMiss_Statics::Function_MetaDataParams), Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFireMiss_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFireMiss()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFireMiss_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnReload_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnReload_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnReload_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInteractibleWeaponBase, nullptr, "K2_OnReload", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnReload_Statics::Function_MetaDataParams), Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnReload_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnReload()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnReload_Statics::FuncParams);
		}
		return ReturnFunction;
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoxCollision_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_BoxCollision;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponSkeletalMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_WeaponSkeletalMeshComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnAlternativeFireChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAlternativeFireChanged;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MainFire_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_MainFire;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AlternativeFire_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_AlternativeFire;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Reload_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_Reload;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AimMode_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_AimMode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_MappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InitialWeaponStruct_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InitialWeaponStruct;
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
		{ &Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnAimModeChanged, "K2_OnAimModeChanged" }, // 2082296069
		{ &Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFire, "K2_OnFire" }, // 1583298135
		{ &Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnFireMiss, "K2_OnFireMiss" }, // 1708177053
		{ &Z_Construct_UFunction_AInteractibleWeaponBase_K2_OnReload, "K2_OnReload" }, // 1463797590
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_BoxCollision_MetaData[] = {
		{ "Category", "InteractibleWeaponBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_BoxCollision = { "BoxCollision", nullptr, (EPropertyFlags)0x00140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInteractibleWeaponBase, BoxCollision), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_BoxCollision_MetaData), Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_BoxCollision_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponSkeletalMeshComponent_MetaData[] = {
		{ "Category", "InteractibleWeaponBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponSkeletalMeshComponent = { "WeaponSkeletalMeshComponent", nullptr, (EPropertyFlags)0x00140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInteractibleWeaponBase, WeaponSkeletalMeshComponent), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponSkeletalMeshComponent_MetaData), Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponSkeletalMeshComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_OnAlternativeFireChanged_MetaData[] = {
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_OnAlternativeFireChanged = { "OnAlternativeFireChanged", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInteractibleWeaponBase, OnAlternativeFireChanged), Z_Construct_UDelegateFunction_WeaponSystem_OnAlternativeFireChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_OnAlternativeFireChanged_MetaData), Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_OnAlternativeFireChanged_MetaData) }; // 2339514187
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_MainFire_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_MainFire = { "MainFire", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInteractibleWeaponBase, MainFire), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_MainFire_MetaData), Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_MainFire_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_AlternativeFire_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_AlternativeFire = { "AlternativeFire", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInteractibleWeaponBase, AlternativeFire), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_AlternativeFire_MetaData), Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_AlternativeFire_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_Reload_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_Reload = { "Reload", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInteractibleWeaponBase, Reload), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_Reload_MetaData), Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_Reload_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_AimMode_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_AimMode = { "AimMode", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInteractibleWeaponBase, AimMode), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_AimMode_MetaData), Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_AimMode_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_MappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_MappingContext = { "MappingContext", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInteractibleWeaponBase, MappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_MappingContext_MetaData), Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_MappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_InitialWeaponStruct_MetaData[] = {
		{ "Category", "Initial Data" },
		{ "ModuleRelativePath", "Public/WeaponActors/InteractibleWeaponBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_InitialWeaponStruct = { "InitialWeaponStruct", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInteractibleWeaponBase, InitialWeaponStruct), Z_Construct_UScriptStruct_FWeaponsDataStruct, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_InitialWeaponStruct_MetaData), Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_InitialWeaponStruct_MetaData) }; // 3575574067
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AInteractibleWeaponBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_BoxCollision,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_WeaponSkeletalMeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_OnAlternativeFireChanged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_MainFire,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_AlternativeFire,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_Reload,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_AimMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_MappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractibleWeaponBase_Statics::NewProp_InitialWeaponStruct,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AInteractibleWeaponBase_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInteractibleWeaponInterface_NoRegister, (int32)VTABLE_OFFSET(AInteractibleWeaponBase, IInteractibleWeaponInterface), false },  // 3400998876
			{ Z_Construct_UClass_UInteractibleItemInterface_NoRegister, (int32)VTABLE_OFFSET(AInteractibleWeaponBase, IInteractibleItemInterface), false },  // 1603300985
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
	struct Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_InteractibleWeaponBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_InteractibleWeaponBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AInteractibleWeaponBase, AInteractibleWeaponBase::StaticClass, TEXT("AInteractibleWeaponBase"), &Z_Registration_Info_UClass_AInteractibleWeaponBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AInteractibleWeaponBase), 735737236U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_InteractibleWeaponBase_h_1918192380(TEXT("/Script/WeaponSystem"),
		Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_InteractibleWeaponBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_InteractibleWeaponBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
