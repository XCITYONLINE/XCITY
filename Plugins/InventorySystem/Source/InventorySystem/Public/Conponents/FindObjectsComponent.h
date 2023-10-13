// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Contracts/FinderOdjectsInterface.h"

#include "FindObjectsComponent.generated.h"

UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INVENTORYSYSTEM_API UFindObjectsComponent : public UActorComponent,
public IFinderObjectsInterface
{
	GENERATED_BODY()

public:	

	UFindObjectsComponent();

	//IFinderObjectsInterface implements
	virtual bool TryFindInteractibleObjects_Implementation(
		TArray<TScriptInterface<IInteractibleItemInterface>>& OutObjects) override;
	//~

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FindRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<ECollisionChannel> CollisionChannel;

private:

	TArray<TScriptInterface<IInteractibleItemInterface>> PreviousFoundObjects;
};
