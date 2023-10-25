// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Data/CameraSystemTypes.h"

#include "PlayerCameraManagerInterface.generated.h"

UINTERFACE(MinimalAPI, NotBlueprintable)
class UPlayerCameraManagerInterface : public UInterface
{
	GENERATED_BODY()
};

class CITYSAMPLE_API IPlayerCameraManagerInterface
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = "Camera System")
	virtual void InitCameraManager();

	UFUNCTION(BlueprintCallable, Category = "Camera System")
	virtual const ECameraMode& GetCameraManagerMode() const;

	UFUNCTION(BlueprintCallable, Category = "Camera System")
	virtual void SetCameraManagerMode(const ECameraMode& InNewCameraMode);

private:
	
	ECameraMode CurrentCameraMode = ECameraMode::ECM_Default;
	
	virtual void UpdateCameraTransformByMode();
};
