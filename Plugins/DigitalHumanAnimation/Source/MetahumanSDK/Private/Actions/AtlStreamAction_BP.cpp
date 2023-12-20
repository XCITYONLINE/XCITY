#include "AtlStreamAction_BP.h"

#include "Engine/World.h"
#include "ATLStreamAction.h"
#include "MetahumanSDKAPIManager.h"
#include "MetahumanSDKSettings.h"
#include "Helpers/SystemUtilityLibrary.h"

UAtlStreamAction_BP* UAtlStreamAction_BP::ATLStream(FMetahumanSDKATLInput Input)
{
	UAtlStreamAction_BP* AtlStreamTask = NewObject<UAtlStreamAction_BP>();
	AtlStreamTask->ATLInput=Input;
	
	return AtlStreamTask;
}

void UAtlStreamAction_BP::Activate()
{
	RequestAtlStream();
}

void UAtlStreamAction_BP::RequestAtlStream()
{
	if (GetDefault<UMetahumanSDKSettings>()->APIToken.Len() == 0)
	{
		FSystemUtilityLibrary::PrintAccessError("Fill API token via Project Settings!");
		return;
	}

	FFrame::KismetExecutionMessage(TEXT("UAtlStreamAction_BP Activate!"), ELogVerbosity::Log);
	ATLStreamAction = new FATLStreamAction(ATLInput);

	ATLStreamAction->OnChunk.AddLambda(
		[this](FBasePendingAction* Action, FATLResponse* Response)
		{
			const FATLStreamAction* CurrentAction = static_cast<FATLStreamAction*>(Action);
			check(CurrentAction != nullptr);

			Chunk.Broadcast(CurrentAction->OutAnimation, nullptr, true, "");
		});
	
	ATLStreamAction->OnStarted.AddLambda(
		[this](FBasePendingAction* Action, UATLStreamBuffer* Buffer, const bool bSuccess)
		{
			const FATLStreamAction* CurrentAction = static_cast<FATLStreamAction*>(Action);		
			
			Started.Broadcast(nullptr, Buffer, bSuccess, CurrentAction->OutError);
		}
	);	

	ATLStreamAction->OnActionCompleted.AddLambda(
	[this](FBasePendingAction* Action)
		{
			const FATLStreamAction* CurrentAction = static_cast<FATLStreamAction*>(Action);
			check(CurrentAction != nullptr);

			Completed.Broadcast(CurrentAction->OutAnimation, nullptr, !CurrentAction->OutError.IsEmpty(),"");

			SetReadyToDestroy();
		}
	);
	
	if (UWorld* World = GetWorld())
	{ 
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();

		FLatentActionInfo LatentInfo;
		LatentInfo.ExecutionFunction = NAME_None;
    	
		if (LatentActionManager.FindExistingAction<FATLStreamAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == nullptr)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, ATLStreamAction);
		}
	}
	else
	{
		ATLStreamAction->Execute();
	}
}
void UAtlStreamAction_BP::BeginDestroy()
{	
	Super::BeginDestroy();

	if (ATLStreamAction != nullptr)
	{
		ATLStreamAction->OnChunk.Clear();
		
		ATLStreamAction->NotifyObjectDestroyed();

		FFrame::KismetExecutionMessage(TEXT("UAtlStreamAction_BP::BeginDestroy"), ELogVerbosity::Log);
	}	
}

