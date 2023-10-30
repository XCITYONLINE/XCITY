// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "XCityHUD.generated.h"

class URadialMenuWidget;
class UMainMenuWidget;

UCLASS()
class CITYSAMPLE_API AXCityHUD : public AHUD
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	URadialMenuWidget* GetRadialMenuWidget() const;

public:

	virtual void BeginPlay() override;

public:
	
	UPROPERTY(EditAnywhere, Category = "UI|Radial Menu")
	TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;

private:

	UPROPERTY()
	TObjectPtr<UMainMenuWidget> MainMenuWidgetRef;
};
