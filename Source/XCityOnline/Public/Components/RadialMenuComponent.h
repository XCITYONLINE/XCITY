// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Contracts/InteractibleItemInterface.h"
#include "WeaponSystem/Public/DataStructs/WeaponsDataStruct.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RadialMenuComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XCITYONLINE_API URadialMenuComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	URadialMenuComponent();

	void GetItemsByType(const EWeaponType& InWeaponType, TMap<int32, TScriptInterface<IInteractibleItemInterface>>& OutItemsByType) const;
};
