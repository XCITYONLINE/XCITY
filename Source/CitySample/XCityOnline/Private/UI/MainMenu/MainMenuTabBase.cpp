// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/MainMenuTabBase.h"

UMainMenuTabBase::UMainMenuTabBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	TabType = ETabType::ETT_Play;
}

void UMainMenuTabBase::OnTabEnabled()
{
	K2_OnTabEnabled();
}

void UMainMenuTabBase::InitializeTab(const int32& Index, UMainMenuWidget* Widget)
{
	TabIndex = Index;
	MainMenuWidgetPtr = Widget;
	
	K2_InitializeTab(Index, Widget);
}

void UMainMenuTabBase::OnTabDisabled()
{
	K2_OnTabDisabled();
}