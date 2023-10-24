// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "XCityHUD.generated.h"

class URadialMenuWidget;

/**
 * 
 */
UCLASS()
class XCITYONLINE_API AXCityHUD : public AHUD
{
	GENERATED_BODY()

public:
	FORCEINLINE URadialMenuWidget* GetRadialMenuWidget() const { return RadialMenuWidget; }
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "UI|Radial Menu")
	TSubclassOf<URadialMenuWidget> RadialMenuWidgetClass;
	
	UPROPERTY(BlueprintReadOnly, Category = "UI|Radial Menu")
	TObjectPtr<URadialMenuWidget> RadialMenuWidget;
};
