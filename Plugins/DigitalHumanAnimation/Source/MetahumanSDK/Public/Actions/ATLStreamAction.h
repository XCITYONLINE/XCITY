#pragma once

#include "CoreMinimal.h"
#include "BasePendingAction.h"
#include "Request/MetahumanSDKResponses.h"
#include "Animation/ATLStreamBuffer.h"
#include "Interfaces/IHttpRequest.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnATLStreamActionChunk, FBasePendingAction*, FATLResponse*);
DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnATLStreamActionStarted, FBasePendingAction*, UATLStreamBuffer*, bool);

class USoundWave;

class FATLStreamAction : public FBasePendingAction
{

public:
    FATLStreamAction(const FMetahumanSDKATLInput& InATLInput);
    ~FATLStreamAction();

    void Execute() override;

    virtual FString GetReferencerName() const override {return TEXT("FATLStreamAction");};
    virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
    
    bool IsActionCompleted() const override;
    bool IsSuccess() const override;

    class UAnimSequence* OutAnimation = nullptr;

    FOnATLStreamActionChunk OnChunk;
    FOnATLStreamActionStarted OnStarted;
    UATLStreamBuffer* Buffer;

    void SetATLInput(const FMetahumanSDKATLInput& AtlInput)
    {
        ATLInput = AtlInput;
    }

private:
    FMetahumanSDKATLInput ATLInput;
};
