#pragma once

#include "CoreMinimal.h"
#include "BasePendingAction.h"
#include "Interfaces/IHttpRequest.h"


class FComboAction : public FBasePendingAction
{

public:
    FComboAction(const FMetahumanSDKComboInput& InComboInput);
    ~FComboAction();

    void Execute() override;

    virtual FString GetReferencerName() const override {return TEXT("FComboAction");};
    virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

    bool IsSuccess() const override;

    class USoundWave* OutSound = nullptr;
    class UAnimSequence* OutAnimation = nullptr;
    FString OutText = "";

private:
    FMetahumanSDKComboInput ComboInput;
};
