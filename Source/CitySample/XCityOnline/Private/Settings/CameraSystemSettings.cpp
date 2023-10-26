// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/Settings/CameraSystemSettings.h"

UCameraSystemSettings::UCameraSystemSettings()
{
	CameraModes.Empty();
}

UCameraSystemSettings* UCameraSystemSettings::GetCameraSystemSettings()
{
	return GetMutableDefault<UCameraSystemSettings>();
}
