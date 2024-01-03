// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AIFaceAnimInstance.generated.h"

class AMetahumanAIBase;

UENUM(Blueprintable, BlueprintType)
enum class EMood : uint8
{
	EM_None						UMETA(Hidden),
	EM_SmallAnger				UMETA(DisplayName = "Small Anger"),
	EM_VeryAnger				UMETA(DisplayName = "Very Anger"),
	EM_Neutral					UMETA(DisplayName = "Neutral"),
	EM_SmallJoy					UMETA(DisplayName = "Small Joy"),
	EM_VeryJoy					UMETA(DisplayName = "Very Joy"),
	EM_Max						UMETA(Hidden)
};

USTRUCT(Blueprintable, BlueprintType)
struct FVisemeAnimationInfo
{
	GENERATED_BODY()

	FVisemeAnimationInfo() : MouthShapeBlend(0.f), Open(0.f) {}
	FVisemeAnimationInfo(const float& InMouthShapeBlend, const float& InOpen)
	{
		MouthShapeBlend = InMouthShapeBlend;
		Open = InOpen;
	}
	
	UPROPERTY(BlueprintReadOnly, Category = "Viseme Animation Info")
	float MouthShapeBlend = 0.f;

	UPROPERTY(BlueprintReadOnly, Category = "Viseme Animation Info")
	float Open = 0.f;
};

/** Because random sequence player anim graph node in Unreal is broken at this moment. I'm writing this small shit.
 *  NumOfSequences is a number of sequence you will use in Blend Poses by int node.
 *  ChanceForEverySequence is a map where int is an index of animation in list and float is a current chance from 0 to 1.
 *  UpdateTimeForEverySequence is a time when i'm trying to calculate new index for random animation.
 */
USTRUCT(Blueprintable, BlueprintType)
struct FSequenceRandomPlayInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sequence Random Play Info")
	int32 NumOfSequences = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sequence Random Play Info")
	TMap<int32, float> ChanceForEverySequence;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sequence Random Play Info")
	TMap<int32, UAnimSequence*> Sequences;
};

UCLASS()
class CITYSAMPLE_API UAIFaceAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "FaceAnim|Getters")
	FORCEINLINE AMetahumanAIBase* GetBotReference() const { return BotRef; }

	UFUNCTION(BlueprintPure, Category = "FaceAnim|Getters")
	FORCEINLINE bool IsJoy() const { return bIsJoy; }

	UFUNCTION(BlueprintPure, Category = "FaceAnim|Getters", meta = (BlueprintThreadSafe))
	FORCEINLINE float GetTemperatureAnimationAlpha() const { return AnimationTemperatureAlpha; }

	inline static TMap<int32, FVisemeAnimationInfo> VisemeInfos = {
		{ 0, FVisemeAnimationInfo(0, 0) },
		{ 1, FVisemeAnimationInfo(1.0f, 0.1f) },
		{ 2, FVisemeAnimationInfo(1.0f, 0.09f) },
		{ 3, FVisemeAnimationInfo(0.0f, 0.1f) },
		{ 4, FVisemeAnimationInfo(1.31f, 0.04f) },
		{ 5, FVisemeAnimationInfo(1.22f, 0.004f) },
		{ 6, FVisemeAnimationInfo(0.25f, 0.1f) },
		{ 7, FVisemeAnimationInfo(0.f, 0.1f) },
		{ 8, FVisemeAnimationInfo(1.0f, 0.1f) },
		{ 9, FVisemeAnimationInfo(1.25f, 0.1f) },
		{ 10, FVisemeAnimationInfo(1.25f, 0.03f) },
		{ 11, FVisemeAnimationInfo(1.0f, 0.06f) },
		{ 12, FVisemeAnimationInfo(.79f, .1f) },
		{ 13, FVisemeAnimationInfo(.82f, .09f) },
		{ 14, FVisemeAnimationInfo(.7f, .1f) },
		{ 15, FVisemeAnimationInfo(.25f, .07f) },
		{ 16, FVisemeAnimationInfo(1.5f, 0.1f) },
		{ 17, FVisemeAnimationInfo(.5f, .09f) },
		{ 18, FVisemeAnimationInfo(1.86f, .1f) },
		{ 19, FVisemeAnimationInfo(1.807f, .07f) },
		{ 20, FVisemeAnimationInfo(1.92f, .05f) },
		{ 21, FVisemeAnimationInfo(0.0f, 0.03f) }
	};

	inline static TMap<float, FName> MoodNames = {
		{ -10.0f, FName("Small Anger") },
		{ -30.0f, FName("Very Anger") },
		{ 0.0f, FName("Neutral") },
		{ 5.0f, FName("Small Joy") },
		{ 10.0f, FName("Very Joy") }
	};

	inline static TMap<FName, EMood> MoodsInfo = {
		{ FName("Small Anger"), EMood::EM_SmallAnger },
		{ FName("Very Anger"), EMood::EM_VeryAnger },
		{ FName("Neutral"), EMood::EM_Neutral },
		{ FName("Small Joy"), EMood::EM_SmallJoy },
		{ FName("Very Joy"), EMood::EM_VeryJoy }
	};
	
protected:
	UAIFaceAnimInstance(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeBeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "FaceAnim|Events", meta = (DisplayName = "OnNewVisemeReceived"))
	void K2_OnNewVisemeReceived(const int32& VisemeID);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "FaceAnim|Events", meta = (DisplayName = "OnTemperatureChanged"))
	void K2_OnTemperatureChanged(const float& NewTemperature);

	UFUNCTION(BlueprintImplementableEvent, Category = "FaceAnim|Events", meta = (DisplayName = "OnConversationStarted"))
	void K2_OnConversationStarted();

	UFUNCTION(BlueprintImplementableEvent, Category = "FaceAnim|Events", meta = (DisplayName = "OnConversationEnded"))
	void K2_OnConversationEnded();

	UFUNCTION(BlueprintPure, Category = "FaceAnim|Helpers", meta = (BlueprintThreadSafe))
	int32 GetCurrentIndexForAnimation();
	
	UPROPERTY(BlueprintReadOnly, Category = "FaceAnim|Static Info")
	float VisemeDelayTime;
	
	UPROPERTY(BlueprintReadOnly, Category = "FaceAnim|Runtime Info")
	float MouthShapeBlend;

	UPROPERTY(BlueprintReadOnly, Category = "FaceAnim|Runtime Info")
	float OpenAlpha;

	UPROPERTY(BlueprintReadOnly, Category = "FaceAnim|Runtime Info")
	int32 CurrentVisemeID;

	UPROPERTY(BlueprintReadOnly, Category = "FaceAnim|Runtime Info")
	EMood CurrentMood;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FaceAnim|Runtime Info")
	TMap<EMood, FSequenceRandomPlayInfo> RandomPosesInfo;
	
private:
	UPROPERTY()
	TObjectPtr<AMetahumanAIBase> BotRef;

	void SubscribeToEvents();
	
	UFUNCTION()
	void OnNewVisemeReceived(const int32& VisemeID);

	void DelayedVisemeOperations();

	UFUNCTION()
	void OnTemperatureChanged(const float& NewTemperature);

	UFUNCTION()
	void OnConversationStarted();

	UFUNCTION()
	void OnConversationEnded();

	void UpdateRandomSequence();
	void RandomSequenceTick();

	FTimerHandle RandomSequenceTimer;

	float TemperatureInternal;
	float AnimationTemperatureAlpha;
	bool bIsJoy;
	FName CurrentExpressionName;
	float CurrentMoodID;
	int32 CurrentMoodAnimIndex;
	int32 CurrentSequenceIndex;

	bool bCanShowNextEmotion;
};
