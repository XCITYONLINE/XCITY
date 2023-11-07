// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/OpenAnimSequence.h"

void UOpenAnimSequence::SetSequenceLength(const float& Length)
{
	PRAGMA_DISABLE_DEPRECATION_WARNINGS
	SequenceLength = Length;
	PRAGMA_ENABLE_DEPRECATION_WARNINGS
}
