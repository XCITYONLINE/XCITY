// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM()
enum class ECameraMode : uint8
{
	ECM_Default UMETA(DisplayName="Default"),
	ECM_Aim UMETA(DisplayName="Aim")
};
