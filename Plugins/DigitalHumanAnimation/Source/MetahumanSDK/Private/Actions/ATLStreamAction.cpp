#include "ATLStreamAction.h"
#include "Animation/AnimSequence.h"
#include "MetahumanSDKAPIManager.h"
#include "Request/MetahumanSDKRequestManager.h"
#include "Request/MetahumanSDKResponses.h"
#include "AnimSequenceFactory.h"


DEFINE_LOG_CATEGORY_STATIC(LogMetahumanSDKATLStreamAction, Log, All);

FATLStreamAction::FATLStreamAction(const FMetahumanSDKATLInput& InATLInput)
: FBasePendingAction(), ATLInput(InATLInput)
{
    Buffer = NewObject<UATLStreamBuffer>();
}

FATLStreamAction::~FATLStreamAction()
{
    //Buffer = nullptr;
}

void FATLStreamAction::Execute()
{
    check(GetRequestsManager().IsValid());

    if (!bRequestSent)
    {
        FATLRequest ATLRequest(ATLInput);        
        if (!ATLRequest.bSuccessful)
        {            
            OutError = "Can't prepare ATL streaming request with provided sound wave!";            
            bRequestCompleted = true;

            if (OnStarted.IsBound())
            {    
                OnStarted.Broadcast(this, Buffer, false);
            }
            
           return;
        }
        
        const double StartTime = FPlatformTime::Seconds();       
       
        Buffer->Clear();
        Buffer->ExpectedLength = ATLInput.Sound->Duration;

        HttpRequest = GetRequestsManager()->MakeATLStreamRequest(
            ATLRequest,
            FResponseCompletedSignature::CreateLambda(
                [this, StartTime](TSharedPtr<FGenericResponse> Response, bool bSuccess)
                {
                    if (!bSuccess)
                    {
                        return;
                    }
                    
                    UE_LOG(LogMetahumanSDKATLStreamAction, Log, TEXT("ATL stream chunk recieved, t = %f seconds"), FPlatformTime::Seconds() - StartTime);

                    FATLResponse* ATLResponse = static_cast<FATLResponse*>(Response.Get());
                    check(ATLResponse != nullptr);

                    if (ATLResponse->bResponseSuccess)
                    {
                        OutAnimation = FAnimSequenceFactory::CreateAnimSequence(
                            ATLInput.Skeleton, ATLInput.BlendShapeCurveInterpMode, ATLInput.MappingsInfo, ATLResponse,
                            OutError);

                        if (IsValid(Buffer))
                        {
                            Buffer->AddChunk(OutAnimation);
                            
                            if (OnChunk.IsBound())
                            {    
                                OnChunk.Broadcast(this, ATLResponse);
                            }
                        }
                    }
                    
                    OutError = Response->Error;                    
                }
            ),
            FResponseCompletedSignature::CreateLambda(
                [this, StartTime](TSharedPtr<FGenericResponse> Response, bool bSuccess)
                {
                    UE_LOG(LogMetahumanSDKATLStreamAction, Log, TEXT("ATL stream request complete, t = %f seconds"), FPlatformTime::Seconds() - StartTime);
                    
                    if (bSuccess && Response->bResponseSuccess)
                    {
                        OutError = "";
                    }
                    else
                    {
                        OutAnimation = nullptr;
                        OutError = bSuccess ? Response->Error : TEXT("");
                    }
                    
                    bRequestCompleted = true;
                }
            )
        );

        if (OnStarted.IsBound())
        {    
            OnStarted.Broadcast(this, Buffer, OutError.IsEmpty());
        }

        bRequestSent = true;

        UE_LOG(LogMetahumanSDKATLStreamAction, Log, TEXT("ATL stream request took %f seconds to be sent"), FPlatformTime::Seconds() - StartTime);
    }
}

void FATLStreamAction::AddReferencedObjects(FReferenceCollector& Collector)
{
    Collector.AddReferencedObject(OutAnimation);
    Collector.AddReferencedObject(Buffer);
}

bool FATLStreamAction::IsActionCompleted() const
{
    return bRequestCompleted;
}

bool FATLStreamAction::IsSuccess() const
{
    return IsActionCompleted() && IsValid(OutAnimation) && OutError.Len() == 0;
}
