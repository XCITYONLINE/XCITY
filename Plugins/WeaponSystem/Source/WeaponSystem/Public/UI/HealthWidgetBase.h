// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "HealthWidgetBase.generated.h"

UCLASS()
class WEAPONSYSTEM_API UHealthWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:

	void InitializeWithOwner(UObject* Owner);

public:

	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnHealthChanged(const float CurrentHealth, const float MaxHealth);

	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnHealthZero();

	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnHealthStartRegen();

	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnHealthStopRegen();
};
