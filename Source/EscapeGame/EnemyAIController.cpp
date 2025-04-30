// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	// Find the player
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	// Start ticking
	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerPawn)
	{
		TimeSinceLastMove += DeltaTime;

		if (TimeSinceLastMove >= ChaseInterval)
		{
			MoveToActor(PlayerPawn);
			TimeSinceLastMove = 0.0f;
		}
	}
}