// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/MainMenuTabInterface.h"


IMainMenuTabInterface::IMainMenuTabInterface()
{
	bIsTabActive = false;
}

// Add default functionality here for any IMainMenuTabInterface functions that are not pure virtual.
void IMainMenuTabInterface::OnTabEnabled()
{
	bIsTabActive = true;
}

void IMainMenuTabInterface::OnTabDisabled()
{
	bIsTabActive = false;
}

bool IMainMenuTabInterface::IsTabActive() const
{
	return bIsTabActive;
}
