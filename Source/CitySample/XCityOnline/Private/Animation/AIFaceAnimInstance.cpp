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

	bCanShowNextEmotion = true;
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
	
	if (!bCanShowNextEmotion)
	{
		return;
	}

	int32 RandomNum = FMath::RandRange(0, RandomPosesInfo[CurrentMood].NumOfSequences - 1);
	while (CurrentMoodAnimIndex == RandomNum)
	{
		RandomNum = FMath::RandRange(0, RandomPosesInfo[CurrentMood].NumOfSequences - 1);
	}
	
	CurrentMoodAnimIndex = RandomNum;
	UE_LOG(LogTemp, Display, TEXT("RandomNum %i"), RandomNum);

	if (GetCurrentIndexForAnimation() >= RandomPosesInfo[CurrentMood].NumOfSequences)
	{
		CurrentMoodAnimIndex = 0;
	}
	
	const UAnimSequence* Sequence = *RandomPosesInfo[CurrentMood].Sequences.Find(GetCurrentIndexForAnimation());
	if (!Sequence) return;
	
	const float PlayLength = (Sequence->GetPlayLength() / Sequence->RateScale) - 1.0f;

	UE_LOG(LogTemp, Display, TEXT("Play Length: %f"), PlayLength);
	
	bCanShowNextEmotion = false;
	GetWorld()->GetTimerManager().SetTimer(RandomSequenceTimer, this, &ThisClass::RandomSequenceTick, PlayLength, false);
}

void UAIFaceAnimInstance::RandomSequenceTick()
{
	bCanShowNextEmotion = true;
	UpdateRandomSequence();
}
