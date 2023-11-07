// Fill out your copyright notice in the Description page of Project Settings.


#include "Demo/DemoLibrary_BP.h"

#include "Engine/Engine.h"
#include "Runtime/Engine/Public/EngineGlobals.h"
#include "EngineUtils.h"

#include "Demo/TalkComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogDemoLibrary_BP, Log, All);

bool UDemoLibrary_BP::GetNativeTalkComponent(const UObject* WorldContextObject, UTalkComponent*& TalkComponent)
{
	const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World)
	{
		return false;
	}

	for (TActorIterator<AActor> It(World); It; ++It)
	{
		const AActor* Actor = *It;
		TalkComponent = Cast<UTalkComponent>(Actor->FindComponentByClass(UTalkComponent::StaticClass()));
		if(TalkComponent)
		{
			return true;
		}
	}

	return  false;
}
