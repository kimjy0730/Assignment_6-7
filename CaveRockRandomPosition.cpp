#include "CaveRockRandomPosition.h"
#include "CaveRock.h"


ACaveRockRandomPosition::ACaveRockRandomPosition()
{
 
	PrimaryActorTick.bCanEverTick = false;

	RockCount = 2;

}


void ACaveRockRandomPosition::BeginPlay()
{
	Super::BeginPlay();

    SpawnRocks();
}


void ACaveRockRandomPosition::SpawnRocks()
{
    FVector AreaMin(2000.0f, -2500.0f, 1300.0f);
    FVector AreaMax(14000.0f, 3000.0f, 2500.0f);

    for (int i = 0; i < RockCount; ++i)
    {
        FVector RandomLocation = FMath::RandPointInBox(FBox(AreaMin, AreaMax));
        FRotator RandomRotation = FRotator::ZeroRotator;
        FVector Scale3D(0.06f);

        FTransform SpawnTransform(RandomRotation, RandomLocation, Scale3D);
        FActorSpawnParameters SpawnParams;

        GetWorld()->SpawnActor<ACaveRock>
        (
            ACaveRock::StaticClass(),
            SpawnTransform,
            SpawnParams
        );
    }

}

