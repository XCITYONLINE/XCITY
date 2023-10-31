﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TabBase.h"
#include "MainMenuTabBase.generated.h"

class UMainMenuWidget;

/**
 * 
 */
UCLASS(Abstract)
class CITYSAMPLE_API UMainMenuTabBase : public UTabBase
{
	GENERATED_BODY()

public:
	FORCEINLINE UMainMenuWidget* GetMainMenuWidget() const { return MainMenuWidgetPtr; }

	//~ Begin UTabBase interface
	virtual void OnTabEnabled() override;
	virtual void InitializeTab(const int32& Index, UWidget* ParentWidget) override;
	virtual void OnTabDisabled() override;
	//~ End UTabBase interface
	
protected:
	UMainMenuTabBase(const FObjectInitializer& ObjectInitializer);

private:
	UPROPERTY()
	TObjectPtr<UMainMenuWidget> MainMenuWidgetPtr;
};