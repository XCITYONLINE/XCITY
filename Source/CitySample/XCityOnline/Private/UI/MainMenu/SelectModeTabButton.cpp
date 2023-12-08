// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SelectModeTabButton.h"

#include "Components/Button.h"
#include "XCityOnline/Public/UI/MainMenu/SelectModeTab.h"

void USelectModeTabButton::InitButton(UWidget* ParentWidget)
{
	ParentTab = CastChecked<USelectModeTab>(ParentWidget);

	SelectModeButton->OnClicked.AddUniqueDynamic(this, &ThisClass::OnClicked);
}

void USelectModeTabButton::OnClicked()
{
	if (!IsValid(ParentTab))
	{
		return;
	}

	if (!ParentTab->IsVisible())
	{
		return;
	}

	ParentTab->SelectNewMode(ModeInfo);
}
