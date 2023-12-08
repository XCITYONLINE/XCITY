// Fill out your copyright notice in the Description page of Project Settings.


#include "XCityOnline/Public/UI/MainMenu/TabButtonBase.h"

#include "Components/Button.h"
#include "XCityOnline/Public/UI/MainMenu/TabBase.h"

void UTabButtonBase::InitializeTabButton(UTabBase* ChildTab)
{
	ChildTabPtr = ChildTab;

	K2_InitializeTabButton(ChildTab);
}

void UTabButtonBase::OnDisabled()
{
	bIsSelected = false;
	
	K2_OnDisabled();
}

void UTabButtonBase::OnSelected()
{
	bIsSelected = true;

	K2_OnSelected();
}

void UTabButtonBase::OnHovered()
{
	K2_OnHovered();
}

void UTabButtonBase::OnUnhovered()
{
	K2_OnUnhovered();
}

void UTabButtonBase::OnPressed()
{
	K2_OnPressed();
}

void UTabButtonBase::OnReleased()
{
	K2_OnReleased();
}

void UTabButtonBase::NativeConstruct()
{
	Super::NativeConstruct();
	
	ButtonPtr->OnClicked.AddUniqueDynamic(this, &ThisClass::OnSelected_Internal);
	ButtonPtr->OnHovered.AddUniqueDynamic(this, &ThisClass::OnHovered_Internal);
	ButtonPtr->OnUnhovered.AddUniqueDynamic(this, &ThisClass::OnUnhovered_Internal);
	ButtonPtr->OnPressed.AddUniqueDynamic(this, &ThisClass::OnPressed_Internal);
	ButtonPtr->OnReleased.AddUniqueDynamic(this, &ThisClass::OnReleased_Internal);
}

void UTabButtonBase::OnSelected_Internal()
{
	OnSelected();
}

void UTabButtonBase::OnHovered_Internal()
{
	OnHovered();
}

void UTabButtonBase::OnUnhovered_Internal()
{
	OnUnhovered();
}

void UTabButtonBase::OnPressed_Internal()
{
	OnPressed();
}

void UTabButtonBase::OnReleased_Internal()
{
	OnReleased();
}
