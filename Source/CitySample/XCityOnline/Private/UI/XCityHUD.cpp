// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/UI/XCityHUD.h"

#include "XCityOnline/Public/UI/MainMenu/MainMenuWidget.h"
#include "XCityOnline/Public/UI/RadialMenu/RadialMenuWidget.h"

URadialMenuWidget* AXCityHUD::GetRadialMenuWidget() const
{
	return RadialMenuWidgetRef;
}

void AXCityHUD::BeginPlay()
{
	Super::BeginPlay();

	MainMenuWidgetRef = CreateWidget<UMainMenuWidget>(GetOwningPlayerController(), MainMenuWidgetClass);
	MainMenuWidgetRef->AddToViewport();

	RadialMenuWidgetRef = CreateWidget<URadialMenuWidget>(GetOwningPlayerController(), RadialMenuWidgetClass);
	RadialMenuWidgetRef->AddToViewport();
}

