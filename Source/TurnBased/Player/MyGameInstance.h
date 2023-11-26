// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */

UCLASS()
class TURNBASED_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UMyGameInstance();
	virtual void Init() override;
public:
	//Save game funciton
	void SaveGame();

	//Load game function
	void LoadGame();

	//Create save file
	void CreateSaveFile();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PlayerLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator PlayerRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int64 PlayerLevel;
	
};
