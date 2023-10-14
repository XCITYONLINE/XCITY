// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCommonContractsPlugin_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_CommonContractsPlugin;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_CommonContractsPlugin()
	{
		if (!Z_Registration_Info_UPackage__Script_CommonContractsPlugin.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/CommonContractsPlugin",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x82B6242F,
				0x0638938D,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_CommonContractsPlugin.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_CommonContractsPlugin.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_CommonContractsPlugin(Z_Construct_UPackage__Script_CommonContractsPlugin, TEXT("/Script/CommonContractsPlugin"), Z_Registration_Info_UPackage__Script_CommonContractsPlugin, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x82B6242F, 0x0638938D));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
