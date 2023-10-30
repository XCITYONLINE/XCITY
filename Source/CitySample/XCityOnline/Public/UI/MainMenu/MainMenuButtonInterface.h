// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MainMenuButtonInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UMainMenuButtonInterface : public UInterface
{
	GENERATED_BODY()
};

class IMainMenuTabInterface;

/**
 * 
 */
class CITYSAMPLE_API IMainMenuButtonInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void InitializeTabButton();
	virtual void OnHovered();
	virtual void OnUnhovered();
	virtual void OnSelected();
	virtual void OnDisabled();

	TScriptInterface<IMainMenuTabInterface> GetChildTab() const;
	
private:
	TScriptInterface<IMainMenuTabInterface> ChildTabPtr;
};
