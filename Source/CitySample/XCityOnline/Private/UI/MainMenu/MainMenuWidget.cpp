// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/UI/MainMenu/MainMenuWidget.h"

#include "Components/Border.h"
#include "Components/WidgetSwitcher.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuButtonBase.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsTab.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsWidget.h"

UWidgetSwitcher* UMainMenuWidget::GetWidgetSwitcher() const
{
	return TabSwitcher;
}

void UMainMenuWidget::SelectNewTab(const int32& Index, UMainMenuButtonBase* MainMenuButton)
{
	if (GetWidgetSwitcher()->GetActiveWidget() == SettingsTab)
	{
		Cast<USettingsWidget>(SettingsTab)->OnTryingToChange();
		return;
	}
	
	if (IsValid(CurrentSelectedButton))
	{
		CurrentSelectedButton->OnDisabled();
	}

	CurrentSelectedButton = MainMenuButton;
	
	if (GetWidgetSwitcher()->GetActiveWidgetIndex() == Index)
	{
		return;
	}
	
	UMainMenuTabBase* CurrentTempTab = Cast<UMainMenuTabBase>(GetWidgetSwitcher()->GetActiveWidget());
	CurrentTempTab->OnTabDisabled();

	GetWidgetSwitcher()->SetActiveWidgetIndex(Index);
	UMainMenuTabBase* NewTab = Cast<UMainMenuTabBase>(GetWidgetSwitcher()->GetWidgetAtIndex(Index));
	NewTab->OnTabEnabled();
	CurrentTab = NewTab;

	if (CurrentTab->bNeedToBeInFullscreen)
	{
		SideBarBorder->SetVisibility(ESlateVisibility::Hidden);
	}
	
	//NewTab->SetUserFocus(GetOwningPlayer());
}

void UMainMenuWidget::SelectTabByType(ETabType TabType)
{
	const UMainMenuTabBase* TempTab = GetTab(TabType);
	if (IsValid(CurrentSelectedButton))
	{
		CurrentSelectedButton->OnDisabled();
	}

	CurrentSelectedButton = GetButton(TabType);

	if (GetWidgetSwitcher()->GetActiveWidgetIndex() == TempTab->GetIndex())
	{
		return;
	}

	UMainMenuTabBase* CurrentTempTab = Cast<UMainMenuTabBase>(GetWidgetSwitcher()->GetActiveWidget());
	CurrentTempTab->OnTabDisabled();

	GetWidgetSwitcher()->SetActiveWidgetIndex(TempTab->GetIndex());
	UMainMenuTabBase* NewTab = Cast<UMainMenuTabBase>(GetWidgetSwitcher()->GetWidgetAtIndex(TempTab->GetIndex()));
	NewTab->OnTabEnabled();
	CurrentTab = NewTab;

	if (CurrentTab->bNeedToBeInFullscreen)
	{
		SideBarBorder->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		SideBarBorder->SetVisibility(ESlateVisibility::Visible);
	}
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
	case ETabType::ETT_Girl:
		return GirlTab;
	}

	return PlayTab;
}

UMainMenuButtonBase* UMainMenuWidget::GetButton(ETabType TabType)
{
	switch (TabType)
	{
	case ETabType::ETT_Club:
		return ClubTabButton;
	case ETabType::ETT_Play:
		return PlayTabButton;
	case ETabType::ETT_Settings:
		return SettingTabButton;
	case ETabType::ETT_Store:
		return StoreTabButton;
	case ETabType::ETT_Girl:
		return GirlTabButton;
	}

	return PlayTabButton;
}

UMainMenuTabBase* UMainMenuWidget::GetCurrentTab() const
{
	return CurrentTab;
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
	InitializeButton(GirlTabButton, GirlTab);
}

void UMainMenuWidget::InitializeButton(UMainMenuButtonBase* Button, UMainMenuTabBase* Tab)
{
	if (!IsValid(Button) || !IsValid(Tab))
	{
		return;
	}

	Button->InitializeTabButton(Tab);
}
