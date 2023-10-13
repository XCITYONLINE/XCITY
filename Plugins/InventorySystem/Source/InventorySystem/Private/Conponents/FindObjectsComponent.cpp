// Fill out your copyright notice in the Description page of Project Settings.

#include "Conponents/FindObjectsComponent.h"

#include "Contracts/InteractibleItemInterface.h"
#include "Kismet/KismetSystemLibrary.h"

UFindObjectsComponent::UFindObjectsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	FindRadius = 300.0f;
	CollisionChannel = ECC_Visibility;
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
	const FVector OwnerLocation = OwnerActor->GetActorLocation();
	
	const bool WasBlocked = UKismetSystemLibrary::SphereTraceMulti(
		this,
		OwnerLocation,
		OwnerLocation,
		FindRadius,
		ETraceTypeQuery { CollisionChannel.GetValue() },
		true,
		{ OwnerActor },
		EDrawDebugTrace::ForOneFrame,
		HitResults,
		true
		);

	if (WasBlocked)
	{
		OutObjects.Empty();
		TArray<TScriptInterface<IInteractibleItemInterface>> IntersectObjects;
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
				const int32 FoundItemIndex = PreviousFoundObjects.Find(NewInteractibleObject);
				
				if (FoundItemIndex != INDEX_NONE)
				{
					IntersectObjects.Add(NewInteractibleObject);
				}
			}
		}
		
		//ToDo: Make algo for management intersection here...
		if (!IntersectObjects.IsEmpty())
		{
			for (const TScriptInterface<IInteractibleItemInterface>& CurrentObject : OutObjects)
			{
				if (IntersectObjects.Find(CurrentObject))
				{
					OutObjects.Remove(CurrentObject);
				}
			}
		}
		//ToDo:~
		
		PreviousFoundObjects = OutObjects;
		return !OutObjects.IsEmpty();
	}

	return WasBlocked;
}
