// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/TabBase.h"

void UTabBase::OnTabEnabled()
{
	K2_OnTabEnabled();
}

void UTabBase::InitializeTab(const int32& Index, UMainMenuWidget* Widget)
{
	TabIndex = Index;

	K2_InitializeTab(Index, Widget);
}

void UTabBase::OnTabDisabled()
{
	K2_OnTabDisabled();
}
