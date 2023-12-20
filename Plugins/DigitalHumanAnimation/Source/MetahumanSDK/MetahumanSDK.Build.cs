using UnrealBuildTool;
using System.IO;

public class MetahumanSDK : ModuleRules
{
    public MetahumanSDK(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bUseUnity = false;
        IWYUSupport = IWYUSupport.Full;

        PublicIncludePaths.Add(ModuleDirectory + "/Public/Actions");
        PublicIncludePaths.Add(ModuleDirectory + "/Public/AnimGraphNodes");
        PublicIncludePaths.Add(ModuleDirectory + "/Public/AssetFactories");
        PublicIncludePaths.Add(ModuleDirectory + "/Public/Assets");
        PrivateIncludePaths.Add(ModuleDirectory + "/Private/Actions");
        PrivateIncludePaths.Add(ModuleDirectory + "/Private/AnimGraphNodes");
        PrivateIncludePaths.Add(ModuleDirectory + "/Private/AssetFactories");
        PrivateIncludePaths.Add(ModuleDirectory + "/Private/Assets");

        
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "Engine",
                "Json"
            }
        );
            
        
        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "HTTP",
                "AudioMixer",
                "AudioPlatformConfiguration",
                "Projects", // IPluginManager
                "kubazip"
            }
        );

        // Custom Http Request
        PrivateIncludePaths.AddRange(
            new string[]
            {
                System.IO.Path.GetFullPath(Target.RelativeEnginePath) + "Source/Runtime/Online/HTTP/Private",
            }
        );
        AddEngineThirdPartyPrivateStaticDependencies(Target, "libcurl");
        AddEngineThirdPartyPrivateStaticDependencies(Target, "OpenSSL");

        // add support for ogg vorbis files for runtime sound wave construction
        AddEngineThirdPartyPrivateStaticDependencies(Target,
            "UEOgg",
            "Vorbis",
            "VorbisFile",
            "libOpus",
            "UELibSampleRate"
        );

        PublicDefinitions.AddRange(
            new string[]
            {
                "DR_WAV_IMPLEMENTATION=1"
            }
        );
        
        // This is used to get FSoundQualityInfo struct for IAudioEncoder.
        PrivateIncludePathModuleNames.Add("TargetPlatform");

        PrivateDependencyModuleNames.Add("BinkAudioDecoder");
			
        PublicSystemIncludePaths.Add(Path.Combine(EngineDirectory, "Source", "Runtime", "BinkAudioDecoder", "SDK", "BinkAudio", "Include"));

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicAdditionalLibraries.Add(Path.Combine(EngineDirectory, "Source", "Runtime", "BinkAudioDecoder", "SDK", "BinkAudio", "Lib", "binka_ue_encode_win64_static.lib"));
        }

        if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            PublicAdditionalLibraries.Add(Path.Combine(EngineDirectory, "Source", "Runtime", "BinkAudioDecoder", "SDK", "BinkAudio", "Lib", "libbinka_ue_encode_lnx64_static.a"));
        }

        if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            if (Target.Version.MajorVersion >= 5 && Target.Version.MinorVersion >= 1)
            {
                PublicAdditionalLibraries.Add(Path.Combine(EngineDirectory, "Source", "Runtime", "BinkAudioDecoder", "SDK", "BinkAudio", "Lib", "libbinka_ue_encode_osx_static.a"));
            }
            else
            {
                PublicAdditionalLibraries.Add(Path.Combine(EngineDirectory, "Source", "Runtime", "BinkAudioDecoder", "SDK", "BinkAudio", "Lib", "libbinka_ue_encode_osx64_static.a"));
            }
        }
        
        
        if (Target.Type == TargetType.Editor)
        {
            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "AssetTools",
                    "AssetRegistry",
                    "UnrealEd",
                    "MsdkEditorHelper"
                }
            );
        }        
    }
}
