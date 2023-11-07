#pragma once

#include "CoreMinimal.h"


class METAHUMANSDK_API FSystemUtilityLibrary
{
public:
	static bool IsWithEditor();

	static void PrintMessage(const ELogVerbosity::Type Verbosity, const FString& Message);
	static void PrintError(const int32& ErrorCode, const FString& JsonMessage);
	static void PrintAccessError(const FString& Message);
};
