#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WinTrigger.generated.h"

UCLASS()
class ESCAPEGAME_API AWinTrigger : public AActor
{
	GENERATED_BODY()

public:
	AWinTrigger();

protected:
	virtual void BeginPlay() override;

	// Box component to detect overlap
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* TriggerBox;

	// Overlap event function
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};