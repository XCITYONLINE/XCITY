// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/MainMenuTabBase.h"

UMainMenuTabBase::UMainMenuTabBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	TabType = ETabType::ETT_Play;
}

void UMainMenuTabBase::OnTabEnabled()
{
	Super::OnTabEnabled();
}

void UMainMenuTabBase::InitializeTab(const int32& Index, UMainMenuWidget* Widget)
{
	Super::InitializeTab(Index, Widget);
	
	MainMenuWidgetPtr = Widget;
}

void UMainMenuTabBase::OnTabDisabled()
{
	Super::OnTabDisabled();
}