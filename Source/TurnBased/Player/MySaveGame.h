// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
USTRUCT()
struct FActorSaveData
{
	GENERATED_BODY()
public:
	UPROPERTY()
	FName ActorName;

	UPROPERTY()
	FTransform Transform;

	UPROPERTY()
	TArray<uint8> ByteData;
};

USTRUCT()
struct FPlayerSaveData
{
	GENERATED_BODY()

public:
	FPlayerSaveData()
	{
		Location = FVector (-4806.261275, -172.659734,207.889770);
		Rotation = FRotator::ZeroRotator;
		bResumeAtTransform = true;
	}

	UPROPERTY()
	FString PlayerID;
	
	/* Location if player was alive during save */
	UPROPERTY()
	FVector Location;

	/* Orientation if player was alive during save */ 
	UPROPERTY()
	FRotator Rotation;

	/* We don't always want to restore location, and may just resume player at specific respawn point in world. */
	UPROPERTY()
	bool bResumeAtTransform;
};


UCLASS()
class TURNBASED_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	
	UPROPERTY()
	TArray<FPlayerSaveData> SavedPlayers;

	UPROPERTY()
	TArray<FActorSaveData> SavedActors;
	

};
