// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM()
enum class ETabType
{
	ETT_Play UMETA(DisplayName = "Play"),
	ETT_Settings UMETA(DisplayName = "Settings"),
	ETT_Store UMETA(DisplayName = "Store"),
	ETT_Club UMETA(DisplayName = "Club")
};