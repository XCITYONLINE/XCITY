// Fill out your copyright notice in the Description page of Project Settings.


#include "Interfaces/PlayerCameraManagerInterface.h"

// Add default functionality here for any IPlayerCameraManagerInterface functions that are not pure virtual.

void IPlayerCameraManagerInterface::InitCameraManager()
{
}

const ECameraMode& IPlayerCameraManagerInterface::GetCameraManagerMode() const
{
	return CurrentCameraMode;
}

void IPlayerCameraManagerInterface::SetCameraManagerMode(const ECameraMode& InNewCameraMode)
{
	if (InNewCameraMode == CurrentCameraMode) return;

	CurrentCameraMode = InNewCameraMode;
}

void IPlayerCameraManagerInterface::UpdateCameraTransformByMode()
{
}