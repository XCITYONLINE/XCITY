// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenuTabBase.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class UMainMenuTabBase;
class UMainMenuButtonBase;
class UWidgetSwitcher;

UCLASS()
class CITYSAMPLE_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintImplementableEvent)
	UUserWidget* K2_GetRadialMenuWidget();

	UFUNCTION(BlueprintPure)
	FORCEINLINE bool IsInitialized() const { return bIsInitialized; }

	UWidgetSwitcher* GetWidgetSwitcher() const;

protected:
	UMainMenuWidget(const FObjectInitializer& ObjectInitializer);
	
	//~ Begin UUserWidget Interface
	virtual void NativeConstruct() override;
	//~ End UUserWidget Interface
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> TabSwitcher;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UMainMenuTabBase> PlayTab;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UMainMenuButtonBase> PlayTabButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UMainMenuTabBase> SettingsTab;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UMainMenuButtonBase> SettingTabButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UMainMenuTabBase> ClubTab;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UMainMenuButtonBase> ClubTabButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UMainMenuTabBase> StoreTab;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UMainMenuButtonBase> StoreTabButton;

private:
	void InitializeMainMenu();
	void InitializeButtons();
	void InitializeButton(UMainMenuButtonBase* Button, UMainMenuTabBase* Tab);
	
	bool bIsInitialized;
};
