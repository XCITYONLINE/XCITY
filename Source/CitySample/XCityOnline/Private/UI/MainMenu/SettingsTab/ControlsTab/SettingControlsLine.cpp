// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SettingsTab/ControlsTab/SettingControlsLine.h"

#include "InputMappingContext.h"
#include "Components/Border.h"
#include "Components/InputKeySelector.h"
#include "Components/TextBlock.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/ControlsTab/SettingsControlsTab.h"

void USettingControlsLine::InitializeLine(const int32& MappingIndex, UInputMappingContext* InputMappingContext, const int32& InLineIndex)
{
	InputMappingIndex = MappingIndex;
	
	CurrentMappingContext = InputMappingContext;
	const FEnhancedActionKeyMapping& KeyMapping = CurrentMappingContext->GetMapping(InputMappingIndex);
	
	ControlKeySelector->SetSelectedKey(KeyMapping.Key);
	ControlKeyTextBlock->SetText(KeyMapping.GetDisplayName());

	LineIndex = InLineIndex;
	
	ControlKeySelector->OnKeySelected.AddUniqueDynamic(this, &USettingControlsLine::OnKeySelected);
}

void USettingControlsLine::OnHovered()
{
	BackgroundBorder->SetBrush(SlateBrush);
	
	FLinearColor WhiteColor = FLinearColor::White;
	WhiteColor.A = 1;
	
	BackgroundBorder->SetBrushColor(WhiteColor);
}

void USettingControlsLine::OnUnhovered()
{
	FLinearColor WhiteColor = FLinearColor::White;
	WhiteColor.A = 0;
	BackgroundBorder->SetBrushColor(WhiteColor);
}

void USettingControlsLine::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);

	OnHovered();
}

void USettingControlsLine::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);

	OnUnhovered();
}

void USettingControlsLine::OnKeySelected(FInputChord InputChord)
{
	FEnhancedActionKeyMapping& KeyMapping = CurrentMappingContext->GetMapping(InputMappingIndex);
	
	KeyMapping.Key = InputChord.Key;
}
