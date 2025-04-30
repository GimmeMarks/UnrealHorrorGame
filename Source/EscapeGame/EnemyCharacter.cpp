#include "EnemyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "EscapeGameCharacter.h"
#include "EscapeGameGameMode.h"
#include "Kismet/GameplayStatics.h"

AEnemyCharacter::AEnemyCharacter()
{
	// Use AI Controller and auto possess
	AIControllerClass = AEnemyCharacter::StaticClass();  // Replace with your custom AIController if you have one
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	// Enable overlap detection on capsule
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemyCharacter::OnOverlapBegin);
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();


}

void AEnemyCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (AEscapeGameCharacter* Player = Cast<AEscapeGameCharacter>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy touched the player!"));

		if (AEscapeGameGameMode* GM = Cast<AEscapeGameGameMode>(UGameplayStatics::GetGameMode(this)))
		{
			UE_LOG(LogTemp, Warning, TEXT("Calling ShowGameOverScreen"));
			GM->ShowGameOverScreen();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to cast GameMode"));
		}
	}
}