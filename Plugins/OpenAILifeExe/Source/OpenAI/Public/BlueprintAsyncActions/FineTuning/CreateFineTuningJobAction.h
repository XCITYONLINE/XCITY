// OpenAI, Copyright LifeEXE. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "Provider/ResponseTypes.h"
#include "Provider/RequestTypes.h"
#include "CreateFineTuningJobAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FOnCreateFineTuningJob, const FFineTuningJobObjectResponse&, Response, const FOpenAIError&, RawError);

class UOpenAIProvider;

UCLASS()
class UCreateFineTuningJobAction : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable)
    FOnCreateFineTuningJob OnCompleted;

    virtual void Activate() override;

private:
    /**
     * @param URLOverride Allows for the specification of a custom endpoint. This is beneficial when using a proxy.
     * If this functionality is not required, this parameter can be left blank.
     */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "OpenAI | FineTunes")
    static UCreateFineTuningJobAction* CreateFineTuningJob(
        const FFineTuningJob& FineTuningJob, const FOpenAIAuth& Auth, const FString& URLOverride);

    void TryToOverrideURL(UOpenAIProvider* Provider);

    void OnCreateFineTuningJobCompleted(const FFineTuningJobObjectResponse& Response);
    void OnRequestError(const FString& URL, const FString& Content);

private:
    FFineTuningJob FineTuningJob;
    FOpenAIAuth Auth;
    FString URLOverride{};
};
