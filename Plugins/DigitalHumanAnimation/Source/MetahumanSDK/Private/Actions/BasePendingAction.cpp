#include "BasePendingAction.h"
#include "Engine/Engine.h"
#include "MetahumanSDKAPIManager.h"


FBasePendingAction::FBasePendingAction()
{
    APIManager = GEngine->GetEngineSubsystem<UMetahumanSDKAPIManager>();
    LatentInfo.ExecutionFunction = NAME_None;
}

void FBasePendingAction::FinishAndTrigger(FLatentActionInfo InLatentInfo)
{
    LatentInfo = InLatentInfo;
}

bool FBasePendingAction::IsActionCompleted() const
{
    return bRequestSent && bRequestCompleted;
}

void FBasePendingAction::AddReferencedObjects(FReferenceCollector& Collector)
{    
}

void FBasePendingAction::UpdateOperation(FLatentResponse& Response)
{
    Execute();

    if (IsActionCompleted())
    {
        OnActionCompleted.Broadcast(this);        
    }
    
    // if we got LatentInfo then we need to finish this action
    if (LatentInfo.ExecutionFunction != NAME_None)
    {
        Response.FinishAndTriggerIf(true, LatentInfo.ExecutionFunction, LatentInfo.Linkage, LatentInfo.CallbackTarget);
    }
}

void FBasePendingAction::NotifyObjectDestroyed()
{
    if (bRequestSent && HttpRequest != nullptr)
    {
        HttpRequest->CancelRequest();
    }
}

void FBasePendingAction::NotifyActionAborted()
{
    if (bRequestSent && HttpRequest != nullptr)
    {
        HttpRequest->CancelRequest();
    }
}

TSharedPtr<FMetahumanSDKRequestManager> FBasePendingAction::GetRequestsManager() const
{
    if (GEngine == nullptr)
    {
        return nullptr;
    }

    return GEngine->GetEngineSubsystem<UMetahumanSDKAPIManager>()->GetRequestManager();
}
