// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RadialMenu/RadialMenuSlot.h"

#include "Components/Image.h"

void URadialMenuSlot::OnSelected()
{
	
}

void URadialMenuSlot::BeginFocus()
{
	SlotImage->SetBrushTintColor(FSlateColor(FColor::White));
}

void URadialMenuSlot::EndFocus()
{
	SlotImage->SetBrushTintColor(FSlateColor(FColor::Black));
}

void URadialMenuSlot::InitializeSlot()
{
	SlotImage->SetBrushTintColor(FSlateColor(FColor::Black));
}

