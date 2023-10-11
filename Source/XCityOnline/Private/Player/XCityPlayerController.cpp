// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/XCityPlayerController.h"

AXCityPlayerController::AXCityPlayerController()
{
}

void AXCityPlayerController::BeginPlay()
{
	Super::BeginPlay();

	InitCameraManager();
}

void AXCityPlayerController::SetCameraManagerMode(const ECameraMode& InNewCameraMode)
{
	IPlayerCameraManagerInterface* CameraInterface = Cast<IPlayerCameraManagerInterface>(GetPawn());
	if (!CameraInterface) return;

	CameraInterface->SetCameraManagerMode(InNewCameraMode);
}