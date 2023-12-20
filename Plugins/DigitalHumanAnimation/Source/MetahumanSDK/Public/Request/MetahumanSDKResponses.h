#pragma once

#include "CoreMinimal.h"
#include "Dom/JsonObject.h"
#include "Dom/JsonValue.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

class USkeleton;

struct METAHUMANSDK_API FGenericResponse
{
    virtual ~FGenericResponse(){}
    virtual void ParseResponse(const TArray<uint8>&) {};
    virtual void ParseResponse(FString&&) {};
    virtual bool PassContentAsBytes() const 
    { 
        return true;
    }
    
    bool bResponseSuccess = true;
    FString Error;
};

struct METAHUMANSDK_API FATLFrameInfo
{
    TArray<float> CurveValues;
    TArray<FVector> BoneRotations;
};

struct METAHUMANSDK_API FATLResponse : public FGenericResponse
{    
    virtual void ParseResponse(FString&& Content) override
    {
#if WITH_EDITOR
        FFileHelper::SaveStringToFile(Content, *(FPaths::ProjectSavedDir() / TEXT("MetahumanSDK") / TEXT("Temp") / TEXT("AtlResponse.json")));
#endif
        ParseDescription(Content, "");
        ParseFrames(Content, "");      
    }

    void ApplyDescription(const FATLResponse& Description)
    {
        Version = Description.Version;
        Platform = Description.Platform;
        FPS = Description.FPS;
        BlendShapeNames = Description.BlendShapeNames;
        BonesNames = Description.BonesNames;
        AudioUrl = Description.AudioUrl;
        Text = Description.Text;
    }
    
    void ParseDescription(const FString& Content, const FString DebugSaveName = "")
    {       
#if WITH_EDITOR
        if ( !DebugSaveName.IsEmpty() ) FFileHelper::SaveStringToFile(Content, *(FPaths::ProjectSavedDir() / TEXT("MetahumanSDK") / TEXT("Temp") / DebugSaveName));
#endif

        const TSharedRef<TJsonReader<>> Reader = FJsonStringReader::Create(Content);
        if (TSharedPtr<FJsonObject> RootJson; FJsonSerializer::Deserialize(Reader, RootJson))
        {
            if (const TSharedPtr<FJsonObject>* Data; RootJson->TryGetObjectField("data", Data))
            {
                RootJson = *Data;
            }        

            bool bSuccess = RootJson->TryGetStringField(TEXT("version"), Version);
            bSuccess &= RootJson->TryGetStringField(TEXT("platform"), Platform);
            bSuccess &= RootJson->TryGetNumberField(TEXT("fps"), FPS);
            bSuccess &= RootJson->TryGetStringArrayField(TEXT("blendShapesNames"), BlendShapeNames);
            // optional
            RootJson->TryGetStringArrayField(TEXT("bonesNames"), BonesNames);
            RootJson->TryGetStringField(TEXT("media"), AudioUrl);
            RootJson->TryGetStringField(TEXT("chatAnswer"), Text);

            if (!bSuccess) Error = "Parse Description Failed!";
            bResponseSuccess = bSuccess;         
        }
    }

    void ParseFrames(const FString& Content, const FString DebugSaveName = "")
    {
#if WITH_EDITOR
        if ( !DebugSaveName.IsEmpty() ) FFileHelper::SaveStringToFile(Content, *(FPaths::ProjectSavedDir() / TEXT("MetahumanSDK") / TEXT("Temp") / DebugSaveName));
#endif

        Frames.Empty();
        
        const TSharedRef<TJsonReader<>> Reader = FJsonStringReader::Create(Content);
        if (TSharedPtr<FJsonObject> RootJson; FJsonSerializer::Deserialize(Reader, RootJson))
        {
            if (const TArray<TSharedPtr<FJsonValue>>* FramesArray; RootJson->TryGetArrayField(TEXT("frames"), FramesArray))
            {
                for (const TSharedPtr<FJsonValue>& FrameValue : *FramesArray)
                {
                    const TSharedPtr<FJsonObject>& FrameObject = FrameValue->AsObject();

                    FATLFrameInfo FrameInfo;
                    {
                        const TArray<TSharedPtr<FJsonValue>>* BlendshapeValues;
                        if (FrameObject->TryGetArrayField(TEXT("blendshapes"), BlendshapeValues))
                        {
                            for (const TSharedPtr<FJsonValue>& BlendshapeValue : *BlendshapeValues)
                            {
                                FrameInfo.CurveValues.Add(BlendshapeValue->AsNumber());
                            }
                        }

                        const TArray<TSharedPtr<FJsonValue>>* BonesValues;
                        if (FrameObject->TryGetArrayField(TEXT("bones"), BonesValues))
                        {
                            for (const TSharedPtr<FJsonValue>& BoneValue : *BonesValues)
                            {
                                const TArray<TSharedPtr<FJsonValue>>* EulerValues;
                                BoneValue->AsObject()->TryGetArrayField(TEXT("eul"), EulerValues);

                                if (EulerValues->Num() > 2)
                                {
                                    FVector EulerValue((*EulerValues)[0]->AsNumber(), (*EulerValues)[1]->AsNumber(), (*EulerValues)[2]->AsNumber());
                                    FrameInfo.BoneRotations.Add(EulerValue);
                                }
                            }
                        }
                    }

                    Frames.Add(FrameInfo);
                }
            }

            const bool bSuccess = (Frames.Num() > 0) && (Frames[0].CurveValues.Num() == BlendShapeNames.Num());
            if (!bSuccess) Error += " Parse Frames Failed!";            
            bResponseSuccess &= bSuccess;
        }
    }

#if WITH_EDITOR
    // json animation import case
    bool IsValidJsonString(const FString& Content)
    {
        bResponseSuccess = true;
        
        const TSharedRef<TJsonReader<>> Reader = FJsonStringReader::Create(Content);        
        if (TSharedPtr<FJsonObject> RootJson; FJsonSerializer::Deserialize(Reader, RootJson))
        {
            bResponseSuccess &= RootJson->HasField(TEXT("version"));
            bResponseSuccess &= RootJson->HasField(TEXT("platform"));
            bResponseSuccess &= RootJson->HasField(TEXT("fps"));
            bResponseSuccess &= RootJson->HasField(TEXT("frames"));
        }

        return bResponseSuccess;
    }
#endif

    virtual bool PassContentAsBytes() const override
    {
        return false;
    }

    //~ Begin Atl Response Data
        // Description
    FString Version;
    FString Platform;
    int32 FPS;
    TArray<FString> BlendShapeNames;
        // Optional
    FString AudioUrl;
    FString Text;
    TArray<FString> BonesNames;
        // Animation Frames 
    TArray<FATLFrameInfo> Frames;        
    //~ End Atl Response Data
};

struct METAHUMANSDK_API FTTSResponse : public FGenericResponse
{
    virtual void ParseResponse(const TArray<uint8>& InData) override
    {
        // only for debugging
        #if WITH_EDITOR
        FFileHelper::SaveArrayToFile(InData, *(FPaths::ProjectSavedDir() / TEXT("MetahumanSDK") / TEXT("Temp") / TEXT("tts_temp.wav")));
#endif
        
        Data = InData;
    }

    TArray<uint8> Data;
};

struct METAHUMANSDK_API FChatResponse : public FGenericResponse
{
    virtual void ParseResponse(FString&& Content) override
    {
        TSharedRef<TJsonReader<>> Reader = FJsonStringReader::Create(MoveTemp(Content));

        TSharedPtr<FJsonObject> RootJson;
        if (FJsonSerializer::Deserialize(Reader, RootJson))
        {
            RootJson->TryGetStringField(TEXT("reply"), Reply);
        }

        if (!Validate())
        {
            bResponseSuccess = false;
            Error = FString::Printf(TEXT("Invalid Chat response json: %s"), *Content);
        }
    }

    virtual bool PassContentAsBytes() const override
    {
        return false;
    }

    bool Validate() const
    {
        return Reply.Len() > 0;
    }

    FString Reply = "";
};

struct METAHUMANSDK_API FComboResponse : public FGenericResponse
{
    virtual void ParseResponse(const TArray<uint8>& InData) override
    {
        Data = InData;
    }

    TArray<uint8> Data;
};