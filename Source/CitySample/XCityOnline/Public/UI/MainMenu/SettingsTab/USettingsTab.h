// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuTabBase.h"
#include "USettingsTab.generated.h"

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API UUSettingsTab : public UMainMenuTabBase
{
	GENERATED_BODY()

protected:
	virtual void OnSettingsConfirmed();
	virtual void OnSettingsCanceled();
};
