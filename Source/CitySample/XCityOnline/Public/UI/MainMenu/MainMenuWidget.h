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

	UFUNCTION(BlueprintPure)
	FORCEINLINE bool IsInitialized() const { return bIsInitialized; }

	UWidgetSwitcher* GetWidgetSwitcher() const;

	void SelectNewTab(const int32& Index, UMainMenuButtonBase* MainMenuButton);

	UFUNCTION(BlueprintCallable)
	void SelectTabByType(ETabType TabType);

	UFUNCTION(BlueprintCallable)
	UMainMenuTabBase* GetTab(ETabType TabType);

	UFUNCTION(BlueprintCallable)
	UMainMenuButtonBase* GetButton(ETabType TabType);

	UFUNCTION(BlueprintPure)
	UMainMenuTabBase* GetCurrentTab() const;
	
protected:
	UMainMenuWidget(const FObjectInitializer& ObjectInitializer);

	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	
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

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UMainMenuTabBase> GirlTab;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UMainMenuButtonBase> GirlTabButton;

private:
	UPROPERTY()
	TObjectPtr<UMainMenuButtonBase> CurrentSelectedButton;
	
	UPROPERTY()
	TObjectPtr<UMainMenuTabBase> CurrentTab;
	
	void InitializeMainMenu();
	void InitializeButtons();
	void InitializeButton(UMainMenuButtonBase* Button, UMainMenuTabBase* Tab);
	
	bool bIsInitialized;
};
