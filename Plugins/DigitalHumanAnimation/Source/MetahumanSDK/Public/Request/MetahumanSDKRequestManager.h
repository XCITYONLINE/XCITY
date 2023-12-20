#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"
#include "HAL/ThreadSafeBool.h"
#include "Tickable.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

#include "MetahumanSDKRequests.h"
#include "MetahumanSDKResponses.h"
#include "RequestStatistics.h"

DECLARE_DELEGATE_TwoParams(FResponseCompletedSignature, TSharedPtr<FGenericResponse>, bool);


class UMetahumanSDKSettings;
class UMetahumanSDKAPIManager;

class METAHUMANSDK_API FMetahumanSDKRequestManager : public FRunnable, public FTickableGameObject
{

public:
    FMetahumanSDKRequestManager(UMetahumanSDKAPIManager* InAPIManager);
    ~FMetahumanSDKRequestManager();

public:
    void Tick(float DeltaTime) override;
    TStatId GetStatId() const override;

public:
    void Initialize();
    void Cleanup();

public:    
    /* FRunnable interface */
    bool Init() override;
    uint32 Run() override;
    void Exit() override;

    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> MakeATLRequest(const FATLRequest& Request, FResponseCompletedSignature CompletedDelegate = nullptr);    
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> MakeATLStreamRequest(const FATLRequest& Request, FResponseCompletedSignature ChunkRecvDelegate = nullptr, FResponseCompletedSignature CompletedDelegate = nullptr);
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> MakeTTSRequest(const FTTSRequest& Request, FResponseCompletedSignature CompletedDelegate = nullptr);
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> MakeChatRequest(const FChatRequest& Request, FResponseCompletedSignature CompletedDelegate = nullptr);
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> MakeComboRequest(const FComboRequest& Request, FResponseCompletedSignature CompletedDelegate = nullptr);
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> MakeComboStreamRequest(
        const FComboRequest& Request, const FResponseCompletedSignature& OnAudioReceived, const FResponseCompletedSignature& OnAnimChunkReceived, const FResponseCompletedSignature& OnRequestCompleted);

    // ~ Begin Stream Specific
private:
#if WITH_EDITOR
    void EndPieReceived(const bool bSimulating) const;
#endif
    
    FThreadSafeCounter ChunkNum = 0;
    FThreadSafeCounter LastProgressUpdateBytes = 0;

    class FStreamResponseProcessor* StreamResponseProcessor = nullptr;
    // ~ End Stream Specific
    
public:    
    void Trigger();
    void BlockTillAllRequestsFinished();
private:
    
    FString GenerateRequestJson(const FGenericRequest& Request) const;
    //bool GenerateAPIToken(FString& OutAPIToken);
    void SetMaxReadBufferSize (const FComboRequest& Request) const;
    void SetMaxReadBufferSize (const FATLRequest& Request) const;
    
    FRunnableThread* WorkerThread = nullptr;
    FEvent* WorkerThreadSemaphore = nullptr;

    FThreadSafeBool bCompletedWork = true; 

    bool bStopThread = false;
   
    UMetahumanSDKAPIManager* APIManager;
    TWeakObjectPtr<UMetahumanSDKSettings> MetahumanSDKSettings;
};
