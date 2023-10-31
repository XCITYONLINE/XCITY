// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SettingsWidget.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API USettingsWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ApplySettingsButton;
};
