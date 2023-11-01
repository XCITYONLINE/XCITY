// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XCityOnline/Public/UI/MainMenu/TabButtonBase.h"
#include "SettingButton.generated.h"

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API USettingButton : public UTabButtonBase
{
	GENERATED_BODY()

protected:
	virtual void OnSelected() override;
};
