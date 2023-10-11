// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Data/CameraSystemTypes.h"
#include "CameraSystemSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "Camera System Settings"))
class XCITYONLINE_API UCameraSystemSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UCameraSystemSettings();

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Camera System|Data")
	TMap<ECameraMode, TSoftObjectPtr<class UCameraModeData>> CameraModes;
};