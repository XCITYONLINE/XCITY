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

void IMainMenuTabInterface::InitializeTab()
{
}

bool IMainMenuTabInterface::IsTabActive() const
{
	return bIsTabActive;
}

bool IMainMenuTabInterface::IsInitialized() const
{
	return bIsInitialized;
}
