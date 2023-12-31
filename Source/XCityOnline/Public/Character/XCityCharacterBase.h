// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/PlayerCameraManagerInterface.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "Character/ALSCharacter.h"
#include "Interfaces/RadialMenuInterface.h"

#include "XCityCharacterBase.generated.h"

class UInputAction;

UCLASS()
class XCITYONLINE_API AXCityCharacterBase : public AALSCharacter,
public IPlayerCameraManagerInterface
{
	GENERATED_BODY()
	
public:
	
	AXCityCharacterBase(const FObjectInitializer& ObjectInitializer);

	void SetSelectedInventoryItem(const TScriptInterface<class IInteractibleItemInterface>& InventoryItem);

	UFUNCTION(BlueprintImplementableEvent)
	void K2_AttachTo(UObject* OutAttachObject);
	
	UFUNCTION(BlueprintImplementableEvent)
	void K2_DropTo(UObject* OutDropObject);

	void ReInitializeItemObject();
	
protected:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//IPlayerCameraManagerInterface implements
	virtual void InitCameraManager() override;
	virtual void SetCameraManagerMode(const ECameraMode& InNewCameraMode) override;
	virtual void UpdateCameraTransformByMode() override;
	//~
	
	UFUNCTION(BlueprintCallable)
	void InitInventorySystem();

	virtual void FindObjectsAround(const bool bForce);

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera System")
	TObjectPtr<class UCameraManagerComponent> CameraManagerComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory System")
	TObjectPtr<class UInventoryComponentBase> InventoryComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory System")
	TObjectPtr<class UFindObjectsComponent> FindItemComponent;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> TakeAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> DropAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> TalkAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> WheelAxisAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> MappingContext;

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<class URadialMenuComponent> RadialMenuComponent;
	
private:
	
	void OnTakeInputChanged(const FInputActionValue& Value);
	void OnDropInputChanged(const FInputActionValue& Value);
	void OnWheelAxisInputChanged(const FInputActionValue& Value);
	void OnTalkInputChanged(const FInputActionValue& Value);
	void OnTalkInputCompleted(const FInputActionValue& Value);

private:

	UFUNCTION()
	virtual void OnInventoryItemChanged(
		const TScriptInterface<class IInteractibleItemInterface>& InInventoryItemChanged);

	TScriptInterface<class IInteractibleItemInterface> GetCloserObject(
		const TArray<TScriptInterface<class IInteractibleItemInterface>>& InFoundObjects) const;
	
	TScriptInterface<class IInteractibleItemInterface> SelectedInventoryItem;
	TScriptInterface<class IInteractibleItemInterface> TriggeredObject;
};
