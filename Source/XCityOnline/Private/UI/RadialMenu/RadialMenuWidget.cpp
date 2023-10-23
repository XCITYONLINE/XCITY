// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RadialMenu/RadialMenuWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"
#include "Libraries/XCityWidgetLibrary.h"
#include "Interfaces/RadialMenuSlotInterface.h"
#include "UI/RadialMenu/RadialMenuSlot.h"

void URadialMenuWidget::RefreshRadialMenu()
{
	if (RadialMenuSlotInfos.Num() == 0) return;
	
	for (auto It = RadialMenuSlotInfos.CreateIterator(); It; ++It)
	{
		It->SlotPtr->RefreshSlot_Implementation();
	}
}

URadialMenuWidget::URadialMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RadialMenuSlotClass = nullptr;
	RadialMenuParts = 4;
	RadialMenuSlotInfos.Empty();
	OverallRadialMenuAngle = 360;
	SlotDistanceFromCenter = 150;
}

FReply URadialMenuWidget::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	const float MouseAngle = UXCityWidgetLibrary::ConvertMousePositionIntoAngle(InMouseEvent.GetScreenSpacePosition());
//	UE_LOG(LogTemp, Display, TEXT("%f"), MouseAngle);

	const FRadialMenuSlotInfo& SlotInfo = GetSlotByAngle(MouseAngle);
	check(SlotInfo.SlotPtr);

	if (SlotInfo.SlotPtr == CurrentSelectedSlot)
	{
		return FReply::Handled();
	}
	
	OnSelectedNewSlot(SlotInfo.SlotPtr);
	
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
	
	int32 Index = 0;
	for (float i = OverallRadialMenuAngle / RadialMenuParts; i <= OverallRadialMenuAngle; i += OverallRadialMenuAngle / RadialMenuParts)
	{
		URadialMenuSlot* RadialMenuSlot = CreateWidget<URadialMenuSlot>(GetOwningPlayer(), RadialMenuSlotClass);
		FRadialMenuSlotInfo SlotInfo { FVector2D(i - OverallRadialMenuAngle / RadialMenuParts, i), RadialMenuSlot };

	//	UE_LOG(LogTemp, Display, TEXT("Slot info: X: %f Y: %f"), SlotInfo.AngleRange.X, SlotInfo.AngleRange.Y);
		SetupSlotVisual(SlotInfo);
		
		if (RadialMenuSlot->Implements<URadialMenuSlotInterface>())
		{
			RadialMenuSlotInfos.Add(SlotInfo);

			IRadialMenuSlotInterface::Execute_InitializeSlot(RadialMenuSlot, Index);
		}

		Index++;
	}
}

const FRadialMenuSlotInfo& URadialMenuWidget::GetSlotByAngle(const float& Angle) const
{
	check(RadialMenuSlotInfos.Num() != 0);
	
	for (const auto& RadialMenuSlot : RadialMenuSlotInfos)
	{
		if (Angle >= RadialMenuSlot.AngleRange.X && Angle <= RadialMenuSlot.AngleRange.Y)
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

void URadialMenuWidget::SetupSlotVisual(const FRadialMenuSlotInfo& SlotInfo) const
{
	RadialMenuCanvas->AddChildToCanvas(SlotInfo.SlotPtr);

	const FVector2D ScreenCenter = UXCityWidgetLibrary::GetScreenCenter();
	const FVector2D DirectionalVector = UXCityWidgetLibrary::ConvertAngleIntoDirectionalVector(SlotInfo.AngleRange.X);
		
	UCanvasPanelSlot* CanvasPanelSlot = Cast<UCanvasPanelSlot>(SlotInfo.SlotPtr->Slot);
	if (IsValid(CanvasPanelSlot))
	{
		CanvasPanelSlot->SetPosition(ScreenCenter + SlotDistanceFromCenter * DirectionalVector);
		CanvasPanelSlot->SetSize(SlotInfo.SlotPtr->GetSlotImage()->GetBrush().ImageSize);
	}

	const float SlotRenderAngle = SlotInfo.AngleRange.X;
	SlotInfo.SlotPtr->GetSlotVerticalBox()->SetRenderTransformAngle(SlotRenderAngle);
}