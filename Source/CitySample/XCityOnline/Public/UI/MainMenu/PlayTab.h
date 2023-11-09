// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuTabBase.h"
#include "PlayTab.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API UPlayTab : public UMainMenuTabBase
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> PlayButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ContinueButton;

	UPROPERTY(EditAnywhere, Category = "Play Tab")
	TSoftObjectPtr<class UWorld> NextLevelInstance;

private:
	UFUNCTION()
	void LoadNextLevel();
};
