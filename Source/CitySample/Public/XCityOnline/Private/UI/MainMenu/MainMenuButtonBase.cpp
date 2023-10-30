// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/MainMenuButtonBase.h"

#include "Components/Button.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuTabInterface.h"

void UMainMenuButtonBase::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonPtr->OnClicked.AddUniqueDynamic(this, &UMainMenuButtonBase::OnSelected);
	ButtonPtr->OnHovered.AddUniqueDynamic(this, &UMainMenuButtonBase::OnHovered);
	ButtonPtr->OnUnhovered.AddUniqueDynamic(this, &UMainMenuButtonBase::OnUnhovered);
}

void UMainMenuButtonBase::InitializeTabButton()
{
	IMainMenuButtonInterface::InitializeTabButton();

	K2_InitializeTabButton();
}

void UMainMenuButtonBase::OnDisabled()
{
	IMainMenuButtonInterface::OnDisabled();

	K2_OnDisabled();
}

void UMainMenuButtonBase::OnUnhovered()
{
	IMainMenuButtonInterface::OnUnhovered();

	K2_OnHovered();
}

void UMainMenuButtonBase::OnSelected()
{
	IMainMenuButtonInterface::OnSelected();

	const TScriptInterface<IMainMenuTabInterface> ChildInterfaceTab = GetChildTab();
	if (ChildInterfaceTab.GetInterface())
	{
		ChildInterfaceTab->OnTabEnabled();
	}

	K2_OnSelected();
}

void UMainMenuButtonBase::OnHovered()
{
	IMainMenuButtonInterface::OnHovered();

	K2_OnHovered();
	// Here will be UI hover visualization logic, like enabling the strip
}
