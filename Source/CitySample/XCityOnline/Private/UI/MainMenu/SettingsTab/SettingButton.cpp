// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingButton.h"

#include "Components/Border.h"
#include "Components/Image.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsTab.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsWidget.h"

void USettingButton::OnSelected()
{
	const USettingsTab* SettingsTab = GetChildTab<USettingsTab>();
	if (!IsValid(SettingsTab))
	{
		return;
	}
	
	USettingsWidget* SettingsWidget = SettingsTab->GetSettingsWidget();
	SettingsWidget->SelectNewTab(SettingsTab->GetIndex(), this);

	BackgroundBorder->SetBrushColor(SelectedColor);
	SelectedImage->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	
	// ToDo: logic to show confirm or cancel message
}

void USettingButton::OnDisabled()
{
	Super::OnDisabled();

	BackgroundBorder->SetBrushColor(DisabledColor);
	SelectedImage->SetVisibility(ESlateVisibility::Hidden);
}

void USettingButton::InitializeTabButton(UTabBase* ChildTab)
{
	Super::InitializeTabButton(ChildTab);

	BackgroundBorder->SetBrushColor(DisabledColor);
	SelectedImage->SetVisibility(ESlateVisibility::Hidden);
}
