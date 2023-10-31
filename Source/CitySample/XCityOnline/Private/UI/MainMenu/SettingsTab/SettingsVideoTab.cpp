// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsVideoTab.h"

#include "Components/Button.h"
#include "GameFramework/GameUserSettings.h"
#include "Components/TextBlock.h"


#define LOCTEXT_NAMESPACE "SettingsTab"

void USettingsVideoTab::OnSettingsConfirmed()
{
	Super::OnSettingsConfirmed();

	UGameUserSettings* GameUserSettings = UGameUserSettings::GetGameUserSettings();
	GameUserSettings->SetFullscreenMode(FullscreenTypes[FullscreenTypeIndex]);
	GameUserSettings->SetScreenResolution(Resolutions[ResolutionIndex]);

	GameUserSettings->ApplySettings(false);
}

USettingsVideoTab::USettingsVideoTab(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	FullscreenTypeIndex = 0;

	FullscreenTypes.Empty();
	FullscreenTypes.Add(0, EWindowMode::Fullscreen);
	FullscreenTypes.Add(1, EWindowMode::Windowed);

	FullscreenDisplayInfo.Empty();
	FullscreenDisplayInfo.Add(0, LOCTEXT("FullscreenTypeFullscreen", "Fullscreen"));
	FullscreenDisplayInfo.Add(1, LOCTEXT("FullscreenTypeWindowed", "Windowed"));

	Resolutions.Empty();
	Resolutions.Add(0, FIntPoint(1280, 720));
	Resolutions.Add(1, FIntPoint(1920, 1080));

	ResolutionIndex = 1;
}

void USettingsVideoTab::NativeConstruct()
{
	Super::NativeConstruct();

	FullscreenSettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnFullscreenSettingLeftButtonClicked);
	FullscreenSettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnFullscreenSettingRightButtonClicked);

	ResolutionSettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnResolutionSettingLeftButtonClicked);
	ResolutionSettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnResolutionSettingRightButtonClicked);
}

void USettingsVideoTab::OnFullscreenSettingLeftButtonClicked()
{
	FullscreenTypeIndex--;
	
	if (FullscreenTypeIndex < 0)
	{
		FullscreenTypeIndex = FullscreenTypes.Num() - 1;
	}

	FullscreenSettingText->SetText(FullscreenDisplayInfo[FullscreenTypeIndex]);
}

void USettingsVideoTab::OnFullscreenSettingRightButtonClicked()
{
	FullscreenTypeIndex++;

	if (FullscreenTypeIndex >= FullscreenTypes.Num() - 1)
	{
		FullscreenTypeIndex = 0;
	}

	FullscreenSettingText->SetText(FullscreenDisplayInfo[FullscreenTypeIndex]);
}

void USettingsVideoTab::OnResolutionSettingLeftButtonClicked()
{
	ResolutionIndex--;

	if (ResolutionIndex < 0)
	{
		ResolutionIndex = Resolutions.Num() - 1;
	}

	ResolutionSettingText->SetText(FText::FromString(Resolutions[ResolutionIndex].X + "X" + Resolutions[ResolutionIndex].Y));
}

void USettingsVideoTab::OnResolutionSettingRightButtonClicked()
{
	ResolutionIndex++;

	if (ResolutionIndex >= Resolutions.Num() - 1)
	{
		ResolutionIndex = 0;
	}

	ResolutionSettingText->SetText(FText::FromString(Resolutions[ResolutionIndex].X + "X" + Resolutions[ResolutionIndex].Y));
}

#undef LOCTEXT_NAMESPACE
