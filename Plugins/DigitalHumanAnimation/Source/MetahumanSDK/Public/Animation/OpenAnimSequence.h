// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimSequence.h"
#include "OpenAnimSequence.generated.h"

/**
 * Anim Sequence with opened interface for runtime manipulations
 */
UCLASS()
class METAHUMANSDK_API UOpenAnimSequence : public UAnimSequence
{
	GENERATED_BODY()

public:

	void SetSequenceLength(const float& Length);
};
