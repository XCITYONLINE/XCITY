// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/LoadingScreenWidget.h"

#include "Animation/WidgetAnimation.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

ULoadingScreenWidget::ULoadingScreenWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	TextsArray.Empty();
	TextChangeTime = 5.0f;
	CurrentTextIndex = 0;
	CurrentTextIndex = 0.0f;
}

void ULoadingScreenWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	AnimateSubtract(InDeltaTime);

	CurrentSlideTime += InDeltaTime;
	if (CurrentSlideTime >= SlideChangeSpeed)
	{
		CurrentSlideIndex = FMath::RandRange(0, Slides.Num() - 1);
		
		if (CurrentSlideIndex >= Slides.Num()) CurrentSlideIndex = 0;
		
		StopAllAnimations();
		PlayAnimation(Slides[CurrentSlideIndex]);

		CurrentSlideTime = 0.0f;
	}
	
	CurrentTextTime += InDeltaTime;
	if (CurrentTextTime >= TextChangeTime)
	{
		TextTimerTick();
		CurrentTextTime = 0.0f;
	}
	
//	GirlScaleTimerTick();
//	BGScaleTick();
}

void ULoadingScreenWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Slides.Add(FirstSlideAnim);
	Slides.Add(SecondSlideAnim);
	Slides.Add(ThirdSlideAnim);
	Slides.Add(FourthSlideAnim);
	Slides.Add(FifthSlideAnim);

	CurrentSlideIndex = FMath::RandRange(0, Slides.Num() - 1);
	PlayAnimation(Slides[CurrentSlideIndex]);
}

void ULoadingScreenWidget::AnimateSubtract(const float& DeltaTime)
{
	const float NewAngle = SubtractImage->GetRenderTransformAngle() + SubtractRotatingSpeed * DeltaTime;
	SubtractImage->SetRenderTransformAngle(NewAngle);
}

void ULoadingScreenWidget::TextTimerTick()
{
	if (!IsValid(LoadingScreenText))
	{
		return;
	}

	CurrentTextIndex++;
	if (CurrentTextIndex >= TextsArray.Num())
	{
		CurrentTextIndex = 0;
	}

	LoadingScreenText->SetText(TextsArray[CurrentTextIndex]);
}

void ULoadingScreenWidget::GirlScaleTimerTick()
{
	const float DeltaTime = GetWorld()->GetDeltaSeconds();

	if (IsValid(GirlImage))
	{
		FWidgetTransform WidgetTransform = GirlImage->GetRenderTransform();
		const float CurrentScale = WidgetTransform.Scale.X;

		FVector2D NewScale {};
		const float NewScaleVal = CurrentScale - BGScaleSpeed * DeltaTime;
		NewScale.X = NewScaleVal; NewScale.Y = NewScaleVal;
		WidgetTransform.Scale = NewScale;
		GirlImage->SetRenderTransform(WidgetTransform);
	}
}

void ULoadingScreenWidget::BGScaleTick()
{
	if (!IsValid(BGCityImage))
	{
		return;
	}

	const float DeltaTime = GetWorld()->GetDeltaSeconds();
	FWidgetTransform WidgetTransform = BGCityImage->GetRenderTransform();
	const float CurrentScale = WidgetTransform.Scale.X;

	FVector2D NewScale {};
	const float NewScaleVal = CurrentScale + BGScaleSpeed * DeltaTime;
	NewScale.X = NewScaleVal; NewScale.Y = NewScaleVal;
	BGCityImage->SetRenderTransform(WidgetTransform);
}
