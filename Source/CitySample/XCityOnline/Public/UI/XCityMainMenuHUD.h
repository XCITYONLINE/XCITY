// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "XCityMainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API AXCityMainMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "UI")
	FORCEINLINE UUserWidget* GetLoadingScreenWidget() const
	{
		return LoadingScreenWidget;
	}

	UFUNCTION(BlueprintPure, Category = "UI")
	FORCEINLINE UUserWidget* GetMainMenuWidget() const
	{
		return MainMenuWidget;
	}
	
protected:
	UPROPERTY(EditAnywhere, Category = "UI|Loading Screen")
	TSubclassOf<UUserWidget> LoadingScreenWidgetClass;

	UPROPERTY(EditAnywhere, Category = "UI|Loading Screen")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

private:
	UPROPERTY()
	TObjectPtr<UUserWidget> LoadingScreenWidget;

	UPROPERTY()
	TObjectPtr<UUserWidget> MainMenuWidget;
};
