// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SettingsTab/ControlsTab/SettingControlsLine.h"

#include "InputMappingContext.h"
#include "Components/InputKeySelector.h"
#include "Components/TextBlock.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/ControlsTab/SettingsControlsTab.h"

void USettingControlsLine::InitializeLine(const FEnhancedActionKeyMapping& Mapping, const USettingsControlsTab* ControlsTab)
{
	ControlKeySelector->SetSelectedKey(Mapping.Key);
	ControlKeyTextBlock->SetText(Mapping.GetDisplayName());

	CurrentMapping = Mapping;
	CurrentMappingContext = ControlsTab->GetMappingContext();
	ControlKeySelector->OnKeySelected.AddUniqueDynamic(this, &USettingControlsLine::OnKeySelected);
}

void USettingControlsLine::OnKeySelected(FInputChord InputChord)
{
	CurrentMappingContext->UnmapAllKeysFromAction(CurrentMapping.Action);
	CurrentMappingContext->MapKey(CurrentMapping.Action, InputChord.Key);
}
