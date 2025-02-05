#include "RotateFloor.h"


ARotateFloor::ARotateFloor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotationSpeed = 90.0f;

	PrimaryActorTick.bCanEverTick = true;

}


void ARotateFloor::BeginPlay()
{
	Super::BeginPlay();
	
}


void ARotateFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
}

