#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CaveRockRandomPosition.generated.h"

UCLASS()
class ASSIGNMENT_6_API ACaveRockRandomPosition : public AActor
{
	GENERATED_BODY()
	
public:	

	ACaveRockRandomPosition();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomPosition|RockCount")
	int RockCount;

	virtual void BeginPlay() override;

	void SpawnRocks();

};
