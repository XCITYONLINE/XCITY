// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReplicaNPC_init() {}
	REPLICANPC_API UFunction* Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ReplicaNPC;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ReplicaNPC()
	{
		if (!Z_Registration_Info_UPackage__Script_ReplicaNPC.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ReplicaNPC_OnNPCRequestCompleted__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ReplicaNPC",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x4C4A9D94,
				0xF4411756,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ReplicaNPC.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ReplicaNPC.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ReplicaNPC(Z_Construct_UPackage__Script_ReplicaNPC, TEXT("/Script/ReplicaNPC"), Z_Registration_Info_UPackage__Script_ReplicaNPC, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x4C4A9D94, 0xF4411756));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
