#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CaveRock.generated.h"

UCLASS()
class ASSIGNMENT_6_API ACaveRock : public AActor
{
	GENERATED_BODY()
	
private:
	FVector InitialLocation;
	FVector ActorScale;
public:	
	ACaveRock();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CaveRock|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CaveRock|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CaveRock|Properties")
	float RotationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CaveRock|Properties")
	float OffsetSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CaveRock|Time")
	float RandomTime;

	
	FTimerHandle TimerHandle;

	void StartFalling();
	void MoveDown();
	void ReturnToInitialPosition();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


};