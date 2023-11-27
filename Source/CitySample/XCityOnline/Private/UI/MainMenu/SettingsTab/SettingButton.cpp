// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingButton.h"

#include "Components/Border.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
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
	SettingsWidget->SelectNewTab(SettingsTab->GetIndex(), this, bIsSubButton);

	BackgroundBorder->SetBrush(SelectedBrush);
	SelectedImage->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

	ButtonTextPtr->SetColorAndOpacity(SelectedTextColor);
	
	// ToDo: logic to show confirm or cancel message
}

void USettingButton::OnDisabled()
{
	Super::OnDisabled();

	BackgroundBorder->SetBrush(DisabledBrush);
	SelectedImage->SetVisibility(ESlateVisibility::Hidden);

	ButtonTextPtr->SetColorAndOpacity(DisabledTextColor);
}

void USettingButton::InitializeTabButton(UTabBase* ChildTab)
{
	Super::InitializeTabButton(ChildTab);

	BackgroundBorder->SetBrush(DisabledBrush);
	SelectedImage->SetVisibility(ESlateVisibility::Hidden);
}
