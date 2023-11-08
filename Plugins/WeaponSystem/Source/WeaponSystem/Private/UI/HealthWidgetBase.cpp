// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/HealthWidgetBase.h"
#include "WeaponComponents/HealthComponent.h"

void UHealthWidgetBase::InitializeWithOwner(UObject* Owner)
{
	if (const AActor* OwnerActor = Cast<AActor>(Owner))
	{
		if (UHealthComponent* FoundHealthComponent = OwnerActor->FindComponentByClass<UHealthComponent>())
		{
			FoundHealthComponent->OnHealthChanged.AddUniqueDynamic(this, &ThisClass::K2_OnHealthChanged);
			FoundHealthComponent->OnHealthZeroed.AddUniqueDynamic(this, &ThisClass::K2_OnHealthZero);
			FoundHealthComponent->OnStartHealthRegen.AddUniqueDynamic(this, &ThisClass::K2_OnHealthStartRegen);
			FoundHealthComponent->OnStopHealthRegen.AddUniqueDynamic(this, &ThisClass::K2_OnHealthStopRegen);
		}
	}
}
