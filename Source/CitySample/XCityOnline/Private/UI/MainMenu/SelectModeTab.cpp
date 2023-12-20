// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SelectModeTab.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "XCityOnline/Public/LoadingScreenSubsystem.h"
#include "XCityOnline/Public/UI/MainMenu/SelectModeTabButton.h"

void USelectModeTab::SelectNewMode(USelectModeTabButton* Button, const FModeInfo& ModeInfo)
{
	if (CurrentModeInfo == ModeInfo)
	{
		return;
	}

	if (IsValid(CurrentSelectedButton))
	{
		if (CurrentSelectedButton != Button)
		{
			CurrentSelectedButton->DisableSelection();
			Button->EnableSelection();

			CurrentSelectedButton = Button;
		}
	}

	else
	{
		Button->EnableSelection();
		CurrentSelectedButton = Button;
	}
	
	if (IsValid(ModeInfo.BGImageAsset)) BGImage->SetBrushFromTexture(ModeInfo.BGImageAsset);
	LabelText->SetText(ModeInfo.LabelText);
	DescriptionText->SetText(ModeInfo.DescriptionText);

	CurrentModeInfo = ModeInfo;
}

void USelectModeTab::NativeConstruct()
{
	Super::NativeConstruct();

	InitButtons();

	PlayButton->OnClicked.AddUniqueDynamic(this, &ThisClass::USelectModeTab::OnPlayButtonClicked);
}

void USelectModeTab::InitButtons()
{
	MultiplayerTabButton->InitButton(this);
	PortTabButton->InitButton(this);
	BankTabButton->InitButton(this);
	CitySampleTabButton->InitButton(this);
	TeamDeathMatchTabButton->InitButton(this);
}

void USelectModeTab::OnPlayButtonClicked()
{
//	if (!CurrentModeInfo.LevelInstance.IsValid())
//	{
	//	return;
//	}
	
	ULoadingScreenSubsystem* LoadingScreenSubsystem = GetGameInstance()->GetSubsystem<ULoadingScreenSubsystem>();
	LoadingScreenSubsystem->StartInGameLoadingScreen("Default");
	
	const FSoftObjectPath& LevelInstancePath = CurrentModeInfo.LevelInstance.ToSoftObjectPath();
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
	GetWorld()->ServerTravel("/Game//Map/Small_City_LVL");
}