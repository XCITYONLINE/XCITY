// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuTypes.h"
#include "TabBase.h"
#include "TabButtonBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CITYSAMPLE_API UTabButtonBase : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void InitializeTabButton(UTabBase* ChildTab);
	virtual void OnDisabled();
	virtual void OnSelected();
	virtual void OnHovered();
	virtual void OnUnhovered();

	FORCEINLINE const ETabType& GetTabType() const { return ButtonTabType; }
	FORCEINLINE UTabBase* GetChildTab() const { return ChildTabPtr; }

	template <class T>
	T* GetChildTab() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, UTabBase>::Value, "'T' template parameter to GetChildTab must be derived from UTabBase");
		
		if (!IsValid(ChildTabPtr.Get()))
		{
			return nullptr;
		}
		
		return Cast<T>(ChildTabPtr);
	}

protected:
	virtual void NativeConstruct() override;
	
	/*
	 * ############################ BLUEPRINT EVENTS #######################
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Button", DisplayName = "InitializeTabButton")
	void K2_InitializeTabButton(UTabBase* ChildTab);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Button", DisplayName = "OnDisabled")
	void K2_OnDisabled();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Button", DisplayName = "OnSelected")
	void K2_OnSelected();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Button", DisplayName = "OnHovered")
	void K2_OnHovered();

	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Button", DisplayName = "OnUnhovered")
	void K2_OnUnhovered();

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> ButtonPtr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> ButtonTextPtr;
	
private:
	UPROPERTY()
	ETabType ButtonTabType;
	
	UPROPERTY()
	TObjectPtr<UTabBase> ChildTabPtr;

	// Just internal functions to handle button events
	UFUNCTION()
	void OnSelected_Internal();

	UFUNCTION()
	void OnHovered_Internal();

	UFUNCTION()
	void OnUnhovered_Internal();
};
