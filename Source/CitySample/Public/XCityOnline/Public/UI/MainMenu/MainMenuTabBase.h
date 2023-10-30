// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuTabInterface.h"
#include "MainMenuTabBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CITYSAMPLE_API UMainMenuTabBase : public UUserWidget, public IMainMenuTabInterface
{
	GENERATED_BODY()

protected:
	//~ Begin IMainMenuTabInterface
	virtual void OnTabEnabled() override;
	virtual void OnTabDisabled() override;
	//~ End IMainMenuTabInterface

	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Tab", DisplayName = "OnTabEnabled")
	void K2_OnTabEnabled();

	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Tab", DisplayName = "OnTabDisabled")
	void K2_OnTabDisabled();
};
