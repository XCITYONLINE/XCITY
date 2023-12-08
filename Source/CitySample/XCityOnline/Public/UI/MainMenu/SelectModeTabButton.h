// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SelectModeTabButton.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FModeInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mode Info")
	FText LabelText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mode Info")
	FText DescriptionText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mode Info")
	TObjectPtr<UTexture2D> BGImageAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mode Info")
	TSoftObjectPtr<class UWorld> LevelInstance;
	
	bool operator==(const FModeInfo& ModeInfo) const
	{
		return LabelText.EqualTo(ModeInfo.LabelText)
		&& DescriptionText.EqualTo(ModeInfo.DescriptionText)
		&& BGImageAsset == ModeInfo.BGImageAsset
		&& LevelInstance == ModeInfo.LevelInstance;
	}
};

UCLASS()
class CITYSAMPLE_API USelectModeTabButton : public UUserWidget
{
	GENERATED_BODY()

public:
	void InitButton(UWidget* ParentWidget);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Select Mode Tab Button")
	FModeInfo ModeInfo;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> SelectModeButton;
	
private:
	UPROPERTY()
	TObjectPtr<class USelectModeTab> ParentTab;

	UFUNCTION()
	void OnClicked();
};
