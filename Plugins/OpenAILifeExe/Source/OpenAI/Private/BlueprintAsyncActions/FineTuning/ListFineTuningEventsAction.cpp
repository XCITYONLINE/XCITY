// OpenAI, Copyright LifeEXE. All Rights Reserved.

#include "BlueprintAsyncActions/FineTuning/ListFineTuningEventsAction.h"
#include "Provider/OpenAIProvider.h"
#include "API/API.h"

UListFineTuningEventsAction* UListFineTuningEventsAction::ListFineTuningEvents(
    const FString& FineTuningID, const FOpenAIAuth& Auth, const FString& URLOverride)
{
    auto* CompletionAction = NewObject<UListFineTuningEventsAction>();
    CompletionAction->FineTuningID = FineTuningID;
    CompletionAction->Auth = Auth;
    return CompletionAction;
}

void UListFineTuningEventsAction::Activate()
{
    auto* Provider = NewObject<UOpenAIProvider>();
    Provider->OnListFineTuneEventsCompleted().AddUObject(this, &ThisClass::OnListFineTuningEventsCompleted);
    Provider->OnRequestError().AddUObject(this, &ThisClass::OnRequestError);
    TryToOverrideURL(Provider);
    Provider->ListFineTuningEvents(FineTuningID, Auth);
}

void UListFineTuningEventsAction::OnListFineTuningEventsCompleted(const FFineTuneEventsResponse& Response)
{
    OnCompleted.Broadcast(Response, {});
}

void UListFineTuningEventsAction::OnRequestError(const FString& URL, const FString& Content)
{
    OnCompleted.Broadcast({}, FOpenAIError{Content, true});
}

void UListFineTuningEventsAction::TryToOverrideURL(UOpenAIProvider* Provider)
{
    if (URLOverride.IsEmpty()) return;

    OpenAI::V1::FOpenAIEndpoints Endpoints;
    Endpoints.FineTuningJobs = URLOverride;
    const auto API = MakeShared<OpenAI::V1::GenericAPI>(Endpoints);
    Provider->SetAPI(API);
}
