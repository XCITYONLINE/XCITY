// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interfaces/PlayerCameraManagerInterface.h"
#include "XCityPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API AXCityPlayerController : public APlayerController, public IPlayerCameraManagerInterface
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Camera System")
	virtual void SetCameraManagerMode(const ECameraMode& InNewCameraMode) override;

protected:
	AXCityPlayerController();

	virtual void BeginPlay() override;
};
