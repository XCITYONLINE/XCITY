// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/UI/MainMenu/MainMenuWidget.h"

#include "Components/WidgetSwitcher.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuButtonBase.h"

UWidgetSwitcher* UMainMenuWidget::GetWidgetSwitcher() const
{
	return TabSwitcher;
}

UMainMenuWidget::UMainMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bIsInitialized = false;
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
