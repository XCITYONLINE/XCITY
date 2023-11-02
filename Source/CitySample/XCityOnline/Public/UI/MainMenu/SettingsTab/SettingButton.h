// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XCityOnline/Public/UI/MainMenu/TabButtonBase.h"
#include "SettingButton.generated.h"

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API USettingButton : public UTabButtonBase
{
	GENERATED_BODY()

public:
	virtual void OnSelected() override;
	virtual void OnDisabled() override;
	virtual void InitializeTabButton(UTabBase* ChildTab) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Setting Button")
	FLinearColor SelectedColor;

	UPROPERTY(EditAnywhere, Category = "Setting Button")
	FLinearColor DisabledColor;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UBorder> BackgroundBorder;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> SelectedImage;
};
