#include "Request/MetahumanSDKRequestManager.h"

#if WITH_EDITOR
#include "Editor.h"
#endif

#include "GenericPlatform/GenericPlatformProcess.h"
#include "HAL/RunnableThread.h"
#include "HAL/Event.h"
#include "HAL/ThreadManager.h"

#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Misc/FileHelper.h"
#include "Dom/JsonObject.h"
#include "Dom/JsonValue.h"
#include "PlatformHttp.h"
#include "HttpModule.h"
#include "HttpManager.h"
#include "Internationalization/Regex.h"
#include "Internationalization/Culture.h"
#include "Kismet/GameplayStatics.h"

#include "MetahumanSDKSettings.h"
#include "MetahumanSDKAPIManager.h"
#include "MetahumanSDKUtils.h"
#include "Request/StreamResponseProcessor.h"
#include "Helpers/SystemUtilityLibrary.h"

#include "Runtime/Launch/Resources/Version.h"


#define VAL(str) #str
#define TOSTRING(str) VAL(str)

DEFINE_LOG_CATEGORY_STATIC(LogMetahumanSDKRequestsManager, Log, All);

FMetahumanSDKRequestManager::FMetahumanSDKRequestManager(UMetahumanSDKAPIManager* InAPIManager)
    : APIManager(InAPIManager)
{
}

FMetahumanSDKRequestManager::~FMetahumanSDKRequestManager()
{
    Cleanup();
}

void FMetahumanSDKRequestManager::Tick(float DeltaTime)
{
}

TStatId FMetahumanSDKRequestManager::GetStatId() const
{
    return TStatId();
}

void FMetahumanSDKRequestManager::Initialize()
{
    WorkerThread = FRunnableThread::Create(this, TEXT("MetahumanSDKRequestsManager"), 0, TPri_TimeCritical);

    MetahumanSDKSettings = GetMutableDefault<UMetahumanSDKSettings>();
}

void FMetahumanSDKRequestManager::Cleanup()
{
    delete StreamResponseProcessor;
    
    bStopThread = true;
    Trigger();
    WorkerThread->WaitForCompletion();

    UE_LOG(LogMetahumanSDKRequestsManager, Display, TEXT("%s"), *FString(__FUNCTION__));
}

bool FMetahumanSDKRequestManager::Init()
{
    WorkerThreadSemaphore = FGenericPlatformProcess::GetSynchEventFromPool(false);

    return true;
}

uint32 FMetahumanSDKRequestManager::Run()
{
    while (!bStopThread)
    {
        WorkerThreadSemaphore->Wait();
        
        BlockTillAllRequestsFinished();
    }

    return 0;
}

void FMetahumanSDKRequestManager::Exit()
{
    bStopThread = true;
    bCompletedWork.AtomicSet(true);
}

void FMetahumanSDKRequestManager::Trigger()
{
    WorkerThreadSemaphore->Trigger();
}

void FMetahumanSDKRequestManager::BlockTillAllRequestsFinished()
{
    while (!bCompletedWork && !bStopThread)
    {
        bCompletedWork.AtomicSet(true);
    }
}

template<typename ResponseType>
void ProcessResponse(const FString& RequestType, TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest, FResponseCompletedSignature CompletedDelegate)
{
    UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("Request (type:'%s') started..."), *RequestType);

    const double StartTime = FPlatformTime::Seconds();
    
    HttpRequest->OnProcessRequestComplete().BindLambda(
        [RequestType, StartTime, CompletedDelegate](FHttpRequestPtr Request, FHttpResponsePtr HttpResponse, bool bConnectedSuccessfully)
        {
            UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("Request (type:'%s') finished!"), *RequestType);

            TSharedPtr<FGenericResponse> OutResponse(new ResponseType);

            const double EndTime = FPlatformTime::Seconds();
            const double RequestDuration = EndTime - StartTime;

            UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("Request (type:'%s') took %f seconds to complete"), *RequestType, RequestDuration);

            // Handle critical error peacefully to avoid crash
            if (HttpResponse != nullptr && HttpResponse->GetResponseCode() == EHttpResponseCodes::Ok)
            {
                const double ParseResponseStartTime = FPlatformTime::Seconds();
                if (OutResponse->PassContentAsBytes())
                {
                    OutResponse->ParseResponse(HttpResponse->GetContent());                   
                }
                else
                {
                    OutResponse->ParseResponse(HttpResponse->GetContentAsString());
                }

                const double ParseResponseDuration = FPlatformTime::Seconds() - ParseResponseStartTime;
                UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("Parsing response took %f seconds to complete"), ParseResponseDuration);
            }
            else
            {
                OutResponse->bResponseSuccess = false;
                OutResponse->Error = HttpResponse->GetContentAsString();
                FSystemUtilityLibrary::PrintError(HttpResponse->GetResponseCode(), *OutResponse->Error);
            }

            if (CompletedDelegate.IsBound())
            {
                CompletedDelegate.Execute(OutResponse, bConnectedSuccessfully);
            }

            GRequestStatistics.UpdateStatisticsSizeTime( HttpResponse->GetContent().Num(), RequestDuration );
        }
    );
}


FString FMetahumanSDKRequestManager::GenerateRequestJson(const FGenericRequest& Request) const
{
    const TSharedPtr<FJsonObject> RootJson = MakeShareable<FJsonObject>(new FJsonObject);
    {
        const TSharedPtr<FJsonObject> DataJson = MakeShareable<FJsonObject>(new FJsonObject);
        {
            DataJson->SetStringField(TEXT("id"), FGuid::NewGuid().ToString());
            DataJson->SetStringField(TEXT("type"), Request.GetRequestType());

            const TSharedPtr<FJsonObject> AttributesJson = MakeShareable<FJsonObject>(new FJsonObject);
            {
                TMap<FString, TSharedPtr<FJsonObject>> Attributes;
                Request.GenerateAttributesJson(Attributes);
                ensure (Attributes.Num() > 0);

                for (const TTuple<FString, TSharedPtr<FJsonObject>>& Attribute : Attributes)
                {
                    AttributesJson->SetObjectField(Attribute.Key, Attribute.Value);
                }
            }
            DataJson->SetObjectField(TEXT("attributes"), AttributesJson);
        }
        RootJson->SetObjectField(TEXT("data"), DataJson);

        const TSharedPtr<FJsonObject> MetaJson = MakeShareable<FJsonObject>(new FJsonObject);
        {
            MetaJson->SetStringField(TEXT("platform"), TEXT("unreal"));
            MetaJson->SetStringField(TEXT("platform_version"), TOSTRING(ENGINE_MAJOR_VERSION) "." TOSTRING(ENGINE_MINOR_VERSION));
            MetaJson->SetBoolField(TEXT("editor"), FSystemUtilityLibrary::IsWithEditor());
            MetaJson->SetStringField(TEXT("plugin_version"), GetMutableDefault<UMetahumanSDKSettings>()->GetPluginVersion());
            MetaJson->SetStringField(TEXT("OS"), UGameplayStatics::GetPlatformName());
            MetaJson->SetStringField(TEXT("local"), FInternationalization::Get().GetDefaultLanguage()->GetName());
            const FString PrevTypeLocal = GRequestStatistics.PrevType.IsValid() ? *GRequestStatistics.PrevType.Get() : "";
            MetaJson->SetStringField( TEXT("prev_type"), FString(PrevTypeLocal) );
            MetaJson->SetStringField(TEXT("prev_size"), FString::FromInt(GRequestStatistics.GetSize()));
            MetaJson->SetStringField(TEXT("latency"), FString::SanitizeFloat(GRequestStatistics.GetTime()));
            MetaJson->SetBoolField(TEXT("prev_combo_atl"), GRequestStatistics.PrevComboAtl);
            MetaJson->SetBoolField(TEXT("prev_combo_chat"), GRequestStatistics.PrevComboChat);
            MetaJson->SetBoolField(TEXT("prev_combo_tts"), GRequestStatistics.PrevComboTts);
            MetaJson->SetNumberField(TEXT("prev_audio_length"), GRequestStatistics.GetAudioLength());
        }
        RootJson->SetObjectField(TEXT("meta"), MetaJson);
    }

    const FString GeneratedRequest = FJsonToStringUtilities::JsonObjectToString(RootJson);
#if WITH_EDITOR
    FFileHelper::SaveStringToFile(GeneratedRequest, *FString( FPaths::ProjectSavedDir() + "/MetahumanSDK/Temp/Request.json" ));
#endif  
    
    return GeneratedRequest;
}


TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> FMetahumanSDKRequestManager::MakeATLRequest(const FATLRequest& Request, FResponseCompletedSignature CompletedDelegate /*= nullptr*/)
{
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    {
        // if (GetMutableDefault<UMetahumanSDKSettings>() && GetMutableDefault<UMetahumanSDKSettings>()->APIToken.IsEmpty() && GenerateAPIToken(GetMutableDefault<UMetahumanSDKSettings>()->APIToken))
        // {
        //     GetMutableDefault<UMetahumanSDKSettings>()->TryUpdateDefaultConfigFile();
        // }
        
        FHttpModule::Get().SetHttpTimeout(GetMutableDefault<UMetahumanSDKSettings>()->ATLRequestTimeoutSeconds);
        
        const FString& ApiBaseUrl = GetMutableDefault<UMetahumanSDKSettings>()->APIURL;
        const FString& ApiToken = GetMutableDefault<UMetahumanSDKSettings>()->APIToken;
        const FString& FullURL = ApiBaseUrl / TEXT("dh/api/v2/atl");
        
        const static FString FORM_BOUNDARY("ATLBoundary");

        HttpRequest->SetURL(FullURL);
        HttpRequest->SetVerb(TEXT("POST"));
        HttpRequest->SetHeader(TEXT("Authorization"), ApiToken);
        HttpRequest->SetHeader("Content-Type", FString::Printf(TEXT("multipart/form-data; boundary=%s"), *FORM_BOUNDARY));
        HttpRequest->SetHeader(TEXT("Accept-Encoding"), TEXT("utf-8"));        

        const FString Line0 = FString::Printf(TEXT("\r\n--%s"), *FORM_BOUNDARY);
        const FString Line1 = TEXT("\r\nContent-Disposition: form-data; name=\"json\"\r\n\r\n");
        const FString Line2 = GenerateRequestJson(Request);
        const FString Line3 = FString::Printf(TEXT("\r\n--%s"), *FORM_BOUNDARY);
        const FString Line4 = TEXT("\r\nContent-Type: application/octet-stream");
        const FString Line5 = TEXT("\r\nContent-Disposition: form-data; name=\"audio\"; filename=\"audio.wav\"\r\n\r\n");
        const FString Line6 = FString::Printf(TEXT("\r\n--%s--\r\n"), *FORM_BOUNDARY);

        TArray<uint8> ContentData;
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line0), Line0.Len());
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line1), Line1.Len());
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line2), Line2.Len());
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line3), Line3.Len());
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line4), Line4.Len());
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line5), Line5.Len());
        ContentData.Append(Request.AudioData);
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line6), Line6.Len());

        HttpRequest->SetContent(ContentData);

        ProcessResponse<FATLResponse>(Request.GetRequestType(), HttpRequest, CompletedDelegate);
    }

    HttpRequest->ProcessRequest();
    GRequestStatistics.UpdateStatisticsWithAudio("atl", false, false, false, Request.ATLInput.Sound->GetDuration());
    
    return HttpRequest;
}

struct FAPITokenResponse : public FGenericResponse
{
    virtual void ParseResponse(FString&& Content) override
    {
        TSharedRef<TJsonReader<>> Reader = FJsonStringReader::Create(MoveTemp(Content));

        TSharedPtr<FJsonObject> RootJson;
        if (FJsonSerializer::Deserialize(Reader, RootJson))
        {
            RootJson->TryGetStringField(TEXT("token"), Token);
        }

        if (!Validate())
        {
            bResponseSuccess = false;
            Error = FString::Printf(TEXT("Invalid API token response json: %s"), *Content);
        }
    }

    virtual bool PassContentAsBytes() const override
    {
        return false;
    }

    bool Validate() const
    {
        return Token.Len() > 0;
    }

    FString Token = "";
};

// bool FMetahumanSDKRequestManager::GenerateAPIToken(FString& OutAPIToken)
// {
// 	FString _GeneratedAPIToken = "";
// 	
//     TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
//     {
//         FHttpModule::Get().SetHttpTimeout(60.0);
//
//         HttpRequest->SetURL(GetMutableDefault<UMetahumanSDKSettings>()->APIURL / TEXT("dh/api/v1/guest-token?engine=unreal"));
//         HttpRequest->SetVerb(TEXT("POST"));
//
//         UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("API token request started..."));
//
// 	    const double StartTime = FPlatformTime::Seconds();
// 	    
// 	    HttpRequest->OnProcessRequestComplete().BindLambda(
// 	        [&_GeneratedAPIToken, StartTime](FHttpRequestPtr Request, FHttpResponsePtr HttpResponse, bool bConnectedSuccessfully)
// 	        {
// 	            UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("API token request finished!"));
//
// 	            TSharedPtr<FGenericResponse> OutResponse(new FAPITokenResponse);
//
// 	            const double EndTime = FPlatformTime::Seconds();
// 	            const double RequestDuration = EndTime - StartTime;
//
// 	            UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("API token request took %f seconds to complete"), RequestDuration);
// 	            UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("DHS HTTP BODY: %s"), *HttpResponse->GetContentAsString());
// 	            // Handle critical error peacefully to avoid crash
// 	            if (HttpResponse != nullptr && HttpResponse->GetResponseCode() == EHttpResponseCodes::Ok)
// 	            {
// 	                const double ParseResponseStartTime = FPlatformTime::Seconds();
// 	                if (OutResponse->PassContentAsBytes())
// 	                {
// 	                    OutResponse->ParseResponse(HttpResponse->GetContent());                   
// 	                }
// 	                else
// 	                {
// 	                    OutResponse->ParseResponse(HttpResponse->GetContentAsString());
// 	                }
//
// 	                const double ParseResponseDuration = FPlatformTime::Seconds() - ParseResponseStartTime;
// 	                UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("Parsing response took %f seconds to complete"), ParseResponseDuration);
// 	            }
// 	            else
// 	            {
// 	                OutResponse->bResponseSuccess = false;
// 	                OutResponse->Error = HttpResponse->GetContentAsString();
// 	                UE_LOG(LogMetahumanSDKRequestsManager, Error, TEXT("Request error: %s"), *OutResponse->Error);
// 	            }
//
// 	        	FAPITokenResponse* APITokenResponse = static_cast<FAPITokenResponse*>(OutResponse.Get());
// 				check(APITokenResponse != nullptr);
// 	        	_GeneratedAPIToken = APITokenResponse->Token;
// 	        }
// 	    );
//     }
// 	HttpRequest->ProcessRequest();
// 	FHttpModule::Get().GetHttpManager().Flush(EHttpFlushReason::Default);
//
// 	OutAPIToken = _GeneratedAPIToken;
//
// 	return true;
// }

TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> FMetahumanSDKRequestManager::MakeTTSRequest(const FTTSRequest& Request, FResponseCompletedSignature CompletedDelegate /*= nullptr*/)
{
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    {
        FHttpModule::Get().SetHttpTimeout(GetMutableDefault<UMetahumanSDKSettings>()->TTSRequestTimeoutSeconds);

        const FString& ApiBaseUrl = GetMutableDefault<UMetahumanSDKSettings>()->APIURL;
        const FString& ApiToken = GetMutableDefault<UMetahumanSDKSettings>()->APIToken;
        const FString& FullURL = ApiBaseUrl / TEXT("dh/api/v1/tts");

        HttpRequest->SetURL(FullURL);
        HttpRequest->SetVerb(TEXT("POST"));
        HttpRequest->SetHeader(TEXT("Authorization"), ApiToken);
        HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
        HttpRequest->SetHeader(TEXT("Accept-Encoding"), TEXT("utf-8"));

        HttpRequest->SetContentAsString(GenerateRequestJson(Request));

        ProcessResponse<FTTSResponse>(Request.GetRequestType(), HttpRequest, CompletedDelegate);
    }

    HttpRequest->ProcessRequest();

    GRequestStatistics.UpdateStatistics("tts", false);
    
    return HttpRequest;
}


TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> FMetahumanSDKRequestManager::MakeChatRequest(const FChatRequest& Request, FResponseCompletedSignature CompletedDelegate /*= nullptr*/)
{
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    {
        FHttpModule::Get().SetHttpTimeout(GetMutableDefault<UMetahumanSDKSettings>()->ChatRequestTimeoutSeconds);
        
        const FString& ApiBaseUrl = GetMutableDefault<UMetahumanSDKSettings>()->APIURL;
        const FString& ApiToken = GetMutableDefault<UMetahumanSDKSettings>()->APIToken;
        const FString& FullURL = ApiBaseUrl / TEXT("dh/api/v1/chat");

        const FString& FORM_BOUNDARY("ATLBoundary");

        HttpRequest->SetURL(FullURL);
        HttpRequest->SetVerb(TEXT("POST"));
        HttpRequest->SetHeader(TEXT("Authorization"), ApiToken);
        HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
        HttpRequest->SetHeader(TEXT("Accept-Encoding"), TEXT("utf-8"));

        HttpRequest->SetContentAsString(GenerateRequestJson(Request));

        ProcessResponse<FChatResponse>(Request.GetRequestType(), HttpRequest, CompletedDelegate);
    }

    HttpRequest->ProcessRequest();

    GRequestStatistics.UpdateStatistics("chat", false);
    
    return HttpRequest;
}


TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> FMetahumanSDKRequestManager::MakeComboRequest(const FComboRequest& Request, FResponseCompletedSignature CompletedDelegate /*= nullptr*/)
{
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    {
        FHttpModule::Get().SetHttpTimeout(GetMutableDefault<UMetahumanSDKSettings>()->ComboRequestTimeoutSeconds);

        const FString& ApiBaseUrl = GetMutableDefault<UMetahumanSDKSettings>()->APIURL;
        const FString& ApiToken = GetMutableDefault<UMetahumanSDKSettings>()->APIToken;
        const FString& FullURL = ApiBaseUrl / TEXT("dh/api/v1/combo");
        HttpRequest->SetURL(FullURL);
        HttpRequest->SetVerb(TEXT("POST"));
        HttpRequest->SetHeader(TEXT("Authorization"), ApiToken);
        HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
        HttpRequest->SetHeader(TEXT("Accept-Encoding"), TEXT("utf-8"));

        HttpRequest->SetContentAsString(GenerateRequestJson(Request));

        ProcessResponse<FComboResponse>(Request.GetRequestType(), HttpRequest, CompletedDelegate);
    }

    HttpRequest->ProcessRequest();
    GRequestStatistics.UpdateStatistics("combo",
        (Request.ComboMode == EComboMode::ECHAT_TTS_ATL || Request.ComboMode == EComboMode::ETTS_ATL),
        (Request.ComboMode == EComboMode::ECHAT_TTS_ATL || Request.ComboMode == EComboMode::ECHAT_TTS),
        (Request.ComboMode == EComboMode::ECHAT_TTS_ATL || Request.ComboMode == EComboMode::ETTS_ATL || Request.ComboMode == EComboMode::ETTS_ATL)
    );   
    
    return HttpRequest;
}


TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> FMetahumanSDKRequestManager::MakeATLStreamRequest(const FATLRequest& Request, FResponseCompletedSignature ChunkRecvDelegate, FResponseCompletedSignature CompletedDelegate)
{
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    {
        FHttpModule::Get().SetHttpTimeout(GetMutableDefault<UMetahumanSDKSettings>()->ATLRequestTimeoutSeconds);
        SetMaxReadBufferSize(Request);
        
        const FString& ApiBaseUrl = GetMutableDefault<UMetahumanSDKSettings>()->APIURL;
        const FString& ApiToken = GetMutableDefault<UMetahumanSDKSettings>()->APIToken;
        const FString& FullURL = ApiBaseUrl / TEXT("dh/api/v1/atl_stream");
        
        const static FString FORM_BOUNDARY("ATLBoundary");

        HttpRequest->SetURL(FullURL);
        HttpRequest->SetVerb(TEXT("POST"));
        HttpRequest->SetHeader(TEXT("Authorization"), ApiToken);
        HttpRequest->SetHeader("Content-Type", FString::Printf(TEXT("multipart/form-data; boundary=%s"), *FORM_BOUNDARY));

        const FString Line0 = FString::Printf(TEXT("\r\n--%s"), *FORM_BOUNDARY);
        const FString Line1 = TEXT("\r\nContent-Disposition: form-data; name=\"json\"\r\n\r\n");
        const FString Line2 = GenerateRequestJson(Request);
        const FString Line3 = FString::Printf(TEXT("\r\n--%s"), *FORM_BOUNDARY);
        const FString Line4 = TEXT("\r\nContent-Type: application/octet-stream");
        const FString Line5 = TEXT("\r\nContent-Disposition: form-data; name=\"audio\"; filename=\"audio.wav\"\r\n\r\n");
        const FString Line6 = FString::Printf(TEXT("\r\n--%s--\r\n"), *FORM_BOUNDARY);

        TArray<uint8> ContentData;
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line0), Line0.Len());
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line1), Line1.Len());
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line2), Line2.Len());
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line3), Line3.Len());
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line4), Line4.Len());
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line5), Line5.Len());
        ContentData.Append(Request.AudioData);
        ContentData.Append((uint8*)TCHAR_TO_UTF8(*Line6), Line6.Len());

        HttpRequest->SetContent(ContentData);

        const double StartTime = FPlatformTime::Seconds();
        UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("ATL stream Request started, t = %f seconds"), StartTime);

        ChunkNum.Reset();
        LastProgressUpdateBytes.Reset();
        HttpRequest->OnRequestProgress().BindLambda(
            [this, ChunkRecvDelegate, StartTime](FHttpRequestPtr Request, int32 BytesSent, int32 BytesReceived)
            {
                const double EndTime = FPlatformTime::Seconds();
                UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("ATL stream OnRequestProgress [BytesSent:%d | BytesReceived:%d], t = %f seconds"), BytesSent, BytesReceived, EndTime - StartTime);
                
                if (BytesReceived == 0)
                {
                    return;
                }

                const FHttpResponsePtr ResponsePtr = Request->GetResponse();
               
                if ( ResponsePtr.IsValid() )
                {   
                    // Info: Response code and Content length is not initialized on request progress
                    // We could have crash here when payload ruined on CurlHttp
                    
                    const FString Content = ResponsePtr->GetContentAsString();
                    
                    bool HasSomethingToParse = true;
                    while (HasSomethingToParse)
                    {
                        HasSomethingToParse = false;
                        
                        FString ContentBuffer = Content.Right(Content.Len() - LastProgressUpdateBytes.GetValue());
                    
                        // BUG: It looks like UE regexp does not support recursion...
                        //const FRegexPattern jsonPattern(TEXT("\\{(?:[^{}]|(?R))*\\}"));
                        // ... so i'll just copy regex into itself a few times
                        const FRegexPattern jsonPattern(TEXT("\\{(?:[^{}]|(\\{(?:[^{}]|(\\{(?:[^{}]|(\\{(?:[^{}])*\\}))*\\}))*\\}))*\\}"));
                        FRegexMatcher jsonPatternMatcher(jsonPattern, ContentBuffer);

                        if (jsonPatternMatcher.FindNext()) 
                        {
                            if (jsonPatternMatcher.GetCaptureGroupBeginning(0) == 0)
                            {
                                FString Chunk = jsonPatternMatcher.GetCaptureGroup(0);

                                UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("ATL stream chunk [len: %d, cursor pos: %d], t = %f seconds"), Chunk.Len(), LastProgressUpdateBytes.GetValue(), EndTime - StartTime);

                                FString TmpFilename = FPaths::ProjectSavedDir() / TEXT("MetahumanSDK") / TEXT("Temp");
                                TmpFilename += TEXT("/");
                                TmpFilename += FString::Printf(TEXT("atl_stream_%d.json"), ChunkNum.GetValue());
                                FFileHelper::SaveStringToFile(Chunk, *TmpFilename);

                                if (ChunkRecvDelegate.IsBound())
                                {
                                    const TSharedPtr<FGenericResponse> OutResponse(new FATLResponse);
                                    OutResponse->ParseResponse(*Chunk);
                                    ChunkRecvDelegate.Execute(OutResponse, true);
                                }

                                ChunkNum.Increment();                                
                                LastProgressUpdateBytes.Add(Chunk.Len());

                                HasSomethingToParse = true;
                            }
                        }
                    }
                }
            }
        );
        HttpRequest->OnProcessRequestComplete().BindLambda(
            [this, StartTime, CompletedDelegate](FHttpRequestPtr Request, FHttpResponsePtr HttpResponse, bool bConnectedSuccessfully)
            {
                UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("ATL stream Request finished!"));

                TSharedPtr<FGenericResponse> OutResponse(new FATLResponse);

                const double EndTime = FPlatformTime::Seconds();
                const double RequestDuration = EndTime - StartTime;

                UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("ATL stream Request took %f seconds to complete"), RequestDuration);

                // Handle critical error peacefully to avoid crash
                if ( HttpResponse != nullptr && HttpResponse->GetResponseCode() == EHttpResponseCodes::Ok )
                {                   
                    OutResponse->bResponseSuccess = true;
                    OutResponse->Error = TEXT("");
                }
                else
                {
                    OutResponse->bResponseSuccess = false;                    
                    OutResponse->Error = HttpResponse->GetResponseCode() == EHttpResponseCodes::Unknown ? TEXT("Request Aborted") : HttpResponse->GetContentAsString();                    

                    FSystemUtilityLibrary::PrintError(HttpResponse->GetResponseCode(), *OutResponse->Error);
                }

                if (CompletedDelegate.IsBound())
                {
                    CompletedDelegate.Execute(OutResponse, bConnectedSuccessfully);
                }

                GRequestStatistics.UpdateStatisticsSizeTime(RequestDuration, HttpResponse->GetContent().Num());
            }
        );
    }

    HttpRequest->ProcessRequest();
    GRequestStatistics.UpdateStatisticsWithAudio("atl_stream", false, Request.ATLInput.Sound->GetDuration());
    
    return HttpRequest;
}


TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> FMetahumanSDKRequestManager::MakeComboStreamRequest(
    const FComboRequest& Request, const FResponseCompletedSignature& OnAudioReceived, const FResponseCompletedSignature& OnAnimChunkReceived, const FResponseCompletedSignature& OnRequestCompleted)
{
    // prevent Stream Response Processor from simultaneous runs as it have to be synchronous.
    if (StreamResponseProcessor != nullptr)
    {
        if (StreamResponseProcessor->IsProcessing())
        {
            UE_LOG(LogMetahumanSDKRequestsManager, Warning, TEXT("Stream Response is already processing"));
            OnRequestCompleted.ExecuteIfBound(nullptr, false);
            return nullptr;
        }
    }
    else
    {
        StreamResponseProcessor = new FStreamResponseProcessor();    

#if WITH_EDITOR
        FDelegateHandle OnEndPie = FEditorDelegates::EndPIE.AddRaw(this, &FMetahumanSDKRequestManager::EndPieReceived);
#endif        
    }

    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    {
        FHttpModule::Get().SetHttpTimeout(GetMutableDefault<UMetahumanSDKSettings>()->ComboRequestTimeoutSeconds);
        // prevent memory allocation while the request in progress
        SetMaxReadBufferSize(Request);

        const FString& ApiToken = GetMutableDefault<UMetahumanSDKSettings>()->APIToken;

        const FString& URL = GetMutableDefault<UMetahumanSDKSettings>()->APIURL + TEXT("/dh/api/v2/combo_stream");        
        HttpRequest->SetURL(URL);
        HttpRequest->SetVerb(TEXT("POST"));
        HttpRequest->SetHeader(TEXT("Authorization"), ApiToken);
        HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
        HttpRequest->SetHeader(TEXT("Accept-Encoding"), TEXT("utf-8"));
        HttpRequest->SetContentAsString(GenerateRequestJson(Request));

        StreamResponseProcessor->ProcessResponse(HttpRequest, OnAudioReceived, OnAnimChunkReceived, OnRequestCompleted);
    }
    
    HttpRequest->ProcessRequest();

    GRequestStatistics.UpdateStatistics(
        "combo_stream",
        (Request.ComboMode == EComboMode::ECHAT_TTS_ATL || Request.ComboMode == EComboMode::ETTS_ATL),
        (Request.ComboMode == EComboMode::ECHAT_TTS_ATL || Request.ComboMode == EComboMode::ECHAT_TTS),
        (Request.ComboMode == EComboMode::ECHAT_TTS_ATL || Request.ComboMode == EComboMode::ETTS_ATL || Request.ComboMode == EComboMode::ETTS_ATL)
    );

    return HttpRequest;
}

void FMetahumanSDKRequestManager::SetMaxReadBufferSize(const FComboRequest& Request) const
{
    int32 SizeMultiplier = 1;
    FString TextRequest = Request.ChatRequest.ChatInput.Text;
    
    if (Request.ComboMode == EComboMode::ETTS_ATL)
    {
        TextRequest = Request.TTSRequest.TTSInput.Text;
    }
    
    SizeMultiplier += TextRequest.Len() / 200;
    
    FHttpModule::Get().SetMaxReadBufferSize(SizeMultiplier * 2048 * 1024);
    UE_LOG(LogMetahumanSDKRequestsManager, Display, TEXT ("MaxReadBufferSize: %d"), FHttpModule::Get().GetMaxReadBufferSize());
}

void FMetahumanSDKRequestManager::SetMaxReadBufferSize(const FATLRequest& Request) const
{
    int32 SizeMultiplier = 1;
    SizeMultiplier += Request.AudioData.Num() / 1024 / 512;
    
    FHttpModule::Get().SetMaxReadBufferSize(SizeMultiplier * 2048 * 1024);
    
    UE_LOG(LogMetahumanSDKRequestsManager, Display, TEXT ("MaxReadBufferSize: %d"), FHttpModule::Get().GetMaxReadBufferSize());
}

#if WITH_EDITOR
void FMetahumanSDKRequestManager::EndPieReceived(const bool bSimulating) const
{
    UE_LOG(LogMetahumanSDKRequestsManager, Log, TEXT("%s"), *FString(__FUNCTION__));
    StreamResponseProcessor->Cleanup();
}
#endif
