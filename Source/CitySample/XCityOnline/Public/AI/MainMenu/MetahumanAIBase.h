// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MetahumanSDKAPIOutput.h"
#include "GameFramework/Pawn.h"

#include "Provider/CommonTypes.h"
#include "Provider/ResponseTypes.h"
#include "Provider/Types/AudioTypes.h"
#include "MetahumanAIBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewVisemeReceived, const int32&, VisemeID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnConversationStarted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnConversationEnded);

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

USTRUCT(Blueprintable, BlueprintType)
struct FAnswerData
{
	GENERATED_BODY()

	FAnswerData() : AnswerAnimation(EAA_Idle), TemperatureDelta(0.25f) {}
	FAnswerData(TEnumAsByte<EAnswerAnimation> InAnswerAnimation, float InTemperatureDelta)
	{
		AnswerAnimation = InAnswerAnimation;
		TemperatureDelta = InTemperatureDelta;
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Answer Data")
	TEnumAsByte<EAnswerAnimation> AnswerAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Answer Data")
	float TemperatureDelta;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewExpressionReceived, const EAnswerAnimation&, Expression);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTemperatureChanged, const float&, NewTemperature);

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
	inline static const FString FineTunedModelName = "ft:gpt-3.5-turbo-0613:binetex-llc:eva-bot:8SS9QVgw";

	UPROPERTY(BlueprintAssignable)
	FOnNewVisemeReceived OnNewVisemeReceived;

	UPROPERTY(BlueprintAssignable)
	FOnNewExpressionReceived OnNewExpressionReceived;

	UPROPERTY(BlueprintAssignable)
	FOnTemperatureChanged OnTemperatureChanged;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnConversationStarted OnConversationStarted;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnConversationEnded OnConversationEnded;

	int64 GetCurrentAudioOffset();

	UFUNCTION(BlueprintPure, Category = "AI")
	virtual FAnswerData GetAnswerAnimationForWord(const FString& Word);

	UFUNCTION(BlueprintPure, Category = "AI")
	FORCEINLINE float GetTemperature() const { return CurrentMoodTemperature; }
	
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintPure, Category = "AI")
	virtual TMap<FString, FAnswerData>& GetAnswerAnimations();
	
	/**
	Paste your OpenAI key here.You can find your API key at https://platform.openai.com/account/api-keys.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OpenAI")
	FString OpenAIKey = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MetahumanSDK")
	USkeleton* MeshSkeleton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MetahumanSDK")
	UPoseAsset* PoseAsset;

	UFUNCTION(BlueprintImplementableEvent, Category = "MetahumanSDK")
	void StartMetahumanSDK(const TArray<uint8>& FinalSound);

private:
	void OnCreateAudioTranscriptionCompleted(const FAudioTranscriptionResponse& Response);
	void OnCreateChatCompletionCompleted(const FChatCompletionResponse& Response);

	UFUNCTION()
	void OnAudioPlaybackPercent(const USoundWave* PlayingSoundWave, const float PlaybackPercent);

	UFUNCTION()
	void OnSynthesisCompleted(const bool bSuccess);

	UFUNCTION()
	void OnAudioFinished();

	UFUNCTION()
	void OnVisemeReceived(const FAzSpeechVisemeData VisemeData);
	
	void AddNewMessage(const FMessage& Message);

	void AfterRecordCompletedWork();

	void ApplyExpression(const FAnswerData& AnswerData);
	
	UPROPERTY(meta = (AllowPrivateAccess = true), EditAnywhere, Category = "AI")
	TObjectPtr<class UAudioCaptureComponent> AudioCaptureComp;

	UPROPERTY(meta = (AllowPrivateAccess = true), EditAnywhere, Category = "AI")
	TObjectPtr<USoundSubmix> SoundSubmixToRecord;

	UPROPERTY(meta = (AllowPrivateAccess = true), EditAnywhere, Category = "AI")
	FText SSMLQueryBase;

	UPROPERTY(meta = (AllowPrivateAccess = true), EditAnywhere, Category = "AI")
	TMap<FString, FAnswerData> AnswerAnimations;

	UPROPERTY(meta = (AllowPrivateAccess = true), EditAnywhere, Category = "AI")
	TArray<FMessage> PromtMessages;

	UPROPERTY(meta = (AllowPrivateAccess = true), EditAnywhere, Category = "AI")
	TMap<float, FMessage> PromptTemperatures;
	
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

	float CurrentMoodTemperature;

	UPROPERTY()
	TArray<FAzSpeechVisemeData> VisemeDatas;

	int32 LastViseme;
	int32 VisemeIndex;

	FString CurrentPlayerMessage;
	FString CurrentBotMessage;

	FMetahumanSDKATLOutput ATLOutput;
	FString Error;
};
