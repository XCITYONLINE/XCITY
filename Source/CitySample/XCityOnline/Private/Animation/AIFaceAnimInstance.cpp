// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/Animation/AIFaceAnimInstance.h"
#include "XCityOnline/Public/AI/MainMenu/MetahumanAIBase.h"

static TMap<int32, FVisemeAnimationInfo> AnimationInfo = UAIFaceAnimInstance::VisemeInfos;
static TMap<int32, FName> Moods = UAIFaceAnimInstance::MoodNames;
static TMap<FName, EMood> MoodEnums = UAIFaceAnimInstance::MoodsInfo;

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

	CurrentMood = EMood::EM_Neutral;
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
	UpdateRandomSequence();
}

int32 UAIFaceAnimInstance::GetCurrentIndexForAnimation()
{
	return CurrentMoodAnimIndex;
}

void UAIFaceAnimInstance::SubscribeToEvents()
{
	if (!IsValid(BotRef))
	{
		return;
	}

	BotRef->OnNewVisemeReceived.AddUniqueDynamic(this, &ThisClass::OnNewVisemeReceived);
	BotRef->OnTemperatureChanged.AddUniqueDynamic(this, &ThisClass::OnTemperatureChanged);
	BotRef->OnConversationStarted.AddUniqueDynamic(this, &ThisClass::OnConversationStarted);
	BotRef->OnConversationEnded.AddUniqueDynamic(this, &ThisClass::OnConversationEnded);
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
	UpdateRandomSequence();
	
	TemperatureInternal = NewTemperature;

	bIsJoy = TemperatureInternal >= 0 ? true : false;
	AnimationTemperatureAlpha = bIsJoy ? AnimationTemperatureAlpha : AnimationTemperatureAlpha * -1;

	CurrentMoodID = TemperatureInternal == 0 ? 0 : static_cast<int32>(TemperatureInternal / .25f);
	
	CurrentExpressionName = Moods[CurrentMoodID];
	CurrentMood = MoodEnums[CurrentExpressionName];
}

void UAIFaceAnimInstance::OnConversationStarted()
{
	K2_OnConversationStarted();
}

void UAIFaceAnimInstance::OnConversationEnded()
{
	K2_OnConversationEnded();
}

void UAIFaceAnimInstance::UpdateRandomSequence()
{
	if (CurrentMood == EMood::EM_None || CurrentMood == EMood::EM_Max) return;
	
	if (GetWorld()->GetTimerManager().IsTimerActive(RandomSequenceTimer))
	{
		GetWorld()->GetTimerManager().ClearTimer(RandomSequenceTimer);
	}

	GetWorld()->GetTimerManager().SetTimer(RandomSequenceTimer, this, &ThisClass::RandomSequenceTick, RandomPosesInfo[CurrentMood].UpdateTimeForEverySequence[GetCurrentIndexForAnimation()], true);
}

void UAIFaceAnimInstance::RandomSequenceTick()
{
	const float RandomNum = FMath::RandRange(0, 1);

	for (int32 i = 1; i < RandomPosesInfo[CurrentMood].ChanceForEverySequence.Num(); i++)
	{
		if (1 - RandomNum > RandomPosesInfo[CurrentMood].ChanceForEverySequence[i - 1] && 1 - RandomNum < RandomPosesInfo[CurrentMood].ChanceForEverySequence[i])
		{
			CurrentMoodAnimIndex = i;
			return;
		}
	}
}
