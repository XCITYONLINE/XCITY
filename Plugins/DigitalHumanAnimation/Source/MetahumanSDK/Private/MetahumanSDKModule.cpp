#include "MetahumanSDKModule.h"

#include "CoreGlobals.h"
#include "Misc/ConfigCacheIni.h"
#include "HttpModule.h"
#include "HttpManager.h"

DEFINE_LOG_CATEGORY(LogMetahumanSDK);

#define LOCTEXT_NAMESPACE "FMetahumanSDKModule"

void FMetahumanSDKModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    double SoftLimitSeconds = 2.0;
    double HardLimitSeconds = 4.0;
    GConfig->GetDouble(TEXT("HTTP"), TEXT("FlushSoftTimeLimitDefault"), SoftLimitSeconds, GEngineIni);
    GConfig->GetDouble(TEXT("HTTP"), TEXT("FlushHardTimeLimitDefault"), HardLimitSeconds, GEngineIni);
    
    bool bReloadConfig = false;
    
    if (SoftLimitSeconds > 0.f && SoftLimitSeconds <= 120.f)
    {
        GConfig->SetDouble(TEXT("HTTP"), TEXT("FlushSoftTimeLimitDefault"), 120.f, GEngineIni);
        bReloadConfig = true;
    }
    
    if (HardLimitSeconds > 0.f && HardLimitSeconds <= 240.f)
    {
        GConfig->SetDouble(TEXT("HTTP"), TEXT("FlushHardTimeLimitDefault"), 240.f, GEngineIni);
        bReloadConfig = true;
    }
    
    if (bReloadConfig)
    {
        FHttpModule::Get().GetHttpManager().UpdateConfigs();
    }
}

void FMetahumanSDKModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.

}


#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FMetahumanSDKModule, MetahumanSDK)