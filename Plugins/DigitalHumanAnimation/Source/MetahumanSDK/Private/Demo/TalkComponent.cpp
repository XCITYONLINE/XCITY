// Fill out your copyright notice in the Description page of Project Settings.


#include "Demo/TalkComponent.h"

UTalkComponent::UTalkComponent()
{	
	PrimaryComponentTick.bCanEverTick = false;
}void UTalkComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTalkComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

