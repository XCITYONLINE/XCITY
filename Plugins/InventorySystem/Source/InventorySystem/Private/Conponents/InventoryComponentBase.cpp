// Fill out your copyright notice in the Description page of Project Settings.

#include "Conponents/InventoryComponentBase.h"
#include "Contracts/InventorySystemInterface.h"

UInventoryComponentBase::UInventoryComponentBase()
{
	PrimaryComponentTick.bCanEverTick = false;

	AllItemsValue = 10;
	CurrentInventoryItemIndex = 0;
	SelectedItem = nullptr;
}

void UInventoryComponentBase::SelectItem_Implementation(TScriptInterface<IInteractibleItemInterface>& InNewSelectedItem)
{
	IInventorySystemInterface::Execute_UnselectAllItems(this);
	
	SelectedItem = InNewSelectedItem;
}

void UInventoryComponentBase::OnInitInventorySystem_Implementation()
{
	AllInventoryItems.SetNumZeroed(AllItemsValue);
	//ToDo: Setup inventory from PlayerSaveFile here...
}

void UInventoryComponentBase::OnForwardItemChanged_Implementation()
{
	if (AllInventoryItems.IsEmpty())
	{
		return;
	}
	
	if (AllInventoryItems.Num() > ++CurrentInventoryItemIndex)
	{
		if (const TScriptInterface<IInteractibleItemInterface> NextInventoryItem =
			AllInventoryItems[CurrentInventoryItemIndex]; IsValid(NextInventoryItem.GetObject()))
		{
			SelectedItem = NextInventoryItem;
			IInventorySystemInterface::Execute_UnselectAllItems(this);
			
			if (OnInventoryItemSelected.IsBound())
			{
				OnInventoryItemSelected.Broadcast(SelectedItem);
			}
		}
	}
	else
	{
		CurrentInventoryItemIndex = -1;
		IInventorySystemInterface::Execute_OnForwardItemChanged(this);
	}
}

void UInventoryComponentBase::OnBackwardItemChanged_Implementation()
{
	if (AllInventoryItems.IsEmpty())
	{
		return;
	}
	
	const int32 NewInventoryIndex = --CurrentInventoryItemIndex;
	if (AllInventoryItems.Num() > NewInventoryIndex && NewInventoryIndex >= 0)
	{
		if (const TScriptInterface<IInteractibleItemInterface> PreviousInventoryItem =
			AllInventoryItems[NewInventoryIndex]; IsValid(PreviousInventoryItem.GetObject()))
		{
			SelectedItem = PreviousInventoryItem;
			IInventorySystemInterface::Execute_UnselectAllItems(this);
			
			if (OnInventoryItemSelected.IsBound())
			{
				OnInventoryItemSelected.Broadcast(SelectedItem);
			}
		}
	}
	else if (NewInventoryIndex < 0)
	{
		CurrentInventoryItemIndex = AllInventoryItems.Num();
		IInventorySystemInterface::Execute_OnBackwardItemChanged(this);
	}
}

void UInventoryComponentBase::AddInventoryItem_Implementation(
	TScriptInterface<IInteractibleItemInterface>& InNewInventoryItem)
{
	if (!IsValid(InNewInventoryItem.GetObject()))
	{
		return;
	}
	
	IInventorySystemInterface::Execute_UnselectAllItems(this);
	
	if (const int32 FoundIndexItem =
		AllInventoryItems.Find(InNewInventoryItem); FoundIndexItem == INDEX_NONE)
	{
		AllInventoryItems.Add(InNewInventoryItem);
		SelectedItem = InNewInventoryItem;
		CurrentInventoryItemIndex = 0;

		if (OnInventorySizeChanged.IsBound())
		{
			OnInventorySizeChanged.Broadcast(AllInventoryItems);
		}
	}
}

void UInventoryComponentBase::SetInventoryItem_Implementation(
	TScriptInterface<IInteractibleItemInterface>& InInventoryItem, const int32 InInventoryIndex)
{
	if (AllInventoryItems.Num() < InInventoryIndex &&
		InInventoryIndex >= 0 &&
		IsValid(InInventoryItem.GetObject()))
	{
		AllInventoryItems[InInventoryIndex] = InInventoryItem;
		if (OnInventorySizeChanged.IsBound())
		{
			OnInventorySizeChanged.Broadcast(AllInventoryItems);
		}
	}
}

void UInventoryComponentBase::RemoveInventoryItem_Implementation(
	TScriptInterface<IInteractibleItemInterface>& InInventoryItem)
{
	if (!IsValid(InInventoryItem.GetObject()))
	{
		return;
	}

	IInventorySystemInterface::Execute_UnselectAllItems(this);
	
	if (const int32 RemovedItemIndex = AllInventoryItems.Remove(InInventoryItem);
		RemovedItemIndex != INDEX_NONE)
	{
		CurrentInventoryItemIndex = 0;
		if (OnInventorySizeChanged.IsBound())
		{
			OnInventorySizeChanged.Broadcast(AllInventoryItems);
		}
	}
}

void UInventoryComponentBase::RemoveInventoryItemByIndex_Implementation(const int32 InInventoryIndex)
{
	if (AllInventoryItems.Num() < InInventoryIndex && InInventoryIndex >= 0)
	{
		CurrentInventoryItemIndex = 0;
		AllInventoryItems.RemoveAt(InInventoryIndex);
		IInventorySystemInterface::Execute_UnselectAllItems(this);
		
		if (OnInventorySizeChanged.IsBound())
		{
			OnInventorySizeChanged.Broadcast(AllInventoryItems);
		}
	}
}

TScriptInterface<IInteractibleItemInterface> UInventoryComponentBase::GetSelectedItem_Implementation()
{
	return SelectedItem;
}

void UInventoryComponentBase::GetAllInventoryItems_Implementation(
	TArray<TScriptInterface<IInteractibleItemInterface>>& OutInventoryItems)
{
	OutInventoryItems = AllInventoryItems;
}

void UInventoryComponentBase::UnselectItem_Implementation()
{
	SelectedItem = nullptr;
	if (OnInventoryItemSelected.IsBound())
	{
		OnInventoryItemSelected.Broadcast(SelectedItem);
	}
}

void UInventoryComponentBase::UnselectAllItems_Implementation()
{
	for (TScriptInterface<IInteractibleItemInterface>& CurrentItem : AllInventoryItems)
	{
		IInteractibleItemInterface::Execute_OnUnselect(CurrentItem.GetObject());
	}
}
