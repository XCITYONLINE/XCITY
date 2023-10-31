// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsTab.h"
#include "SettingsVideoTab.generated.h"

class UTextBlock;
class UButton;

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API USettingsVideoTab : public USettingsTab
{
	GENERATED_BODY()

public:
	virtual void OnSettingsConfirmed() override;
	
protected:
	USettingsVideoTab(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> FullscreenSettingLeftButton;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> FullscreenSettingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> FullscreenSettingRightButton;

	UPROPERTY()
	TMap<int32, EWindowMode::Type> FullscreenTypes;

	UPROPERTY()
	TMap<int32, FText> FullscreenDisplayInfo;

	UPROPERTY()
	int32 FullscreenTypeIndex;
	
protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ResolutionSettingLeftButton;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> ResolutionSettingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ResolutionSettingRightButton;

	UPROPERTY()
	TMap<int32, FIntPoint> Resolutions;
	
	UPROPERTY()
	int32 ResolutionIndex;
	
private:
	UFUNCTION()
	void OnFullscreenSettingLeftButtonClicked();

	UFUNCTION()
	void OnFullscreenSettingRightButtonClicked();

	UFUNCTION()
	void OnResolutionSettingLeftButtonClicked();

	UFUNCTION()
	void OnResolutionSettingRightButtonClicked();
};
