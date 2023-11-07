#pragma once

#include "CoreMinimal.h"
#include "BasePendingAction.h"
#include "Interfaces/IHttpRequest.h"


class FChatAction : public FBasePendingAction
{

public:
    FChatAction(const FMetahumanSDKChatInput& ChatInput);
    ~FChatAction();

    void Execute() override;

    bool IsActionCompleted() const override;
    bool IsSuccess() const override;
    
    FString OutText = "";

private:
    FMetahumanSDKChatInput ChatInput;
};
