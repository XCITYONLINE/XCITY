// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/XCityMainMenuHUD.h"

#include "Blueprint/UserWidget.h"

void AXCityMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	LoadingScreenWidget = CreateWidget(GetOwningPlayerController(), LoadingScreenWidgetClass);
}
