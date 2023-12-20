#pragma once

#include "CoreMinimal.h"
#include "BasePendingAction.h"
#include "Interfaces/IHttpRequest.h"


class USoundWave;

class FATLAction : public FBasePendingAction
{

public:
    FATLAction(const FMetahumanSDKATLInput& InATLInput);
    ~FATLAction();

    void Execute() override;

    virtual FString GetReferencerName() const override {return TEXT("FATLAction");};
    virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

    bool IsActionCompleted() const override;
    bool IsSuccess() const override;
    
    class UAnimSequence* OutAnimation = nullptr;

private:
    FMetahumanSDKATLInput ATLInput;
};
