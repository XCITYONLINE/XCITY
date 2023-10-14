// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InventorySystem/Public/Conponents/FindObjectsComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFindObjectsComponent() {}
// Cross Module References
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UFinderObjectsInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
	INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UFindObjectsComponent();
	INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UFindObjectsComponent_NoRegister();
	INVENTORYSYSTEM_API UEnum* Z_Construct_UEnum_InventorySystem_EFinderTraceMode();
	UPackage* Z_Construct_UPackage__Script_InventorySystem();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFinderTraceMode;
	static UEnum* EFinderTraceMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EFinderTraceMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EFinderTraceMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_InventorySystem_EFinderTraceMode, (UObject*)Z_Construct_UPackage__Script_InventorySystem(), TEXT("EFinderTraceMode"));
		}
		return Z_Registration_Info_UEnum_EFinderTraceMode.OuterSingleton;
	}
	template<> INVENTORYSYSTEM_API UEnum* StaticEnum<EFinderTraceMode>()
	{
		return EFinderTraceMode_StaticEnum();
	}
	struct Z_Construct_UEnum_InventorySystem_EFinderTraceMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_InventorySystem_EFinderTraceMode_Statics::Enumerators[] = {
		{ "FTM_None", (int64)FTM_None },
		{ "FTM_MultiSphereAround", (int64)FTM_MultiSphereAround },
		{ "FTM_SingleLineTrace", (int64)FTM_SingleLineTrace },
		{ "FTM_Max", (int64)FTM_Max },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_InventorySystem_EFinderTraceMode_Statics::Enum_MetaDataParams[] = {
		{ "FTM_Max.Hidden", "" },
		{ "FTM_Max.Name", "FTM_Max" },
		{ "FTM_MultiSphereAround.DisplayName", "Multi Sphere Trace" },
		{ "FTM_MultiSphereAround.Name", "FTM_MultiSphereAround" },
		{ "FTM_None.Hidden", "" },
		{ "FTM_None.Name", "FTM_None" },
		{ "FTM_SingleLineTrace.DisplayName", "Single Line Trace" },
		{ "FTM_SingleLineTrace.Name", "FTM_SingleLineTrace" },
		{ "ModuleRelativePath", "Public/Conponents/FindObjectsComponent.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_InventorySystem_EFinderTraceMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_InventorySystem,
		nullptr,
		"EFinderTraceMode",
		"EFinderTraceMode",
		Z_Construct_UEnum_InventorySystem_EFinderTraceMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_InventorySystem_EFinderTraceMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_InventorySystem_EFinderTraceMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_InventorySystem_EFinderTraceMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_InventorySystem_EFinderTraceMode()
	{
		if (!Z_Registration_Info_UEnum_EFinderTraceMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFinderTraceMode.InnerSingleton, Z_Construct_UEnum_InventorySystem_EFinderTraceMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EFinderTraceMode.InnerSingleton;
	}
	void UFindObjectsComponent::StaticRegisterNativesUFindObjectsComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFindObjectsComponent);
	UClass* Z_Construct_UClass_UFindObjectsComponent_NoRegister()
	{
		return UFindObjectsComponent::StaticClass();
	}
	struct Z_Construct_UClass_UFindObjectsComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FindRadius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FindRadius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TraceOffset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TraceOffset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TraceMode_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_TraceMode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CollisionChannel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_CollisionChannel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDrawDebug_MetaData[];
#endif
		static void NewProp_bDrawDebug_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawDebug;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFindObjectsComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFindObjectsComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFindObjectsComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Conponents/FindObjectsComponent.h" },
		{ "ModuleRelativePath", "Public/Conponents/FindObjectsComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_FindRadius_MetaData[] = {
		{ "Category", "FindObjectsComponent" },
		{ "ModuleRelativePath", "Public/Conponents/FindObjectsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_FindRadius = { "FindRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFindObjectsComponent, FindRadius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_FindRadius_MetaData), Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_FindRadius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_TraceOffset_MetaData[] = {
		{ "Category", "FindObjectsComponent" },
		{ "ModuleRelativePath", "Public/Conponents/FindObjectsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_TraceOffset = { "TraceOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFindObjectsComponent, TraceOffset), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_TraceOffset_MetaData), Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_TraceOffset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_TraceMode_MetaData[] = {
		{ "Category", "FindObjectsComponent" },
		{ "ModuleRelativePath", "Public/Conponents/FindObjectsComponent.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_TraceMode = { "TraceMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFindObjectsComponent, TraceMode), Z_Construct_UEnum_InventorySystem_EFinderTraceMode, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_TraceMode_MetaData), Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_TraceMode_MetaData) }; // 2666603532
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_CollisionChannel_MetaData[] = {
		{ "Category", "FindObjectsComponent" },
		{ "ModuleRelativePath", "Public/Conponents/FindObjectsComponent.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_CollisionChannel = { "CollisionChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFindObjectsComponent, CollisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_CollisionChannel_MetaData), Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_CollisionChannel_MetaData) }; // 1822723181
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_bDrawDebug_MetaData[] = {
		{ "Category", "FindObjectsComponent" },
		{ "ModuleRelativePath", "Public/Conponents/FindObjectsComponent.h" },
	};
#endif
	void Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_bDrawDebug_SetBit(void* Obj)
	{
		((UFindObjectsComponent*)Obj)->bDrawDebug = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_bDrawDebug = { "bDrawDebug", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UFindObjectsComponent), &Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_bDrawDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_bDrawDebug_MetaData), Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_bDrawDebug_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFindObjectsComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_FindRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_TraceOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_TraceMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_CollisionChannel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_bDrawDebug,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UFindObjectsComponent_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UFinderObjectsInterface_NoRegister, (int32)VTABLE_OFFSET(UFindObjectsComponent, IFinderObjectsInterface), false },  // 763171924
		};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFindObjectsComponent_Statics::InterfaceParams) < 64);
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFindObjectsComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFindObjectsComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UFindObjectsComponent_Statics::ClassParams = {
		&UFindObjectsComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFindObjectsComponent_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFindObjectsComponent_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFindObjectsComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UFindObjectsComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFindObjectsComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UFindObjectsComponent()
	{
		if (!Z_Registration_Info_UClass_UFindObjectsComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFindObjectsComponent.OuterSingleton, Z_Construct_UClass_UFindObjectsComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UFindObjectsComponent.OuterSingleton;
	}
	template<> INVENTORYSYSTEM_API UClass* StaticClass<UFindObjectsComponent>()
	{
		return UFindObjectsComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFindObjectsComponent);
	UFindObjectsComponent::~UFindObjectsComponent() {}
	struct Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_Statics::EnumInfo[] = {
		{ EFinderTraceMode_StaticEnum, TEXT("EFinderTraceMode"), &Z_Registration_Info_UEnum_EFinderTraceMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2666603532U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UFindObjectsComponent, UFindObjectsComponent::StaticClass, TEXT("UFindObjectsComponent"), &Z_Registration_Info_UClass_UFindObjectsComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFindObjectsComponent), 2553410394U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_2289745070(TEXT("/Script/InventorySystem"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
