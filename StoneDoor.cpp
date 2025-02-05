#include "StoneDoor.h"


AStoneDoor::AStoneDoor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotationSpeed = 250.0f;
	OffsetSpeed = 800.0f;
	
	PrimaryActorTick.bCanEverTick = true;
	MoveStoneLocation = true;
}


void AStoneDoor::BeginPlay()
{
	Super::BeginPlay();
	
}


void AStoneDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	if (CurrentLocation.Y >= 2600)
	{
		MoveStoneLocation = false;
		
	}
	else if (CurrentLocation.Y <= -2200)
	{
		MoveStoneLocation = true;
	}

	Direction = MoveStoneLocation ? 1.0f : -1.0f;
	AddActorWorldRotation(FRotator(0.0f, 0.0f, RotationSpeed * DeltaTime * Direction));
	AddActorWorldOffset(FVector(0.0f, OffsetSpeed * DeltaTime * Direction, 0.0f));
}

