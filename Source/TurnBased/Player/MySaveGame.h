// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class TURNBASED_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()

	UMySaveGame();
public:
	UPROPERTY(VisibleAnywhere)
	FVector CurrentPlayerLocation;
	
	UPROPERTY(VisibleAnywhere)
	FRotator CurrentPlayerRotation;
	
};
