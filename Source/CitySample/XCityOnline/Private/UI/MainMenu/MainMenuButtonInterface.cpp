// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/MainMenuButtonInterface.h"

void IMainMenuButtonInterface::InitializeTabButton()
{
}

void IMainMenuButtonInterface::OnHovered()
{
}

void IMainMenuButtonInterface::OnUnhovered()
{
}

void IMainMenuButtonInterface::OnSelected()
{
}

void IMainMenuButtonInterface::OnDisabled()
{
}

TScriptInterface<IMainMenuTabInterface> IMainMenuButtonInterface::GetChildTab() const
{
	return ChildTabPtr;
}