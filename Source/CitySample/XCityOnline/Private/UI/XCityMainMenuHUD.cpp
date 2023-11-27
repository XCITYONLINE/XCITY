// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/XCityMainMenuHUD.h"

#include "Blueprint/UserWidget.h"

void AXCityMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(LoadingScreenWidgetClass))
	{
		LoadingScreenWidget = CreateWidget(GetOwningPlayerController(), LoadingScreenWidgetClass);
	}

	if (IsValid(MainMenuWidgetClass))
	{
		MainMenuWidget = CreateWidget(GetOwningPlayerController(), MainMenuWidgetClass);
		MainMenuWidget->AddToViewport();
	}
}
