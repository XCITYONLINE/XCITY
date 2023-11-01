// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsWidget.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsTab.h"

void USettingsWidget::SelectNewTab(const int32& Index)
{
	if (GetWidgetSwitcher()->GetActiveWidgetIndex() == Index)
	{
		return;
	}

	USettingsTab* CurrentTab = Cast<USettingsTab>(GetWidgetSwitcher()->GetActiveWidget());
	CurrentTab->OnTabDisabled();

	GetWidgetSwitcher()->SetActiveWidgetIndex(Index);
	
	USettingsTab* NewTab = Cast<USettingsTab>(GetWidgetSwitcher()->GetActiveWidget());
	NewTab->OnTabEnabled();
}

void USettingsWidget::InitializeTab(const int32& Index, UWidget* ParentWidget)
{
	Super::InitializeTab(Index, ParentWidget);

	InitializeSettingsWidget();
}

USettingsWidget::USettingsWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bInitialized = false;
}

void USettingsWidget::InitializeSettingsWidget()
{
	ApplySettingsButton->OnClicked.AddUniqueDynamic(this, &USettingsWidget::OnApplySettingsButtonClicked);
	
	for (auto It = GetWidgetSwitcher()->GetAllChildren().CreateIterator(); It; ++It)
	{
		if (USettingsTab* SettingsTab = Cast<USettingsTab>(GetWidgetSwitcher()->GetAllChildren()[It.GetIndex()]))
		{
			SettingsTab->InitializeTab(It.GetIndex(), this);
		}
	}

	InitializeButtons();

	bInitialized = true;
}

void USettingsWidget::InitializeButtons()
{
	InitializeButton(VideoTab, VideoTabButton);
}

void USettingsWidget::InitializeButton(USettingsTab* SettingsTab, USettingButton* SettingsButton)
{
	if (!IsValid(SettingsTab) || !IsValid(SettingsButton))
	{
		return;
	}

	SettingsButton->InitializeTabButton(SettingsTab);
}

void USettingsWidget::OnApplySettingsButtonClicked()
{
	for (const auto Widget : GetWidgetSwitcher()->GetAllChildren())
	{
		if (USettingsTab* SettingsTab = Cast<USettingsTab>(Widget))
		{
			SettingsTab->OnSettingsConfirmed();
		}
	}
}
