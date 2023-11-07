#pragma once

#include "CoreMinimal.h"
#include "BasePendingAction.h"
#include "Interfaces/IHttpRequest.h"


class FTTSAction : public FBasePendingAction
{

public:
    FTTSAction(const FMetahumanSDKTTSInput& InTTSInput);
    ~FTTSAction();

    void Execute() override;

    virtual FString GetReferencerName() const override {return TEXT("FTTSAction");};
    virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

    bool IsSuccess() const override;

    class USoundWave* OutSound = nullptr;

private:
    FMetahumanSDKTTSInput TTSInput;
};
