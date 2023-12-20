#pragma once

#include "MetahumanSDKRequestManager.h"

class IHttpRequest;

class FStreamResponseProcessor
{
public:
	
	void ProcessResponse(TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest,
	                     const FResponseCompletedSignature& OnAudioReceived, const FResponseCompletedSignature& OnAnimChunkReceived, const
	                     FResponseCompletedSignature& OnRequestCompleted);
	TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpAnimationRequest;
	
	bool IsProcessing() const;

	void Cleanup();
	
private:
	TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> RequestAudio(FStreamResponseProcessor* StreamResponseProcessor, const FString& AudioUrl, const FResponseCompletedSignature& OnAudioReceived) const;
	TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpAudioRequest;

	void ParseFrames(const FString& InData, const FResponseCompletedSignature& OnParseCompleted) const;
	
	bool IsProcessingValid(const FHttpResponsePtr ResponsePtr, const bool bConnectedSuccessfully, const FString& LogCategory) const;
	bool IsRequestProcessing(const TSharedPtr<IHttpRequest, ESPMode::ThreadSafe>& Request) const;
	
	int32 AnimChunkNum = 0;
	int32 LastProgressUpdateBytes = 0;
	bool bDescriptionReceived = false;

	bool bProcessing = false;
	bool bAnimationReceived = false;
	bool bAudioReceived = false;
	
	// ?Todo replace with weak ptr to prevent memory leaks in lambda
	TSharedPtr<FATLResponse, ESPMode::ThreadSafe> Response = nullptr;
};
