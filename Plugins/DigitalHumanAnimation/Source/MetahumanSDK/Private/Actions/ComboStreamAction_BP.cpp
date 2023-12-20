#include "Actions/ComboStreamAction_BP.h"

#include "MetahumanSDKSettings.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Animation/AnimSequence.h"
#include "Helpers/SystemUtilityLibrary.h"

UComboStreamAction_BP* UComboStreamAction_BP::ComboStream(const UObject* InWorldContextObject, FMetahumanSDKComboInput Input)
{
	UComboStreamAction_BP* ComboStreamTask = NewObject<UComboStreamAction_BP>();
	ComboStreamTask->ComboInput = Input;	
	if (GEngine) ComboStreamTask->World = GEngine->GetWorldFromContextObjectChecked(InWorldContextObject);	
	
	return ComboStreamTask;
}

void UComboStreamAction_BP::Activate()
{
	Super::Activate();

	RequestComboStream();
}

void UComboStreamAction_BP::RequestComboStream()
{
	if (GetDefault<UMetahumanSDKSettings>()->APIToken.Len() == 0)
	{
		FSystemUtilityLibrary::PrintAccessError("Fill API token via Project Settings!");
		if (Failed.IsBound()) Failed.Broadcast(ComboStreamOutput, CurrentAnim_Idx, "EmptyToken");
		return;
	}

	FFrame::KismetExecutionMessage(TEXT("UComboStreamAction_BP Activate"), ELogVerbosity::Log);
	ComboStreamAction = new FComboStreamAction(ComboInput);
	
	// Audio Received
	ComboStreamAction->OnAudioReceived.AddLambda(
		[this](USoundWave* InSoundWave)
		{
			if (InSoundWave == nullptr)
			{
				StreamError = "Can't receive audio!";
				return;
			}

			ComboStreamOutput.Sound = InSoundWave;			
					
			UpdateStream();
		}
	);

	
	// Anim Chunk Received
	ComboStreamAction->OnAnimChunkReceived.AddLambda(
		[this](UAnimSequence* InAnimation)
		{
			if (InAnimation == nullptr)
			{
				StreamError = "Can't receive animation!";
				return;
			}			
			
			ComboStreamOutput.Animations.Add(InAnimation);			
			
			UpdateStream();
		}
	);


	// Text Answer Received
	ComboStreamAction->OnTextAnswerReceived.AddLambda(
		[this](const FString& InText)
		{						
			ComboStreamOutput.Text = InText;		
		}
	);

	// Request Completed
	ComboStreamAction->OnRequestCompleted.AddLambda(
		[this]()
		{
			bRequestCompleted = true;
			if ( !ComboStreamAction->OutError.IsEmpty() )
			{
				if (Failed.IsBound()) Failed.Broadcast(ComboStreamOutput, CurrentAnim_Idx, ComboStreamAction->OutError);
			}
		}
	);
	
	// Action Completed	
	ComboStreamAction->OnActionCompleted.AddLambda(
	[this](FBasePendingAction* InAction)
		{
			FFrame::KismetExecutionMessage(TEXT("ComboStreamAction Completed"), ELogVerbosity::Log);	

			const FComboStreamAction* CurrentAction = static_cast<FComboStreamAction*>(InAction);
			check(CurrentAction != nullptr);

			delete ComboStreamAction;
			ComboStreamAction = nullptr;
		}
	);

	ComboStreamAction->Execute();
}

bool UComboStreamAction_BP::IsStreamReady() const
{
	return ( ComboStreamOutput.Animations.Num() > 0 && ComboStreamOutput.Sound != nullptr ); 
}

void UComboStreamAction_BP::UpdateStream()
{
	if ( !IsStreamReady() )
	{
		return;
	}

	if ( !bStreamStarted )
	{
		StartStream();
		return;
	}
	
	if ( !PlayAnimTimerHandle.IsValid() )
	{
		FFrame::KismetExecutionMessage(TEXT("UComboStreamAction_BP::UpdateStream -- Received waiting chunk"), ELogVerbosity::Warning);
		PlayCurrentAnim();
	}
}

void UComboStreamAction_BP::StartStream()
{
	FFrame::KismetExecutionMessage(TEXT("UComboStreamAction_BP::StartStream"), ELogVerbosity::Log);

	bStreamStarted = true;
				
	if (Ready.IsBound()) Ready.Broadcast(ComboStreamOutput, CurrentAnim_Idx, StreamError);

	PlayCurrentAnim();
}

void UComboStreamAction_BP::PlayCurrentAnim()
{
	if (!World)
	{
		FFrame::KismetExecutionMessage(TEXT("UComboStreamAction_BP::PlayCurrentAnim -- World isn't Valid!"), ELogVerbosity::Error);
		return;
	}
	
	if ( ComboStreamOutput.Animations.IsValidIndex(CurrentAnim_Idx) )
	{		
		FFrame::KismetExecutionMessage( *FString::Printf(TEXT("\r\nUComboStreamAction_BP::PlayCurrentAnim: %d\r\n"), CurrentAnim_Idx), ELogVerbosity::Log );
		
		if (PlayCurrent.IsBound()) PlayCurrent.Broadcast(ComboStreamOutput, CurrentAnim_Idx, StreamError);
		
		const float CurrentAnimationLength = ComboStreamOutput.Animations[CurrentAnim_Idx++]->GetPlayLength();
		World->GetTimerManager().SetTimer(PlayAnimTimerHandle, this, &UComboStreamAction_BP::PlayCurrentAnim, 1.f, false, CurrentAnimationLength);
	}
	else
	{
		AnimFinished();
	}	
}

void UComboStreamAction_BP::AnimFinished()
{
	if ( bRequestCompleted == false )
	{
		FFrame::KismetExecutionMessage(TEXT("UComboStreamAction_BP::AnimFinished -- But the Request is still in the process. Waiting next chunk data..."), ELogVerbosity::Warning);
		PlayAnimTimerHandle.Invalidate();

		StreamError = "delay";
		if (Failed.IsBound()) Failed.Broadcast(ComboStreamOutput, CurrentAnim_Idx, StreamError);
				
		return;
	}

	FFrame::KismetExecutionMessage(TEXT("UComboStreamAction_BP::AnimFinished"), ELogVerbosity::Log);

	if (Finished.IsBound()) Finished.Broadcast(ComboStreamOutput, CurrentAnim_Idx, StreamError);

	bStreamStarted = false;
	SetReadyToDestroy();
}

void UComboStreamAction_BP::BeginDestroy()
{
	FFrame::KismetExecutionMessage(TEXT("UComboStreamAction_BP::BeginDestroy"), ELogVerbosity::Log);
	
	if ( bStreamStarted && ComboStreamAction != nullptr )
	{		
		ComboStreamAction->NotifyObjectDestroyed();
	}

	Super::BeginDestroy();
}
