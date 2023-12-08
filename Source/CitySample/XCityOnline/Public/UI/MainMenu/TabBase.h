// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuTypes.h"
#include "TabBase.generated.h"

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API UTabBase : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void OnTabEnabled();
	virtual void InitializeTab(const int32& Index, UWidget* ParentWidget);
	virtual void OnTabDisabled();

	FORCEINLINE const int32& GetIndex() const { return TabIndex; }

	UFUNCTION(BlueprintPure)
	FORCEINLINE ETabType GetTabType() const { return TabType; }
	
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Tab", DisplayName = "OnTabEnabled")
	void K2_OnTabEnabled();

	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Tab", DisplayName = "InitializeTab")
	void K2_InitializeTab(const int32& Index, UWidget* ParentWidget);

	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Tab", DisplayName = "OnTabDisabled")
	void K2_OnTabDisabled();

	UPROPERTY(EditAnywhere, Category = "Main Menu Tab")
	ETabType TabType;

private:
	int32 TabIndex;
};
