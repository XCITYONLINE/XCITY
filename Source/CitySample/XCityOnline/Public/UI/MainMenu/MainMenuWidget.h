// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Public/XCityOnline/Public/Interfaces/PlayerWidgetInterface.h"

#include "MainMenuWidget.generated.h"

UCLASS()
class CITYSAMPLE_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintImplementableEvent)
	UUserWidget* K2_GetRadialMenuWidget();

protected:
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* TabSwitcher;
};
