// Fill out your copyright notice in the Description page of Project Settings.

#include "Conponents/FindObjectsComponent.h"
#include "Camera/CameraComponent.h"
#include "Conponents/InventoryComponentBase.h"
#include "Contracts/InteractibleItemInterface.h"
#include "Kismet/KismetSystemLibrary.h"

UFindObjectsComponent::UFindObjectsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
	FindRadius = 300.0f;
	CollisionChannel = ECollisionChannel::ECC_Visibility;
	TraceOffset = 0.0f;
	TraceMode = EFinderTraceMode::FTM_MultiSphereAround;
	bDrawDebug = false;
}

void UFindObjectsComponent::ResetPreviousItems_Implementation()
{
	PreviousFoundObjects.Empty();
}

bool UFindObjectsComponent::TryFindInteractibleObjects_Implementation(
	TArray<TScriptInterface<IInteractibleItemInterface>>& OutObjects)
{
	AActor* OwnerActor = GetOwner();
	if (!IsValid(OwnerActor))
	{
		OutObjects.Empty();
		return false;
	}

	TArray<FHitResult> HitResults;
	bool WasBlocked = false;

	switch (TraceMode.GetValue())
	{
		case FTM_MultiSphereAround:
			{
				const FVector StartTraceLocation = OwnerActor->GetActorLocation();
				const FVector EndTraceLocation =
					StartTraceLocation + OwnerActor->GetActorForwardVector() * TraceOffset;
				
				WasBlocked = UKismetSystemLibrary::SphereTraceMulti(
				this,
				StartTraceLocation,
				EndTraceLocation,
				FindRadius,
				ETraceTypeQuery { CollisionChannel.GetValue() },
				true,
				{ OwnerActor },
				bDrawDebug ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None,
				HitResults,
				true
				);
				
				break;
			}
		
		case FTM_SingleLineTrace:
			{
				FHitResult HitResult;
				UActorComponent* CameraComponent =
					OwnerActor->FindComponentByClass(UCameraComponent::StaticClass());
				UCameraComponent* CurrentCameraComponent = Cast<UCameraComponent>(CameraComponent);

				const FVector StartTraceLocation = IsValid(CurrentCameraComponent)
				? CurrentCameraComponent->GetComponentLocation()
				: OwnerActor->GetActorLocation();
				
				const FVector DirectionTraceLocation = IsValid(CurrentCameraComponent)
				? CurrentCameraComponent->GetForwardVector()
				: OwnerActor->GetActorForwardVector();
				
				const FVector EndTraceLocation = StartTraceLocation + DirectionTraceLocation * TraceOffset;
				
				WasBlocked = UKismetSystemLibrary::LineTraceSingle(
					this,
					StartTraceLocation,
					EndTraceLocation,
					ETraceTypeQuery { CollisionChannel.GetValue() },
					true,
					{ OwnerActor },
					bDrawDebug ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None,
					HitResult,
					true);

				if (WasBlocked)
				{
					HitResults.Add(HitResult);
				}
				
				break;
			}
	}

	if (WasBlocked)
	{
		UActorComponent* InventoryComponent = OwnerActor->FindComponentByClass<UInventoryComponentBase>();
		TArray<TScriptInterface<IInteractibleItemInterface>> InventoryItems;
		if (IsValid(InventoryComponent) && InventoryComponent->Implements<UInventorySystemInterface>())
		{
			IInventorySystemInterface::Execute_GetAllInventoryItems(InventoryComponent, InventoryItems);
		}

		for (const TScriptInterface<IInteractibleItemInterface>& CurrentInventoryItem : InventoryItems)
		{
			if (PreviousFoundObjects.Find(CurrentInventoryItem) != INDEX_NONE)
			{
				PreviousFoundObjects.Remove(CurrentInventoryItem);
			}
		}
		
		OutObjects.Empty();
		for (const FHitResult& HitResult : HitResults)
		{
			if (HitResult.bBlockingHit &&
			IsValid(HitResult.GetActor()) &&
			HitResult.GetActor()->Implements<UInteractibleItemInterface>())
			{
				TScriptInterface<IInteractibleItemInterface> NewInteractibleObject;
				NewInteractibleObject.SetInterface(Cast<IInteractibleItemInterface>(HitResult.GetActor()));
				NewInteractibleObject.SetObject(HitResult.GetActor());
				
				OutObjects.Add(NewInteractibleObject);
			}
		}
		
		TArray<TScriptInterface<IInteractibleItemInterface>> UniqueObjects;
		for (auto NewFoundObject : OutObjects)
		{
			if (PreviousFoundObjects.Find(NewFoundObject) == INDEX_NONE)
			{
				UniqueObjects.Add(NewFoundObject);
			}
		}

		TArray<TScriptInterface<IInteractibleItemInterface>> OldObjects;
		for (auto PreviousFoundObject : PreviousFoundObjects)
		{
			if (OutObjects.Find(PreviousFoundObject) == INDEX_NONE)
			{
				IInteractibleItemInterface::Execute_K2_OnHover(PreviousFoundObject.GetObject(), false);
			}
		}

		PreviousFoundObjects = OutObjects;
		OutObjects = UniqueObjects;
		
		return !OutObjects.IsEmpty();
	}
	
	for (auto PreviousFoundObject : PreviousFoundObjects)
	{
		IInteractibleItemInterface::Execute_K2_OnHover(PreviousFoundObject.GetObject(), false);
	}
	
	PreviousFoundObjects.Empty();
	return WasBlocked;
}
