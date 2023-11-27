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

// Sets default values
AMetahumanAIBase::AMetahumanAIBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AudioCaptureComponent = CreateDefaultSubobject<UAudioCaptureComponent>(TEXT("AudioCapture"));
	AudioCaptureComponent->SetupAttachment(GetRootComponent());

	LastViseme = 9999;
}

void AMetahumanAIBase::StartRecording()
{
	if (!IsValid(AudioCaptureComponent) || !IsValid(SoundSubmixToRecord))
	{
		return;
	}
	
	AudioCaptureComponent->Start();
	UAudioMixerBlueprintLibrary::StartRecordingOutput(this, 60.0f, SoundSubmixToRecord);
}

void AMetahumanAIBase::FinishRecording()
{
	if (!IsValid(AudioCaptureComponent) || !IsValid(SoundSubmixToRecord))
	{
		return;
	}

	AudioCaptureComponent->Stop();
	UAudioMixerBlueprintLibrary::StopRecordingOutput(this, EAudioRecordingExportType::WavFile, FileName, FString(), SoundSubmixToRecord);
	
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::AfterRecordCompletedWork, 1.0f);
}

int32 AMetahumanAIBase::GetCurrentViseme()
{
	if (VisemeDatas.Num() == 0)
	{
		return 0;
	}

	for (auto It = VisemeDatas.CreateIterator(); It; ++It)
	{
		if (CurrentAudioTime >= It->AudioOffsetMilliseconds && It->AudioOffsetMilliseconds >= LastAudioOffset && It->VisemeID != LastViseme)
		{
			LastAudioOffset = It->AudioOffsetMilliseconds;
			LastViseme = It->VisemeID;
			OnNewVisemeReceived.Broadcast(It->VisemeID);
			return It->VisemeID;
		}
	}

	return 0;
}

// Called when the game starts or when spawned
void AMetahumanAIBase::BeginPlay()
{
	Super::BeginPlay();
	
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
	ChatCompletion.Model = "gpt-3.5-turbo";
	ChatCompletion.Max_Tokens = 999;
	
	const FOpenAIAuth OpenAIAuth = UOpenAIFuncLib::LoadAPITokensFromFileOnce(UKismetSystemLibrary::GetProjectDirectory().Append("OpenAIAuth.ini"));

	Provider->OnCreateChatCompletionCompleted().AddUObject(this, &ThisClass::OnCreateChatCompletionCompleted);
	Provider->CreateChatCompletion(ChatCompletion, OpenAIAuth);
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
	UE_LOG(LogTemp, Display, TEXT("%f"), CurrentAudioTime);
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
	AudioComponent->Play();
}

void AMetahumanAIBase::OnVisemeReceived(const FAzSpeechVisemeData VisemeData)
{
	VisemeDatas.Add(VisemeData);
}

void AMetahumanAIBase::AddNewMessage(const FMessage& Message)
{
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
	
	const FOpenAIAuth OpenAIAuth = UOpenAIFuncLib::LoadAPITokensFromFileOnce(UKismetSystemLibrary::GetProjectDirectory().Append("OpenAIAuth.ini"));

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
