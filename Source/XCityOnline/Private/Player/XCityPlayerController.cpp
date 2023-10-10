// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/XCityPlayerController.h"

AXCityPlayerController::AXCityPlayerController()
{
	ChildCameraInterface = nullptr;
}

void AXCityPlayerController::BeginPlay()
{
	Super::BeginPlay();

	InitCameraManager();
}

void AXCityPlayerController::SetCameraManagerMode(const ECameraMode& InNewCameraMode)
{
	ChildCameraInterface->SetCameraManagerMode(InNewCameraMode);
}

void AXCityPlayerController::InitCameraManager()
{
	IPlayerCameraManagerInterface* CameraInterface = Cast<IPlayerCameraManagerInterface>(GetPawn());
	if (!CameraInterface) return;

	ChildCameraInterface.SetInterface(CameraInterface);
	CameraInterface->InitCameraManager();
}

void AXCityPlayerController::UpdateCameraTransformByMode()
{

}