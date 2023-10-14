// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Contracts/FinderOdjectsInterface.h"

#include "FindObjectsComponent.generated.h"

UENUM()
enum EFinderTraceMode : uint8
{
	FTM_None =				0		UMETA(Hidden),
	FTM_MultiSphereAround = 1 << 1	UMETA(DisplayName = "Multi Sphere Trace"),
	FTM_SingleLineTrace =	1 << 2	UMETA(DisplayName = "Single Line Trace"),
	FTM_Max =				1 << 3	UMETA(Hidden)
};

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
	float TraceOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EFinderTraceMode> TraceMode;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<ECollisionChannel> CollisionChannel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDrawDebug;

private:

	TArray<TScriptInterface<IInteractibleItemInterface>> PreviousFoundObjects;
};
