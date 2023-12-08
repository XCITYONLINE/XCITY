// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/MainMenuTabBase.h"

#include "XCityOnline/Public/UI/MainMenu/MainMenuWidget.h"

UMainMenuTabBase::UMainMenuTabBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	TabType = ETabType::ETT_Play;
}

void UMainMenuTabBase::OnTabEnabled()
{
	Super::OnTabEnabled();
}

void UMainMenuTabBase::InitializeTab(const int32& Index, UWidget* ParentWidget)
{
	Super::InitializeTab(Index, ParentWidget);
	
	MainMenuWidgetPtr = Cast<UMainMenuWidget>(ParentWidget);
}

void UMainMenuTabBase::OnTabDisabled()
{
	Super::OnTabDisabled();
}