// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MyGameInstance.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	UMyGameInstance* GameInstance = GetWorld()->GetGameInstance<UMyGameInstance>();
	SetActorLocation(GameInstance->PlayerLocation);
	SetActorRotation(GameInstance->PlayerRotation);
	

	//LoadGame();
	//Set mapping context by default
	/*if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if(UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			SubSystem->AddMappingContext(PlayerMappingContext, 0);
		}
	}*/
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	//PlayerInputComponent->BindAction("IA_Save", IE_Pressed, this, &AMyCharacter::SaveGame);
	//PlayerInputComponent->BindAction("IA_Load", IE_Pressed, this, &AMyCharacter::LoadGame);
	EnhancedInput->BindAction(InputToSave,ETriggerEvent::Started, this, &AMyCharacter::SaveGame);
	EnhancedInput->BindAction(InputToLoad,ETriggerEvent::Started, this, &AMyCharacter::LoadGame);
}

// Save Game
void AMyCharacter::SaveGame()
{
	UMyGameInstance* GameInstance = GetWorld()->GetGameInstance<UMyGameInstance>();
	GameInstance->PlayerLocation = GetActorLocation();
	GameInstance->PlayerRotation = GetActorRotation();
	GameInstance->SaveGame();
	//Log a message to show we have save the game*/
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Game Saved"));
}

// Load Game
void AMyCharacter::LoadGame()
{
}


