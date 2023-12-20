#include "MetahumanSDKSettingsDetails.h"
#include "MetahumanSDKSettings.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "DetailWidgetRow.h"
#include "Request/MetahumanSDKResponses.h"
#include "Widgets/Input/SButton.h"
#include "HttpModule.h"
#include "HttpManager.h"
#include "Interfaces/IHttpResponse.h"

#define LOCTEXT_NAMESPACE "MetahumanSDKSettingsDetails"
DEFINE_LOG_CATEGORY_STATIC(LogMetahumanSDKSettingsDetails, Log, All);

TSharedRef<IDetailCustomization> FMetahumanSDKSettingsDetails::MakeInstance()
{
	return MakeShareable(new FMetahumanSDKSettingsDetails);
}

bool FMetahumanSDKSettingsDetails::GenerateAPIToken(FString& OutAPIToken)
{
	const UMetahumanSDKSettings* MetahumanSDKSettings = GetDefault<UMetahumanSDKSettings>();
	FString _GeneratedAPIToken = "";
	
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    {
        FHttpModule::Get().SetHttpTimeout(60.0);

        HttpRequest->SetURL(MetahumanSDKSettings->APIURL / TEXT("dh/api/v1/guest-token?engine=unreal"));
        HttpRequest->SetVerb(TEXT("POST"));

        UE_LOG(LogMetahumanSDKSettingsDetails, Log, TEXT("API token request started..."));

	    const double StartTime = FPlatformTime::Seconds();
	    
	    HttpRequest->OnProcessRequestComplete().BindLambda(
	        [&_GeneratedAPIToken, StartTime](FHttpRequestPtr Request, FHttpResponsePtr HttpResponse, bool bConnectedSuccessfully)
	        {
	            UE_LOG(LogMetahumanSDKSettingsDetails, Log, TEXT("API token request finished!"));

	            TSharedPtr<FGenericResponse> OutResponse(new FAPITokenResponse);

	            const double EndTime = FPlatformTime::Seconds();
	            const double RequestDuration = EndTime - StartTime;

	            UE_LOG(LogMetahumanSDKSettingsDetails, Log, TEXT("API token request took %f seconds to complete"), RequestDuration);

	            // Handle critical error peacefully to avoid crash
	            if (HttpResponse != nullptr && HttpResponse->GetResponseCode() == EHttpResponseCodes::Ok)
	            {
	                const double ParseResponseStartTime = FPlatformTime::Seconds();
	                if (OutResponse->PassContentAsBytes())
	                {
	                    OutResponse->ParseResponse(HttpResponse->GetContent());                   
	                }
	                else
	                {
	                    OutResponse->ParseResponse(HttpResponse->GetContentAsString());
	                }

	                const double ParseResponseDuration = FPlatformTime::Seconds() - ParseResponseStartTime;
	                UE_LOG(LogMetahumanSDKSettingsDetails, Log, TEXT("Parsing response took %f seconds to complete"), ParseResponseDuration);
	            }
	            else
	            {
	                OutResponse->bResponseSuccess = false;
	                OutResponse->Error = HttpResponse->GetContentAsString();
	                UE_LOG(LogMetahumanSDKSettingsDetails, Error, TEXT("Request error: %s"), *OutResponse->Error);
	            }

	        	FAPITokenResponse* APITokenResponse = static_cast<FAPITokenResponse*>(OutResponse.Get());
				check(APITokenResponse != nullptr);
	        	_GeneratedAPIToken = APITokenResponse->Token;
	        }
	    );
    }
	HttpRequest->ProcessRequest();
	FHttpModule::Get().GetHttpManager().Flush(EHttpFlushReason::Default);

	OutAPIToken = _GeneratedAPIToken;

	return true;
}

void FMetahumanSDKSettingsDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized;
	DetailBuilder.GetObjectsBeingCustomized(ObjectsBeingCustomized);
	check(ObjectsBeingCustomized.Num() == 1);
	TWeakObjectPtr<UMetahumanSDKSettings> Settings = Cast<UMetahumanSDKSettings>(ObjectsBeingCustomized[0].Get());

	IDetailCategoryBuilder& Category = DetailBuilder.EditCategory("MetahumanSDKSettings");

	// Generate API Token
	// Category.AddCustomRow(LOCTEXT("APITokenGenerator", "APITokenGenerator"))
	// 	.ValueContent()
	// 	[
	// 		SNew(SHorizontalBox)
	// 		+ SHorizontalBox::Slot()
	// 		.Padding(5)
	// 		.AutoWidth()
	// 		[
	// 			SNew(SButton)
	// 			.Text(LOCTEXT("APIToken", "Generate New API Token"))
	// 			.ToolTipText(LOCTEXT("GenerateAPIToken_Tooltip", "Generates a new API token"))
	// 			.OnClicked_Lambda([this, Settings]()
	// 			{
	// 				if (Settings.IsValid() && GenerateAPIToken(Settings->APIToken))
	// 				{
	// 					Settings->TryUpdateDefaultConfigFile();
	// 				}
	// 				else
	// 				{
	// 					// toast?
	// 				}
	//
	// 				return(FReply::Handled());
	// 			})
	// 		]
	// 	];

	// Go to web Personal Account
	Category.AddCustomRow(LOCTEXT("WebAccountButton", "WebAccountButton"))
	.ValueContent()
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.Padding(5)
		.AutoWidth()
		[
			SNew(SButton)
			.Text(LOCTEXT("WebAccount", "Personal Account"))
			.ToolTipText(LOCTEXT("WebAccount_Tooltip", "Opens site with your personal account. "
				"You have to assign old generated token in your account or generate new one. "
				"All tokens outside the personal account will be suspended."))
			.OnClicked_Lambda([this, Settings]()
			{				
				if (Settings.IsValid())
				{
					FPlatformProcess::LaunchURL( *Settings->GetWebAccountUrl(), nullptr, nullptr);	
				}				

				return(FReply::Handled());
			})
		]
	];
}

#undef LOCTEXT_NAMESPACE