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
	virtual void OnHovered() override;
	virtual void OnUnhovered() override;
	virtual void OnPressed() override;
	virtual void OnReleased() override;
	
	UPROPERTY(EditAnywhere, Category = "Setting Button")
	bool bIsSubButton;
	
	UPROPERTY(EditAnywhere, Category = "Setting Button")
	FSlateBrush SelectedBrush;

	UPROPERTY(EditAnywhere, Category = "Setting Button")
	FSlateBrush HoveredBrush;

	UPROPERTY(EditAnywhere, Category = "Setting Button")
	FSlateBrush DisabledBrush;

	UPROPERTY(EditAnywhere, Category = "Setting Button")
	FLinearColor SelectedTextColor;

	UPROPERTY(EditAnywhere, Category = "Setting Button")
	FLinearColor DisabledTextColor;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UBorder> BackgroundBorder;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> SelectedImage;
};
