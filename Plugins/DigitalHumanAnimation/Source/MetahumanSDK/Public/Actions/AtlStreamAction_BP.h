#pragma once

#include "ATLStreamAction.h"
#include "Animation/ATLStreamBuffer.h"
#include "MetahumanSDKAPIInput.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AtlStreamAction_BP.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FBaseStreamActionOutputPin,UAnimSequence*,OutAnimation,UATLStreamBuffer*,Buffer,bool,bSuccess,FString,Error);

UCLASS()
class UAtlStreamAction_BP : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FBaseStreamActionOutputPin Chunk;

	UPROPERTY(BlueprintAssignable)
	FBaseStreamActionOutputPin Completed;

	UPROPERTY(BlueprintAssignable)
	FBaseStreamActionOutputPin Started;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AsyncNode")
	static UAtlStreamAction_BP* ATLStream(FMetahumanSDKATLInput Input);

	virtual void Activate() override;

	virtual void BeginDestroy() override;
	
private:
	void RequestAtlStream();

	FMetahumanSDKATLInput ATLInput;

	FATLStreamAction* ATLStreamAction;
};
