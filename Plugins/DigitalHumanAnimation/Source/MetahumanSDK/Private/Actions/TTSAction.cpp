#include "TTSAction.h"
#include "MetahumanSDKAPIManager.h"
#include "Request/MetahumanSDKRequestManager.h"
#include "SoundWaveFactory.h"
#include "Kismet/GameplayStatics.h"


DEFINE_LOG_CATEGORY_STATIC(LogMetahumanSDKTTSAction, Log, All);


FTTSAction::FTTSAction(const FMetahumanSDKTTSInput& InTTSInput)
: TTSInput(InTTSInput)
{   
}

FTTSAction::~FTTSAction()
{
}

void FTTSAction::Execute()
{
    check(GetRequestsManager().IsValid());

    if (!bRequestSent)
    {
        const double StartTime = FPlatformTime::Seconds();

        FTTSRequest Request(TTSInput);

        HttpRequest = GetRequestsManager()->MakeTTSRequest(
            Request,
            FResponseCompletedSignature::CreateLambda(
                [this](TSharedPtr<FGenericResponse> Response, bool bSuccess)
                {
                    if (bSuccess && Response->bResponseSuccess)
                    {
                        FTTSResponse* TTSResponse = static_cast<FTTSResponse*>(Response.Get());
                        check(TTSResponse != nullptr);

                        OutSound = FSoundWaveFactory::CreateSoundWave(TTSResponse->Data, OutError);
                    }
                    else
                    {
                        OutSound = nullptr;
                        OutError = bSuccess ? Response->Error : TEXT("");
                    }
                    
                    bRequestCompleted = true;
                }
            )
        );

        bRequestSent = true;

        const double EndTime = FPlatformTime::Seconds();
        UE_LOG(LogMetahumanSDKTTSAction, Log, TEXT("TTS request took %f seconds to be sent"), EndTime - StartTime);
    }
}

void FTTSAction::AddReferencedObjects(FReferenceCollector& Collector)
{
    Collector.AddReferencedObject(OutSound);
}

bool FTTSAction::IsSuccess() const
{
    return IsActionCompleted() && IsValid(OutSound) && OutError.Len() == 0;
}
