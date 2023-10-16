// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReplicaNPC/Public/ReplicaNPC.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReplicaNPC() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
	REPLICANPC_API UClass* Z_Construct_UClass_UReplicaNPC();
	REPLICANPC_API UClass* Z_Construct_UClass_UReplicaNPC_NoRegister();
	REPLICANPC_API UEnum* Z_Construct_UEnum_ReplicaNPC_CurrentStyles();
	REPLICANPC_API UEnum* Z_Construct_UEnum_ReplicaNPC_ELanguageModel();
	REPLICANPC_API UEnum* Z_Construct_UEnum_ReplicaNPC_Voices();
	REPLICANPC_API UFunction* Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_ReplicaNPC();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics
	{
		struct _Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms
		{
			FString Url;
			FString NewContext;
			TArray<FString> Timeline;
			TArray<FString> Phonemes;
			FString SubTitle;
			FString PlayerText;
			bool bSuccess;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Url_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Url;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewContext_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_NewContext;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Timeline_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Timeline_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Timeline;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Phonemes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Phonemes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Phonemes;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SubTitle_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SubTitle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerText_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_PlayerText;
		static void NewProp_bSuccess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Url_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Url = { "Url", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms, Url), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Url_MetaData), Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Url_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_NewContext_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_NewContext = { "NewContext", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms, NewContext), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_NewContext_MetaData), Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_NewContext_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Timeline_Inner = { "Timeline", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Timeline_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Timeline = { "Timeline", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms, Timeline), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Timeline_MetaData), Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Timeline_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Phonemes_Inner = { "Phonemes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Phonemes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Phonemes = { "Phonemes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms, Phonemes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Phonemes_MetaData), Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Phonemes_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_SubTitle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_SubTitle = { "SubTitle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms, SubTitle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_SubTitle_MetaData), Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_SubTitle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_PlayerText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_PlayerText = { "PlayerText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms, PlayerText), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_PlayerText_MetaData), Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_PlayerText_MetaData) };
	void Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_bSuccess_SetBit(void* Obj)
	{
		((_Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms*)Obj)->bSuccess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms), &Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Url,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_NewContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Timeline_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Timeline,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Phonemes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_Phonemes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_SubTitle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_PlayerText,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::NewProp_bSuccess,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(FOnNPCRequestCompleted, const FString&, Url, const FString&, NewContext, const TArray<FString>&, Timeline, const TArray<FString>&, Phonemes, const FString&, SubTitle, const FString&, PlayerText, bool, bSuccess);\n" },
#endif
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(FOnNPCRequestCompleted, const FString&, Url, const FString&, NewContext, const TArray<FString>&, Timeline, const TArray<FString>&, Phonemes, const FString&, SubTitle, const FString&, PlayerText, bool, bSuccess);" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ReplicaNPC, nullptr, "OnNPCRequestCompleted__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::_Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::_Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnNPCRequestCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnNPCRequestCompleted, const FString& Url, const FString& NewContext, TArray<FString> const& Timeline, TArray<FString> const& Phonemes, const FString& SubTitle, const FString& PlayerText, bool bSuccess)
{
	struct _Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms
	{
		FString Url;
		FString NewContext;
		TArray<FString> Timeline;
		TArray<FString> Phonemes;
		FString SubTitle;
		FString PlayerText;
		bool bSuccess;
	};
	_Script_ReplicaNPC_eventOnNPCRequestCompleted_Parms Parms;
	Parms.Url=Url;
	Parms.NewContext=NewContext;
	Parms.Timeline=Timeline;
	Parms.Phonemes=Phonemes;
	Parms.SubTitle=SubTitle;
	Parms.PlayerText=PlayerText;
	Parms.bSuccess=bSuccess ? true : false;
	OnNPCRequestCompleted.ProcessMulticastDelegate<UObject>(&Parms);
}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_Voices;
	static UEnum* Voices_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_Voices.OuterSingleton)
		{
			Z_Registration_Info_UEnum_Voices.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ReplicaNPC_Voices, (UObject*)Z_Construct_UPackage__Script_ReplicaNPC(), TEXT("Voices"));
		}
		return Z_Registration_Info_UEnum_Voices.OuterSingleton;
	}
	template<> REPLICANPC_API UEnum* StaticEnum<Voices>()
	{
		return Voices_StaticEnum();
	}
	struct Z_Construct_UEnum_ReplicaNPC_Voices_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_ReplicaNPC_Voices_Statics::Enumerators[] = {
		{ "Vinnie", (int64)Vinnie },
		{ "Kaylee", (int64)Kaylee },
		{ "Nathan", (int64)Nathan },
		{ "Olivia", (int64)Olivia },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_ReplicaNPC_Voices_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Kaylee.DisplayName", "Kaylee" },
		{ "Kaylee.Name", "Kaylee" },
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
		{ "Nathan.DisplayName", "Nathan" },
		{ "Nathan.Name", "Nathan" },
		{ "Olivia.DisplayName", "Olivia" },
		{ "Olivia.Name", "Olivia" },
		{ "Vinnie.DisplayName", "Vinnie" },
		{ "Vinnie.Name", "Vinnie" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ReplicaNPC_Voices_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_ReplicaNPC,
		nullptr,
		"Voices",
		"Voices",
		Z_Construct_UEnum_ReplicaNPC_Voices_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_ReplicaNPC_Voices_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ReplicaNPC_Voices_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ReplicaNPC_Voices_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_ReplicaNPC_Voices()
	{
		if (!Z_Registration_Info_UEnum_Voices.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_Voices.InnerSingleton, Z_Construct_UEnum_ReplicaNPC_Voices_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_Voices.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_CurrentStyles;
	static UEnum* CurrentStyles_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_CurrentStyles.OuterSingleton)
		{
			Z_Registration_Info_UEnum_CurrentStyles.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ReplicaNPC_CurrentStyles, (UObject*)Z_Construct_UPackage__Script_ReplicaNPC(), TEXT("CurrentStyles"));
		}
		return Z_Registration_Info_UEnum_CurrentStyles.OuterSingleton;
	}
	template<> REPLICANPC_API UEnum* StaticEnum<CurrentStyles>()
	{
		return CurrentStyles_StaticEnum();
	}
	struct Z_Construct_UEnum_ReplicaNPC_CurrentStyles_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_ReplicaNPC_CurrentStyles_Statics::Enumerators[] = {
		{ "Serious", (int64)Serious },
		{ "Sassy", (int64)Sassy },
		{ "Defeated", (int64)Defeated },
		{ "Warm", (int64)Warm },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_ReplicaNPC_CurrentStyles_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Defeated.DisplayName", "Defeated" },
		{ "Defeated.Name", "Defeated" },
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
		{ "Sassy.DisplayName", "Sassy" },
		{ "Sassy.Name", "Sassy" },
		{ "Serious.DisplayName", "Serious" },
		{ "Serious.Name", "Serious" },
		{ "Warm.DisplayName", "Warm" },
		{ "Warm.Name", "Warm" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ReplicaNPC_CurrentStyles_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_ReplicaNPC,
		nullptr,
		"CurrentStyles",
		"CurrentStyles",
		Z_Construct_UEnum_ReplicaNPC_CurrentStyles_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_ReplicaNPC_CurrentStyles_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ReplicaNPC_CurrentStyles_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ReplicaNPC_CurrentStyles_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_ReplicaNPC_CurrentStyles()
	{
		if (!Z_Registration_Info_UEnum_CurrentStyles.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_CurrentStyles.InnerSingleton, Z_Construct_UEnum_ReplicaNPC_CurrentStyles_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_CurrentStyles.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ELanguageModel;
	static UEnum* ELanguageModel_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ELanguageModel.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ELanguageModel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ReplicaNPC_ELanguageModel, (UObject*)Z_Construct_UPackage__Script_ReplicaNPC(), TEXT("ELanguageModel"));
		}
		return Z_Registration_Info_UEnum_ELanguageModel.OuterSingleton;
	}
	template<> REPLICANPC_API UEnum* StaticEnum<ELanguageModel>()
	{
		return ELanguageModel_StaticEnum();
	}
	struct Z_Construct_UEnum_ReplicaNPC_ELanguageModel_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_ReplicaNPC_ELanguageModel_Statics::Enumerators[] = {
		{ "OpenAImodel", (int64)OpenAImodel },
		{ "HostedLLMmodel", (int64)HostedLLMmodel },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_ReplicaNPC_ELanguageModel_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HostedLLMmodel.DisplayName", "Hosted LLM" },
		{ "HostedLLMmodel.Name", "HostedLLMmodel" },
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
		{ "OpenAImodel.DisplayName", "Open AI" },
		{ "OpenAImodel.Name", "OpenAImodel" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ReplicaNPC_ELanguageModel_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_ReplicaNPC,
		nullptr,
		"ELanguageModel",
		"ELanguageModel",
		Z_Construct_UEnum_ReplicaNPC_ELanguageModel_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_ReplicaNPC_ELanguageModel_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ReplicaNPC_ELanguageModel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ReplicaNPC_ELanguageModel_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_ReplicaNPC_ELanguageModel()
	{
		if (!Z_Registration_Info_UEnum_ELanguageModel.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ELanguageModel.InnerSingleton, Z_Construct_UEnum_ReplicaNPC_ELanguageModel_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ELanguageModel.InnerSingleton;
	}
	DEFINE_FUNCTION(UReplicaNPC::execReplica)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_AudioPath);
		P_GET_PROPERTY(FStrProperty,Z_Param_SpeechText);
		P_GET_PROPERTY(FStrProperty,Z_Param_CharacterName);
		P_GET_PROPERTY(FStrProperty,Z_Param_Context);
		P_GET_PROPERTY(FByteProperty,Z_Param_CurrentVoice);
		P_GET_PROPERTY(FByteProperty,Z_Param_CurrentStyle);
		P_GET_PROPERTY(FByteProperty,Z_Param_LanguageModelUsed);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UReplicaNPC**)Z_Param__Result=UReplicaNPC::Replica(Z_Param_WorldContextObject,Z_Param_AudioPath,Z_Param_SpeechText,Z_Param_CharacterName,Z_Param_Context,Voices(Z_Param_CurrentVoice),CurrentStyles(Z_Param_CurrentStyle),ELanguageModel(Z_Param_LanguageModelUsed));
		P_NATIVE_END;
	}
	void UReplicaNPC::StaticRegisterNativesUReplicaNPC()
	{
		UClass* Class = UReplicaNPC::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Replica", &UReplicaNPC::execReplica },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UReplicaNPC_Replica_Statics
	{
		struct ReplicaNPC_eventReplica_Parms
		{
			UObject* WorldContextObject;
			FString AudioPath;
			FString SpeechText;
			FString CharacterName;
			FString Context;
			TEnumAsByte<Voices> CurrentVoice;
			TEnumAsByte<CurrentStyles> CurrentStyle;
			TEnumAsByte<ELanguageModel> LanguageModelUsed;
			UReplicaNPC* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AudioPath;
		static const UECodeGen_Private::FStrPropertyParams NewProp_SpeechText;
		static const UECodeGen_Private::FStrPropertyParams NewProp_CharacterName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Context;
		static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentVoice;
		static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentStyle;
		static const UECodeGen_Private::FBytePropertyParams NewProp_LanguageModelUsed;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ReplicaNPC_eventReplica_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_AudioPath = { "AudioPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ReplicaNPC_eventReplica_Parms, AudioPath), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_SpeechText = { "SpeechText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ReplicaNPC_eventReplica_Parms, SpeechText), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_CharacterName = { "CharacterName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ReplicaNPC_eventReplica_Parms, CharacterName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ReplicaNPC_eventReplica_Parms, Context), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_CurrentVoice = { "CurrentVoice", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ReplicaNPC_eventReplica_Parms, CurrentVoice), Z_Construct_UEnum_ReplicaNPC_Voices, METADATA_PARAMS(0, nullptr) }; // 2570189179
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_CurrentStyle = { "CurrentStyle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ReplicaNPC_eventReplica_Parms, CurrentStyle), Z_Construct_UEnum_ReplicaNPC_CurrentStyles, METADATA_PARAMS(0, nullptr) }; // 3149562606
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_LanguageModelUsed = { "LanguageModelUsed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ReplicaNPC_eventReplica_Parms, LanguageModelUsed), Z_Construct_UEnum_ReplicaNPC_ELanguageModel, METADATA_PARAMS(0, nullptr) }; // 4124066770
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ReplicaNPC_eventReplica_Parms, ReturnValue), Z_Construct_UClass_UReplicaNPC_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UReplicaNPC_Replica_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_AudioPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_SpeechText,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_CharacterName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_CurrentVoice,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_CurrentStyle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_LanguageModelUsed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReplicaNPC_Replica_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UReplicaNPC_Replica_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "ReplicaNPC" },
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UReplicaNPC_Replica_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UReplicaNPC, nullptr, "Replica", nullptr, nullptr, Z_Construct_UFunction_UReplicaNPC_Replica_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UReplicaNPC_Replica_Statics::PropPointers), sizeof(Z_Construct_UFunction_UReplicaNPC_Replica_Statics::ReplicaNPC_eventReplica_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UReplicaNPC_Replica_Statics::Function_MetaDataParams), Z_Construct_UFunction_UReplicaNPC_Replica_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UReplicaNPC_Replica_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UReplicaNPC_Replica_Statics::ReplicaNPC_eventReplica_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UReplicaNPC_Replica()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UReplicaNPC_Replica_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UReplicaNPC);
	UClass* Z_Construct_UClass_UReplicaNPC_NoRegister()
	{
		return UReplicaNPC::StaticClass();
	}
	struct Z_Construct_UClass_UReplicaNPC_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Completed_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_Completed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AudioPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AudioPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Context;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpeechText_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SpeechText;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CharacterName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_CharacterName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HttpAddress_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_HttpAddress;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OpenAI_MetaData[];
#endif
		static void NewProp_OpenAI_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_OpenAI;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HostedLLM_MetaData[];
#endif
		static void NewProp_HostedLLM_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_HostedLLM;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Voice_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Voice;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Style_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Style;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UReplicaNPC_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ReplicaNPC,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UReplicaNPC_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UReplicaNPC_Replica, "Replica" }, // 1722759512
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplicaNPC_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ReplicaNPC.h" },
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Completed_MetaData[] = {
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Completed = { "Completed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReplicaNPC, Completed), Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Completed_MetaData), Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Completed_MetaData) }; // 2862985784
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplicaNPC_Statics::NewProp_AudioPath_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//UPROPERTY(BlueprintAssignable)\n//FNewTestDelegate Completed;\n" },
#endif
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(BlueprintAssignable)\nFNewTestDelegate Completed;" },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UReplicaNPC_Statics::NewProp_AudioPath = { "AudioPath", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReplicaNPC, AudioPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::NewProp_AudioPath_MetaData), Z_Construct_UClass_UReplicaNPC_Statics::NewProp_AudioPath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Context_MetaData[] = {
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReplicaNPC, Context), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Context_MetaData), Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Context_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplicaNPC_Statics::NewProp_SpeechText_MetaData[] = {
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UReplicaNPC_Statics::NewProp_SpeechText = { "SpeechText", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReplicaNPC, SpeechText), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::NewProp_SpeechText_MetaData), Z_Construct_UClass_UReplicaNPC_Statics::NewProp_SpeechText_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplicaNPC_Statics::NewProp_CharacterName_MetaData[] = {
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UReplicaNPC_Statics::NewProp_CharacterName = { "CharacterName", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReplicaNPC, CharacterName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::NewProp_CharacterName_MetaData), Z_Construct_UClass_UReplicaNPC_Statics::NewProp_CharacterName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplicaNPC_Statics::NewProp_HttpAddress_MetaData[] = {
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UReplicaNPC_Statics::NewProp_HttpAddress = { "HttpAddress", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReplicaNPC, HttpAddress), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::NewProp_HttpAddress_MetaData), Z_Construct_UClass_UReplicaNPC_Statics::NewProp_HttpAddress_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplicaNPC_Statics::NewProp_OpenAI_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//UPROPERTY()\n//bool SwitchAPI;\n" },
#endif
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY()\nbool SwitchAPI;" },
#endif
	};
#endif
	void Z_Construct_UClass_UReplicaNPC_Statics::NewProp_OpenAI_SetBit(void* Obj)
	{
		((UReplicaNPC*)Obj)->OpenAI = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UReplicaNPC_Statics::NewProp_OpenAI = { "OpenAI", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UReplicaNPC), &Z_Construct_UClass_UReplicaNPC_Statics::NewProp_OpenAI_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::NewProp_OpenAI_MetaData), Z_Construct_UClass_UReplicaNPC_Statics::NewProp_OpenAI_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplicaNPC_Statics::NewProp_HostedLLM_MetaData[] = {
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
	};
#endif
	void Z_Construct_UClass_UReplicaNPC_Statics::NewProp_HostedLLM_SetBit(void* Obj)
	{
		((UReplicaNPC*)Obj)->HostedLLM = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UReplicaNPC_Statics::NewProp_HostedLLM = { "HostedLLM", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UReplicaNPC), &Z_Construct_UClass_UReplicaNPC_Statics::NewProp_HostedLLM_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::NewProp_HostedLLM_MetaData), Z_Construct_UClass_UReplicaNPC_Statics::NewProp_HostedLLM_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Voice_MetaData[] = {
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Voice = { "Voice", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReplicaNPC, Voice), Z_Construct_UEnum_ReplicaNPC_Voices, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Voice_MetaData), Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Voice_MetaData) }; // 2570189179
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Style_MetaData[] = {
		{ "ModuleRelativePath", "Public/ReplicaNPC.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Style = { "Style", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReplicaNPC, Style), Z_Construct_UEnum_ReplicaNPC_CurrentStyles, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Style_MetaData), Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Style_MetaData) }; // 3149562606
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UReplicaNPC_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Completed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReplicaNPC_Statics::NewProp_AudioPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReplicaNPC_Statics::NewProp_SpeechText,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReplicaNPC_Statics::NewProp_CharacterName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReplicaNPC_Statics::NewProp_HttpAddress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReplicaNPC_Statics::NewProp_OpenAI,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReplicaNPC_Statics::NewProp_HostedLLM,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Voice,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReplicaNPC_Statics::NewProp_Style,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UReplicaNPC_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UReplicaNPC>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UReplicaNPC_Statics::ClassParams = {
		&UReplicaNPC::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UReplicaNPC_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::Class_MetaDataParams), Z_Construct_UClass_UReplicaNPC_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UReplicaNPC_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UReplicaNPC()
	{
		if (!Z_Registration_Info_UClass_UReplicaNPC.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UReplicaNPC.OuterSingleton, Z_Construct_UClass_UReplicaNPC_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UReplicaNPC.OuterSingleton;
	}
	template<> REPLICANPC_API UClass* StaticClass<UReplicaNPC>()
	{
		return UReplicaNPC::StaticClass();
	}
	UReplicaNPC::UReplicaNPC(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UReplicaNPC);
	UReplicaNPC::~UReplicaNPC() {}
	struct Z_CompiledInDeferFile_FID_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_Statics::EnumInfo[] = {
		{ Voices_StaticEnum, TEXT("Voices"), &Z_Registration_Info_UEnum_Voices, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2570189179U) },
		{ CurrentStyles_StaticEnum, TEXT("CurrentStyles"), &Z_Registration_Info_UEnum_CurrentStyles, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3149562606U) },
		{ ELanguageModel_StaticEnum, TEXT("ELanguageModel"), &Z_Registration_Info_UEnum_ELanguageModel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4124066770U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UReplicaNPC, UReplicaNPC::StaticClass, TEXT("UReplicaNPC"), &Z_Registration_Info_UClass_UReplicaNPC, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UReplicaNPC), 1259463140U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_186329633(TEXT("/Script/ReplicaNPC"),
		Z_CompiledInDeferFile_FID_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_XCITY_Plugins_ReplicaNPC_Source_ReplicaNPC_Public_ReplicaNPC_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
