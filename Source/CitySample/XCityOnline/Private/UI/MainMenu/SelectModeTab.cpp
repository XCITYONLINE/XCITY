// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SelectModeTab.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "XCityOnline/Public/UI/MainMenu/SelectModeTabButton.h"

void USelectModeTab::SelectNewMode(const FModeInfo& ModeInfo)
{
	if (CurrentModeInfo == ModeInfo)
	{
		return;
	}
	
	BGImage->SetBrushFromTexture(ModeInfo.BGImageAsset);
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
	// Here will be load new map logic
}