// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/Interfaces/PlayerCameraManagerInterface.h"

void IPlayerCameraManagerInterface::InitCameraManager()
{
}

const ECameraMode& IPlayerCameraManagerInterface::GetCameraManagerMode() const
{
	return CurrentCameraMode;
}

void IPlayerCameraManagerInterface::SetCameraManagerMode(const ECameraMode& InNewCameraMode)
{
	if (InNewCameraMode == CurrentCameraMode)
	{
		return;
	}

	CurrentCameraMode = InNewCameraMode;
}

void IPlayerCameraManagerInterface::UpdateCameraTransformByMode()
{
}