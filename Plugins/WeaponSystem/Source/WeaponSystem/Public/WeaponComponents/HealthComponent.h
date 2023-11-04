// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, Current, float, Max);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChange);

UCLASS( ClassGroup=(Custom), Blueprintable, meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UHealthComponent();
	
protected:
	
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnHealthZeroed();

	UFUNCTION(BlueprintCallable)
	void SetMaxHealth(const float NewMaxHealth);

	UFUNCTION(BlueprintCallable)
	float GetMaxHealth() const;
	
	UFUNCTION(BlueprintCallable)
	void SetCurrentHealth(const float NewCurrentHealth);
	
	UFUNCTION(BlueprintCallable)
	float GetCurrentHealth() const;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChange OnHealthZeroed;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChange OnStartHealthRegen;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChange OnStopHealthRegen;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
	float MaxHealthValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
	float RegenHealthValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
	float DelayAfterStartRegen;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
	float HealthRegenSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health UI Widget")
	TSubclassOf<class UHealthWidgetBase> HealthWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health UI Widget")
	FTransform HealthWidgetOffsetTransform;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health UI Widget")
	bool bRotateToPlayer;

	float CurrentHealthValue;

	UPROPERTY(Transient)
	TObjectPtr<class UWidgetComponent> HealthWidgetComponentRef;

protected:

	UFUNCTION()
	virtual void OnOwnerDamaged(
		AActor* DamagedActor,
		float Damage,
		const class UDamageType* DamageType,
		class AController* InstigatedBy,
		AActor* DamageCauser);
	virtual void ApplyDamage(const float Damage);
	
	void WaitForStartRegen();
	FTimerHandle WaitRegenTimerHandle;

	void RegenStart();
	FTimerHandle HealthRegenTimerHandle;

private:
	
	virtual void ApplyHealthRegen();
};
