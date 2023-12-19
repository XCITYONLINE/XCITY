// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsTab.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsWidget.h"

void USettingsTab::OnSettingsConfirmed()
{
}

void USettingsTab::OnSettingsDeclined()
{
}

void USettingsTab::InitializeTab(const int32& Index, UWidget* ParentWidget)
{
	Super::InitializeTab(Index, ParentWidget);

	SettingsWidgetPtr = Cast<USettingsWidget>(ParentWidget);
}

void USettingsTab::MarkAsDirty()
{
	bIsDirty = true;
}
