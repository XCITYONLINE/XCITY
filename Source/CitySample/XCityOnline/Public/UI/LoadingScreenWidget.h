// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoadingScreenWidget.generated.h"

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API ULoadingScreenWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	ULoadingScreenWidget(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> SubtractImage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> GirlImage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> BGCityImage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> LoadingScreenText;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	TObjectPtr<class UWidgetAnimation> FirstSlideAnim;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	TObjectPtr<class UWidgetAnimation> SecondSlideAnim;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	TObjectPtr<class UWidgetAnimation> ThirdSlideAnim;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	TObjectPtr<class UWidgetAnimation> FourthSlideAnim;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	TObjectPtr<class UWidgetAnimation> FifthSlideAnim; 

	UPROPERTY(EditAnywhere)
	TArray<FText> TextsArray;

	UPROPERTY(EditAnywhere)
	float TextChangeTime;

	UPROPERTY(EditAnywhere)
	float ScaleSpeed;

	UPROPERTY(EditAnywhere)
	float BGScaleSpeed;

	UPROPERTY(EditAnywhere)
	float SlideChangeSpeed;

	UPROPERTY(EditAnywhere)
	float SubtractRotatingSpeed;

private:
	UFUNCTION()
	void AnimateSubtract(const float& DeltaTime);
	
	UFUNCTION()
	void TextTimerTick();
	
	UFUNCTION()
	void GirlScaleTimerTick();

	void BGScaleTick();

	int32 CurrentTextIndex;
	float CurrentTextTime;

	float CurrentSlideTime;

	int32 CurrentSlideIndex;

	TArray<UWidgetAnimation*> Slides;
};
