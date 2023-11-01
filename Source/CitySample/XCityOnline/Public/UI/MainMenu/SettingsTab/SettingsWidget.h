// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SettingButton.h"
#include "Blueprint/UserWidget.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuTabBase.h"
#include "SettingsWidget.generated.h"

class UButton;
class UWidgetSwitcher;
class USettingsTab;
class USettingButton;

UCLASS()
class CITYSAMPLE_API USettingsWidget : public UMainMenuTabBase
{
	GENERATED_BODY()

public:
	FORCEINLINE UWidgetSwitcher* GetWidgetSwitcher() const { return SettingsWidgetSwitcher; }

	void SelectNewTab(const int32& Index);

	virtual void InitializeTab(const int32& Index, UWidget* ParentWidget) override;
	
protected:
	USettingsWidget(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ApplySettingsButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> SettingsWidgetSwitcher;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingsTab> VideoTab;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingButton> VideoTabButton;

private:
	void InitializeSettingsWidget();
	void InitializeButtons();
	void InitializeButton(USettingsTab* SettingsTab, USettingButton* SettingsButton);

	UFUNCTION()
	void OnApplySettingsButtonClicked();

	bool bInitialized;
};
