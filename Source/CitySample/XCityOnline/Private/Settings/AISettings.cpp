// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/Settings/AISettings.h"

UAISettings::UAISettings()
{
	WordsData = nullptr;
}

UAISettings* UAISettings::GetAISystemSettings()
{
	return GetMutableDefault<UAISettings>();
}
