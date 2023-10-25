// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "XCityWidgetLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API UXCityWidgetLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/**
	 * Calculates mouse angle relatively to screen center by mouse screen space position,
	 * if we got any problem in process of calculation returned value will be 0 to avoid crashes
	 * @param CurrentMousePosition Mouse position in screen space
	 * @return angle of mouse relatively to screen center
	 */
	UFUNCTION(BlueprintPure, Category = "UI|Functions")
	static float ConvertMousePositionIntoAngle(const FVector2D& CurrentMousePosition);

	/**
	 * @return center of screen
	 */
	UFUNCTION(BlueprintPure, Category = "UI|Functions")
	static FVector2D GetScreenCenter();

	UFUNCTION(BlueprintPure, Category = "UI|Functions")
	static FVector2D ConvertAngleIntoDirectionalVector(const float& Angle);
};
