// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/MainMenuButtonBase.h"
#include "Components/TextBlock.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuTabBase.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuWidget.h"

void UMainMenuButtonBase::InitializeTabButton(UTabBase* ChildTab)
{
	Super::InitializeTabButton(ChildTab);
	
	InitializeVisual();
}

void UMainMenuButtonBase::OnUnhovered()
{
	K2_OnHovered();

	ButtonTextPtr->SetColorAndOpacity(UnhoveredTextColor);
}

void UMainMenuButtonBase::InitializeVisual()
{
	ButtonTextPtr->SetColorAndOpacity(UnhoveredTextColor);
}

void UMainMenuButtonBase::OnSelected()
{
	const UMainMenuTabBase* MainMenuTabBase = GetChildTab<UMainMenuTabBase>();
	if (!IsValid(MainMenuTabBase))
	{
		return;
	}
	
	const UMainMenuWidget* MainMenuWidget = MainMenuTabBase->GetMainMenuWidget();
	if (!IsValid(MainMenuWidget))
	{
		return;
	}

	MainMenuWidget->SelectNewTab(GetChildTab()->GetIndex());
	
	K2_OnSelected();
}

void UMainMenuButtonBase::OnHovered()
{
	// Here will be UI hover visualization logic, like enabling the strip
	ButtonTextPtr->SetColorAndOpacity(HoveredTextColor);

	Super::OnHovered();
}