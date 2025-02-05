#include "Stone.h"


AStone::AStone()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
}


void AStone::BeginPlay()
{
	Super::BeginPlay();
	
}


void AStone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

