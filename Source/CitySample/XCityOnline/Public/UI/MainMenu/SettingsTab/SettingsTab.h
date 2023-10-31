// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XCityOnline/Public/UI/MainMenu/TabBase.h"
#include "SettingsTab.generated.h"

class USettingsWidget;

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API USettingsTab : public UTabBase
{
	GENERATED_BODY()

public:
	virtual void OnSettingsConfirmed();
	virtual void OnSettingsDeclined();

	FORCEINLINE USettingsWidget* GetSettingsWidget() const { return SettingsWidgetPtr; }

	virtual void InitializeTab(const int32& Index, UWidget* ParentWidget) override;

private:
	UPROPERTY()
	TObjectPtr<class USettingsWidget> SettingsWidgetPtr;
};
