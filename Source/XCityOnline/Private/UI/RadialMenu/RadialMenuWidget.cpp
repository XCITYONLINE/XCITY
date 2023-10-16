// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RadialMenu/RadialMenuWidget.h"
#include "Libraries/XCityWidgetLibrary.h"
#include "Interfaces/RadialMenuSlotInterface.h"
#include "UI/RadialMenu/RadialMenuSlot.h"

URadialMenuWidget::URadialMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RadialMenuSlotClass = nullptr;
	RadialMenuParts = 4;
	RadialMenuSlotInfos.Empty();
	OverallRadialMenuAngle = 360;
}

FReply URadialMenuWidget::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	const float MouseAngle = UXCityWidgetLibrary::ConvertMousePositionIntoAngle(InMouseEvent.GetScreenSpacePosition());

	const FRadialMenuSlotInfo& SlotInfo = GetSlotByAngle(MouseAngle);
	check(SlotInfo.SlotPtr);

	if (SlotInfo.SlotPtr == CurrentSelectedSlot)
	{
		return FReply::Handled();
	}
	
	OnSelectedNewSlot(SlotInfo.SlotPtr);
	UE_LOG(LogTemp, Display, TEXT("Found new slot with cooridantes: X: %f, Y: %f"), SlotInfo.AngleRange.X, SlotInfo.AngleRange.Y);
	
	return FReply::Handled();
}

void URadialMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	InitRadialMenu();
}

void URadialMenuWidget::InitRadialMenu()
{
	if (!IsValid(RadialMenuSlotClass))
	{
		return;
	}
	
	for (float i = OverallRadialMenuAngle / RadialMenuParts; i <= OverallRadialMenuAngle; i += OverallRadialMenuAngle / RadialMenuParts)
	{
		URadialMenuSlot* RadialMenuSlot = CreateWidget<URadialMenuSlot>(GetOwningPlayer(), RadialMenuSlotClass);
		FRadialMenuSlotInfo SlotInfo { FVector2D(i - OverallRadialMenuAngle / RadialMenuParts, i), RadialMenuSlot };
		
		if (RadialMenuSlot->Implements<URadialMenuSlotInterface>())
		{
			RadialMenuSlotInfos.Add(SlotInfo);

			IRadialMenuSlotInterface::Execute_InitializeSlot(RadialMenuSlot);
		}
	}
}

const FRadialMenuSlotInfo& URadialMenuWidget::GetSlotByAngle(const float& Angle) const
{
	check(RadialMenuSlotInfos.Num() != 0);
	
	for (const auto& RadialMenuSlot : RadialMenuSlotInfos)
	{
		if (Angle > RadialMenuSlot.AngleRange.X && Angle < RadialMenuSlot.AngleRange.Y)
		{
			return RadialMenuSlot;
		}
	}

	return RadialMenuSlotInfos[0];
}

void URadialMenuWidget::OnSelectedNewSlot(URadialMenuSlot* NewSlot)
{
	if (IsValid(CurrentSelectedSlot))
	{
		if (CurrentSelectedSlot->Implements<URadialMenuSlotInterface>())
		{
			IRadialMenuSlotInterface::Execute_EndFocus(CurrentSelectedSlot);
		}
	}
	
	if (NewSlot->Implements<URadialMenuSlotInterface>())
	{
		IRadialMenuSlotInterface::Execute_BeginFocus(NewSlot);
		CurrentSelectedSlot = NewSlot;
	}
}