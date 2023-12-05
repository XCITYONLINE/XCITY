// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsVideoTab.h"

#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/ScrollBox.h"
#include "GameFramework/GameUserSettings.h"
#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "XCityOnline/Public/UI/MainMenu/SettingsTab/SettingsWidget.h"

const TMap<int32, EWindowMode::Type> FullscreenTypes = USettingsVideoTab::FullscreenTypes;
const TMap<int32, FText> FullscreenDisplayInfos = USettingsVideoTab::FullscreenDisplayInfos;
const TMap<int32, FIntPoint> Resolutions = USettingsVideoTab::Resolutions;
const TMap<bool, FText> VSyncDisplayInfos = USettingsVideoTab::VSyncDisplayInfos;
const TMap<int32, FText> QualityDisplayInfos = USettingsVideoTab::QualityDisplayInfos;

void USettingsVideoTab::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (GetSettingsWidget()->GetWidgetSwitcher()->GetActiveWidget() != this)
	{
		return;
	}

	CheckBorders();
}

void USettingsVideoTab::OnSettingsConfirmed()
{
	Super::OnSettingsConfirmed();

	UGameUserSettings* GameUserSettings = UGameUserSettings::GetGameUserSettings();
	GameUserSettings->SetFullscreenMode(FullscreenTypes[FullscreenTypeIndex]);
	GameUserSettings->SetScreenResolution(Resolutions[ResolutionIndex]);
	GameUserSettings->bUseVSync = bVSyncEnabled;
	
	GameUserSettings->SetReflectionQuality(ReflectionQualityIndex);
	GameUserSettings->SetShadowQuality(ShadowQualityIndex);
	GameUserSettings->SetShadingQuality(ShadingQualityIndex);
	GameUserSettings->SetTextureQuality(TextureQualityIndex);
	GameUserSettings->SetFoliageQuality(FoliageQualityIndex);
	GameUserSettings->SetAntiAliasingQuality(AntiAliasingQualityIndex);
	GameUserSettings->SetGlobalIlluminationQuality(GlobalIlluminationQualityIndex);
	GameUserSettings->SetViewDistanceQuality(ViewDistanceQualityIndex);
	GameUserSettings->SetPostProcessingQuality(PostProcessingQualityIndex);

	GameUserSettings->ApplySettings(false);
}

void USettingsVideoTab::OnSettingsDeclined()
{
	Super::OnSettingsDeclined();

	ReloadWidget();
}

void USettingsVideoTab::OnTabEnabled()
{
	Super::OnTabEnabled();

	ReloadWidget();

	VideoTabScrollBox->ScrollToStart();
}

void USettingsVideoTab::InitializeTab(const int32& Index, UWidget* ParentWidget)
{
	Super::InitializeTab(Index, ParentWidget);

	FullscreenSettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnFullscreenSettingLeftButtonClicked);
	FullscreenSettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnFullscreenSettingRightButtonClicked);

	ResolutionSettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnResolutionSettingLeftButtonClicked);
	ResolutionSettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnResolutionSettingRightButtonClicked);

	VSyncSettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnVSyncSettingButtonClicked);
	VSyncSettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnVSyncSettingButtonClicked);

	ReflectionQualitySettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnReflectionQualitySettingLeftButtonClicked);
	ReflectionQualitySettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnReflectionQualitySettingRightButtonClicked);

	ShadowQualitySettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnShadowQualitySettingLeftButtonClicked);
	ShadowQualitySettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnShadowQualitySettingRightButtonClicked);

	ShadingQualitySettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnShadingQualitySettingLeftButtonClicked);
	ShadingQualitySettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnShadingQualitySettingRightButtonClicked);

	TextureQualitySettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnTextureQualitySettingLeftButtonClicked);
	TextureQualitySettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnTextureQualitySettingRightButtonClicked);

	FoliageQualitySettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnFoliageQualitySettingLeftButtonClicked);
	FoliageQualitySettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnFoliageQualitySettingRightButtonClicked);

	AntiAliasingQualitySettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnAntiAliasingQualitySettingLeftButtonClicked);
	AntiAliasingQualitySettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnAntiAliasingQualitySettingRightButtonClicked);

	GlobalIlluminationQualitySettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnGlobalIlluminationSettingLeftButtonClicked);
	GlobalIlluminationQualitySettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnGlobalIlluminationSettingRightButtonClicked);

	ViewDistanceQualitySettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnViewDistanceSettingLeftButtonClicked);
	ViewDistanceQualitySettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnViewDistanceSettingRightButtonClicked);

	PostProcessingQualitySettingLeftButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnPostProcessingSettingLeftButtonClicked);
	PostProcessingQualitySettingRightButton->OnClicked.AddUniqueDynamic(this, &USettingsVideoTab::OnPostProcessingSettingRightButtonClicked);

	ReloadWidget();
}

USettingsVideoTab::USettingsVideoTab(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	FullscreenTypeIndex = 0;
	ResolutionIndex = 0;
	bVSyncEnabled = true;
	ReflectionQualityIndex = 0;
	ShadowQualityIndex = 0;
	ShadingQualityIndex = 0;
	TextureQualityIndex = 0;
	FoliageQualityIndex = 0;
	AntiAliasingQualityIndex = 0;
	GlobalIlluminationQualityIndex = 0;
	ViewDistanceQualityIndex = 0;
	PostProcessingQualityIndex = 0;
}

void USettingsVideoTab::CheckBorders()
{
	for (const auto Border : Borders)
	{
		CheckIsBorderHovered(Border);
	}
}

void USettingsVideoTab::ReloadWidget()
{
	VideoTabScrollBox->ScrollToStart();
	
	const UGameUserSettings* GameUserSettings = UGameUserSettings::GetGameUserSettings();

	const EWindowMode::Type FullscreenType = GameUserSettings->GetFullscreenMode();
	TArray<EWindowMode::Type> FullscreenTypesTemp;
	FullscreenTypes.GenerateValueArray(FullscreenTypesTemp);
	for (auto It = FullscreenTypesTemp.CreateIterator(); It; ++It)
	{
		if (FullscreenType == FullscreenTypesTemp[It.GetIndex()])
		{
			FullscreenTypeIndex = It.GetIndex();
		}
	}

	FullscreenSettingText->SetText(FullscreenDisplayInfos[FullscreenTypeIndex]);

	const FIntPoint ScreenResolution = GameUserSettings->GetScreenResolution();
	TArray<FIntPoint> ScreenResolutions;
	Resolutions.GenerateValueArray(ScreenResolutions);
	for (auto It = ScreenResolutions.CreateIterator(); It; ++It)
	{
		if (ScreenResolution == ScreenResolutions[It.GetIndex()])
		{
			ResolutionIndex = It.GetIndex();
		}
	}

	ResolutionSettingText->SetText(FText::FromString(FString::FromInt(Resolutions[ResolutionIndex].X) + FString("x") + FString::FromInt(Resolutions[ResolutionIndex].Y)));
	
	bVSyncEnabled = GameUserSettings->bUseVSync;
	VSyncSettingText->SetText(VSyncDisplayInfos[bVSyncEnabled]);

	ReflectionQualityIndex = GameUserSettings->GetReflectionQuality();
	ReflectionQualitySettingText->SetText(QualityDisplayInfos[ReflectionQualityIndex]);

	ShadowQualityIndex = GameUserSettings->GetShadowQuality();
	ShadowQualitySettingText->SetText(QualityDisplayInfos[ShadowQualityIndex]);

	ShadingQualityIndex = GameUserSettings->GetShadingQuality();
	ShadingQualitySettingText->SetText(QualityDisplayInfos[ShadingQualityIndex]);

	TextureQualityIndex = GameUserSettings->GetTextureQuality();
	TextureQualitySettingText->SetText(QualityDisplayInfos[TextureQualityIndex]);
	
	FoliageQualityIndex = GameUserSettings->GetFoliageQuality();
	FoliageQualitySettingText->SetText(QualityDisplayInfos[FoliageQualityIndex]);

	AntiAliasingQualityIndex = GameUserSettings->GetAntiAliasingQuality();
	AntiAliasingQualitySettingText->SetText(QualityDisplayInfos[AntiAliasingQualityIndex]);

	GlobalIlluminationQualityIndex = GameUserSettings->GetGlobalIlluminationQuality();
	GlobalIlluminationQualitySettingText->SetText(QualityDisplayInfos[GlobalIlluminationQualityIndex]);

	ViewDistanceQualityIndex = GameUserSettings->GetViewDistanceQuality();
	ViewDistanceQualitySettingText->SetText(QualityDisplayInfos[ViewDistanceQualityIndex]);

	PostProcessingQualityIndex = GameUserSettings->GetPostProcessingQuality();
	PostProcessingQualitySettingText->SetText(QualityDisplayInfos[PostProcessingQualityIndex]);

	Borders.Add(FullscreenModeBorder);
	Borders.Add(ResolutionBorder);
	Borders.Add(VSyncBorder);
	Borders.Add(ReflectionQualityBorder);
	Borders.Add(ShadowQualityBorder);
	Borders.Add(ShadingQualityBorder);
	Borders.Add(TextureQualityBorder);
	Borders.Add(FolliageQualityBorder);
	Borders.Add(AntiAlliasingBorder);
	Borders.Add(GlobalIlluminationBorder);
	Borders.Add(ViewDistanceBorder);
	Borders.Add(PostProcessingBorder);
}

void USettingsVideoTab::OnFullscreenSettingLeftButtonClicked()
{
	FullscreenTypeIndex--;
	
	if (FullscreenTypeIndex < 0)
	{
		FullscreenTypeIndex = FullscreenTypes.Num() - 1;
	}

	FullscreenSettingText->SetText(FullscreenDisplayInfos[FullscreenTypeIndex]);
}

void USettingsVideoTab::OnFullscreenSettingRightButtonClicked()
{
	FullscreenTypeIndex++;

	if (FullscreenTypeIndex >= FullscreenTypes.Num() - 1)
	{
		FullscreenTypeIndex = 0;
	}

	FullscreenSettingText->SetText(FullscreenDisplayInfos[FullscreenTypeIndex]);
}

void USettingsVideoTab::OnResolutionSettingLeftButtonClicked()
{
	ResolutionIndex--;

	if (ResolutionIndex < 0)
	{
		ResolutionIndex = Resolutions.Num() - 1;
	}

	ResolutionSettingText->SetText(FText::FromString(FString::FromInt(Resolutions[ResolutionIndex].X) + FString("x") + FString::FromInt(Resolutions[ResolutionIndex].Y)));
}

void USettingsVideoTab::OnResolutionSettingRightButtonClicked()
{
	ResolutionIndex++;

	if (ResolutionIndex >= Resolutions.Num() - 1)
	{
		ResolutionIndex = 0;
	}

	ResolutionSettingText->SetText(FText::FromString(FString::FromInt(Resolutions[ResolutionIndex].X) + FString("x") + FString::FromInt(Resolutions[ResolutionIndex].Y)));
}

void USettingsVideoTab::OnVSyncSettingButtonClicked()
{
	bVSyncEnabled = !bVSyncEnabled;

	VSyncSettingText->SetText(VSyncDisplayInfos[bVSyncEnabled]);
}

void USettingsVideoTab::OnReflectionQualitySettingLeftButtonClicked()
{
	ReflectionQualityIndex--;

	if (ReflectionQualityIndex < 0)
	{
		ReflectionQualityIndex = 4;
	}

	ReflectionQualitySettingText->SetText(QualityDisplayInfos[ReflectionQualityIndex]);
}

void USettingsVideoTab::OnReflectionQualitySettingRightButtonClicked()
{
	ReflectionQualityIndex++;

	if (ReflectionQualityIndex > 4)
	{
		ReflectionQualityIndex = 0;
	}

	ReflectionQualitySettingText->SetText(QualityDisplayInfos[ReflectionQualityIndex]);
}

void USettingsVideoTab::OnShadowQualitySettingLeftButtonClicked()
{
	ShadowQualityIndex--;

	if (ShadowQualityIndex < 0)
	{
		ShadowQualityIndex = 4;
	}

	ShadowQualitySettingText->SetText(QualityDisplayInfos[ShadowQualityIndex]);
}

void USettingsVideoTab::OnShadowQualitySettingRightButtonClicked()
{
	ShadowQualityIndex++;

	if (ShadowQualityIndex > 4)
	{
		ShadowQualityIndex = 0;
	}

	ShadowQualitySettingText->SetText(QualityDisplayInfos[ShadowQualityIndex]);
}

void USettingsVideoTab::OnShadingQualitySettingLeftButtonClicked()
{
	ShadingQualityIndex--;

	if (ShadingQualityIndex < 0)
	{
		ShadowQualityIndex = 4;
	}

	ShadingQualitySettingText->SetText(QualityDisplayInfos[ShadingQualityIndex]);
}

void USettingsVideoTab::OnShadingQualitySettingRightButtonClicked()
{
	ShadingQualityIndex++;

	if (ShadingQualityIndex > 4)
	{
		ShadingQualityIndex = 0;
	}

	ShadingQualitySettingText->SetText(QualityDisplayInfos[ShadingQualityIndex]);
}

void USettingsVideoTab::OnTextureQualitySettingLeftButtonClicked()
{
	TextureQualityIndex--;

	if (TextureQualityIndex < 0)
	{
		TextureQualityIndex = 4;
	}

	TextureQualitySettingText->SetText(QualityDisplayInfos[TextureQualityIndex]);
}

void USettingsVideoTab::OnTextureQualitySettingRightButtonClicked()
{
	TextureQualityIndex++;

	if (TextureQualityIndex > 4)
	{
		TextureQualityIndex = 0;
	}

	TextureQualitySettingText->SetText(QualityDisplayInfos[TextureQualityIndex]);
}

void USettingsVideoTab::OnFoliageQualitySettingLeftButtonClicked()
{
	FoliageQualityIndex--;

	if (FoliageQualityIndex < 0)
	{
		FoliageQualityIndex = 4;
	}

	FoliageQualitySettingText->SetText(QualityDisplayInfos[FoliageQualityIndex]);
}

void USettingsVideoTab::OnFoliageQualitySettingRightButtonClicked()
{
	FoliageQualityIndex++;

	if (FoliageQualityIndex > 4)
	{
		FoliageQualityIndex = 0;
	}

	FoliageQualitySettingText->SetText(QualityDisplayInfos[FoliageQualityIndex]);
}

void USettingsVideoTab::OnAntiAliasingQualitySettingLeftButtonClicked()
{
	AntiAliasingQualityIndex--;

	if (AntiAliasingQualityIndex < 0)
	{
		AntiAliasingQualityIndex = 4;
	}

	AntiAliasingQualitySettingText->SetText(QualityDisplayInfos[AntiAliasingQualityIndex]);
}

void USettingsVideoTab::OnAntiAliasingQualitySettingRightButtonClicked()
{
	AntiAliasingQualityIndex++;

	if (AntiAliasingQualityIndex > 4)
	{
		AntiAliasingQualityIndex = 0;
	}

	AntiAliasingQualitySettingText->SetText(QualityDisplayInfos[AntiAliasingQualityIndex]);
}

void USettingsVideoTab::OnGlobalIlluminationSettingLeftButtonClicked()
{
	GlobalIlluminationQualityIndex--;

	if (GlobalIlluminationQualityIndex < 0)
	{
		GlobalIlluminationQualityIndex = 4;
	}

	GlobalIlluminationQualitySettingText->SetText(QualityDisplayInfos[GlobalIlluminationQualityIndex]);
}

void USettingsVideoTab::OnGlobalIlluminationSettingRightButtonClicked()
{
	GlobalIlluminationQualityIndex++;

	if (GlobalIlluminationQualityIndex > 4)
	{
		GlobalIlluminationQualityIndex = 0;
	}

	GlobalIlluminationQualitySettingText->SetText(QualityDisplayInfos[GlobalIlluminationQualityIndex]);
}

void USettingsVideoTab::OnViewDistanceSettingLeftButtonClicked()
{
	ViewDistanceQualityIndex--;

	if (ViewDistanceQualityIndex < 0)
	{
		ViewDistanceQualityIndex = 4;
	}

	ViewDistanceQualitySettingText->SetText(QualityDisplayInfos[ViewDistanceQualityIndex]);
}

void USettingsVideoTab::OnViewDistanceSettingRightButtonClicked()
{
	ViewDistanceQualityIndex++;

	if (ViewDistanceQualityIndex > 4)
	{
		ViewDistanceQualityIndex = 0;
	}

	ViewDistanceQualitySettingText->SetText(QualityDisplayInfos[ViewDistanceQualityIndex]);
}

void USettingsVideoTab::OnPostProcessingSettingLeftButtonClicked()
{
	PostProcessingQualityIndex--;

	if (PostProcessingQualityIndex < 0)
	{
		PostProcessingQualityIndex = 4;
	}

	PostProcessingQualitySettingText->SetText(QualityDisplayInfos[PostProcessingQualityIndex]);
}

void USettingsVideoTab::OnPostProcessingSettingRightButtonClicked()
{
	PostProcessingQualityIndex++;

	if (PostProcessingQualityIndex > 4)
	{
		PostProcessingQualityIndex = 0;
	}

	PostProcessingQualitySettingText->SetText(QualityDisplayInfos[PostProcessingQualityIndex]);
}

void USettingsVideoTab::OnBorderHovered(UBorder* HoveredBorder)
{
	HoveredBorder->SetBrush(SlateBrush);

	FLinearColor WhiteColor = FLinearColor::White;
	WhiteColor.A = 1;
	
	HoveredBorder->SetBrushColor(WhiteColor);

	DeactivateBorders(HoveredBorder);
}

void USettingsVideoTab::CheckIsBorderHovered(UBorder* Border)
{
	if (Border->IsHovered())
	{
		OnBorderHovered(Border);
	}
}

void USettingsVideoTab::DeactivateBorders(UBorder* ActiveBorder)
{
	for (const auto Border : Borders)
	{
		if (Border != ActiveBorder)
		{
			FLinearColor WhiteColor = FLinearColor::White;
			WhiteColor.A = 0;
			Border->SetBrushColor(WhiteColor);
		}
	}
}
