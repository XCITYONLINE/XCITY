// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/UI/MainMenu/MainMenuWidget.h"

#include "Components/WidgetSwitcher.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuButtonBase.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsWidget.h"

UWidgetSwitcher* UMainMenuWidget::GetWidgetSwitcher() const
{
	return TabSwitcher;
}

void UMainMenuWidget::SelectNewTab(const int32& Index, UMainMenuButtonBase* MainMenuButton)
{
	if (IsValid(CurrentSelectedButton))
	{
		CurrentSelectedButton->OnDisabled();
	}

	CurrentSelectedButton = MainMenuButton;
	
	if (GetWidgetSwitcher()->GetActiveWidgetIndex() == Index)
	{
		return;
	}
	
	UMainMenuTabBase* CurrentTab = Cast<UMainMenuTabBase>(GetWidgetSwitcher()->GetActiveWidget());
	CurrentTab->OnTabDisabled();

	GetWidgetSwitcher()->SetActiveWidgetIndex(Index);
	UMainMenuTabBase* NewTab = Cast<UMainMenuTabBase>(GetWidgetSwitcher()->GetWidgetAtIndex(Index));
	NewTab->OnTabEnabled();
	//NewTab->SetUserFocus(GetOwningPlayer());
}

UMainMenuTabBase* UMainMenuWidget::GetTab(ETabType TabType)
{
	switch (TabType)
	{
	case ETabType::ETT_Club:
		return ClubTab;
	case ETabType::ETT_Play:
		return PlayTab;
	case ETabType::ETT_Settings:
		return SettingsTab;
	case ETabType::ETT_Store:
		return StoreTab;
	}

	return PlayTab;
}

UMainMenuWidget::UMainMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bIsInitialized = false;
}

FReply UMainMenuWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	USettingsWidget* SettingsWidget = Cast<USettingsWidget>(SettingsTab);
	
	if (InKeyEvent.GetKey() == SettingsWidget->ApplyKey) SettingsWidget->OnApplySettingsButtonClicked();
	UE_LOG(LogTemp, Display, TEXT("Key down"));
	
	return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
}

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	InitializeMainMenu();
}

void UMainMenuWidget::InitializeMainMenu()
{
	for (auto It = TabSwitcher->GetAllChildren().CreateIterator(); It; ++It)
	{
		if (UMainMenuTabBase* MainMenuTab = Cast<UMainMenuTabBase>(TabSwitcher->GetAllChildren()[It.GetIndex()]))
		{
			MainMenuTab->InitializeTab(It.GetIndex(), this);
		}
	}
	
	InitializeButtons();
	
	bIsInitialized = true;
}

void UMainMenuWidget::InitializeButtons()
{
	InitializeButton(PlayTabButton, PlayTab);
	InitializeButton(SettingTabButton, SettingsTab);
	InitializeButton(ClubTabButton, ClubTab);
	InitializeButton(StoreTabButton, StoreTab);
}

void UMainMenuWidget::InitializeButton(UMainMenuButtonBase* Button, UMainMenuTabBase* Tab)
{
	if (!IsValid(Button) || !IsValid(Tab))
	{
		return;
	}

	Button->InitializeTabButton(Tab);
}
