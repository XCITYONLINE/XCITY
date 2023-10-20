// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CommonContractsPlugin/Public/CommonUnils/CommonUtilsBPFL.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCommonUtilsBPFL() {}
// Cross Module References
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UCommonUtilsBPFL();
	COMMONCONTRACTSPLUGIN_API UClass* Z_Construct_UClass_UCommonUtilsBPFL_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UProperty();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_CommonContractsPlugin();
// End Cross Module References
	void UCommonUtilsBPFL::StaticRegisterNativesUCommonUtilsBPFL()
	{
		UClass* Class = UCommonUtilsBPFL::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetStructPropertyValueByName", &UCommonUtilsBPFL::execGetStructPropertyValueByName },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics
	{
		struct CommonUtilsBPFL_eventGetStructPropertyValueByName_Parms
		{
			UObject* Target;
			FName VarName;
			bool Success;
			UProperty* Result;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
		static const UECodeGen_Private::FNamePropertyParams NewProp_VarName;
		static void NewProp_Success_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Success;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Result;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CommonUtilsBPFL_eventGetStructPropertyValueByName_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::NewProp_VarName = { "VarName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CommonUtilsBPFL_eventGetStructPropertyValueByName_Parms, VarName), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::NewProp_Success_SetBit(void* Obj)
	{
		((CommonUtilsBPFL_eventGetStructPropertyValueByName_Parms*)Obj)->Success = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::NewProp_Success = { "Success", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CommonUtilsBPFL_eventGetStructPropertyValueByName_Parms), &Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::NewProp_Success_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CommonUtilsBPFL_eventGetStructPropertyValueByName_Parms, Result), Z_Construct_UClass_UProperty, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::NewProp_Target,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::NewProp_VarName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::NewProp_Success,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::NewProp_Result,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::Function_MetaDataParams[] = {
		{ "CustomStructureParam", "Result" },
		{ "CustomThunk", "true" },
		{ "ModuleRelativePath", "Public/CommonUnils/CommonUtilsBPFL.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCommonUtilsBPFL, nullptr, "GetStructPropertyValueByName", nullptr, nullptr, Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::CommonUtilsBPFL_eventGetStructPropertyValueByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::CommonUtilsBPFL_eventGetStructPropertyValueByName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCommonUtilsBPFL);
	UClass* Z_Construct_UClass_UCommonUtilsBPFL_NoRegister()
	{
		return UCommonUtilsBPFL::StaticClass();
	}
	struct Z_Construct_UClass_UCommonUtilsBPFL_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCommonUtilsBPFL_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_CommonContractsPlugin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCommonUtilsBPFL_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UCommonUtilsBPFL_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCommonUtilsBPFL_GetStructPropertyValueByName, "GetStructPropertyValueByName" }, // 2767731227
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCommonUtilsBPFL_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCommonUtilsBPFL_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CommonUnils/CommonUtilsBPFL.h" },
		{ "ModuleRelativePath", "Public/CommonUnils/CommonUtilsBPFL.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCommonUtilsBPFL_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCommonUtilsBPFL>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCommonUtilsBPFL_Statics::ClassParams = {
		&UCommonUtilsBPFL::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCommonUtilsBPFL_Statics::Class_MetaDataParams), Z_Construct_UClass_UCommonUtilsBPFL_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UCommonUtilsBPFL()
	{
		if (!Z_Registration_Info_UClass_UCommonUtilsBPFL.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCommonUtilsBPFL.OuterSingleton, Z_Construct_UClass_UCommonUtilsBPFL_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCommonUtilsBPFL.OuterSingleton;
	}
	template<> COMMONCONTRACTSPLUGIN_API UClass* StaticClass<UCommonUtilsBPFL>()
	{
		return UCommonUtilsBPFL::StaticClass();
	}
	UCommonUtilsBPFL::UCommonUtilsBPFL(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCommonUtilsBPFL);
	UCommonUtilsBPFL::~UCommonUtilsBPFL() {}
	struct Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_CommonUnils_CommonUtilsBPFL_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_CommonUnils_CommonUtilsBPFL_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCommonUtilsBPFL, UCommonUtilsBPFL::StaticClass, TEXT("UCommonUtilsBPFL"), &Z_Registration_Info_UClass_UCommonUtilsBPFL, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCommonUtilsBPFL), 2789844276U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_CommonUnils_CommonUtilsBPFL_h_2838124212(TEXT("/Script/CommonContractsPlugin"),
		Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_CommonUnils_CommonUtilsBPFL_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_XCityNew_XCITY_Plugins_CommonContractsPlugin_Source_CommonContractsPlugin_Public_CommonUnils_CommonUtilsBPFL_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
