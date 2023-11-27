// OpenAI, Copyright LifeEXE. All Rights Reserved.

#include "BlueprintAsyncActions/FineTunes/DeleteFineTunedModelAction.h"
#include "Provider/OpenAIProvider.h"
#include "API/API.h"

UDeleteFineTunedModelAction* UDeleteFineTunedModelAction::DeleteFineTuneModel(
    const FString& ModelID, const FOpenAIAuth& Auth, const FString& URLOverride)
{
    auto* CompletionAction = NewObject<UDeleteFineTunedModelAction>();
    CompletionAction->ModelID = ModelID;
    CompletionAction->Auth = Auth;
    return CompletionAction;
}

void UDeleteFineTunedModelAction::Activate()
{
    auto* Provider = NewObject<UOpenAIProvider>();
    Provider->OnDeleteFineTunedModelCompleted().AddUObject(this, &ThisClass::OnDeleteFineTunedModelCompleted);
    Provider->OnRequestError().AddUObject(this, &ThisClass::OnRequestError);
    TryToOverrideURL(Provider);
    Provider->DeleteFineTunedModel(ModelID, Auth);
}

void UDeleteFineTunedModelAction::OnDeleteFineTunedModelCompleted(const FDeleteFineTuneResponse& Response)
{
    OnCompleted.Broadcast(Response, {});
}

void UDeleteFineTunedModelAction::OnRequestError(const FString& URL, const FString& Content)
{
    OnCompleted.Broadcast({}, FOpenAIError{Content, true});
}

void UDeleteFineTunedModelAction::TryToOverrideURL(UOpenAIProvider* Provider)
{
    if (URLOverride.IsEmpty()) return;

    OpenAI::V1::FOpenAIEndpoints Endpoints;
    Endpoints.Models = URLOverride;
    const auto API = MakeShared<OpenAI::V1::GenericAPI>(Endpoints);
    Provider->SetAPI(API);
}
