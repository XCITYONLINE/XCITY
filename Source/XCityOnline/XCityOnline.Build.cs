// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class XCityOnline : ModuleRules
{
	public XCityOnline(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"WeaponSystem"
		});
		
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"InventorySystem",
			"CommonContractsPlugin",
			"UMG",
			"ALSV4_CPP"
		});

		// Uncomment if you are using Slate UI
		 PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
