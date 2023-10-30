// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/UI/MainMenu/MainMenuWidget.h"

#include "Components/WidgetSwitcher.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuTabInterface.h"

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
		if (IMainMenuTabInterface* MainMenuTabInterface = Cast<IMainMenuTabInterface>(TabSwitcher->GetAllChildren()[It.GetIndex()]))
		{
			MainMenuTabInterface->InitializeTab();
		}
	}

	bIsInitialized = true;
}