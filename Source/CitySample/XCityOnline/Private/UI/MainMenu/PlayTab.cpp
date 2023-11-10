// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/PlayTab.h"

#include "Components/Button.h"
#include "XCityOnline/Public/LoadingScreenSubsystem.h"
#include "XCityOnline/Public/MainMenu/MainMenuPlayerController.h"

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