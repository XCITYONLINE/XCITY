// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/XCityHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/RadialMenu/RadialMenuWidget.h"

void AXCityHUD::BeginPlay()
{
	Super::BeginPlay();

	RadialMenuWidget = CreateWidget<URadialMenuWidget>(GetOwningPlayerController(), RadialMenuWidgetClass);
	RadialMenuWidget->SetVisibility(ESlateVisibility::Hidden);
	RadialMenuWidget->AddToViewport();
}