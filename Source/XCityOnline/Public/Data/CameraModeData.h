// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CameraModeData.generated.h"

/**
 * 
 */
UCLASS()
class XCITYONLINE_API UCameraModeData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UCameraModeData();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CameraData")
	FVector LocationSocketOffset;
};
