// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/MainMenuButtonBase.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuTabBase.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuWidget.h"

void UMainMenuButtonBase::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonPtr->OnClicked.AddUniqueDynamic(this, &UMainMenuButtonBase::OnSelected_Internal);
	ButtonPtr->OnHovered.AddUniqueDynamic(this, &UMainMenuButtonBase::OnHovered_Internal);
	ButtonPtr->OnUnhovered.AddUniqueDynamic(this, &UMainMenuButtonBase::OnUnhovered_Internal);
}

void UMainMenuButtonBase::InitializeTabButton(UMainMenuTabBase* ChildTab)
{
	ChildTabPtr = ChildTab;
	InitializeVisual();
	
	K2_InitializeTabButton(ChildTabPtr);
}

void UMainMenuButtonBase::OnDisabled()
{
	K2_OnDisabled();
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

void UMainMenuButtonBase::OnSelected_Internal()
{
	OnSelected();
}

void UMainMenuButtonBase::OnHovered_Internal()
{
	OnHovered();
}

void UMainMenuButtonBase::OnUnhovered_Internal()
{
	OnUnhovered();
}

void UMainMenuButtonBase::OnSelected()
{
	if (!IsValid(ChildTabPtr))
	{
		return;
	}

	const UMainMenuWidget* MainMenuWidget = ChildTabPtr->GetMainMenuWidget();
	if (!IsValid(MainMenuWidget))
	{
		return;
	}

	MainMenuWidget->SelectNewTab(ChildTabPtr->GetIndex());
	K2_OnSelected();
}

void UMainMenuButtonBase::OnHovered()
{
	K2_OnHovered();
	
	// Here will be UI hover visualization logic, like enabling the strip
	ButtonTextPtr->SetColorAndOpacity(HoveredTextColor);
}
