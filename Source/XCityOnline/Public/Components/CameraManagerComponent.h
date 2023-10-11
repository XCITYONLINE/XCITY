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

	void SetupAttachments(const AActor* ParentActor);

	void UpdateCameraOffset();
	void SetCameraMode(const ECameraMode& CameraMode);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera System")
	float LocationInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera System")
	TObjectPtr<class USpringArmComponent> SpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera System")
	TObjectPtr<class UCameraComponent> CameraComponent;

private:
	UPROPERTY()
	TSoftObjectPtr<UCameraModeData> CurrentCameraMode;
};
