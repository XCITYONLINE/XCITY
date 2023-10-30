// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

UCLASS()
class CITYSAMPLE_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintImplementableEvent)
	UUserWidget* K2_GetRadialMenuWidget();

	UFUNCTION(BlueprintPure)
	FORCEINLINE bool IsInitialized() const { return bIsInitialized; }

protected:
	UMainMenuWidget(const FObjectInitializer& ObjectInitializer);
	
	//~ Begin UUserWidget Interface
	virtual void NativeConstruct() override;
	//~ End UUserWidget Interface
	
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* TabSwitcher;

private:
	void InitializeMainMenu();
	bool bIsInitialized;
};
