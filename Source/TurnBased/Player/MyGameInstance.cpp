// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"

UMyGameInstance::UMyGameInstance()
{
	PlayerLocation = FVector (-4806.261275, -172.659734,207.889770);
	PlayerRotation = FRotator (0.f, 0.f, 0.f);
}


void UMyGameInstance::Init()
{
	Super::Init();
	//FCoreDelegates::OnControllerConnectionChange.AddUObject(this, &UMyGameInstance::"Feature function gamepade");
	LoadGame();
	
}
// Create save file
void UMyGameInstance::CreateSaveFile()
{
	UMySaveGame* DataToSave = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	UGameplayStatics::SaveGameToSlot(DataToSave, "Slot1", 0);
}
// Save game objects
void UMyGameInstance::SaveGame()
{
	UMySaveGame* DataToSave = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot("Slot1", 0));

	if(DataToSave !=nullptr)
	{
		DataToSave->CurrentPlayerLocation = PlayerLocation;
		DataToSave->CurrentPlayerRotation = PlayerRotation;
		UGameplayStatics::SaveGameToSlot(DataToSave, "Slot1",0);
	}else if (!UGameplayStatics::DoesSaveGameExist("Slo1", 0))
	{
		CreateSaveFile();
	}
}
// Load game objects
void UMyGameInstance::LoadGame()
{
	UMySaveGame* DataToLoad = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot("Slot1", 0));

	if(DataToLoad !=nullptr)
	{
		PlayerLocation = DataToLoad->CurrentPlayerLocation;
		PlayerRotation = DataToLoad->CurrentPlayerRotation;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Game Loaded"));

	}else if(!UGameplayStatics::DoesSaveGameExist("Slot1", 0))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Game without save"));
		CreateSaveFile();
	}
}
