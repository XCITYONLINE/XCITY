// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsWidget.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsTab.h"

void USettingsWidget::SelectNewTab(const int32& Index, USettingButton* SettingButton, bool bIsSubTab)
{
	if (IsValid(CurrentSelectedButton))
	{
		CurrentSelectedButton->OnDisabled();
	}
	CurrentSelectedButton = SettingButton;

	UWidgetSwitcher* WidgetSwitcher = bIsSubTab ? GetSubWidgetSwitcher() : GetWidgetSwitcher();
	
	if (WidgetSwitcher->GetActiveWidgetIndex() == Index)
	{
		return;
	}

	USettingsTab* CurrentTab = Cast<USettingsTab>(WidgetSwitcher->GetActiveWidget());
	CurrentTab->OnTabDisabled();

	WidgetSwitcher->SetActiveWidgetIndex(Index);
	
	USettingsTab* NewTab = Cast<USettingsTab>(WidgetSwitcher->GetActiveWidget());
	NewTab->OnTabEnabled();
}

void USettingsWidget::InitializeTab(const int32& Index, UWidget* ParentWidget)
{
	Super::InitializeTab(Index, ParentWidget);

	InitializeSettingsWidget();
}

FReply USettingsWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == ApplyKey)
	{
		OnApplySettingsButtonClicked();
	}
	
	return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
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
	
	VideoTabButton->OnSelected();
	
	bInitialized = true;
}

void USettingsWidget::InitializeButtons()
{
	InitializeButton(VideoTab, VideoTabButton);
	InitializeButton(ControlsTab, ControlsTabButton);
	InitializeButton(AudioTab, AudioTabButton);
	InitializeButton(VideoTab, DisplayTabButton);
	InitializeButton(AudioTab, NotificationsTabButton);
	InitializeButton(ControlsTab, SettingsMainButton);
	InitializeButton(VideoTab, GameButton);
	InitializeButton(VideoTab, MapButton);
	InitializeButton(VideoTab, StatsButton);
	InitializeButton(VideoTab, BriefButton);
	InitializeButton(VideoTab, OnlineButton);
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
