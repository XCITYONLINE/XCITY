// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AIFaceAnimInstance.generated.h"

class AMetahumanAIBase;

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

UCLASS()
class CITYSAMPLE_API UAIFaceAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "FaceAnim|Getters")
	FORCEINLINE AMetahumanAIBase* GetBotReference() const { return BotRef; }

	UFUNCTION(BlueprintPure, Category = "FaceAnim|Getters")
	FORCEINLINE bool IsJoy() const { return bIsJoy; }

	UFUNCTION(BlueprintPure, Category = "FaceAnim|Getters")
	FORCEINLINE float GetTemperatureAnimationAlpha() const { return AnimationTemperatureAlpha; }

	UFUNCTION(BlueprintPure, Category = "FaceAnim|Getters")
	UBlendSpace* GetCurrentMoodBlendSpace() const;

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

	inline static TMap<int32, FName> MoodNames = {
		{ -1, FName("Small Anger") },
		{ -2, FName("Medium Anger") },
		{ -3, FName("Very Anger") },
		{ -4, FName("Super Anger") },
		{ 0, FName("Neutral") },
		{ 1, FName("Small Joy") },
		{ 2, FName("Medium Joy") },
		{ 3, FName("Very Joy") },
		{ 4, FName("Super Joy") }
	};
	
protected:
	UAIFaceAnimInstance(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeBeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "FaceAnim|Events", meta = (DisplayName = "OnNewVisemeReceived"))
	void K2_OnNewVisemeReceived(const int32& VisemeID);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "FaceAnim|Events", meta = (DisplayName = "OnTemperatureChanged"))
	void K2_OnTemperatureChanged(const float& NewTemperature);

	UPROPERTY(BlueprintReadOnly, Category = "FaceAnim|Static Info")
	float VisemeDelayTime;
	
	UPROPERTY(BlueprintReadOnly, Category = "FaceAnim|Runtime Info")
	float MouthShapeBlend;

	UPROPERTY(BlueprintReadOnly, Category = "FaceAnim|Runtime Info")
	float OpenAlpha;

	UPROPERTY(BlueprintReadOnly, Category = "FaceAnim|Runtime Info")
	int32 CurrentVisemeID;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FaceAnim|Static Info", meta = (AllowPrivateAccess = true))
	TMap<FName, class UBlendSpace*> FacialBlendSpaces; 
	
	UPROPERTY()
	TObjectPtr<AMetahumanAIBase> BotRef;

	void SubscribeToEvents();
	
	UFUNCTION()
	void OnNewVisemeReceived(const int32& VisemeID);

	void DelayedVisemeOperations();

	UFUNCTION()
	void OnTemperatureChanged(const float& NewTemperature);

	float TemperatureInternal;
	float AnimationTemperatureAlpha;
	bool bIsJoy;
	FName CurrentExpressionName;
	int32 CurrentMoodID;
};
