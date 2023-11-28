// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MySaveGame.h"
#include "GameFramework/GameModeBase.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "Engine/DataTable.h"
#include "KingdomGameModeBase.generated.h"

/**
 * 
 */


UCLASS()
class TURNBASED_API AKingdomGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	/* Name of slot to save/load to disk. Can be overriden via InitGame() Options-string */
	FString SlotName;

	UPROPERTY()
	UMySaveGame* CurrentSaveGame;
public:
	
	AKingdomGameModeBase();

	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	//virtual void StartPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void WriteSaveGame();

	//void LoadSaveGame();
};
