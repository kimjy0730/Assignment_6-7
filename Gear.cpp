#include "Gear.h"


AGear::AGear()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotationSpeed = 90.0f;

	PrimaryActorTick.bCanEverTick = true;

}


void AGear::BeginPlay()
{
	Super::BeginPlay();
	
}


void AGear::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

