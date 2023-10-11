// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/PlayerCameraManagerInterface.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "XCityCharacterBase.generated.h"

class UInputAction;
//class UInputMappingContext;

UCLASS()
class XCITYONLINE_API AXCityCharacterBase : public ACharacter, public IPlayerCameraManagerInterface
{
	GENERATED_BODY()

public:
	AXCityCharacterBase();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Camera System")
	virtual void SetCameraManagerMode(const ECameraMode& InNewCameraMode) override;

	virtual void InitCameraManager() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera System")
	TObjectPtr<class UCameraManagerComponent> CameraManagerComponent;

	// Input
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> MappingContext;

	void LookInput(const FInputActionValue& Value);

private:
	virtual void UpdateCameraTransformByMode() override;
};
