// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API AMainMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void CreateAndShowLoadingScreen();

private:
	UPROPERTY(EditAnywhere, Category = "UI|Loading Screen")
	TSubclassOf<UUserWidget> LoadingScreenClass;
};
