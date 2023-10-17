// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RadialMenu/RadialMenuSlot.h"

#include "Components/Image.h"

void URadialMenuSlot::OnSelected_Implementation()
{
	
}

void URadialMenuSlot::BeginFocus_Implementation()
{
	if (IsValid(RadialMenuSlotData.HoveredImage))
	{
		SlotImage->SetBrushFromTexture(RadialMenuSlotData.HoveredImage);
	}
}

void URadialMenuSlot::EndFocus_Implementation()
{
	if (IsValid(RadialMenuSlotData.IdleImage))
	{
		SlotImage->SetBrushFromTexture(RadialMenuSlotData.IdleImage);
	}
}

void URadialMenuSlot::InitializeSlot_Implementation()
{
	if (IsValid(RadialMenuSlotData.IdleImage))
	{
		SlotImage->SetBrushFromTexture(RadialMenuSlotData.IdleImage);
	}
}

URadialMenuSlot::URadialMenuSlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SlotImage = nullptr;
	RadialMenuSlotData = FRadialMenuSlotData();
}

