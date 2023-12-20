#pragma once

struct FRequestStatistics
{
	TSharedPtr<FString, ESPMode::ThreadSafe> PrevType;
	FThreadSafeBool PrevComboAtl = false;
	FThreadSafeBool PrevComboChat = false;
	FThreadSafeBool PrevComboTts = false;
	
private:
	int32 PrevSize = 0;
	int64 PrevTime = 0;
	int64 PrevAudioLength = 0;
	
public:

	void UpdateStatistics(const int64 AudioLength)
	{
		FPlatformAtomics::AtomicStore(&PrevAudioLength, AudioLength);
	}
	
	void UpdateStatistics(const FString& RequestName, const bool bCombo)
	{
		PrevType = MakeShared<FString, ESPMode::ThreadSafe>(RequestName);
		UpdateStatistics(bCombo, bCombo, bCombo);
	}

	void UpdateStatistics(const bool bComboAtl, const bool bComboChat, const bool bComboTts)
	{
		PrevComboAtl.AtomicSet(bComboAtl);
		PrevComboChat.AtomicSet(bComboChat);
		PrevComboTts.AtomicSet(bComboTts);
	}
	
	void UpdateStatistics(const FString& RequestName, const bool bComboAtl, const bool bComboChat, const bool bComboTts)
	{
		PrevType = MakeShared<FString, ESPMode::ThreadSafe>(RequestName);
		UpdateStatistics(bComboAtl, bComboChat, bComboTts);
	}	
	
	void UpdateStatisticsWithAudio(const FString& RequestName, const bool bComboAtl, const bool bComboChat, const bool bComboTts, const int64 AudioLength)
	{
		PrevType = MakeShared<FString, ESPMode::ThreadSafe>(RequestName);
		UpdateStatistics(bComboAtl, bComboChat, bComboTts);
		FPlatformAtomics::AtomicStore(&PrevAudioLength, AudioLength);
	}

	void UpdateStatisticsWithAudio(const FString& RequestName, const bool bCombo, const int64 AudioLength)
	{
		PrevType = MakeShared<FString, ESPMode::ThreadSafe>(RequestName);
		UpdateStatistics(bCombo, bCombo, bCombo);
		FPlatformAtomics::AtomicStore(&PrevAudioLength, AudioLength);
	}

	void UpdateStatisticsSizeTime(const int32 Size, const int64 Time)
	{
		FPlatformAtomics::AtomicStore( &PrevSize, Size );
		FPlatformAtomics::AtomicStore( &PrevTime, Time );      
	}	

	int32 GetSize() const
	{
		return FPlatformAtomics::AtomicRead(&PrevSize);
	}

	int64 GetTime() const
	{
		return FPlatformAtomics::AtomicRead(&PrevTime);
	}

	int64 GetAudioLength() const
	{
		return FPlatformAtomics::AtomicRead(&PrevAudioLength);
	}	
};

static FRequestStatistics GRequestStatistics;
