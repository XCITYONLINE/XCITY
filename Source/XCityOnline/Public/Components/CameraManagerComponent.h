// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/CameraSystemTypes.h"
#include "CameraManagerComponent.generated.h"

class UCameraModeData;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class XCITYONLINE_API UCameraManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCameraManagerComponent();

	void UpdateCameraOffset(class USpringArmComponent* SpringArm);
	void SetCameraMode(const ECameraMode& CameraMode);

	UPROPERTY(EditAnywhere, Category = "Data")
	TMap<ECameraMode, UCameraModeData*> CameraModes;

private:
	UPROPERTY()
	TObjectPtr<UCameraModeData> CurrentCameraMode;
};
