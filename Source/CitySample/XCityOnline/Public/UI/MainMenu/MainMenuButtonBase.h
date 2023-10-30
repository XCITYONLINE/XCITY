// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenuButtonInterface.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuButtonBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CITYSAMPLE_API UMainMenuButtonBase : public UUserWidget, public IMainMenuButtonInterface
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
	//~ Begin IMainMenuButtonInterface
	virtual void InitializeTabButton() override;
	virtual void OnDisabled() override;
	virtual void OnSelected() override;
	virtual void OnHovered() override;
	virtual void OnUnhovered() override;
	//~ End IMainMenuButtonInterface

	/*
	 * ############################ BLUEPRINT EVENTS #######################
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Button", DisplayName = "InitializeTabButton")
	void K2_InitializeTabButton();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Button", DisplayName = "OnDisabled")
	void K2_OnDisabled();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Button", DisplayName = "OnSelected")
	void K2_OnSelected();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Button", DisplayName = "OnHovered")
	void K2_OnHovered();

	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Button", DisplayName = "OnUnhovered")
	void K2_OnUnhovered();
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> ButtonPtr;
};
