// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "ReplicaPlayerComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class REPLICANPC_API UReplicaPlayerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UReplicaPlayerComponent();

public:

	UFUNCTION(BlueprintImplementableEvent)
	void OnReplicaChange();

	UFUNCTION(BlueprintImplementableEvent)
	void OnReplicaComplete();
};
