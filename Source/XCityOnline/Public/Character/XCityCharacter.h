// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/PlayerCameraManagerInterface.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "XCityCharacter.generated.h"

class UInputAction;
//class UInputMappingContext;

UCLASS()
class XCITYONLINE_API AXCityCharacter : public ACharacter, public IPlayerCameraManagerInterface
{
	GENERATED_BODY()

public:
	AXCityCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Camera System")
	virtual void SetCameraManagerMode(const ECameraMode& InNewCameraMode) override;

	virtual void InitCameraManager() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera System")
	TObjectPtr<class UCameraManagerComponent> CameraManagerComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera System")
	TObjectPtr<class USpringArmComponent> SpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera System")
	TObjectPtr<class UCameraComponent> CameraComponent;

	// Input
	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputMappingContext> MappingContext;

	void LookInput(const FInputActionValue& Value);

private:
	virtual void UpdateCameraTransformByMode() override;
};
