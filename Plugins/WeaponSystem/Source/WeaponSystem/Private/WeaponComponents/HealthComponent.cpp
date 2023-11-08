// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponComponents/HealthComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "UI/HealthWidgetBase.h"

UHealthComponent::UHealthComponent()
	: MaxHealthValue(100.0f)
	  , RegenHealthValue(2.0f)
	  , DelayAfterStartRegen(3.0f)
	  , HealthRegenSpeed(0.2f)
	  , bRotateToPlayer(false)
	, CurrentHealthValue(MaxHealthValue)
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHealthComponent::SetMaxHealth(const float NewMaxHealth)
{
	if (MaxHealthValue == NewMaxHealth || NewMaxHealth < 0)
	{
		return;
	}

	MaxHealthValue = NewMaxHealth;
}

float UHealthComponent::GetMaxHealth() const
{
	return MaxHealthValue;
}

void UHealthComponent::SetCurrentHealth(const float NewCurrentHealth)
{
	if (CurrentHealthValue == NewCurrentHealth || NewCurrentHealth < 0)
	{
    		return;
	}
    
	CurrentHealthValue = NewCurrentHealth;
}

float UHealthComponent::GetCurrentHealth() const
{
	return CurrentHealthValue;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	ensureMsgf(MaxHealthValue > 0, TEXT("Max Health below zero. Component not initilized. %s"), *GetName());
	ensureMsgf(RegenHealthValue >= 0, TEXT("Regen helath value below zero. Component not initilized. %s"), *GetName());
	ensureMsgf(DelayAfterStartRegen >= 0, TEXT("Delay helath value below zero. Component not initilized. %s"), *GetName());
	ensureMsgf(HealthRegenSpeed >= 0, TEXT("Regen speed value below zero. Component not initilized. %s"), *GetName());

	if (!HealthWidget || !GetOwner())
	{
		return;
	}

	GetOwner()->OnTakeAnyDamage.AddUniqueDynamic(this, &ThisClass::OnOwnerDamaged);
	
	UActorComponent* ActorComponent = GetOwner()->AddComponentByClass(
		UWidgetComponent::StaticClass(),
		false,
		FTransform::Identity,
		false);
	
	ActorComponent->RegisterComponent();
	GetOwner()->AddInstanceComponent(ActorComponent);
	
	HealthWidgetComponentRef = Cast<UWidgetComponent>(ActorComponent);
	HealthWidgetComponentRef->SetRelativeTransform(HealthWidgetOffsetTransform);
	
	UHealthWidgetBase* HealthWidgetBase = CreateWidget<UHealthWidgetBase>(GetWorld(), HealthWidget);
	HealthWidgetBase->InitializeWithOwner(GetOwner());
	
	HealthWidgetComponentRef->SetWidgetSpace(EWidgetSpace::World);
	HealthWidgetComponentRef->SetWidget(HealthWidgetBase);

	CurrentHealthValue = MaxHealthValue;
	OnHealthChanged.Broadcast(CurrentHealthValue, MaxHealthValue);

	if (!bRotateToPlayer)
	{
		PrimaryComponentTick.bCanEverTick = false;
		SetComponentTickEnabled(false);	
	}
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bRotateToPlayer && HealthWidgetComponentRef)
	{
		const FVector PlayerLocation =
			UGameplayStatics::GetPlayerCharacter(this, 0)->GetActorLocation();
		FRotator RotateToPlayer =
			UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), PlayerLocation);

		//RotateToPlayer.Pitch = 0;
		RotateToPlayer.Roll = 0;
		
		HealthWidgetComponentRef->SetWorldRotation(RotateToPlayer);
	}
}

void UHealthComponent::OnOwnerDamaged(
	AActor* DamagedActor,
	float Damage,
	const UDamageType* DamageType,
	AController* InstigatedBy,
	AActor* DamageCauser)
{
	if (DamagedActor == GetOwner())
	{
		ApplyDamage(Damage);
	}
}

void UHealthComponent::ApplyDamage(const float Damage)
{
	GetWorld()->GetTimerManager().ClearTimer(WaitRegenTimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(HealthRegenTimerHandle);
		
	WaitRegenTimerHandle.Invalidate();
	HealthRegenTimerHandle.Invalidate();
	
	if (CurrentHealthValue < Damage)
	{
		CurrentHealthValue = 0;
		OnHealthZeroed.Broadcast();

		K2_OnHealthZeroed();
		return;
	}

	CurrentHealthValue -= Damage;
	OnHealthChanged.Broadcast(CurrentHealthValue, MaxHealthValue);

	WaitForStartRegen();
}

void UHealthComponent::WaitForStartRegen()
{
	FTimerManager& CurrentTimerManager = GetWorld()->GetTimerManager();
	CurrentTimerManager.ClearTimer(WaitRegenTimerHandle);
	
	CurrentTimerManager.SetTimer(WaitRegenTimerHandle, FTimerDelegate::CreateWeakLambda(this, [this]
	{
		RegenStart();
	}),
	DelayAfterStartRegen,
	false);
}

void UHealthComponent::RegenStart()
{
	OnStartHealthRegen.Broadcast();

	FTimerManager& CurrentTimerManager = GetWorld()->GetTimerManager();
	CurrentTimerManager.ClearTimer(HealthRegenTimerHandle);
	
	CurrentTimerManager.SetTimer(HealthRegenTimerHandle, FTimerDelegate::CreateWeakLambda(this, [this]
	{
		ApplyHealthRegen();
	}),
	HealthRegenSpeed,
	true);
}

void UHealthComponent::ApplyHealthRegen()
{
	CurrentHealthValue += RegenHealthValue;
	
	if (CurrentHealthValue >= MaxHealthValue)
	{
		CurrentHealthValue = MaxHealthValue;
		OnStopHealthRegen.Broadcast();

		FTimerManager& CurrentTimerManager = GetWorld()->GetTimerManager();
		CurrentTimerManager.ClearTimer(HealthRegenTimerHandle);
	}

	OnHealthChanged.Broadcast(CurrentHealthValue, MaxHealthValue);
}
