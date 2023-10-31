// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XCityOnline/Public/UI/MainMenu/TabBase.h"
#include "SettingsTab.generated.h"

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API USettingsTab : public UTabBase
{
	GENERATED_BODY()

protected:
	virtual void OnSettingsConfirmed();
	virtual void OnSettingsDeclined();
};
