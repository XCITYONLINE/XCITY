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
	K2_OnDisabled();
}

void UTabButtonBase::OnSelected()
{
	if (IsValid(ChildTabPtr))
	{
		ChildTabPtr->OnTabEnabled();
	}

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

void UTabButtonBase::NativeConstruct()
{
	Super::NativeConstruct();
	
	ButtonPtr->OnClicked.AddUniqueDynamic(this, &UTabButtonBase::OnSelected_Internal);
	ButtonPtr->OnHovered.AddUniqueDynamic(this, &UTabButtonBase::OnHovered_Internal);
	ButtonPtr->OnUnhovered.AddUniqueDynamic(this, &UTabButtonBase::OnUnhovered_Internal);
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
