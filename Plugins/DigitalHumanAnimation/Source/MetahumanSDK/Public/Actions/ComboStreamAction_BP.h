#pragma once

#include <memory>

#include "MetahumanSDKAPIInput.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ComboStreamAction.h"
#include "MetahumanSDKAPIOutput.h"
#include "ComboStreamAction_BP.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOutputPinSignature, FComboStreamOutput, ComboStreamOutput, int32, CurrentAnim_Idx, FString, StreamError);

class FComboStreamAction;

UCLASS()
class UComboStreamAction_BP : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AsyncNode")
	static UComboStreamAction_BP* ComboStream(const UObject* WorldContextObject, FMetahumanSDKComboInput Input);

	UPROPERTY(BlueprintAssignable, meta = (Tooltip = "Runs when an audio with a first animation chunk received"))
	FOutputPinSignature Ready;
	UPROPERTY(BlueprintAssignable, meta = (Tooltip = "Runs when ready to play current animation chunk"))
	FOutputPinSignature PlayCurrent;
	UPROPERTY(BlueprintAssignable, meta = (Tooltip = "Runs when a last animation chunk was played"))
	FOutputPinSignature Finished;
	UPROPERTY(BlueprintAssignable, meta = (Tooltip = "Runs in case impossibility stream processing"))
	FOutputPinSignature Failed;

	virtual void Activate() override;
	virtual void BeginDestroy() override;

	UPROPERTY(BlueprintReadOnly, Category = "Combo Stream Action BP")
	FComboStreamOutput ComboStreamOutput;
	UPROPERTY(BlueprintReadOnly, Category = "Combo Stream Action BP")
	int32 CurrentAnim_Idx = 0;
	UPROPERTY(BlueprintReadOnly, Category = "Combo Stream Action BP")
	FString StreamError = "";	

private:
	void RequestComboStream();	
	bool IsStreamReady() const;
	void UpdateStream();
	void StartStream();

	void PlayCurrentAnim();
	void AnimFinished();
	
	FMetahumanSDKComboInput ComboInput;
	FComboStreamAction* ComboStreamAction;
	bool bStreamStarted = false;
	bool bRequestCompleted = false;
	FTimerHandle PlayAnimTimerHandle;
	
	UPROPERTY()
	UWorld* World = nullptr;
};
