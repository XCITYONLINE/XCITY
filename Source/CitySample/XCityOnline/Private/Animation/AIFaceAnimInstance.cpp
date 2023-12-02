// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/Animation/AIFaceAnimInstance.h"
#include "XCityOnline/Public/AI/MainMenu/MetahumanAIBase.h"

static TMap<int32, FVisemeAnimationInfo> AnimationInfo = UAIFaceAnimInstance::VisemeInfos;
static TMap<int32, FName> Moods = UAIFaceAnimInstance::MoodNames;

UBlendSpace* UAIFaceAnimInstance::GetCurrentMoodBlendSpace() const
{
	if (FacialBlendSpaces.Num() == 0)
	{
		return nullptr;
	}

	UBlendSpace* CurrentBS = *FacialBlendSpaces.Find(CurrentExpressionName);
	if (!CurrentBS) return nullptr;
	
	return CurrentBS;
}

UAIFaceAnimInstance::UAIFaceAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	VisemeDelayTime = 0.08f;
	MouthShapeBlend = 0.0f;
	OpenAlpha = 0.0f;
	TemperatureInternal = 0.0f;
	
	CurrentVisemeID = 0;

	BotRef = nullptr;

	bIsJoy = false;

	CurrentExpressionName = FName("Neutral");

	CurrentMoodID = 0;
}

void UAIFaceAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	BotRef = Cast<AMetahumanAIBase>(TryGetPawnOwner());
	if (!IsValid(BotRef))
	{
		UE_LOG(LogAnimation, Error, TEXT("Bot owner is nullptr"));
		return;
	}

	SubscribeToEvents();
}

void UAIFaceAnimInstance::SubscribeToEvents()
{
	if (!IsValid(BotRef))
	{
		return;
	}

	BotRef->OnNewVisemeReceived.AddUniqueDynamic(this, &ThisClass::OnNewVisemeReceived);
	BotRef->OnTemperatureChanged.AddUniqueDynamic(this, &ThisClass::OnTemperatureChanged);
}

void UAIFaceAnimInstance::OnNewVisemeReceived(const int32& VisemeID)
{
	K2_OnNewVisemeReceived(VisemeID);

	CurrentVisemeID = VisemeID;
	
	FTimerHandle VisemeTimer {};
	GetWorld()->GetTimerManager().SetTimer(VisemeTimer, this, &ThisClass::DelayedVisemeOperations, VisemeDelayTime);
}

void UAIFaceAnimInstance::DelayedVisemeOperations()
{
	if (const FVisemeAnimationInfo* CurrentAnimationInfo = AnimationInfo.Find(CurrentVisemeID))
	{
		MouthShapeBlend = CurrentAnimationInfo->MouthShapeBlend;
		OpenAlpha = CurrentAnimationInfo->Open;
		return;
	}

	MouthShapeBlend = 0.0f;
	OpenAlpha = 0.0f;
}

void UAIFaceAnimInstance::OnTemperatureChanged(const float& NewTemperature)
{
	TemperatureInternal = NewTemperature;

	bIsJoy = TemperatureInternal >= 0 ? true : false;
	AnimationTemperatureAlpha = bIsJoy ? AnimationTemperatureAlpha : AnimationTemperatureAlpha * -1;

	CurrentMoodID = TemperatureInternal == 0 ? 0 : static_cast<int32>(TemperatureInternal / .25f);
	
	CurrentExpressionName = Moods[CurrentMoodID];
}