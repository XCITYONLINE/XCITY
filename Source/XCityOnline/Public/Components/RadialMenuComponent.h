// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Contracts/InteractibleItemInterface.h"
#include "WeaponSystem/Public/DataStructs/WeaponsDataStruct.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputActionValue.h"
#include "RadialMenuComponent.generated.h"


class UInputAction;
class URadialMenuWidget;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XCITYONLINE_API URadialMenuComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	URadialMenuComponent();

	void GetItemsByType(const EWeaponType& InWeaponType, TMap<int32, TScriptInterface<IInteractibleItemInterface>>& OutItemsByType);

	void EnableRadialMenu(const FInputActionValue& Value);
	void DisableRadialMenu(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, Category = "Radial Menu|Input")
	TObjectPtr<UInputAction> EnableRadialMenuInput;
	
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnInventorySizeChanged(const TArray<TScriptInterface<IInteractibleItemInterface>>& Value);

	UPROPERTY()
	TObjectPtr<URadialMenuWidget> RadialMenuWidget;

	UPROPERTY(EditAnywhere, Category = "Radial Menu Component")
	TSubclassOf<URadialMenuWidget> RadialMenuWidgetClass;
	
private:
	void SelectItem();
	
	class UInventoryComponentBase* GetInventoryComponentBase() const;
};
