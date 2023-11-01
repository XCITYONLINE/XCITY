// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingButton.h"
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
	SettingsWidget->SelectNewTab(SettingsTab->GetIndex());

	// ToDo: logic to show confirm or cancel message
}
