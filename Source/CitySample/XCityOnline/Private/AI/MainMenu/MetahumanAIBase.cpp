// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/AI/MainMenu/MetahumanAIBase.h"
#include "AudioCaptureComponent.h"
#include "AudioMixerBlueprintLibrary.h"
#include "AzSpeech/AzSpeechHelper.h"
#include "AzSpeech/AzSpeechSettings.h"
#include "AzSpeech/Tasks/Synthesis/SSMLToSpeechAsync.h"
#include "FuncLib/OpenAIFuncLib.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Provider/OpenAIProvider.h"
#include "XCityOnline/Public/UI/XCityMainMenuHUD.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuWidget.h"
#include "XCityOnline/Public/UI/MainMenu/PlayTab.h"

const FString FileName = AMetahumanAIBase::FileName;
const FString FineTunedModelName = AMetahumanAIBase::FineTunedModelName;

// Sets default values
AMetahumanAIBase::AMetahumanAIBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AudioCaptureComp = CreateDefaultSubobject<UAudioCaptureComponent>(TEXT("AudioCaptureComp"));
	AudioCaptureComp->SetupAttachment(GetRootComponent());

	LastViseme = 9999;
}

void AMetahumanAIBase::StartRecording()
{
	if (!IsValid(AudioCaptureComp) || !IsValid(SoundSubmixToRecord))
	{
		return;
	}
	
	AudioCaptureComp->Start();
	UAudioMixerBlueprintLibrary::StartRecordingOutput(this, 60.0f, SoundSubmixToRecord);
}

void AMetahumanAIBase::FinishRecording()
{
	if (!IsValid(AudioCaptureComp) || !IsValid(SoundSubmixToRecord))
	{
		return;
	}

	AudioCaptureComp->Stop();
	UAudioMixerBlueprintLibrary::StopRecordingOutput(this, EAudioRecordingExportType::WavFile, FileName, FString(), SoundSubmixToRecord);
	
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::AfterRecordCompletedWork, 1.0f);
}

int64 AMetahumanAIBase::GetCurrentAudioOffset()
{
	if (VisemeIndex == 0)
	{
		return VisemeDatas[0].AudioOffsetMilliseconds;
	}
	
	if (VisemeDatas.IsValidIndex(VisemeIndex))
	{
		return VisemeDatas[VisemeIndex].AudioOffsetMilliseconds - LastAudioOffset;
	}

	return 0;
}

FAnswerData AMetahumanAIBase::GetAnswerAnimationForWord(const FString& Word)
{
	if (Word.IsEmpty()) return FAnswerData();
	
	TArray<FString> Keys;
	GetAnswerAnimations().GetKeys(Keys);
	
	if (Keys.Num() == 0) return FAnswerData();

	for (auto It = Keys.CreateIterator(); It; ++It)
	{
		if (Word.Contains(Keys[It.GetIndex()]))
		{
			return GetAnswerAnimations()[Keys[It.GetIndex()]];
		}
	}

	return FAnswerData();
}

void AMetahumanAIBase::BeginPlay()
{
	Super::BeginPlay();

	Messages.Append(PromtMessages);
}

TMap<FString, FAnswerData>& AMetahumanAIBase::GetAnswerAnimations()
{
	return AnswerAnimations;
}

void AMetahumanAIBase::OnCreateAudioTranscriptionCompleted(const FAudioTranscriptionResponse& Response)
{
	if (Response.Text.IsEmpty()) return;

	const FMessage Message { "user", Response.Text };
	AddNewMessage(Message);

	if (!IsValid(Provider))
	{
		Provider = NewObject<UOpenAIProvider>(this);
	}

	FChatCompletion ChatCompletion { Messages };
	ChatCompletion.Model = FineTunedModelName;
	ChatCompletion.Max_Tokens = 999;
	
	FOpenAIAuth OpenAIAuth { };
	OpenAIAuth.OrganizationID = "";
	OpenAIAuth.APIKey = OpenAIKey;

	Provider->OnCreateChatCompletionCompleted().AddUObject(this, &ThisClass::OnCreateChatCompletionCompleted);
	Provider->CreateChatCompletion(ChatCompletion, OpenAIAuth);

	if (const FAnswerData AnswerData = GetAnswerAnimationForWord(Response.Text); AnswerData.AnswerAnimation != EAA_None)
	{
		OnNewExpressionReceived.Broadcast(AnswerData.AnswerAnimation);

		ApplyExpression(AnswerData);
	}
}

void AMetahumanAIBase::OnCreateChatCompletionCompleted(const FChatCompletionResponse& Response)
{
	if (Response.Choices.Num() == 0) return;

	AddNewMessage(Response.Choices[0].Message);

	FAzSpeechSynthesisOptions AzSpeechSynthesisOptions;
	AzSpeechSynthesisOptions.Locale = FName("en-US");
	AzSpeechSynthesisOptions.Voice = FName("en-US-JennyNeural");
	AzSpeechSynthesisOptions.bEnableViseme = true;
	AzSpeechSynthesisOptions.SpeechSynthesisOutputFormat = EAzSpeechSynthesisOutputFormat::Riff44100Hz16BitMonoPcm;

	const FString NewString = SSMLQueryBase.ToString().Replace(TEXT("{text}"), *Response.Choices[0].Message.Content);

	if (IsValid(AsyncTask))
	{
		AsyncTask->ConditionalBeginDestroy();
		AsyncTask = nullptr;

		VisemeDatas.Empty();
	}

	LastViseme = 9999;
	CurrentAudioTime = 0.0f;
	VisemeIndex = 0;
	
	AsyncTask = USSMLToSpeechAsync::SSMLToSpeech_CustomOptions(this,
		UAzSpeechSettings::GetDefaultOptions().SubscriptionOptions,
		AzSpeechSynthesisOptions,
		NewString);

	AsyncTask->VisemeReceived.AddUniqueDynamic(this, &ThisClass::OnVisemeReceived);
	AsyncTask->SynthesisCompleted.AddUniqueDynamic(this, &ThisClass::OnSynthesisCompleted);
	AsyncTask->Activate();
}

void AMetahumanAIBase::OnAudioPlaybackPercent(const USoundWave* PlayingSoundWave, const float PlaybackPercent)
{
	CurrentAudioTime = PlayingSoundWave->GetDuration() * PlaybackPercent;
	CurrentAudioTime *= 1000; // converting seconds to milliseconds

	for (auto It = VisemeDatas.CreateConstIterator(); It; ++It)
	{
		if (FMath::IsNearlyEqual(CurrentAudioTime, It->AudioOffsetMilliseconds, 25.0f))
		{
			OnNewVisemeReceived.Broadcast(It->VisemeID);
			break;
		}
	}
}

void AMetahumanAIBase::OnSynthesisCompleted(const bool bSuccess)
{
	if (!bSuccess || !IsValid(AsyncTask))
	{
		return;
	}
	
	USoundWave* FinalSound = UAzSpeechHelper::ConvertAudioDataToSoundWave(AsyncTask->GetAudioData());
	UAudioComponent* AudioComponent = UGameplayStatics::CreateSound2D(this, FinalSound);
	
	CurrentAudioTime = 0.0f;
	AudioComponent->OnAudioPlaybackPercent.AddUniqueDynamic(this, &ThisClass::OnAudioPlaybackPercent);
	AudioComponent->OnAudioFinished.AddUniqueDynamic(this, &ThisClass::OnAudioFinished);
	AudioComponent->Play();

	OnConversationStarted.Broadcast();
}

void AMetahumanAIBase::OnAudioFinished()
{
	OnConversationEnded.Broadcast();
}

void AMetahumanAIBase::OnVisemeReceived(const FAzSpeechVisemeData VisemeData)
{
	VisemeDatas.Add(VisemeData);

	CurrentAudioTime = 0.0f;
	LastAudioOffset = 0.0f;
}

void AMetahumanAIBase::AddNewMessage(const FMessage& Message)
{
	if (Message.Role == "assistant")
	{
		CurrentBotMessage = Message.Content;
	}

	else
	{
		CurrentPlayerMessage = Message.Content;
	}
	
	Messages.Add(Message);
	
	const APlayerController* PlayerController = GetController<APlayerController>();
	if (!IsValid(PlayerController))
	{
		return;
	}

	const AXCityMainMenuHUD* HUD = Cast<AXCityMainMenuHUD>(PlayerController->GetHUD());
	if (!IsValid(HUD))
	{
		return;
	}

	UMainMenuWidget* MainMenuWidget = Cast<UMainMenuWidget>(HUD->GetMainMenuWidget());
	UPlayTab* PlayTab = Cast<UPlayTab>(MainMenuWidget->GetTab(ETabType::ETT_Play));

	PlayTab->OnNewAIMessageReceived(Message);
}

void AMetahumanAIBase::AfterRecordCompletedWork()
{
	FAudioTranscription AudioTranscription;
	AudioTranscription.Language = FString("en");
	AudioTranscription.File = UKismetSystemLibrary::GetProjectDirectory() + "/Saved/BouncedWavFiles/" + FileName + ".wav";
	
	FOpenAIAuth OpenAIAuth { };
	OpenAIAuth.OrganizationID = "";
	OpenAIAuth.APIKey = OpenAIKey;

	if (IsValid(Provider))
	{
		Provider->OnCreateAudioTranscriptionCompleted().Clear();
		Provider->ConditionalBeginDestroy();
		Provider = nullptr;
	}

	Provider = NewObject<UOpenAIProvider>(this);
	Provider->OnCreateAudioTranscriptionCompleted().AddUObject(this, &ThisClass::OnCreateAudioTranscriptionCompleted);
	Provider->CreateAudioTranscription(AudioTranscription, OpenAIAuth);
}

void AMetahumanAIBase::ApplyExpression(const FAnswerData& AnswerData)
{
	if (FMath::IsNearlyEqual(AnswerData.TemperatureDelta, 0.f))
	{
		return;
	}

	CurrentMoodTemperature = FMath::Clamp(CurrentMoodTemperature + AnswerData.TemperatureDelta, -1, 1);
	OnTemperatureChanged.Broadcast(CurrentMoodTemperature);

	TArray<float> Keys;
	PromptTemperatures.GetKeys(Keys);
	
	for (const auto Key : Keys)
	{
		if (FMath::IsNearlyEqual(Key, CurrentMoodTemperature))
		{
			Messages[0] = PromptTemperatures[Key];
		}
	}
}