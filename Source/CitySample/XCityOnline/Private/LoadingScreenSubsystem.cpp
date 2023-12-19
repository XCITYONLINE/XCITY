// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/LoadingScreenSubsystem.h"

#include "MoviePlayer.h"
#include "Blueprint/UserWidget.h"
#include "XCityOnline/Public/UI/XCityMainMenuHUD.h"

void ULoadingScreenSubsystem::StartInGameLoadingScreen(const FString& MapName)
{
	APlayerController* Controller = GetWorld()->GetFirstPlayerController();
	if (!Controller)
	{
		UE_LOG(LogTemp, Display, TEXT("Controller is nullptr"));
		return;
	}

	AHUD* HUD = Controller->GetHUD();
	if (!HUD)
	{
		UE_LOG(LogTemp, Display, TEXT("HUD is nullptr"));
		return;
	}
	
	const AXCityMainMenuHUD* MainMenuHUD = Cast<AXCityMainMenuHUD>(HUD);
	if (!MainMenuHUD) return;
	
	FLoadingScreenAttributes LoadingScreenAttributes;
	LoadingScreenAttributes.WidgetLoadingScreen = MainMenuHUD->GetLoadingScreenWidget()->TakeWidget();
	LoadingScreenAttributes.MinimumLoadingScreenDisplayTime = 35.0f;
	LoadingScreenAttributes.bMoviesAreSkippable = false;
	LoadingScreenAttributes.bAutoCompleteWhenLoadingCompletes = false;
	LoadingScreenAttributes.bAllowEngineTick = true;
	
	GetMoviePlayer()->SetupLoadingScreen(LoadingScreenAttributes);
	GetMoviePlayer()->PlayMovie();
	UE_LOG(LogTemp, Display, TEXT("Loading Screen Setup"));
}

void ULoadingScreenSubsystem::StopInGameLoadingScreen()
{
}
