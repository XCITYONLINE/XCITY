// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/MainMenu/MainMenuPlayerController.h"

#include "Blueprint/UserWidget.h"

void AMainMenuPlayerController::CreateAndShowLoadingScreen()
{
	UUserWidget* LoadingScreenWidget = CreateWidget(this, LoadingScreenClass);
	LoadingScreenWidget->AddToViewport(1);
}
