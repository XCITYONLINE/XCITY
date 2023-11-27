// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XCityOnline/Public/UI/MainMenu/MainMenuTabBase.h"
#include "PlayTab.generated.h"

class UButton;
class URichTextBlock;

/**
 * 
 */
UCLASS()
class CITYSAMPLE_API UPlayTab : public UMainMenuTabBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnNewAIMessageReceived(const FMessage& Message);

	inline static const FString UserRole = "user";
	inline static const FString AssistantRole = "assistant";
	
protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> PlayButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ContinueButton;

	UPROPERTY(EditAnywhere, Category = "Play Tab")
	TSoftObjectPtr<class UWorld> NextLevelInstance;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> AIChatText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> PlayerChatText;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	TObjectPtr<UWidgetAnimation> PlayerBorderAnimIn;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	TObjectPtr<UWidgetAnimation> AIBorderAnimIn;

private:
	UFUNCTION()
	void LoadNextLevel();
};
