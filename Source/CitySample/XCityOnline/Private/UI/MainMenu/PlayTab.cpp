// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/PlayTab.h"

#include "../../../../../../Plugins/OpenAILifeExe/Source/OpenAI/Public/Provider/CommonTypes.h"
#include "Components/Button.h"
#include "Components/RichTextBlock.h"
#include "XCityOnline/Public/LoadingScreenSubsystem.h"

const FString UserRole = UPlayTab::UserRole;
const FString AssistantRole = UPlayTab::AssistantRole;

void UPlayTab::OnNewAIMessageReceived(const FMessage& Message)
{
	if (Message.Role == UserRole)
	{
		FString BaseString = "<FiraCode.Regular.Purple>You: </>";
		BaseString.Append(Message.Content);
		
		PlayerChatText->SetText(FText::FromString(BaseString));

		PlayAnimation(PlayerBorderAnimIn);
	}

	else if (Message.Role == AssistantRole)
	{
		FString BaseString = "<FiraCode.Regular.Orange>Sara: </>";
		BaseString.Append(Message.Content);
		
		AIChatText->SetText(FText::FromString(BaseString));

		PlayAnimation(AIBorderAnimIn);
	}
}

void UPlayTab::NativeConstruct()
{
	Super::NativeConstruct();

	PlayButton->OnClicked.AddUniqueDynamic(this, &UPlayTab::LoadNextLevel);
	ContinueButton->OnClicked.AddUniqueDynamic(this, &UPlayTab::LoadNextLevel);
}

void UPlayTab::LoadNextLevel()
{
	ULoadingScreenSubsystem* LoadingScreenSubsystem = GetGameInstance()->GetSubsystem<ULoadingScreenSubsystem>();
	LoadingScreenSubsystem->StartInGameLoadingScreen("Default");
	
	const FSoftObjectPath& LevelInstancePath = NextLevelInstance.ToSoftObjectPath();
	UObject* LevelAsset = LevelInstancePath.TryLoad();
	if (!LevelAsset)
	{
		UE_LOG(LogTemp, Display, TEXT("Level is null"));
		return;
	}

	if (!LevelAsset->IsA(UWorld::StaticClass()))
	{
		UE_LOG(LogTemp, Display, TEXT("Level asset should derive from UWorld"));
		return;
	}

	const UWorld* WorldAsset = Cast<UWorld>(LevelAsset);
	GetWorld()->ServerTravel("/Game/XCityOnline/Maps/Default");
}