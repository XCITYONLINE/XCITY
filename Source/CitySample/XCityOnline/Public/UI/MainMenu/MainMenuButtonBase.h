// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuTypes.h"
#include "MainMenuButtonBase.generated.h"

class UMainMenuTabBase;

/**
 * 
 */
UCLASS(Abstract)
class CITYSAMPLE_API UMainMenuButtonBase : public UUserWidget
{
	GENERATED_BODY()

public:
	FORCEINLINE const ETabType& GetTabType() const { return ButtonTabType; }
	
	//~ Begin IMainMenuButtonInterface
	virtual void InitializeTabButton(UMainMenuTabBase* ChildTab);
	virtual void OnDisabled();
	virtual void OnSelected();
	virtual void OnHovered();
	virtual void OnUnhovered();
	//~ End IMainMenuButtonInterface

	FORCEINLINE UMainMenuTabBase* GetChildTab() const { return ChildTabPtr; }
	
protected:
	virtual void NativeConstruct() override;

	virtual void InitializeVisual();
	
	UPROPERTY(EditAnywhere, Category = "Main Menu Button Info")
	FSlateColor HoveredTextColor;

	UPROPERTY(EditAnywhere, Category = "Main Menu Button Info")
	FSlateColor UnhoveredTextColor;

	/*
	 * ############################ BLUEPRINT EVENTS #######################
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Button", DisplayName = "InitializeTabButton")
	void K2_InitializeTabButton(UMainMenuTabBase* ChildTab);
	
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

	UPROPERTY(EditAnywhere)
	ETabType ButtonTabType;

private:

	// Just internal functions to handle button events
	UFUNCTION()
	void OnSelected_Internal();

	UFUNCTION()
	void OnHovered_Internal();

	UFUNCTION()
	void OnUnhovered_Internal();

	UPROPERTY()
	TObjectPtr<UMainMenuTabBase> ChildTabPtr;
};
