// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedActionKeyMapping.h"
#include "Blueprint/UserWidget.h"
#include "SettingControlsLine.generated.h"

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API USettingControlsLine : public UUserWidget
{
	GENERATED_BODY()

public:
	void InitializeLine(const int32& MappingIndex, UInputMappingContext* InputMappingContext);
	
protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> ControlKeyTextBlock;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UInputKeySelector> ControlKeySelector;

private:
	UFUNCTION()
	void OnKeySelected(FInputChord InputChord);

	UPROPERTY()
	int32 InputMappingIndex;
	
	UPROPERTY()
	TObjectPtr<class UInputMappingContext> CurrentMappingContext;
};
