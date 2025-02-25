// Fill out your copyright notice in the Description page of Project Settings.


#include "AgoraBluePrint/IAudioEncodedFrameObserver.h"


void AIPacketObserver::BeginPlay()
{
	Super::BeginPlay();
}


AIPacketObserver::AIPacketObserver()
{
	PrimaryActorTick.bCanEverTick = false;
}


void AIPacketObserver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AIPacketObserver::onSendAudioPacket(agora::rtc::IPacketObserver::Packet& packet)
{
	FPacket pack;
	OnSendAudioPacket.Broadcast(pack);
	unsigned char* tempdata = new unsigned char[pack.size];
	for (int i = 0; i < pack.size; i++)
	{
		tempdata[i] = pack.buffer[i];
	}
	FMemory::Memcpy((void*)packet.buffer, tempdata, pack.size);
	delete[] tempdata;
	packet.size = pack.size;

	return true;
}
bool AIPacketObserver::onSendVideoPacket(agora::rtc::IPacketObserver::Packet& packet)
{
	FPacket pack;
	OnSendVideoPacket.Broadcast(pack);
	unsigned char* tempdata = new unsigned char[pack.size];
	for (int i = 0; i < pack.size; i++)
	{
		tempdata[i] = pack.buffer[i];
	}
	FMemory::Memcpy((void*)packet.buffer, tempdata, pack.size);
	delete[] tempdata;
	packet.size = pack.size;

	return true;
}
bool AIPacketObserver::onReceiveAudioPacket(agora::rtc::IPacketObserver::Packet& packet)
{
	FPacket pack;
	unsigned char* tempdata = new unsigned char[packet.size];
	FMemory::Memcpy((void*)tempdata, packet.buffer, packet.size);
	TArray<int64> callBackdata;
	for (unsigned int i = 0; i < packet.size; i++)
	{
		callBackdata.Add(tempdata[i]);
	}
	delete[] tempdata;
	pack.buffer = callBackdata;
	pack.size = packet.size;
	OnReceiveAudioPacket.Broadcast(pack);
	return true;
}
bool AIPacketObserver::onReceiveVideoPacket(agora::rtc::IPacketObserver::Packet& packet)
{
	FPacket pack;
	unsigned char* tempdata = new unsigned char[packet.size];
	FMemory::Memcpy((void*)tempdata, packet.buffer, packet.size);
	TArray<int64> callBackdata;
	for (unsigned int i = 0; i < packet.size; i++)
	{
		callBackdata.Add(tempdata[i]);
	}
	delete[] tempdata;
	pack.buffer = callBackdata;
	pack.size = packet.size;
	OnReceiveVideoPacket.Broadcast(pack);

	return true;
}

void AIAudioEncodedFrameObserver::OnRecordAudioEncodedFrame(const uint8_t* frameBuffer, int length, const agora::rtc::EncodedAudioFrameInfo& audioEncodedFrameInfo)
{
	FEncodedAudioFrameInfo encodedAudioFrameInfo;
	encodedAudioFrameInfo.codec = (EAUDIO_CODEC_TYPE)audioEncodedFrameInfo.codec;
	encodedAudioFrameInfo.sampleRateHz = audioEncodedFrameInfo.sampleRateHz;
	encodedAudioFrameInfo.samplesPerChannel = audioEncodedFrameInfo.samplesPerChannel;
	encodedAudioFrameInfo.numberOfChannels = audioEncodedFrameInfo.numberOfChannels;
	FEncodedAudioFrameAdvancedSettings advancedSettings;
	advancedSettings.sendEvenIfEmpty = audioEncodedFrameInfo.advancedSettings.sendEvenIfEmpty;
	advancedSettings.speech =audioEncodedFrameInfo.advancedSettings.speech;
	encodedAudioFrameInfo.advancedSettings = advancedSettings;
	encodedAudioFrameInfo.captureTimeMs = audioEncodedFrameInfo.captureTimeMs;
	unsigned char* tempdata = new unsigned char[length];
	FMemory::Memcpy(tempdata,frameBuffer,length);
	TArray<int64> buffer;
	for (int i = 0; i < length; i++)
	{
		buffer.Add(tempdata[i]);
	}
	delete[] tempdata;
	OnRecordAudioEncoded.Broadcast(buffer, length, encodedAudioFrameInfo);
}

void AIAudioEncodedFrameObserver::OnPlaybackAudioEncodedFrame(const uint8_t* frameBuffer, int length, const agora::rtc::EncodedAudioFrameInfo& audioEncodedFrameInfo)
{
	FEncodedAudioFrameInfo encodedAudioFrameInfo;
	encodedAudioFrameInfo.codec = (EAUDIO_CODEC_TYPE)audioEncodedFrameInfo.codec;
	encodedAudioFrameInfo.sampleRateHz = audioEncodedFrameInfo.sampleRateHz;
	encodedAudioFrameInfo.samplesPerChannel = audioEncodedFrameInfo.samplesPerChannel;
	encodedAudioFrameInfo.numberOfChannels = audioEncodedFrameInfo.numberOfChannels;
	FEncodedAudioFrameAdvancedSettings advancedSettings;
	advancedSettings.sendEvenIfEmpty = audioEncodedFrameInfo.advancedSettings.sendEvenIfEmpty;
	advancedSettings.speech = audioEncodedFrameInfo.advancedSettings.speech;
	encodedAudioFrameInfo.advancedSettings = advancedSettings;
	encodedAudioFrameInfo.captureTimeMs = audioEncodedFrameInfo.captureTimeMs;
	unsigned char* tempdata = new unsigned char[length];
	FMemory::Memcpy(tempdata, frameBuffer, length);
	TArray<int64> buffer;
	for (int i = 0; i < length; i++)
	{
		buffer.Add(tempdata[i]);
	}
	delete[] tempdata;
	OnPlaybackAudioEncoded.Broadcast(buffer, length, encodedAudioFrameInfo);
}


void AIAudioEncodedFrameObserver::OnMixedAudioEncodedFrame(const uint8_t* frameBuffer, int length, const agora::rtc::EncodedAudioFrameInfo& audioEncodedFrameInfo)
{
	FEncodedAudioFrameInfo encodedAudioFrameInfo;
	encodedAudioFrameInfo.codec = (EAUDIO_CODEC_TYPE)audioEncodedFrameInfo.codec;
	encodedAudioFrameInfo.sampleRateHz = audioEncodedFrameInfo.sampleRateHz;
	encodedAudioFrameInfo.samplesPerChannel = audioEncodedFrameInfo.samplesPerChannel;
	encodedAudioFrameInfo.numberOfChannels = audioEncodedFrameInfo.numberOfChannels;
	FEncodedAudioFrameAdvancedSettings advancedSettings;
	advancedSettings.sendEvenIfEmpty = audioEncodedFrameInfo.advancedSettings.sendEvenIfEmpty;
	advancedSettings.speech = audioEncodedFrameInfo.advancedSettings.speech;
	encodedAudioFrameInfo.advancedSettings = advancedSettings;
	encodedAudioFrameInfo.captureTimeMs = audioEncodedFrameInfo.captureTimeMs;
	unsigned char* tempdata = new unsigned char[length];
	FMemory::Memcpy(tempdata, frameBuffer, length);
	TArray<int64> buffer;
	for (int i = 0; i < length; i++)
	{
		buffer.Add(tempdata[i]);
	}
	delete[] tempdata;
	OnMixedAudioEncoded.Broadcast(buffer, length, encodedAudioFrameInfo);
}
