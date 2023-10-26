// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/UI/RadialMenu/RadialMenuSlot.h"
#include "Components/Image.h"
#include "XCityOnline/Public/Components/RadialMenuComponent.h"
#include "XCityOnline/Public/Interfaces/RadialMenuSlotInterface.h"

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

void URadialMenuSlot::InitializeSlot_Implementation(const int32& Index)
{
	if (IsValid(RadialMenuSlotData.IdleImage))
	{
		SlotImage->SetBrushFromTexture(RadialMenuSlotData.IdleImage);
	}

	SlotIndex = Index;
}

void URadialMenuSlot::RefreshSlot_Implementation()
{
	IRadialMenuSlotInterface::RefreshSlot_Implementation();
}

void URadialMenuSlot::NativeConstruct()
{
	Super::NativeConstruct();

	UActorComponent* ActorComponent = GetOwningPlayerPawn()->GetComponentByClass(URadialMenuComponent::StaticClass());
	check(ActorComponent);

	RadialMenuComponent = Cast<URadialMenuComponent>(ActorComponent);
}

URadialMenuSlot::URadialMenuSlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SlotImage = nullptr;
	RadialMenuSlotData = FRadialMenuSlotData();
}

