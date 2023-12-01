// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Provider/CommonTypes.h"
#include "Provider/ResponseTypes.h"
#include "Provider/Types/AudioTypes.h"
#include "MetahumanAIBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewVisemeReceived, const int32&, VisemeID);

UENUM(Blueprintable, BlueprintType)
enum EAnswerAnimation : uint8
{
	EAA_None = 0				UMETA(Hidden),
	EAA_Idle = 1 << 1				UMETA(DisplayName = "Idle"),
	EAA_Threat = 1 << 2				UMETA(DisplayName = "Threat"),
	EAA_Sadness = 1 << 3			UMETA(DisplayName = "Sadness"),
	EAA_Joy = 1 << 4				UMETA(DisplayName = "Joy"),
	EAA_Apathy = 1 << 5				UMETA(DisplayName = "Apathy"),
	EAA_Laugh = 1 << 6				UMETA(DisplayName = "Laugh"),
	EAA_HardQuestion = 1 << 7		UMETA(DisplayName = "Hard Question"),
	EAA_Love = 2 << 0				UMETA(DisplayName = "Love"),
	EAA_Action = 2 << 1				UMETA(DisplayName = "Action"),
	EAA_MAX = 2 << 2				UMETA(Hidden)
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewExpressionReceived, const EAnswerAnimation&, Expression);

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

	UPROPERTY(BlueprintAssignable)
	FOnNewExpressionReceived OnNewExpressionReceived;

	int64 GetCurrentAudioOffset();

	UFUNCTION(BlueprintPure, Category = "AI")
	virtual EAnswerAnimation GetAnswerAnimationForWord(const FString& Word);
	
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintPure, Category = "AI")
	virtual TMap<FString, TEnumAsByte<EAnswerAnimation>>& GetAnswerAnimations();
	
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
	TObjectPtr<class UAudioCaptureComponent> AudioCaptureComp;

	UPROPERTY(meta = (AllowPrivateAccess = true), EditAnywhere, Category = "AI")
	TObjectPtr<USoundSubmix> SoundSubmixToRecord;

	UPROPERTY(meta = (AllowPrivateAccess = true), EditAnywhere, Category = "AI")
	FText SSMLQueryBase;

	UPROPERTY(meta = (AllowPrivateAccess = true), EditAnywhere, Category = "AI")
	TMap<FString, TEnumAsByte<EAnswerAnimation>> AnswerAnimations;

	UPROPERTY(meta = (AllowPrivateAccess = true), EditAnywhere, Category = "AI")
	TArray<FMessage> PromtMessages;

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

	FString CurrentPlayerMessage;
	FString CurrentBotMessage;
};
