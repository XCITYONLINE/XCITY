// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Provider/CommonTypes.h"
#include "Provider/ResponseTypes.h"
#include "Provider/Types/AudioTypes.h"
#include "MetahumanAIBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewVisemeReceived, const int32&, VisemeID);

UCLASS()
class CITYSAMPLE_API AMetahumanAIBase : public APawn
{
	GENERATED_BODY()

	friend class FWaitForViseme;
	
public:
	// Sets default values for this pawn's properties
	AMetahumanAIBase();

	UFUNCTION(BlueprintCallable, Category = "AI")
	void StartRecording();

	UFUNCTION(BlueprintCallable, Category = "AI")
	void FinishRecording();
	
	inline static const FString FileName = "voiceRecorded";

	UPROPERTY(BlueprintAssignable)
	FOnNewVisemeReceived OnNewVisemeReceived;

	int64 GetCurrentAudioOffset();

protected:
	/**
	Paste your OpenAI key here.You can find your API key at https://platform.openai.com/account/api-keys.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OpenAI")
	FString OpenAIKey = "";

private:
	void OnCreateAudioTranscriptionCompleted(const FAudioTranscriptionResponse& Response);
	void OnCreateChatCompletionCompleted(const FChatCompletionResponse& Response);

	UFUNCTION()
	void OnAudioPlaybackPercent(const USoundWave* PlayingSoundWave, const float PlaybackPercent);

	UFUNCTION()
	void OnSynthesisCompleted(const bool bSuccess);

	UFUNCTION()
	void OnVisemeReceived(const FAzSpeechVisemeData VisemeData);
	
	void AddNewMessage(const FMessage& Message);

	void AfterRecordCompletedWork();
	
	UPROPERTY(meta = (AllowPrivateAccess = true), EditAnywhere, Category = "AI")
	TObjectPtr<class UAudioCaptureComponent> AudioCaptureComponent;

	UPROPERTY(meta = (AllowPrivateAccess = true), EditAnywhere, Category = "AI")
	TObjectPtr<USoundSubmix> SoundSubmixToRecord;

	UPROPERTY(meta = (AllowPrivateAccess = true), EditAnywhere, Category = "AI")
	FText SSMLQueryBase;

	UPROPERTY()
	TObjectPtr<class UOpenAIProvider> Provider;

	UPROPERTY()
	TArray<FMessage> Messages;

	UPROPERTY()
	TObjectPtr<class USSMLToSpeechAsync> AsyncTask;

	UPROPERTY()
	FTimerHandle AudioTimer;

	float CurrentAudioTime;
	int64 LastAudioOffset;

	UPROPERTY()
	TArray<FAzSpeechVisemeData> VisemeDatas;

	int32 LastViseme;
	int32 VisemeIndex;
};
