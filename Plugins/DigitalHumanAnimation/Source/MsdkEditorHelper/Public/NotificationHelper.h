#pragma once
#include "CoreMinimal.h"

class MSDKEDITORHELPER_API FNotificationHelper
{
public:
	static void NotifyError(const FString& Message, const FString& LaunchUrl = "", const FString& UrlText = "");	
	static void NotifyAccessError(const FString& Message);
	static void NotifyResponseError(const int32& ErrorCode, const FString& JsonMessage);

	static void SetWebAccUrl(const FString& Url);

private:
	static inline FString WebAccUrl = "";
};
