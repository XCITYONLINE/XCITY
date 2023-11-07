#include "MetahumanSDKSettings.h"

#include "Interfaces/IPluginManager.h"

#if WITH_EDITOR
#include "MsdkEditorHelper/Public/NotificationHelper.h"
#endif

UMetahumanSDKSettings::UMetahumanSDKSettings()
{
	LoadConfig();

#if WITH_EDITOR
	FNotificationHelper::SetWebAccUrl(WebAccountUrl);
#endif
	
	UE_LOG(LogProfilingDebugging, Display, TEXT("Current Plugin Version: %s"), *GetPluginVersion());
}

const FString UMetahumanSDKSettings::GetPluginVersion()
{
	if (PluginVersion.IsEmpty())
	{
		const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("MetahumanSDK"));
	
		if (Plugin.IsValid())
		{
			PluginVersion = Plugin->GetDescriptor().VersionName;
		}		
	}

	return PluginVersion;
}

const FString UMetahumanSDKSettings::GetWebAccountUrl() const
{
	return WebAccountUrl;
}
