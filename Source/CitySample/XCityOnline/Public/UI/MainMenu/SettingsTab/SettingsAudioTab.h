// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SettingsTab.h"
#include "SettingsAudioTab.generated.h"

class USlider;

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API USettingsAudioTab : public USettingsTab
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USlider> OverallVolumeSlider;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USlider> MusicVolumeSlider;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USlider> CharacterVoiceVolumeSlider;
};
