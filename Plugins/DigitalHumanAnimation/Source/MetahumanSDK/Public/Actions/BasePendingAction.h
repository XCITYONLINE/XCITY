#pragma once

#include "CoreMinimal.h"
#include "UObject/GCObject.h"
#include "UObject/UObjectGlobals.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Interfaces/IHttpRequest.h"
#include "UObject/GCObject.h"
#include "MetahumanSDKAPIInput.h"

class UMetahumanSDKAPIManager;
class FPendingLatentAction;
struct FLatentActionInfo;

class FBasePendingAction;
DECLARE_MULTICAST_DELEGATE_OneParam(FOnActionCompleted, FBasePendingAction*);
DECLARE_MULTICAST_DELEGATE(FOnRequestCompleted);

class FBasePendingAction : public FPendingLatentAction, public FGCObject
{

public:
    FBasePendingAction();
    
    virtual void Execute() = 0;
    void FinishAndTrigger(FLatentActionInfo InLatentInfo);
    
protected:
    virtual bool IsActionCompleted() const;
    virtual bool IsSuccess() const = 0;

public:
    FOnActionCompleted OnActionCompleted;
    FOnRequestCompleted OnRequestCompleted;
    
    FString OutError = "";
    
protected:
    UMetahumanSDKAPIManager* APIManager;
    TSharedPtr<class FMetahumanSDKRequestManager> GetRequestsManager() const;

    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = nullptr;
    bool bRequestSent = false;
    bool bRequestCompleted = false;
    
private:
    FLatentActionInfo LatentInfo;   
    
    //~ Begin FPendingLatentAction Interface
public:
    virtual void NotifyObjectDestroyed() override;
protected:
    virtual void UpdateOperation(FLatentResponse& Response) override;    
    virtual void NotifyActionAborted() override;
    //~ End FPendingLatentAction Interface

    //~ Begin FGCObject Interface
protected:
    virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
    virtual FString GetReferencerName() const override {return TEXT("FBasePendingAction");};
    //~ Begin FGCObject Interface
};
