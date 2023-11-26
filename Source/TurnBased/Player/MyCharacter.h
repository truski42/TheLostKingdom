// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

class UInputMappingContext;

UCLASS()
class TURNBASED_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SaveGame();

	void LoadGame();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mapping Input")
	//UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* InputToSave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* InputToLoad;

	// Player level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int64 Level;

	//Player current experience
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	float Exp = 0.f;

	//Experience need to level up
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	float NeededExp = 100.f;
	

};
