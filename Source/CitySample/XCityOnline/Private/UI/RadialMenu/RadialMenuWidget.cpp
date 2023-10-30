// Fill out your copyright notice in the Description page of Project Settings.

#include "XCityOnline/Public/UI/RadialMenu/RadialMenuWidget.h"

#include "Blueprint/SlateBlueprintLibrary.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"
#include "Kismet/KismetMathLibrary.h"
#include "XCityOnline/Public/Libraries/XCityWidgetLibrary.h"
#include "XCityOnline/Public/Interfaces/RadialMenuSlotInterface.h"
#include "XCityOnline/Public/UI/RadialMenu/RadialMenuSlot.h"

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
	bIsInitialized = false;
}

FReply URadialMenuWidget::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
/**	const float MouseAngle = GetAngle(InGeometry, InMouseEvent.GetScreenSpacePosition());
	UE_LOG(LogTemp, Display, TEXT("%f"), MouseAngle);

	const FRadialMenuSlotInfo& SlotInfo = GetSlotByAngle(MouseAngle);
	check(SlotInfo.SlotPtr);

	if (SlotInfo.SlotPtr == CurrentSelectedSlot)
	{
		return FReply::Handled();
	}
	
	OnSelectedNewSlot(SlotInfo.SlotPtr);*/
	return FReply::Handled(); 
}

void URadialMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	InitRadialMenu();
}

void URadialMenuWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (IsVisible() && bIsInitialized)
	{
		UpdateRadialMenuState();
	}
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
		FRadialMenuSlotInfo SlotInfo
		{
			FVector2D(i - OverallRadialMenuAngle / RadialMenuParts, i),
			RadialMenuSlot
		};
		
		SetupSlotVisual(SlotInfo);
		
		if (IsValid(RadialMenuSlot) && RadialMenuSlot->Implements<URadialMenuSlotInterface>())
		{
			RadialMenuSlotInfos.Add(SlotInfo);
			IRadialMenuSlotInterface::Execute_InitializeSlot(RadialMenuSlot, Index);
		}

		Index++;
	}

	bIsInitialized = true;
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

	if (IsValid(SlotInfo.SlotPtr.Get()))
	{
		if (UCanvasPanelSlot* CanvasPanelSlot =
			Cast<UCanvasPanelSlot>(SlotInfo.SlotPtr->Slot); IsValid(CanvasPanelSlot))
		{
			CanvasPanelSlot->SetPosition(ScreenCenter + SlotDistanceFromCenter * DirectionalVector);
			CanvasPanelSlot->SetSize(SlotInfo.SlotPtr->GetSlotImage()->GetBrush().ImageSize);
		}

		const float SlotRenderAngle = SlotInfo.AngleRange.X;
		SlotInfo.SlotPtr->GetSlotVerticalBox()->SetRenderTransformAngle(SlotRenderAngle);
	}
}

float URadialMenuWidget::GetAngle(const FGeometry& InGeometry, const FVector2D& MousePosition) const
{
	FVector2D PixelPosition;
	FVector2D ViewportPosition;
	
	USlateBlueprintLibrary::LocalToViewport(GetWorld(), InGeometry, FVector2D(0, 0), PixelPosition, ViewportPosition);

	const FVector2D WidgetCenter = ViewportPosition;
	const FVector2D WidgetTopMiddle { WidgetCenter.X, 0 };

	const FVector2D V1 = (WidgetTopMiddle - WidgetCenter).GetSafeNormal();
	const FVector2D V2 = (MousePosition - WidgetCenter).GetSafeNormal();

	float AngleInDegrees = UKismetMathLibrary::DegAtan2(V2.Y, V2.X) - UKismetMathLibrary::DegAtan2(V1.Y, V1.X);
	if (AngleInDegrees < 0)
	{
		AngleInDegrees = AngleInDegrees + 360;
	}
	return AngleInDegrees;
}

void URadialMenuWidget::UpdateRadialMenuState()
{
	const float MouseAngle = GetAngle(GetCachedGeometry(), UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld()));
	UE_LOG(LogTemp, Display, TEXT("%f"), MouseAngle);

	const FRadialMenuSlotInfo& SlotInfo = GetSlotByAngle(MouseAngle);
	check(SlotInfo.SlotPtr);

	if (SlotInfo.SlotPtr == CurrentSelectedSlot)
	{
		return;
	}
	
	OnSelectedNewSlot(SlotInfo.SlotPtr);
	return;
}
