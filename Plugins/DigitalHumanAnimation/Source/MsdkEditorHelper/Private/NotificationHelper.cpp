#include "NotificationHelper.h"

#include "Editor.h"
#include "Editor/EditorEngine.h"
#include "Editor/EditorStyle/Public/EditorStyle.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Internationalization/Internationalization.h"
#include "Framework/Notifications/NotificationManager.h"

#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"


DEFINE_LOG_CATEGORY_STATIC(LogMsdkEditorHelper, Warning, All);

void FNotificationHelper::NotifyError(const FString& Message, const FString& LaunchUrl, const FString& UrlText)
{						
	UE_LOG(LogMsdkEditorHelper, Error, TEXT("%s"), *Message);
	
	FNotificationInfo Info( FText::FromString(Message) );

	if( !LaunchUrl.IsEmpty() )
	{
		Info.Hyperlink = FSimpleDelegate::CreateStatic( [](FString InUrl)
			{
				FPlatformProcess::LaunchURL( *InUrl, nullptr, nullptr );
			} ,
			LaunchUrl);

		if ( !UrlText.IsEmpty() )
		{
			Info.HyperlinkText = FText::FromString(UrlText);
		}
	}
		
	Info.Image = FAppStyle::GetBrush(TEXT("LevelEditor.RecompileGameCode"));
	Info.FadeInDuration = 2.f;
	Info.FadeOutDuration = 5.f;
	Info.ExpireDuration = 20.f;
	Info.bUseThrobber = false;
	Info.bUseSuccessFailIcons = true;
	Info.bUseLargeFont = true;
	Info.bFireAndForget = false;
	Info.bAllowThrottleWhenFrameRateIsLow = false;
	const auto NotificationItem = FSlateNotificationManager::Get().AddNotification( Info );
	NotificationItem->SetCompletionState(SNotificationItem::CS_Fail);
	NotificationItem->ExpireAndFadeout();
		
	GEditor->PlayEditorSound("/Engine/EditorSounds/Notifications/CompileFailed_Cue.CompileFailed_Cue");
}

void FNotificationHelper::NotifyAccessError(const FString& Message)
{
	const FString LaunchUrl = WebAccUrl;
	const FString UrlText = "Open personal account";
	
	NotifyError(Message, LaunchUrl, UrlText);
}

void FNotificationHelper::NotifyResponseError(const int32& ErrorCode, const FString& JsonMessage)
{
	FString Message ="";
	const TSharedRef<TJsonReader<>> JsonReader = FJsonStringReader::Create(JsonMessage);
	TSharedPtr<FJsonObject> RootJson;
	if (FJsonSerializer::Deserialize(JsonReader, RootJson))
	{
		const TSharedPtr<FJsonObject>* ErrorDescription;
		RootJson->TryGetObjectField(TEXT("detail"), ErrorDescription);

		ErrorDescription->Get()->TryGetStringField("error", Message);		
	}

	if (Message.IsEmpty()) Message = JsonMessage;
	
	const bool bShowWebAccUrl = ( ErrorCode >= 401 && ErrorCode <= 403 );

	FString LaunchUrl = "";
	FString UrlText = "";
	if (bShowWebAccUrl)
	{
		LaunchUrl = WebAccUrl;
		UrlText = "Open personal account";
	}

	NotifyError(Message, LaunchUrl, UrlText);
}

void FNotificationHelper::SetWebAccUrl(const FString& Url)
{
	WebAccUrl = Url;
}	