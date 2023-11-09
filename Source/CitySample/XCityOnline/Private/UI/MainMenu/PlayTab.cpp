// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/PlayTab.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "XCityOnline/Public/Libraries/XCityWidgetLibrary.h"

void UPlayTab::NativeConstruct()
{
	Super::NativeConstruct();

	PlayButton->OnClicked.AddUniqueDynamic(this, &UPlayTab::LoadNextLevel);
	ContinueButton->OnClicked.AddUniqueDynamic(this, &UPlayTab::LoadNextLevel);
}

void UPlayTab::LoadNextLevel()
{
	UXCityWidgetLibrary::StartLoadingScreen(GetOwningPlayer(), nullptr);
	UGameplayStatics::OpenLevelBySoftObjectPtr(this, NextLevelInstance);
}
