// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TabButtonBase.h"
#include "MainMenuButtonBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CITYSAMPLE_API UMainMenuButtonBase : public UTabButtonBase
{
	GENERATED_BODY()

public:
	virtual void InitializeTabButton(UTabBase* ChildTab) override;
	virtual void OnUnhovered() override;
	virtual void OnSelected() override;
	virtual void OnDisabled() override;
	virtual void OnHovered() override;
	
protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> SelectedImage;
	
	virtual void InitializeVisual();
	
	UPROPERTY(EditAnywhere, Category = "Main Menu Button Info")
	FSlateColor HoveredTextColor;

	UPROPERTY(EditAnywhere, Category = "Main Menu Button Info")
	FSlateColor UnhoveredTextColor;
};
