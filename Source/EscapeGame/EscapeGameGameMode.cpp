// Copyright Epic Games, Inc. All Rights Reserved.

#include "EscapeGameGameMode.h"
#include "EscapeGameCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

AEscapeGameGameMode::AEscapeGameGameMode()
	: Super()
{
	// Set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}

void AEscapeGameGameMode::ShowScreen(TSubclassOf<UUserWidget> ScreenClass)
{
	if (ScreenClass)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
		if (PC)
		{
			UUserWidget* Screen = CreateWidget(PC, ScreenClass);
			if (Screen)
			{
				Screen->AddToViewport();
				PC->SetShowMouseCursor(true);
				PC->SetInputMode(FInputModeUIOnly());
				UGameplayStatics::SetGamePaused(GetWorld(), true);
			}
		}
	}
}

void AEscapeGameGameMode::ShowWinScreen()
{
	ShowScreen(WinScreenClass);
}

void AEscapeGameGameMode::ShowGameOverScreen()
{
	ShowScreen(GameOverScreenClass);
}