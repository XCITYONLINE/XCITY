#pragma once

#include "CoreMinimal.h"
#include "BasePendingAction.h"
#include "Request/MetahumanSDKResponses.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FAudioReceivedSignature, USoundWave*);
DECLARE_MULTICAST_DELEGATE_OneParam(FAnimChunkReceivedSignature, UAnimSequence*);
DECLARE_MULTICAST_DELEGATE_OneParam(FTextAnswerReceivedSignature, const FString&);

class FComboStreamAction : public FBasePendingAction
{

public:
     FComboStreamAction(const FMetahumanSDKComboInput& InComboInput);

     void Execute() override;

     virtual FString GetReferencerName() const override {return TEXT("FComboStreamAction");};
     
     bool IsActionCompleted() const override;
     bool IsSuccess() const override;

     FAudioReceivedSignature OnAudioReceived;
     FAnimChunkReceivedSignature OnAnimChunkReceived;
     FTextAnswerReceivedSignature OnTextAnswerReceived;

private:
     FMetahumanSDKComboInput ComboInput;

     bool bAudioRequestCompleted = false;
     bool bFirstAnimChunkReceived = false;
};
