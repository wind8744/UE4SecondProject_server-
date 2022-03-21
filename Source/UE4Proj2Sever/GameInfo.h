// Fill out your copyright notice in the Description page of Project Settings.

// ���� ���
#pragma once

#include "EngineMinimal.h"
#include "DrawDebugHelpers.h"
#include "Engine.h"
#include "EngineGlobals.h"

#include "Networking.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "HAL/Runnable.h"
#include "HAL/RunnableThread.h"

#include "GameInfo.generated.h"

#define PACKET_SIZE	1024

DECLARE_LOG_CATEGORY_EXTERN(UE4Proj2Server, Log, All);
#define	LOG_CALLINFO	(FString(__FUNCTION__) + TEXT("{") + FString::FromInt(__LINE__) + TEXT("}"))
#define	LOG(Format, ...)	UE_LOG(UE4Proj2Server, Warning, TEXT("%s : %s"), *LOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
#define	LOGSTRING(Str)		UE_LOG(UE4Proj2Server, Warning, TEXT("%s : %s"), *LOG_CALLINFO, *Str)

void PrintViewport(float Time, const FColor& Color, const FString& Text);

UENUM(BlueprintType)
enum class ECharAnimType : uint8
{
	GROUND,
	IDLE,
	RUN,
	JUMP,
	FALL,
	ATTACK,
	SKILL,
	DEATH,
};

UENUM(BlueprintType)
enum class ECharJob : uint8
{
	Wizard,
	Knight,
	Archer,
};


struct RecvQueueData
{
	int32 Protocol;
	int32 Length;
	uint8 Packet[PACKET_SIZE];

	RecvQueueData()	:
		Protocol(-1),
		Length(0),
		Packet{}
	{
	}
};

enum class NetworkProtocol
{
	Chat,
	UserConnect
};

USTRUCT(BlueprintType)
struct FCharInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		FString		Name;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		ECharJob	Job;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		int32		HP;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		int32		MP;

};
