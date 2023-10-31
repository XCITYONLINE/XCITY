// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenuTypes.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuTabBase.generated.h"

class UMainMenuWidget;

/**
 * 
 */
UCLASS(Abstract)
class CITYSAMPLE_API UMainMenuTabBase : public UUserWidget
{
	GENERATED_BODY()

public:
	FORCEINLINE const ETabType& GetTabType() const { return TabType; }
	FORCEINLINE UMainMenuWidget* GetMainMenuWidget() const { return MainMenuWidgetPtr; }
	FORCEINLINE const int32& GetIndex() const { return TabIndex; }

	//~ Begin IMainMenuTabInterface
	virtual void OnTabEnabled();
	virtual void InitializeTab(const int32& Index, UMainMenuWidget* Widget);
	virtual void OnTabDisabled();
	//~ End IMainMenuTabInterface
	
protected:
	UMainMenuTabBase(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Tab", DisplayName = "OnTabEnabled")
	void K2_OnTabEnabled();

	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Tab", DisplayName = "InitializeTab")
	void K2_InitializeTab(const int32& Index, UMainMenuWidget* Widget);

	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Tab", DisplayName = "OnTabDisabled")
	void K2_OnTabDisabled();

	UPROPERTY(EditAnywhere, Category = "Main Menu Tab")
	ETabType TabType;

private:
	UPROPERTY()
	TObjectPtr<UMainMenuWidget> MainMenuWidgetPtr;

	int32 TabIndex;
};
