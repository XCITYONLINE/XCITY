// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RadialMenu/RadialMenuSlot.h"

#include "Components/Image.h"

void URadialMenuSlot::OnSelected_Implementation()
{
	
}

void URadialMenuSlot::BeginFocus_Implementation()
{
	SlotImage->SetBrushTintColor(FSlateColor(FColor::White));
}

void URadialMenuSlot::EndFocus_Implementation()
{
	SlotImage->SetBrushTintColor(FSlateColor(FColor::Black));
}

void URadialMenuSlot::InitializeSlot_Implementation()
{
	SlotImage->SetBrushTintColor(FSlateColor(FColor::Black));
}

