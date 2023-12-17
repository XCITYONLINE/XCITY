// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SettingsTab/ControlsTab/SettingsControlsTab.h"
#include "InputMappingContext.h"
#include "Components/ScrollBox.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/ControlsTab/SettingControlsLine.h"

void USettingsControlsTab::OnTabEnabled()
{
	Super::OnTabEnabled();

	RedrawWidget();
}

void USettingsControlsTab::InitializeTab(const int32& Index, UWidget* ParentWidget)
{
	Super::InitializeTab(Index, ParentWidget);

	RedrawWidget();
}

void USettingsControlsTab::RedrawWidget() const
{
	InputsBox->ScrollToStart();
	
	InputsBox->ClearChildren();
	
	for (auto It = InputMappingContext->GetMappings().CreateConstIterator(); It; ++It)
	{
		const FEnhancedActionKeyMapping& KeyMapping = GetMappingContext()->GetMapping(It.GetIndex());
		if (KeyMapping.GetDisplayName().IsEmpty()) continue;
		
		USettingControlsLine* SettingControlsLine = CreateWidget<USettingControlsLine>(GetWorld(), ControlsLineClass);
		SettingControlsLine->InitializeLine(It.GetIndex(), GetMappingContext(), It.GetIndex());

		InputsBox->AddChild(SettingControlsLine);
	}
}
