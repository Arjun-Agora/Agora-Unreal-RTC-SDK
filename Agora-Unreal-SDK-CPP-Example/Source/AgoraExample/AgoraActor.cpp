// Fill out your copyright notice in the Description page of Project Settings.


#include "AgoraActor.h"
#include "Engine/Engine.h"
// Sets default values
AAgoraActor::AAgoraActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAgoraActor::BeginPlay()
{
	Super::BeginPlay();
	if (VideoWidget==nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "please set VideoWidget in AgoraActor");
		return;
	}
	VideoWidget->AddToViewport();
	if (APP_ID=="YOUR_APPID")
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "please input your APP_ID");
		return;
	}
	VideoWidget->InitAgoraWidget(APP_ID, TOKEN, CHANNEL_NAME);
}


// Called every frame
void AAgoraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

