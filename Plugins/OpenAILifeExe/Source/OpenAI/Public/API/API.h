// OpenAI, Copyright LifeEXE. All Rights Reserved.

#pragma once

// https://platform.openai.com/docs/api-reference

namespace OpenAI
{

class IAPI
{
public:
    virtual ~IAPI() = default;
    virtual FString BaseURL() const = 0;

    virtual FString Models() const = 0;
    virtual FString Completion() const = 0;
    virtual FString ChatCompletion() const = 0;
    UE_DEPRECATED("5.3", "Deprecated in OpenAI API")
    virtual FString Edits() const = 0;
    virtual FString ImageGenerations() const = 0;
    virtual FString ImageEdits() const = 0;
    virtual FString ImageVariations() const = 0;
    virtual FString Embeddings() const = 0;
    virtual FString Speech() const = 0;
    virtual FString AudioTranscriptions() const = 0;
    virtual FString AudioTranslations() const = 0;
    virtual FString Files() const = 0;
    UE_DEPRECATED("5.3", "Deprecated in OpenAI API, use fine-tuning job object requests instead")
    virtual FString FineTunes() const = 0;
    virtual FString FineTuningJobs() const = 0;
    virtual FString Moderations() const = 0;
};

namespace V1
{
class OpenAIAPI : public IAPI
{
public:
    OpenAIAPI(const FString& BaseURL = "https://api.openai.com") : API_URL(BaseURL) {}
    virtual FString BaseURL() const override { return API_URL; }

    virtual FString Models() const override { return API_URL + "/v1/models"; }
    virtual FString Completion() const override { return API_URL + "/v1/completions"; }
    virtual FString ChatCompletion() const override { return API_URL + "/v1/chat/completions"; }
    UE_DEPRECATED("5.3", "Deprecated in OpenAI API")
    virtual FString Edits() const override { return API_URL + "/v1/edits"; }
    virtual FString ImageGenerations() const override { return API_URL + "/v1/images/generations"; }
    virtual FString ImageEdits() const override { return API_URL + "/v1/images/edits"; }
    virtual FString ImageVariations() const override { return API_URL + "/v1/images/variations"; }
    virtual FString Embeddings() const override { return API_URL + "/v1/embeddings"; }
    virtual FString Speech() const override { return API_URL + "/v1/audio/speech"; }
    virtual FString AudioTranscriptions() const override { return API_URL + "/v1/audio/transcriptions"; }
    virtual FString AudioTranslations() const override { return API_URL + "/v1/audio/translations"; }
    virtual FString Files() const override { return API_URL + "/v1/files"; }
    UE_DEPRECATED("5.3", "Deprecated in OpenAI API, use fine-tuning job object requests instead")
    virtual FString FineTunes() const override { return API_URL + "/v1/fine-tunes"; }
    virtual FString FineTuningJobs() const override { return API_URL + "/v1/fine_tuning/jobs"; }
    virtual FString Moderations() const override { return API_URL + "/v1/moderations"; }

private:
    const FString API_URL;
};

//
struct FOpenAIEndpoints
{
    FString Models;
    FString Completions;
    FString ChatCompletions;
    FString Edits;
    FString ImageGenerations;
    FString ImageEdits;
    FString ImageVariations;
    FString Embeddings;
    FString Speech;
    FString AudioTranscriptions;
    FString AudioTranslations;
    FString Files;
    FString FineTunes;
    FString FineTuningJobs;
    FString Moderations;
};

class GenericAPI : public OpenAI::IAPI
{
public:
    GenericAPI(const FOpenAIEndpoints& Endpoints) : OpenAIEndpoints(Endpoints) {}

    virtual FString Models() const override { return OpenAIEndpoints.Models; }
    virtual FString Completion() const override { return OpenAIEndpoints.Completions; }
    virtual FString ChatCompletion() const override { return OpenAIEndpoints.ChatCompletions; }
    virtual FString Edits() const override { return OpenAIEndpoints.Edits; }
    virtual FString ImageGenerations() const override { return OpenAIEndpoints.ImageGenerations; }
    virtual FString ImageEdits() const override { return OpenAIEndpoints.ImageEdits; }
    virtual FString ImageVariations() const override { return OpenAIEndpoints.ImageVariations; }
    virtual FString Embeddings() const override { return OpenAIEndpoints.Embeddings; }
    virtual FString Speech() const override { return OpenAIEndpoints.Speech; }
    virtual FString AudioTranscriptions() const override { return OpenAIEndpoints.AudioTranscriptions; }
    virtual FString AudioTranslations() const override { return OpenAIEndpoints.AudioTranslations; }
    virtual FString Files() const override { return OpenAIEndpoints.Files; }
    virtual FString FineTunes() const override { return OpenAIEndpoints.FineTunes; }
    virtual FString FineTuningJobs() const override { return OpenAIEndpoints.FineTuningJobs; }
    virtual FString Moderations() const override { return OpenAIEndpoints.Moderations; }

private:
    const FOpenAIEndpoints OpenAIEndpoints;
    const FString API_URL;

    virtual FString BaseURL() const override { return {}; }
};

}  // namespace V1
}  // namespace OpenAI
