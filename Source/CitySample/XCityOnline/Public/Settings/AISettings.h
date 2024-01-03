// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AISettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "AI System Settings"))
class CITYSAMPLE_API UAISettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UAISettings();
	static UAISettings* GetAISystemSettings();

public:
	/** Data for words, to simulate AI angry / joy expressions in animation and prompt */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI System Settings")
	UDataTable* WordsData;
};
