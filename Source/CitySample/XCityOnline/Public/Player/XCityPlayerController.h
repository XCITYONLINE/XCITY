// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "XCityOnline/Public/Interfaces/PlayerCameraManagerInterface.h"
#include "InputActionValue.h"
#include "Character/ALSPlayerController.h"
#include "XCityPlayerController.generated.h"

class UInputAction;

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API AXCityPlayerController : public AALSPlayerController, public IPlayerCameraManagerInterface
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Camera System")
	virtual void SetCameraManagerMode(const ECameraMode& InNewCameraMode) override;

protected:
	AXCityPlayerController();
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MouseMovedAxisAction;

	virtual void SetupInputComponent() override;

private:
	void OnMousePositionChanged(const FInputActionValue& Value);
	
};
