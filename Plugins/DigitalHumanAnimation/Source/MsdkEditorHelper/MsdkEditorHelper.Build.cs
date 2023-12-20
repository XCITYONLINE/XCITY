using UnrealBuildTool;

public class MsdkEditorHelper: ModuleRules
{
	public MsdkEditorHelper(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        bUseUnity = false;
        IWYUSupport = IWYUSupport.Full;
	
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "UnrealEd",
            "Slate", "SlateCore",
            "EditorStyle",
            "Json"
		});
	}
}
