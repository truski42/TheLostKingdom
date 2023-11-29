// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

#include "EngineUtils.h"
#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
#include "TurnBased/ItemComponent.h"

UMyGameInstance::UMyGameInstance()
{
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
		DataToSave->SavedActors.Empty();
		for(FActorIterator It(GetWorld()); It; ++It)
		{
			AActor* Actor = *It;
			if (Actor->FindComponentByClass<UItemComponent>())
			{
				UE_LOG(LogTemp, Warning, TEXT("Name of Actor Saved: %s"), *Actor->GetFName().ToString());
				FActorSaveData ActorSaveData;
				ActorSaveData.Transform = Actor->GetActorTransform();
				ActorSaveData.ActorName = Actor->GetFName();

				FMemoryWriter MemWriter(ActorSaveData.ByteData);

				FObjectAndNameAsStringProxyArchive Ar(MemWriter, true);

				Ar.ArIsSaveGame = true;
				Actor->Serialize(Ar);

				DataToSave->SavedActors.Add(ActorSaveData);
			}
		}
		UGameplayStatics::SaveGameToSlot(DataToSave, "Slot1",0);
	}else if (!UGameplayStatics::DoesSaveGameExist("Slo1", 0))
	{
		CreateSaveFile();
	}
}
// Load game objects
void UMyGameInstance::LoadGame()
{
	if (UGameplayStatics::DoesSaveGameExist("Slot1", 0)){
		UMySaveGame* DataToLoad = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot("Slot1", 0));
		if (DataToLoad == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to load SaveGame Data."));
			return;
		}
		
		UE_LOG(LogTemp, Log, TEXT("Loaded SaveGame Data."));
		for (FActorIterator It(GetWorld()); It; ++It)
		{
			AActor* Actor = *It;
			for (FActorSaveData ActorData : DataToLoad->SavedActors)
			{
				if (ActorData.ActorName == Actor->GetFName())
				{
					Actor->SetActorTransform(ActorData.Transform);

					FMemoryReader MemReader(ActorData.ByteData);

					FObjectAndNameAsStringProxyArchive Ar(MemReader, true);
					Ar.ArIsSaveGame = true;
					// Convert binary array back into actor's variables
					Actor->Serialize(Ar);
					UE_LOG(LogTemp, Warning, TEXT("Name of Actor Loaded: %s"), *Actor->GetFName().ToString());
					break;
				}
			}
		}
	}
}
/*else if(!UGameplayStatics::DoesSaveGameExist("Slot1", 0))
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Game without save"));
	CreateSaveFile();
}*/
