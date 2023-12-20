#include "ComboStreamAction.h"
#include "Animation/AnimSequence.h"
#include "MetahumanSDKAPIManager.h"
#include "Request/MetahumanSDKRequestManager.h"
#include "Request/MetahumanSDKResponses.h"
#include "AnimSequenceFactory.h"
#include "SoundWaveFactory.h"


DEFINE_LOG_CATEGORY_STATIC(LogMetahumanSDKComboStreamAction, Log, All);

FComboStreamAction::FComboStreamAction(const FMetahumanSDKComboInput& InComboInput)
: FBasePendingAction(), ComboInput(InComboInput)
{   
}

void FComboStreamAction::Execute()
{
    check(GetRequestsManager().IsValid());

    if (bRequestSent)
    {
        UE_LOG(LogMetahumanSDKComboStreamAction, Log, TEXT("%s -- Request has been already sent"), *FString(__FUNCTION__));
        return;
    }
    
    FChatRequest ChatRequest(ComboInput.ChatInput);
    {
        APIManager->CacheChatMessage(ComboInput.ChatInput.Text);
        ChatRequest.ChatID = APIManager->GetChatID();
        ChatRequest.ChatHistory = APIManager->GetChatHistory();
    }
    FTTSRequest TTSRequest(ComboInput.TTSInput);
    FATLRequest ATLRequest(ComboInput.ATLInput, false);
    FComboRequest ComboRequest(ComboInput.ComboMode, TTSRequest, ATLRequest, ChatRequest);
    
    const double StartTime = FPlatformTime::Seconds();      
    HttpRequest = GetRequestsManager()->MakeComboStreamRequest(
        ComboRequest,
        FResponseCompletedSignature::CreateLambda(
            [this, StartTime](TSharedPtr<FGenericResponse> Response, bool bSuccess)
            {
                TRACE_CPUPROFILER_EVENT_SCOPE_STR("ComboStreamAction : Audio Received");

                bAudioRequestCompleted = true;
                
                if (!bSuccess)
                {
                    UE_LOG(LogMetahumanSDKComboStreamAction, Log, TEXT("OnAudioReceived wasn't successful response"));
                    if (OnAudioReceived.IsBound()) OnAudioReceived.Broadcast(nullptr);
                    return;
                }

                UE_LOG(LogMetahumanSDKComboStreamAction, Log, TEXT("Audio recieved, t = %f seconds"), FPlatformTime::Seconds() - StartTime);
                
                const FTTSResponse* TtsResponse = static_cast<FTTSResponse*>(Response.Get());
                check(TtsResponse != nullptr);

                USoundWave* OutSound = FSoundWaveFactory::CreateSoundWave(TtsResponse->Data, OutError);
                GRequestStatistics.UpdateStatistics(OutSound->GetDuration());                

                if (OnAudioReceived.IsBound()) OnAudioReceived.Broadcast(OutSound);
            }), 
        FResponseCompletedSignature::CreateLambda(
            [this, StartTime](TSharedPtr<FGenericResponse> Response, bool bSuccess)
            {                
                TRACE_CPUPROFILER_EVENT_SCOPE_STR("ComboStreamAction : Anim Chunk Received");
                
                if (!bSuccess)
                {
                    UE_LOG(LogMetahumanSDKComboStreamAction, Log, TEXT("OnAnimChunkRecieved wasn't successful response"));
                    if (OnAnimChunkReceived.IsBound()) OnAnimChunkReceived.Broadcast(nullptr);
                    return;
                }
                
                UE_LOG(LogMetahumanSDKComboStreamAction, Log, TEXT("Anim chunk recieved, t = %f seconds"), FPlatformTime::Seconds() - StartTime);
                
                FATLResponse* AtlResponse = static_cast<FATLResponse*>(Response.Get());
                check(AtlResponse != nullptr);
                OutError = AtlResponse->Error;

                UAnimSequence* OutAnimation = FAnimSequenceFactory::CreateAnimSequence(
                    ComboInput.ATLInput.Skeleton, ComboInput.ATLInput.BlendShapeCurveInterpMode, ComboInput.ATLInput.MappingsInfo, AtlResponse,OutError);

                if (OnAnimChunkReceived.IsBound()) OnAnimChunkReceived.Broadcast(OutAnimation);

                // On Text Answer Received
                if (bFirstAnimChunkReceived)
                {
                    const FString TextAnswer = AtlResponse->Text;
                    if (OnTextAnswerReceived.IsBound() && TextAnswer != "" && TextAnswer != "null")
                    {
                        OnTextAnswerReceived.Broadcast(TextAnswer);
                    };    
                }
                else
                {
                    bFirstAnimChunkReceived = true;    
                }
            }),
        FResponseCompletedSignature::CreateLambda(
            [this, StartTime](TSharedPtr<FGenericResponse> Response, bool bSuccess)
            {
                bRequestCompleted = true;
                
                if (!bSuccess)
                {
                    UE_LOG(LogMetahumanSDKComboStreamAction, Warning, TEXT("OnRequestCompleted wasn't successful response"));
                    return;
                }

                UE_LOG(LogMetahumanSDKComboStreamAction, Log, TEXT("Combo stream request completed, t = %f seconds"), FPlatformTime::Seconds() - StartTime);

                OutError = Response->Error;

                if ( OnRequestCompleted.IsBound() )
                {
                    OnRequestCompleted.Broadcast();
                }
            }
        ));

    bRequestSent = true;
    
}

bool FComboStreamAction::IsActionCompleted() const
{
    return bRequestCompleted && bAudioRequestCompleted;
}

bool FComboStreamAction::IsSuccess() const
{
    return IsActionCompleted() && OutError.Len() == 0;
}
