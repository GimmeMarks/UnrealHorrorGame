// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EscapeGameGameMode.generated.h"

UCLASS(minimalapi)
class AEscapeGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEscapeGameGameMode();

	// Call this to display win/game over screens
	void ShowWinScreen();
	void ShowGameOverScreen();

protected:
	// Assign these in the GameMode Blueprint
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> WinScreenClass;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> GameOverScreenClass;

private:
	void ShowScreen(TSubclassOf<class UUserWidget> ScreenClass);
};



