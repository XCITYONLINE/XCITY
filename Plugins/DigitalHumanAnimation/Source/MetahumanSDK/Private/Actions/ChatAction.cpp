#include "ChatAction.h"
#include "MetahumanSDKAPIManager.h"
#include "Request/MetahumanSDKRequestManager.h"
#include "Request/MetahumanSDKResponses.h"


FChatAction::FChatAction(const FMetahumanSDKChatInput& InChatInput)
: ChatInput(InChatInput)
{    
}

FChatAction::~FChatAction()
{
}


void FChatAction::Execute()
{
    check(GetRequestsManager().IsValid());

    if (!bRequestSent)
    {
        FChatRequest Request(ChatInput);
        {
            APIManager->CacheChatMessage(ChatInput.Text);
            Request.ChatID = APIManager->GetChatID();
            Request.ChatHistory = APIManager->GetChatHistory();
        }

        HttpRequest = GetRequestsManager()->MakeChatRequest(
            Request,
            FResponseCompletedSignature::CreateLambda(
                [this](TSharedPtr<FGenericResponse> Response, bool bSuccess)
                {   
                    if (bSuccess && Response->bResponseSuccess)
                    {
                        FChatResponse* ChatResponse = static_cast<FChatResponse*>(Response.Get());
                        check (ChatResponse != nullptr);

                        if (ChatResponse->bResponseSuccess)
                        {
                            OutText = ChatResponse->Reply;
                            APIManager->CacheChatMessage(OutText);
                        }
                        else
                        {
                            OutError = ChatResponse->Error;
                        }
                    }
                    else
                    {
                        OutText = "";
                        OutError = bSuccess ? Response->Error : TEXT("");
                    }
                    
                    bRequestCompleted = true;
                }
            )
        );

        bRequestSent = true;
    }
}

bool FChatAction::IsActionCompleted() const
{
    return bRequestSent&& bRequestCompleted;
}

bool FChatAction::IsSuccess() const
{
    return OutText.Len() > 0 && OutError.Len() == 0;
}
