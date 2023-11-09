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

	FORCEINLINE UUserWidget* GetLoadingScreenWidget() const
	{
		return LoadingScreenWidget;
	}
	
protected:
	UPROPERTY(EditAnywhere, Category = "UI|Loading Screen")
	TSubclassOf<UUserWidget> LoadingScreenWidgetClass;

private:
	UPROPERTY()
	TObjectPtr<UUserWidget> LoadingScreenWidget;
};
