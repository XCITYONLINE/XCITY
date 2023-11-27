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
	void InitializeLine(const int32& MappingIndex, UInputMappingContext* InputMappingContext, const int32& InLineIndex);

	FORCEINLINE const int32& GetLineIndex() const { return LineIndex; }

	void OnHovered();
	void OnUnhovered();
	
protected:
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UBorder> BackgroundBorder;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> ControlKeyTextBlock;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UInputKeySelector> ControlKeySelector;

	UPROPERTY(EditAnywhere)
	FSlateBrush SlateBrush;

private:
	UFUNCTION()
	void OnKeySelected(FInputChord InputChord);

	UPROPERTY()
	int32 InputMappingIndex;

	UPROPERTY()
	int32 LineIndex;
	
	UPROPERTY()
	TObjectPtr<class UInputMappingContext> CurrentMappingContext;
};
