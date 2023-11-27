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
	FORCEINLINE UWidgetSwitcher* GetSubWidgetSwitcher() const { return SubWidgetSwitcher; }

	void SelectNewTab(const int32& Index, USettingButton* SettingButton, bool bIsSubTab);

	virtual void InitializeTab(const int32& Index, UWidget* ParentWidget) override;

	UFUNCTION()
	void OnApplySettingsButtonClicked();

	UPROPERTY(EditAnywhere)
	FKey ApplyKey;
	
protected:
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	
	USettingsWidget(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ApplySettingsButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> SettingsWidgetSwitcher;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingsTab> VideoTab;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingButton> VideoTabButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingsTab> ControlsTab;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingButton> ControlsTabButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingsTab> AudioTab;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingButton> AudioTabButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingButton> DisplayTabButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingButton> NotificationsTabButton;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UWidgetSwitcher> SubWidgetSwitcher;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingButton> SettingsMainButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingButton> GameButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingButton> MapButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingButton> StatsButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingButton> BriefButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingButton> OnlineButton;

private:
	void InitializeSettingsWidget();
	void InitializeButtons();
	void InitializeButton(USettingsTab* SettingsTab, USettingButton* SettingsButton);

	UPROPERTY()
	TObjectPtr<USettingButton> CurrentSelectedButton;

	bool bInitialized;
};
