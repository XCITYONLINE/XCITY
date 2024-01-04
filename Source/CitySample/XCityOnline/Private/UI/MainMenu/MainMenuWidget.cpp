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
	UMainMenuTabBase* SettingsTab = GetTab(ETabType::ETT_Settings);
	
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
	for (auto It = GetWidgetSwitcher()->GetAllChildren().CreateIterator(); It; ++It)
	{
		if (UMainMenuTabBase* MainMenuTabBase = Cast<UMainMenuTabBase>(GetWidgetSwitcher()->GetAllChildren()[It.GetIndex()]))
		{
			if (MainMenuTabBase->GetTabType() == TabType) return MainMenuTabBase;
		}
	}

	return nullptr;
}

UMainMenuButtonBase* UMainMenuWidget::GetButton(ETabType TabType)
{
	for (auto It = ButtonsArray.CreateIterator(); It; ++It)
	{
		if (ButtonsArray[It.GetIndex()]->GetTabType() == TabType) return ButtonsArray[It.GetIndex()];
	}

	return nullptr;
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
	USettingsWidget* SettingsWidget = Cast<USettingsWidget>(GetTab(ETabType::ETT_Settings));
	
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
	
	bIsInitialized = true;
}

void UMainMenuWidget::InitializeButton(UMainMenuButtonBase* Button, UMainMenuTabBase* Tab)
{
	if (!IsValid(Button) || !IsValid(Tab))
	{
		return;
	}

	Button->InitializeTabButton(Tab);
	ButtonsArray.Add(Button);
}
