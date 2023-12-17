// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SelectModeTabButton.h"

#include "Components/Border.h"
#include "Components/Button.h"
#include "XCityOnline/Public/UI/MainMenu/SelectModeTab.h"

void USelectModeTabButton::InitButton(UWidget* ParentWidget)
{
	ParentTab = CastChecked<USelectModeTab>(ParentWidget);

	SelectModeButton->OnClicked.AddUniqueDynamic(this, &ThisClass::OnClicked);
}

void USelectModeTabButton::DisableSelection()
{
	SelectModeBorder->SetPadding(FMargin(0.f, 0.f, 0.f, 0.f));
}

void USelectModeTabButton::EnableSelection()
{
	SelectModeBorder->SetPadding(FMargin(3.f, 3.f, 3.f, 3.f));
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

	ParentTab->SelectNewMode(this, ModeInfo);
}
