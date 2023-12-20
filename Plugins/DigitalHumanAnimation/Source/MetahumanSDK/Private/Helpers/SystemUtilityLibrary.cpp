#include "Helpers/SystemUtilityLibrary.h"
#include "MetahumanSDKModule.h"
#include "Engine/Engine.h"

#if WITH_EDITOR
#include "Editor/EditorEngine.h"
#include "NotificationHelper.h"
#endif

bool FSystemUtilityLibrary::IsWithEditor()
{
#if WITH_EDITOR
	return true;
#else
	return false;
#endif
}

void FSystemUtilityLibrary::PrintMessage(const ELogVerbosity::Type Verbosity, const FString& Message)
{	
	UE_LOG(LogMetahumanSDK, Warning, TEXT("%s -- %s"), *FString(__FUNCTION__), *Message);

	FColor ScreenMessageColor (FColor::Blue);
	if (Verbosity == ELogVerbosity::Type::Error) ScreenMessageColor = FColor::Red;
	if (Verbosity == ELogVerbosity::Type::Warning) ScreenMessageColor = FColor::Yellow;
		
	GEngine->AddOnScreenDebugMessage(-1, 10.f, ScreenMessageColor, TEXT("Fill API token via Project Settings!"));	
}

void FSystemUtilityLibrary::PrintError(const int32& ErrorCode, const FString& JsonMessage)
{
#if WITH_EDITOR	
	if ( IsValid(GEditor) && GEditor->IsPlayingSessionInEditor() )
	{
		FNotificationHelper::NotifyResponseError(ErrorCode, JsonMessage);
		return;
	}
#endif

	UE_LOG(LogMetahumanSDK, Error, TEXT("%s -- Code: %d, Error: %s"), *FString(__FUNCTION__), ErrorCode, *JsonMessage);
}

void FSystemUtilityLibrary::PrintAccessError(const FString& Message)
{
#if WITH_EDITOR	
	if ( IsValid(GEditor) && GEditor->IsPlayingSessionInEditor() )
	{
		FNotificationHelper::NotifyAccessError(Message);
		return;
	}
#endif

	UE_LOG(LogMetahumanSDK, Error, TEXT("%s -- Access Error: %s"), *FString(__FUNCTION__), *Message);
}

