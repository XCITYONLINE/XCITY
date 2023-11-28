// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/UI/XCityHUD.h"
#include "XCityOnline/Public/UI/RadialMenu/RadialMenuWidget.h"

#include "Engine/Canvas.h"
#include "Blueprint/UserWidget.h"

URadialMenuWidget* AXCityHUD::GetRadialMenuWidget() const
{
	if (IsValid(MainMenuWidgetRef.Get()))
	{
		return Cast<URadialMenuWidget>(MainMenuWidgetRef->K2_GetRadialMenuWidget());
	}

	return nullptr;
}

void AXCityHUD::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerHUDWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDWidgetClass);
	if (PlayerHUDWidget)
	{
		PlayerHUDWidget->AddToViewport();
	}

	MainMenuWidgetRef = CreateWidget<UMainMenuWidget>(GetOwningPlayerController(), MainMenuWidgetClass);
	MainMenuWidgetRef->AddToViewport();
}

void AXCityHUD::DrawHUD()
{
	Super::DrawHUD();

	//DrawCrosshair();
}

//Debug Crosshair Position
//void AXCityHUD::DrawCrosshair()
//{

	//const TInterval<float> Center(Canvas->SizeX * 0.5f, Canvas->SizeY * 0.5f);

	//const float HalfLineSize = 10.0f;
	//const float LineThickness = 1.0f;
	//const FLinearColor LineColor = FLinearColor::White;

	//DrawLine(Center.Min - HalfLineSize, Center.Max, Center.Min + HalfLineSize, Center.Max, LineColor, LineThickness);
	//DrawLine(Center.Min, Center.Max - HalfLineSize, Center.Min, Center.Max + HalfLineSize, LineColor, LineThickness);
//}
