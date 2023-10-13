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
	UPackage* Z_Construct_UPackage__Script_InventorySystem();
// End Cross Module References
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CollisionChannel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_CollisionChannel;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_CollisionChannel_MetaData[] = {
		{ "Category", "FindObjectsComponent" },
		{ "ModuleRelativePath", "Public/Conponents/FindObjectsComponent.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_CollisionChannel = { "CollisionChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFindObjectsComponent, CollisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_CollisionChannel_MetaData), Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_CollisionChannel_MetaData) }; // 1822723181
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFindObjectsComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_FindRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFindObjectsComponent_Statics::NewProp_CollisionChannel,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UFindObjectsComponent_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UFinderObjectsInterface_NoRegister, (int32)VTABLE_OFFSET(UFindObjectsComponent, IFinderObjectsInterface), false },  // 259855486
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
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UFindObjectsComponent, UFindObjectsComponent::StaticClass, TEXT("UFindObjectsComponent"), &Z_Registration_Info_UClass_UFindObjectsComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFindObjectsComponent), 2288686663U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_1013549376(TEXT("/Script/InventorySystem"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_InventorySystem_Source_InventorySystem_Public_Conponents_FindObjectsComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
