// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/UI/XCityHUD.h"

#include "XCityOnline/Public/UI/MainMenu/MainMenuWidget.h"
#include "XCityOnline/Public/UI/RadialMenu/RadialMenuWidget.h"

URadialMenuWidget* AXCityHUD::GetRadialMenuWidget() const
{
	if (IsValid(MainMenuWidgetRef.Get()))
	{
		return Cast<URadialMenuWidget>(MainMenuWidgetRef->K2_GetRadialMenuWidget());
	}

	return nullptr;
}

void AXCityHUD::BeginPlay()
{
	Super::BeginPlay();

	MainMenuWidgetRef = CreateWidget<UMainMenuWidget>(GetOwningPlayerController(), MainMenuWidgetClass);
	MainMenuWidgetRef->AddToViewport();
}
