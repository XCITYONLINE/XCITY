// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenuTabBase.h"
#include "SelectModeTabButton.h"
#include "SelectModeTab.generated.h"

class UImage;
class UTextBlock;
class UButton;
class USelectModeTabButton;

UCLASS()
class CITYSAMPLE_API USelectModeTab : public UMainMenuTabBase
{
	GENERATED_BODY()

public:
	void SelectNewMode(class USelectModeTabButton* Button, const FModeInfo& ModeInfo);
	
protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> BGImage;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> LabelText;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> DescriptionText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> PlayButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USelectModeTabButton> MultiplayerTabButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USelectModeTabButton> PortTabButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USelectModeTabButton> BankTabButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USelectModeTabButton> CitySampleTabButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USelectModeTabButton> TeamDeathMatchTabButton;
	
	UPROPERTY(BlueprintReadOnly, Category = "Select Mode Tab")
	FModeInfo CurrentModeInfo;

private:
	UPROPERTY()
	TObjectPtr<USelectModeTabButton> CurrentSelectedButton;
	
	void InitButtons();

	UFUNCTION()
	void OnPlayButtonClicked();
};
