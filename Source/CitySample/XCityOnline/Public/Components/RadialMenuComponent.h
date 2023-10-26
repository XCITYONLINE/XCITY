// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Contracts/InteractibleItemInterface.h"
#include "WeaponSystem/Public/DataStructs/WeaponsDataStruct.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputActionValue.h"
#include "XCityOnline/Public/Interfaces/RadialMenuInterface.h"
#include "RadialMenuComponent.generated.h"


class UInputAction;
class URadialMenuWidget;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CITYSAMPLE_API URadialMenuComponent : public UActorComponent, public IRadialMenuInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	URadialMenuComponent();

	virtual void GetItemsByType(const EWeaponType& InWeaponType, TMap<int32, TScriptInterface<IInteractibleItemInterface>>& OutItemsByType) override;

	void SetupInput(class UEnhancedInputComponent* EnhancedInputComponent);
	
	UPROPERTY(EditAnywhere, Category = "Radial Menu|Input")
	TObjectPtr<UInputAction> EnableRadialMenuInput;

	UPROPERTY(EditAnywhere, Category = "Radial Menu|Input")
	TObjectPtr<UInputAction> RadialMenuSlotRightInput;

	UPROPERTY(EditAnywhere, Category = "Radial Menu|Input")
	TObjectPtr<UInputAction> RadialMenuSlotLeftInput;
	
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnInventorySizeChanged(const TArray<TScriptInterface<IInteractibleItemInterface>>& Value);

	UPROPERTY()
	TObjectPtr<URadialMenuWidget> RadialMenuWidget;
	
private:
	void SelectItem();

	void EnableRadialMenu(const FInputActionValue& Value);
	void DisableRadialMenu(const FInputActionValue& Value);

	void RadialMenuSlotRight(const FInputActionValue& Value);
	void RadialMenuSlotLeft(const FInputActionValue& Value);

	UPROPERTY()
	class UInventoryComponentBase* InventoryComponentBase;
};
