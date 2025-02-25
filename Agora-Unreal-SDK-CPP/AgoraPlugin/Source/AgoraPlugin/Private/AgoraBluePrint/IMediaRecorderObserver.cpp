// Fill out your copyright notice in the Description page of Project Settings.


#include "AgoraBluePrint/IMediaRecorderObserver.h"


void AIMediaRecorderObserver::BeginPlay()
{
	Super::BeginPlay();
}


AIMediaRecorderObserver::AIMediaRecorderObserver()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AIMediaRecorderObserver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AIMediaRecorderObserver::onRecorderStateChanged(agora::media::RecorderState state, agora::media::RecorderErrorCode error)
{
	OnRecorderStateChanged.Broadcast((ERecorderState)state, (ERecorderErrorCode)error);
}
void AIMediaRecorderObserver::onRecorderInfoUpdated(const agora::media::RecorderInfo& info)
{
	FRecorderInfo recorderInfo;
	recorderInfo.fileName = FString(info.fileName);
	recorderInfo.durationMs = info.durationMs;
	recorderInfo.fileSize = info.fileSize;
	OnRecorderInfoUpdated.Broadcast(recorderInfo);
}
