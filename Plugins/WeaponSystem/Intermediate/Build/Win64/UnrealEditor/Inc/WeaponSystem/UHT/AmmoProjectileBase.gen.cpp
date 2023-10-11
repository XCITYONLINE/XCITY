// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponSystem/Public/WeaponActors/AmmoProjectileBase.h"
#include "../../Source/Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAmmoProjectileBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	UPackage* Z_Construct_UPackage__Script_WeaponSystem();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_AAmmoProjectileBase();
	WEAPONSYSTEM_API UClass* Z_Construct_UClass_AAmmoProjectileBase_NoRegister();
	WEAPONSYSTEM_API UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics
	{
		struct _Script_WeaponSystem_eventOnProjectileHit_Parms
		{
			FHitResult Value;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_WeaponSystem_eventOnProjectileHit_Parms, Value), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::NewProp_Value_MetaData), Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::NewProp_Value_MetaData) }; // 1891709922
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponActors/AmmoProjectileBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_WeaponSystem, nullptr, "OnProjectileHit__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::_Script_WeaponSystem_eventOnProjectileHit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::_Script_WeaponSystem_eventOnProjectileHit_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnProjectileHit_DelegateWrapper(const FMulticastScriptDelegate& OnProjectileHit, FHitResult const& Value)
{
	struct _Script_WeaponSystem_eventOnProjectileHit_Parms
	{
		FHitResult Value;
	};
	_Script_WeaponSystem_eventOnProjectileHit_Parms Parms;
	Parms.Value=Value;
	OnProjectileHit.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct AmmoProjectileBase_eventK2_HitNotify_Parms
	{
		FHitResult OutImpactResult;
	};
	static FName NAME_AAmmoProjectileBase_K2_HitNotify = FName(TEXT("K2_HitNotify"));
	void AAmmoProjectileBase::K2_HitNotify(FHitResult const& OutImpactResult)
	{
		AmmoProjectileBase_eventK2_HitNotify_Parms Parms;
		Parms.OutImpactResult=OutImpactResult;
		ProcessEvent(FindFunctionChecked(NAME_AAmmoProjectileBase_K2_HitNotify),&Parms);
	}
	static FName NAME_AAmmoProjectileBase_K2_StartFly = FName(TEXT("K2_StartFly"));
	void AAmmoProjectileBase::K2_StartFly()
	{
		ProcessEvent(FindFunctionChecked(NAME_AAmmoProjectileBase_K2_StartFly),NULL);
	}
	void AAmmoProjectileBase::StaticRegisterNativesAAmmoProjectileBase()
	{
	}
	struct Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OutImpactResult_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutImpactResult;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::NewProp_OutImpactResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::NewProp_OutImpactResult = { "OutImpactResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AmmoProjectileBase_eventK2_HitNotify_Parms, OutImpactResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::NewProp_OutImpactResult_MetaData), Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::NewProp_OutImpactResult_MetaData) }; // 1891709922
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::NewProp_OutImpactResult,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponActors/AmmoProjectileBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AAmmoProjectileBase, nullptr, "K2_HitNotify", nullptr, nullptr, Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::PropPointers), sizeof(AmmoProjectileBase_eventK2_HitNotify_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::PropPointers) < 2048);
	static_assert(sizeof(AmmoProjectileBase_eventK2_HitNotify_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AAmmoProjectileBase_K2_StartFly_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAmmoProjectileBase_K2_StartFly_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponActors/AmmoProjectileBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAmmoProjectileBase_K2_StartFly_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AAmmoProjectileBase, nullptr, "K2_StartFly", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAmmoProjectileBase_K2_StartFly_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAmmoProjectileBase_K2_StartFly_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AAmmoProjectileBase_K2_StartFly()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAmmoProjectileBase_K2_StartFly_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAmmoProjectileBase);
	UClass* Z_Construct_UClass_AAmmoProjectileBase_NoRegister()
	{
		return AAmmoProjectileBase::StaticClass();
	}
	struct Z_Construct_UClass_AAmmoProjectileBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnProjectileHit_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnProjectileHit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileMovementComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileMovementComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StaticMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMeshComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAmmoProjectileBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_WeaponSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoProjectileBase_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AAmmoProjectileBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AAmmoProjectileBase_K2_HitNotify, "K2_HitNotify" }, // 293919295
		{ &Z_Construct_UFunction_AAmmoProjectileBase_K2_StartFly, "K2_StartFly" }, // 1722596347
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoProjectileBase_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAmmoProjectileBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "WeaponActors/AmmoProjectileBase.h" },
		{ "ModuleRelativePath", "Public/WeaponActors/AmmoProjectileBase.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_OnProjectileHit_MetaData[] = {
		{ "ModuleRelativePath", "Public/WeaponActors/AmmoProjectileBase.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_OnProjectileHit = { "OnProjectileHit", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAmmoProjectileBase, OnProjectileHit), Z_Construct_UDelegateFunction_WeaponSystem_OnProjectileHit__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_OnProjectileHit_MetaData), Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_OnProjectileHit_MetaData) }; // 3995390249
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_ProjectileMovementComponent_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "AmmoProjectileBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WeaponActors/AmmoProjectileBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_ProjectileMovementComponent = { "ProjectileMovementComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAmmoProjectileBase, ProjectileMovementComponent), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_ProjectileMovementComponent_MetaData), Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_ProjectileMovementComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_StaticMeshComponent_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "AmmoProjectileBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WeaponActors/AmmoProjectileBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_StaticMeshComponent = { "StaticMeshComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAmmoProjectileBase, StaticMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_StaticMeshComponent_MetaData), Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_StaticMeshComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAmmoProjectileBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_OnProjectileHit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_ProjectileMovementComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAmmoProjectileBase_Statics::NewProp_StaticMeshComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAmmoProjectileBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAmmoProjectileBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AAmmoProjectileBase_Statics::ClassParams = {
		&AAmmoProjectileBase::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AAmmoProjectileBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoProjectileBase_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoProjectileBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AAmmoProjectileBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoProjectileBase_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AAmmoProjectileBase()
	{
		if (!Z_Registration_Info_UClass_AAmmoProjectileBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAmmoProjectileBase.OuterSingleton, Z_Construct_UClass_AAmmoProjectileBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AAmmoProjectileBase.OuterSingleton;
	}
	template<> WEAPONSYSTEM_API UClass* StaticClass<AAmmoProjectileBase>()
	{
		return AAmmoProjectileBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAmmoProjectileBase);
	AAmmoProjectileBase::~AAmmoProjectileBase() {}
	struct Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AAmmoProjectileBase, AAmmoProjectileBase::StaticClass, TEXT("AAmmoProjectileBase"), &Z_Registration_Info_UClass_AAmmoProjectileBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAmmoProjectileBase), 1176270296U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_1740593591(TEXT("/Script/WeaponSystem"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_WeaponSystem_Source_WeaponSystem_Public_WeaponActors_AmmoProjectileBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
