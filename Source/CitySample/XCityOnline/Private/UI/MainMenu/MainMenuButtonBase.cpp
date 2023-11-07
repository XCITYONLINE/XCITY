// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/MainMenuButtonBase.h"

#include "Components/Image.h"
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
	const FSlateColor NewButtonColor = IsButtonSelected() ? HoveredTextColor : UnhoveredTextColor;
	
	K2_OnUnhovered();

	ButtonTextPtr->SetColorAndOpacity(NewButtonColor);
}

void UMainMenuButtonBase::InitializeVisual()
{
	ButtonTextPtr->SetColorAndOpacity(UnhoveredTextColor);
}

void UMainMenuButtonBase::OnSelected()
{
	Super::OnSelected();
	
	const UMainMenuTabBase* MainMenuTabBase = GetChildTab<UMainMenuTabBase>();
	if (!IsValid(MainMenuTabBase))
	{
		return;
	}
	
	UMainMenuWidget* MainMenuWidget = MainMenuTabBase->GetMainMenuWidget();
	if (!IsValid(MainMenuWidget))
	{
		return;
	}

	ButtonTextPtr->SetColorAndOpacity(HoveredTextColor);
	MainMenuWidget->SelectNewTab(GetChildTab()->GetIndex(), this);
	SelectedImage->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	
	K2_OnSelected();
}

void UMainMenuButtonBase::OnDisabled()
{
	Super::OnDisabled();

	ButtonTextPtr->SetColorAndOpacity(UnhoveredTextColor);

	SelectedImage->SetVisibility(ESlateVisibility::Hidden);
}

void UMainMenuButtonBase::OnHovered()
{
	const FSlateColor NewButtonColor = IsButtonSelected() ? UnhoveredTextColor : HoveredTextColor;
	
	// Here will be UI hover visualization logic, like enabling the strip
	ButtonTextPtr->SetColorAndOpacity(NewButtonColor);

	Super::OnHovered();
}
