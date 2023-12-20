// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TalkComponent.generated.h"


UCLASS( Abstract, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class METAHUMANSDK_API UTalkComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Talk Component")
	void Talk_Native(const USoundWave* Sound, const UAnimSequence* LipSyncAnim);
	
//~ Begin ActorComponent Interface
public:	
	UTalkComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
protected:
	virtual void BeginPlay() override;
//~ End ActorComponent Interface		
};
