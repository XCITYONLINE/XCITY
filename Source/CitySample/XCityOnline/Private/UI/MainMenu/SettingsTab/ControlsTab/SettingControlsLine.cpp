// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SettingsTab/ControlsTab/SettingControlsLine.h"

#include "InputMappingContext.h"
#include "Components/InputKeySelector.h"
#include "Components/TextBlock.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/ControlsTab/SettingsControlsTab.h"

void USettingControlsLine::InitializeLine(const int32& MappingIndex, UInputMappingContext* InputMappingContext)
{
	InputMappingIndex = MappingIndex;
	
	CurrentMappingContext = InputMappingContext;
	const FEnhancedActionKeyMapping& KeyMapping = CurrentMappingContext->GetMapping(InputMappingIndex);
	
	ControlKeySelector->SetSelectedKey(KeyMapping.Key);
	ControlKeyTextBlock->SetText(KeyMapping.GetDisplayName());
	
	ControlKeySelector->OnKeySelected.AddUniqueDynamic(this, &USettingControlsLine::OnKeySelected);
}

void USettingControlsLine::OnKeySelected(FInputChord InputChord)
{
	FEnhancedActionKeyMapping& KeyMapping = CurrentMappingContext->GetMapping(InputMappingIndex);
	
	KeyMapping.Key = InputChord.Key;
}
