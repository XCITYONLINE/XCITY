#include "TextToSpeechExtension.h"

#include "AssetToolsModule.h"
#include "UObject/Object.h"
#include "ToolMenus.h"
#include "ContentBrowserMenuContexts.h"
#include "ContentBrowserDataMenuContexts.h"
#include "IContentBrowserDataModule.h"
#include "ContentBrowserDataSubsystem.h"
#include "Sound/SoundWave.h"
#include "MetahumanSDKSoundWaveAssetFactory.h"

#define LOCTEXT_NAMESPACE "TextToSpeechExtension"

void FTextToSpeechExtension::RegisterMenus()
{
	if (!UToolMenus::IsToolMenuUIEnabled())
	{
		return;
	}

	FToolUIAction Action;
	Action.ExecuteAction = FToolMenuExecuteAction::CreateStatic(&FTextToSpeechExtension::ExecuteTextToSpeech);
	Action.CanExecuteAction = FToolMenuCanExecuteAction::CreateStatic(&FTextToSpeechExtension::CanExecuteTextToSpeech);
	Action.IsActionVisibleDelegate = FToolMenuCanExecuteAction::CreateStatic(&FTextToSpeechExtension::CanExecuteTextToSpeech);
	
	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("ContentBrowser.AddNewContextMenu");
	FToolMenuSection& Section = Menu->FindOrAddSection(NAME_None);
	Section.AddMenuEntry(
		"NewSpeech",
		LOCTEXT("SoundWave_CreateTextToSpeech", "Create Speech from Text"),
		LOCTEXT("SoundWave_CreateTextToSpeechTooltip", "Creates a sound wave by executing text-to-speech."),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "ClassIcon.SoundWave"),
		Action
	);
}

bool FTextToSpeechExtension::CanExecuteTextToSpeech(const FToolMenuContext& MenuContext)
{
	UContentBrowserDataMenuContext_AddNewMenu* Context = MenuContext.FindContext<UContentBrowserDataMenuContext_AddNewMenu>();
	return Context && Context->bCanBeModified && Context->SelectedPaths.Num() == 1;
}

void FTextToSpeechExtension::ExecuteTextToSpeech(const FToolMenuContext& MenuContext)
{
	UContentBrowserDataMenuContext_AddNewMenu* Context = MenuContext.FindContext<UContentBrowserDataMenuContext_AddNewMenu>();

	if (!Context || !Context->bCanBeModified || Context->SelectedPaths.Num() != 1)
	{
		return;
	}
	
	const FString DefaultSuffix = TEXT("");
	FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");
	
	// Create the factory used to generate the asset
	UMetahumanSDKSoundWaveAssetFactory* Factory = NewObject<UMetahumanSDKSoundWaveAssetFactory>();
	
	// Determine an appropriate name
	FName ConvertedPath;
	IContentBrowserDataModule::Get().GetSubsystem()->TryConvertVirtualPath(Context->SelectedPaths[0], ConvertedPath);
	
	FString Name;
	FString PackagePath;
	AssetToolsModule.Get().CreateUniqueAssetName(ConvertedPath.ToString() / Factory->GetDefaultNewAssetName(), DefaultSuffix, PackagePath, Name);
	
	// create new asset
	AssetToolsModule.Get().CreateAsset(Name, FPackageName::GetLongPackagePath(PackagePath), USoundWave::StaticClass(), Factory);
}

#undef LOCTEXT_NAMESPACE