// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame.h"

UMySaveGame::UMySaveGame()
{
	CurrentPlayerLocation = FVector (-4806.261275, -172.659734,207.889770);
	CurrentPlayerRotation = FRotator (0.f, 0.f, 0.f);
	CurrentPlayerLevel = 0;
	CurrentExp = 0.f;
	CurrentNeededExp = 100.f;
}