// Fill out your copyright notice in the Description page of Project Settings.


#include "Libraries/XCityWidgetLibrary.h"
#include "Kismet/KismetMathLibrary.h"

float UXCityWidgetLibrary::ConvertMousePositionIntoAngle(const FVector2D& CurrentMousePosition)
{
	FVector2D ViewportSize;
	if (IsValid(GEngine))
	{
		if (IsValid(GEngine->GameViewport))
		{
			GEngine->GameViewport->GetViewportSize(ViewportSize);
		}
		
		else
		{
			return 0;
		}
	}

	else
	{
		return 0;
	}

	const FVector2D ScreenCenter = ViewportSize / 2;
	const FVector2D ScreenTopMiddle { ScreenCenter.X, 0 };
	
	const FVector2D V1 = (ScreenTopMiddle - ScreenCenter).GetSafeNormal();
	const FVector2D V2 = (CurrentMousePosition - ScreenCenter).GetSafeNormal();

	float AngleInDegrees = UKismetMathLibrary::DegAtan2(V2.Y, V2.X) - UKismetMathLibrary::DegAtan2(V1.Y, V1.X);
	if (AngleInDegrees < 0)
	{
		AngleInDegrees = AngleInDegrees + 360;
	}
	return AngleInDegrees;
}

FVector2D UXCityWidgetLibrary::GetScreenCenter()
{
	FVector2D ViewportSize = FVector2D();
	if (IsValid(GEngine))
	{
		if (IsValid(GEngine->GameViewport))
		{
			GEngine->GameViewport->GetViewportSize(ViewportSize);
			return ViewportSize / 2;
		}
	}

	return ViewportSize;
}

FVector2D UXCityWidgetLibrary::ConvertAngleIntoDirectionalVector(const float& Angle)
{
	const float AngleRadians = FMath::DegreesToRadians(Angle);

	const float X = FMath::Sin(AngleRadians);
	const float Y = FMath::Cos(AngleRadians);

	const FVector2D DirectionalVector { X, Y * -1 };
	return DirectionalVector;
}
