#include "Request/StreamResponseProcessor.h"

//#include "HAL/ThreadManager.h"

#include "HttpModule.h"
#include "Async/Async.h"
#include "Helpers/SystemUtilityLibrary.h"
#include "Internationalization/Regex.h"

DEFINE_LOG_CATEGORY_STATIC(LogStreamResponseProcessor, Log, All);

void FStreamResponseProcessor::ProcessResponse(TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest,
                                               const FResponseCompletedSignature& OnAudioReceived, const FResponseCompletedSignature& OnAnimChunkReceived, const
                                               FResponseCompletedSignature& OnRequestCompleted)
{
    bProcessing = true;
    Response = MakeShared<FATLResponse>();
    HttpAnimationRequest = HttpRequest;
    
    UE_LOG(LogStreamResponseProcessor, Log, TEXT("Stream Request started..."));
    const double StartTime = FPlatformTime::Seconds();
   
    // Progress
    HttpAnimationRequest->OnRequestProgress().BindLambda(
        [this, OnAudioReceived, OnAnimChunkReceived, StartTime](const FHttpRequestPtr& Request, const int32 BytesSent, const int32 BytesReceived)
        {
            TRACE_CPUPROFILER_EVENT_SCOPE_STR("StreamResponseProcessor : OnRequestProgress");
            const double EndTime = FPlatformTime::Seconds();
            UE_LOG(LogStreamResponseProcessor, Log, TEXT("Stream OnRequestProgress [BytesSent:%d | BytesReceived:%d], t = %f seconds"), BytesSent, BytesReceived, EndTime - StartTime);
            
            if ( BytesReceived == 0 )
            {
                return;
            }

            if ( !bProcessing )
            {
                UE_LOG(LogStreamResponseProcessor, Error, TEXT("OnRequestProgress : Request isn't Processing"));
                return;
            }

            if ( const FHttpResponsePtr ResponsePtr = Request->GetResponse(); ResponsePtr.IsValid() )            
            {

                const FString Content = ResponsePtr->GetContentAsString();
                if (Content.IsEmpty())
                {
                    UE_LOG( LogStreamResponseProcessor, Log, TEXT("Stream OnRequestProgress -- Content is Empty") );
                    return;
                }
                
                bool HasSomethingToParse = true;
                while (HasSomethingToParse)
                {
                    HasSomethingToParse = false;
                    
                    FString ContentBuffer = Content.Right(Content.Len() - LastProgressUpdateBytes);
                
                    // Info: jsonPattern(TEXT("\\{(?:[^{}]|(?R))*\\}"))
                    const FRegexPattern jsonPattern(TEXT("\\{(?:[^{}]|(\\{(?:[^{}]|(\\{(?:[^{}]|(\\{(?:[^{}])*\\}))*\\}))*\\}))*\\}"));
                    FRegexMatcher jsonPatternMatcher(jsonPattern, ContentBuffer);

                    if (jsonPatternMatcher.FindNext()) 
                    {
                        if (jsonPatternMatcher.GetCaptureGroupBeginning(0) == 0)
                        {
                            FString Chunk = jsonPatternMatcher.GetCaptureGroup(0);
                            UE_LOG(LogStreamResponseProcessor, Log,
                                TEXT("Stream chunk %d [len: %d, cursor pos: %d], t = %f seconds"), AnimChunkNum, Chunk.Len(), LastProgressUpdateBytes, EndTime - StartTime);

                            // Try to parse description first
                            if (!bDescriptionReceived)
                            {                               
                                TRACE_CPUPROFILER_EVENT_SCOPE_STR("Stream : Parse description");
                                Response->ParseDescription( Chunk, "stream_description.json");
                                if ( !Response->bResponseSuccess )
                                {
                                    UE_LOG(LogStreamResponseProcessor, Error, TEXT("Can't Parse Response Description! Chunk data: %s"), *FString(Chunk));
                                    return;
                                }

                                bDescriptionReceived = true;
                                
                                HttpAudioRequest = RequestAudio(this, Response->AudioUrl, OnAudioReceived);
                            }
                            // Try to parse frames
                            else
                            {                               
                                ParseFrames(Chunk, OnAnimChunkReceived);
                            }

                            AnimChunkNum++;                                
                            LastProgressUpdateBytes += Chunk.Len();
                            HasSomethingToParse = true;
                        }
                    }
                }
            }
        }
    );
    

    // Complete
    HttpAnimationRequest->OnProcessRequestComplete().BindLambda(
        [this, StartTime, OnAudioReceived, OnAnimChunkReceived, OnRequestCompleted]
            (const FHttpRequestPtr& Request, const FHttpResponsePtr& HttpResponse, const bool bConnectedSuccessfully)
        {
            UE_LOG(LogStreamResponseProcessor, Log, TEXT("Stream Request took %f seconds to complete"), FPlatformTime::Seconds() - StartTime);

            if ( !IsProcessingValid(HttpResponse, bConnectedSuccessfully, "Animation Request Completed") )
            {
                Cleanup();
                return;
            }

            FString Error = "";
            if ( HttpResponse != nullptr )
            {                
                if (const int32 ResponseCode = HttpResponse->GetResponseCode(); ResponseCode != EHttpResponseCodes::Ok)
                {
                    Error = *HttpResponse->GetContentAsString();
                    FSystemUtilityLibrary::PrintError(HttpResponse->GetResponseCode(), Error);
                    Response->Error = Error;
                }                               
            }
            else
            {
                UE_LOG(LogStreamResponseProcessor, Error, TEXT("%s -- HttpResponse isn't Valid!"), *FString(__FUNCTION__));    
            }
            
            GRequestStatistics.UpdateStatisticsSizeTime( HttpResponse->GetContent().Num(), (FPlatformTime::Seconds() - StartTime) );

            if (OnRequestCompleted.IsBound()) OnRequestCompleted.Execute(Response, bConnectedSuccessfully);

            bAnimationReceived = true;
            if ( bAudioReceived || HttpResponse->GetResponseCode()!=EHttpResponseCodes::Ok ) Cleanup();
        }
    );
}

bool FStreamResponseProcessor::IsProcessing() const
{
    return bProcessing;
}

TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> FStreamResponseProcessor::RequestAudio(FStreamResponseProcessor* StreamResponseProcessor, const FString& AudioUrl, const FResponseCompletedSignature& OnAudioReceived) const
{
    if ( AudioUrl.IsEmpty() )
    {
        UE_LOG(LogStreamResponseProcessor, Error, TEXT("Can't Request Audio: AudioUrl is empty in the Request!"));        
        return nullptr;
    }

    UE_LOG(LogStreamResponseProcessor, Log, TEXT("Audio Request started..."));
    const double StartTime = FPlatformTime::Seconds();

    
    const TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetURL(AudioUrl);
    HttpRequest->SetVerb(TEXT("GET"));

    HttpRequest->OnProcessRequestComplete().BindLambda(
       [this, StreamResponseProcessor, StartTime, OnAudioReceived]
           (FHttpRequestPtr Request, FHttpResponsePtr HttpResponse, bool bConnectedSuccessfully) 
       {           
           UE_LOG(LogStreamResponseProcessor, Log, TEXT("Audio Request took %f seconds to complete"), FPlatformTime::Seconds() - StartTime);

           if ( !IsProcessingValid(HttpResponse, bConnectedSuccessfully, "Audio Request Completed") )
           {
               StreamResponseProcessor->Cleanup();
               return;
           }

           if (StreamResponseProcessor == nullptr)
           {
               UE_LOG(LogStreamResponseProcessor, Error, TEXT("%s -- Stream Response Processor isn't valid!"), *FString(__FUNCTION__));
               StreamResponseProcessor->Cleanup();
               return;
           }

           const TSharedPtr<FGenericResponse> OutResponse(new FTTSResponse);
           OutResponse->ParseResponse(HttpResponse->GetContent());
          
           OnAudioReceived.ExecuteIfBound(OutResponse, OutResponse->bResponseSuccess);
           StreamResponseProcessor->bAudioReceived = true;
           
           if ( StreamResponseProcessor->bAnimationReceived ) StreamResponseProcessor->Cleanup();
       }
    );

    HttpRequest->ProcessRequest();

    return HttpRequest;
}

void FStreamResponseProcessor::ParseFrames(const FString& InData, const FResponseCompletedSignature& OnParseCompleted) const
{
    TRACE_CPUPROFILER_EVENT_SCOPE_STR("Stream : Parse frames");

    const TSharedPtr<FATLResponse> CurrentChunkResponse = MakeShared<FATLResponse>();
    CurrentChunkResponse.Get()->ApplyDescription(*Response.Get());
    
    CurrentChunkResponse->ParseFrames( InData, FString::Printf(TEXT("stream_chunk_%d.json"), AnimChunkNum) );
    if ( !CurrentChunkResponse->bResponseSuccess )
    {
        UE_LOG(LogStreamResponseProcessor, Error, TEXT("Can't Parse Response Frames! Chunk data: %s"), *FString(InData));
        return;
    }
    
    Response.Get()->Frames.Append(CurrentChunkResponse.Get()->Frames);
    
    if (OnParseCompleted.IsBound())
    {
        const TSharedPtr<FGenericResponse> OutResponse = CurrentChunkResponse;
        OnParseCompleted.Execute(OutResponse, true);
    }
    
    // AsyncTask(ENamedThreads::AnyBackgroundHiPriTask, [this, InData, OnParseCompleted]()
    // {
    //     UE_LOG(LogStreamResponseProcessor, Log, TEXT("AnyBackgroundHiPriTask -- On Anim Chunk Received"));
    //     const TSharedPtr<FATLResponse> CurrentChunkResponse = MakeShared<FATLResponse>();
    //     CurrentChunkResponse.Get()->ApplyDescription(*Response.Get());
    //
    //     CurrentChunkResponse->ParseFrames( InData, FString::Printf(TEXT("stream_chunk_%d.json"), AnimChunkNum) );
    //     if ( !CurrentChunkResponse->bResponseSuccess )
    //     {
    //         UE_LOG(LogStreamResponseProcessor, Error, TEXT("Can't Parse Response Frames! Chunk data: %s"), *FString(InData));
    //         return;
    //     }
    //
    //     Response.Get()->Frames.Append(CurrentChunkResponse.Get()->Frames);
    //
    //
    //     if (OnParseCompleted.IsBound())
    //     {
    //         AsyncTask(ENamedThreads::GameThread, [this, CurrentChunkResponse, OnParseCompleted]()
    //         {
    //             UE_LOG(LogStreamResponseProcessor, Log, TEXT("GameThread -- On Anim Chunk Received"));
    //
    //             const TSharedPtr<FGenericResponse> OutResponse = CurrentChunkResponse;
    //             OnParseCompleted.Execute(OutResponse, true);                     
    //         });
    //     }
    // });      
}

bool FStreamResponseProcessor::IsProcessingValid(const FHttpResponsePtr ResponsePtr, const bool bConnectedSuccessfully, const FString& LogCategory) const
{
    if (!bConnectedSuccessfully)
    {
        UE_LOG(LogStreamResponseProcessor, Error, TEXT("%s --  %s : Connection wasn't succeed!"), *FString(__FUNCTION__),  *LogCategory);
    }
    
    if (!bProcessing)
    {
        UE_LOG(LogStreamResponseProcessor, Error, TEXT("%s --  %s : Connection isn't processing!"), *FString(__FUNCTION__), *LogCategory);  
    }

    return  bConnectedSuccessfully && bProcessing;
}

bool FStreamResponseProcessor::IsRequestProcessing(const TSharedPtr<IHttpRequest, ESPMode::ThreadSafe>& Request) const
{
    return Request.IsValid() && Request.Get()->GetStatus() == EHttpRequestStatus::Processing;
}

void FStreamResponseProcessor::Cleanup()
{    
    UE_LOG(LogStreamResponseProcessor, Log, TEXT("%s --  Cleanup"), *FString(__FUNCTION__));   
    
    if ( IsRequestProcessing(HttpAnimationRequest) ) HttpAnimationRequest->CancelRequest();
    if ( IsRequestProcessing(HttpAudioRequest) ) HttpAudioRequest->CancelRequest();
    
    AnimChunkNum = 0;
    LastProgressUpdateBytes = 0;
    bDescriptionReceived = false;

    bProcessing = false;
    bAnimationReceived = false;
    bAudioReceived = false;
}
