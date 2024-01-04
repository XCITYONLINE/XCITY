// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XCityOnline/Public/Interfaces/PlayerCameraManagerInterface.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "ALSExtras/Public/AlsCharacterExample.h"
#include "XCityOnline/Public/Interfaces/RadialMenuInterface.h"

#include "Game/ICitySampleTraversalInterface.h"
#include "UI/CitySampleControlsOverlayInterface.h"
#include "UI/CitySampleUIComponentInterface.h"
#include "Util/ICitySampleInputInterface.h"

#include "XCCharacter.generated.h"

class UInputAction;
class UMotionWarpingComponent;

UCLASS()
class CITYSAMPLE_API AXCCharacter : public ACharacter,
	public IPlayerCameraManagerInterface,
	public ICitySampleTraversalInterface,
	public ICitySampleUIComponentInterface,
	public ICitySampleControlsOverlayInterface,
	public ICitySampleInputInterface
{
	GENERATED_BODY()

public:

	AXCCharacter();

	void SetSelectedInventoryItem(const TScriptInterface<class IInteractibleItemInterface>& InventoryItem);

	void ReInitializeItemObject();

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* Input) override;

	//IPlayerCameraManagerInterface implements
	virtual void InitCameraManager() override;
	virtual void SetCameraManagerMode(const ECameraMode& InNewCameraMode) override;
	virtual void UpdateCameraTransformByMode() override;
	//~

public:
	/** Returns true if this character is driving a vehicle */
	UFUNCTION(BlueprintCallable)
	bool IsDriving() const;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera System")
	TObjectPtr<class UCameraManagerComponent> CameraManagerComponent;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> TalkAction;

	//UPROPERTY(EditAnywhere, Category = "Input")
	//TObjectPtr<UInputAction> RadialMenuOpen;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> MappingContext;

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<class URadialMenuComponent> RadialMenuComponent;

	/** Reference to owned motion warping component */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
	UMotionWarpingComponent* MotionWarpingComponent;

private:

	void OnTalkInputChanged(const FInputActionValue& Value);
	void OnTalkInputCompleted(const FInputActionValue& Value);

};
