#include "WinTrigger.h"
#include "Components/BoxComponent.h"
#include "EscapeGameCharacter.h"
#include "EscapeGameGameMode.h"
#include "Kismet/GameplayStatics.h"

AWinTrigger::AWinTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create the box component and make it the root
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;

	// Set it to act as a trigger
	TriggerBox->SetCollisionProfileName(TEXT("Trigger"));

	// Bind the overlap event
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AWinTrigger::OnOverlapBegin);
}

void AWinTrigger::BeginPlay()
{
	Super::BeginPlay();
}

void AWinTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Check if the overlapping actor is the player
	if (AEscapeGameCharacter* Player = Cast<AEscapeGameCharacter>(OtherActor))
	{
		// Get the game mode and call ShowWinScreen()
		if (AEscapeGameGameMode* GM = Cast<AEscapeGameGameMode>(UGameplayStatics::GetGameMode(this)))
		{
			GM->ShowWinScreen();
		}
	}
}