// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsTab.h"
#include "SettingsVideoTab.generated.h"

class UTextBlock;
class UButton;
class UBorder;

#define LOCTEXT_NAMESPACE "SettingsVideoTab"

UCLASS()
class CITYSAMPLE_API USettingsVideoTab : public USettingsTab
{
	GENERATED_BODY()

public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	virtual void OnSettingsConfirmed() override;
	virtual void OnSettingsDeclined() override;
	virtual void OnTabEnabled() override;

	virtual void InitializeTab(const int32& Index, UWidget* ParentWidget) override;

public:
	inline static const TMap<int32, EWindowMode::Type> FullscreenTypes {
			{ 0, EWindowMode::Fullscreen },
			{ 1, EWindowMode::Windowed }
	};

	inline static const TMap<int32, FText> FullscreenDisplayInfos {
			{ 0, LOCTEXT("FullscreenTypeFullscreen", "Fullscreen") },
			{ 1, LOCTEXT("FullscreenTypeWindowed", "Windowed") }
	};

	inline static const TMap<int32, FIntPoint> Resolutions {
			{ 0, FIntPoint(1920, 1080) },
			{ 1, FIntPoint(1280, 720) }
	};

	inline static const TMap<bool, FText> VSyncDisplayInfos {
		{ false, LOCTEXT("VSyncOff", "Off") },
		{ true, LOCTEXT("VSyncOn", "On") }
	};

	inline static const TMap<int32, FText> QualityDisplayInfos {
		{ 0, LOCTEXT("QualitySettingLow", "Low") },
		{ 1, LOCTEXT("QualitySettingMedium", "Medium") },
		{ 2, LOCTEXT("QualitySettingHigh", "High") },
		{ 3, LOCTEXT("QualitySettingUltra", "Ultra") },
		{ 4, LOCTEXT("QualitySettingUltra", "Cinematic") }
	};
	
protected:
	USettingsVideoTab(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> FullscreenSettingLeftButton;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> FullscreenSettingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> FullscreenSettingRightButton;

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
	int32 ResolutionIndex;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> VSyncSettingLeftButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> VSyncSettingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> VSyncSettingRightButton;

	UPROPERTY()
	bool bVSyncEnabled;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ReflectionQualitySettingLeftButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> ReflectionQualitySettingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ReflectionQualitySettingRightButton;

	UPROPERTY()
	int32 ReflectionQualityIndex;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ShadowQualitySettingLeftButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> ShadowQualitySettingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ShadowQualitySettingRightButton;

	UPROPERTY()
	int32 ShadowQualityIndex;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ShadingQualitySettingLeftButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> ShadingQualitySettingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ShadingQualitySettingRightButton;

	UPROPERTY()
	int32 ShadingQualityIndex;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> TextureQualitySettingLeftButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> TextureQualitySettingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> TextureQualitySettingRightButton;

	UPROPERTY()
	int32 TextureQualityIndex;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> FoliageQualitySettingLeftButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> FoliageQualitySettingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> FoliageQualitySettingRightButton;

	UPROPERTY()
	int32 FoliageQualityIndex;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> AntiAliasingQualitySettingLeftButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> AntiAliasingQualitySettingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> AntiAliasingQualitySettingRightButton;

	UPROPERTY()
	int32 AntiAliasingQualityIndex;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> GlobalIlluminationQualitySettingLeftButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> GlobalIlluminationQualitySettingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> GlobalIlluminationQualitySettingRightButton;

	UPROPERTY()
	int32 GlobalIlluminationQualityIndex;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ViewDistanceQualitySettingLeftButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> ViewDistanceQualitySettingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ViewDistanceQualitySettingRightButton;

	UPROPERTY()
	int32 ViewDistanceQualityIndex;
	
protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> PostProcessingQualitySettingLeftButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> PostProcessingQualitySettingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> PostProcessingQualitySettingRightButton;

	UPROPERTY()
	int32 PostProcessingQualityIndex;
	
protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBorder> FullscreenModeBorder;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBorder> ResolutionBorder;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBorder> VSyncBorder;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBorder> ReflectionQualityBorder;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBorder> ShadowQualityBorder;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBorder> ShadingQualityBorder;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBorder> TextureQualityBorder;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBorder> FolliageQualityBorder;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBorder> AntiAlliasingBorder;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBorder> GlobalIlluminationBorder;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBorder> ViewDistanceBorder;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBorder> PostProcessingBorder;
	
private:
	void CheckBorders();
	
	void ReloadWidget();
	
	UFUNCTION()
	void OnFullscreenSettingLeftButtonClicked();

	UFUNCTION()
	void OnFullscreenSettingRightButtonClicked();

	UFUNCTION()
	void OnResolutionSettingLeftButtonClicked();

	UFUNCTION()
	void OnResolutionSettingRightButtonClicked();

	UFUNCTION()
	void OnVSyncSettingButtonClicked();

	UFUNCTION()
	void OnReflectionQualitySettingLeftButtonClicked();
	
	UFUNCTION()
	void OnReflectionQualitySettingRightButtonClicked();
	
	UFUNCTION()
	void OnShadowQualitySettingLeftButtonClicked();

	UFUNCTION()
	void OnShadowQualitySettingRightButtonClicked();

	UFUNCTION()
	void OnShadingQualitySettingLeftButtonClicked();

	UFUNCTION()
	void OnShadingQualitySettingRightButtonClicked();

	UFUNCTION()
	void OnTextureQualitySettingLeftButtonClicked();

	UFUNCTION()
	void OnTextureQualitySettingRightButtonClicked();

	UFUNCTION()
	void OnFoliageQualitySettingLeftButtonClicked();

	UFUNCTION()
	void OnFoliageQualitySettingRightButtonClicked();
	
	UFUNCTION()
	void OnAntiAliasingQualitySettingLeftButtonClicked();

	UFUNCTION()
	void OnAntiAliasingQualitySettingRightButtonClicked();

	UFUNCTION()
	void OnGlobalIlluminationSettingLeftButtonClicked();

	UFUNCTION()
	void OnGlobalIlluminationSettingRightButtonClicked();

	UFUNCTION()
	void OnViewDistanceSettingLeftButtonClicked();

	UFUNCTION()
	void OnViewDistanceSettingRightButtonClicked();

	UFUNCTION()
	void OnPostProcessingSettingLeftButtonClicked();

	UFUNCTION()
	void OnPostProcessingSettingRightButtonClicked();

protected:
	void OnBorderHovered(class UBorder* HoveredBorder);
	void CheckIsBorderHovered(class UBorder* Border);
	void DeactivateBorders(UBorder* ActiveBorder);

	UPROPERTY(EditAnywhere)
	FSlateBrush SlateBrush;
	
	UPROPERTY()
	TArray<class UBorder*> Borders;
};

#undef LOCTEXT_NAMESPACE
