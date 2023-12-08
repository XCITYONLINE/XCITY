// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsTab.h"
#include "SettingsControlsTab.generated.h"

class UInputKeySelector;

UCLASS()
class CITYSAMPLE_API USettingsControlsTab : public USettingsTab
{
	GENERATED_BODY()

public:
	virtual void OnTabEnabled() override;
	virtual void InitializeTab(const int32& Index, UWidget* ParentWidget) override;

	FORCEINLINE class UInputMappingContext* GetMappingContext() const { return InputMappingContext; }
	
protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UScrollBox> InputsBox;

	UPROPERTY(EditAnywhere, Category = "Settings Controls Tab")
	TObjectPtr<class UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, Category = "Setting Controls Tab")
	TSubclassOf<class USettingControlsLine> ControlsLineClass;
	
private:
	void RedrawWidget() const;
};
