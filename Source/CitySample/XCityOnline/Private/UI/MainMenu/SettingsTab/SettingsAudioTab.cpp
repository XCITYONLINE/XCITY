// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsAudioTab.h"

#include "Components/Slider.h"
#include "Kismet/GameplayStatics.h"

USettingsAudioTab::USettingsAudioTab(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	OverallVolume = 1;
}

void USettingsAudioTab::NativeConstruct()
{
	Super::NativeConstruct();

	OverallVolumeSlider->OnValueChanged.AddUniqueDynamic(this, &ThisClass::OnOverallVolumeChanged);
}

void USettingsAudioTab::OnOverallVolumeChanged(float NewValue)
{
	OverallVolume = NewValue;

	UGameplayStatics::SetSoundMixClassOverride(GetWorld(), nullptr, MasterSoundClass, OverallVolume, 1, 0);
}
