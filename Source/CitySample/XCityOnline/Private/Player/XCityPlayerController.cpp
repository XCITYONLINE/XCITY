// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/Player/XCityPlayerController.h"

#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Public/XCityOnline/Public/Interfaces/PlayerWidgetInterface.h"
#include "XCityOnline/Public/Interfaces/PlayerCameraManagerInterface.h"
#include "XCityOnline/Public/UI/XCityHUD.h"
#include "XCityOnline/Public/UI/RadialMenu/RadialMenuWidget.h"

class URadialMenuWidget;

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

void AXCityPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (IsValid(MouseMovedAxisAction))
		{
			EnhancedInputComponent->BindAction(MouseMovedAxisAction, ETriggerEvent::Triggered, this, &AXCityPlayerController::OnMousePositionChanged);
		}
	}
}

void AXCityPlayerController::OnMousePositionChanged(const FInputActionValue& Value)
{
	const FVector2D MousePosition = Value.Get<FVector2D>();
	const AXCityHUD* HUD = Cast<AXCityHUD>(GetHUD());
	if (!IsValid(HUD))
	{
		return;
	}

	URadialMenuWidget* RadialMenuWidget = HUD->GetRadialMenuWidget();
	if (RadialMenuWidget && RadialMenuWidget->Implements<UPlayerWidgetInterface>())
	{
		IPlayerWidgetInterface::Execute_OnMouseMovedOnViewport(RadialMenuWidget, MousePosition);
	}
}
