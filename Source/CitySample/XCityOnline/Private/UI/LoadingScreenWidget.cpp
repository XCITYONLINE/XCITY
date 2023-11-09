// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/LoadingScreenWidget.h"
#include "Components/Image.h"

void ULoadingScreenWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	UE_LOG(LogTemp, Display, TEXT("Playing Animation"));
}

void ULoadingScreenWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	const float NewAngle = SubtractImage->GetRenderTransformAngle() + SubtractRotatingSpeed * InDeltaTime;
	SubtractImage->SetRenderTransformAngle(NewAngle);
	UE_LOG(LogTemp, Display, TEXT("Slate tick"));
}
