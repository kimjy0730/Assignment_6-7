#include "Door.h"
#include "TimerManager.h"

ADoor::ADoor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

    Timer = 5.0f;
}


void ADoor::BeginPlay()
{
    Super::BeginPlay();

 
    GetWorld()->GetTimerManager().SetTimer
    (
        TimerHandle, this, &ADoor::HideActor, Timer, false
    );
}

void ADoor::HideActor()
{
   
    SetActorHiddenInGame(true);
    SetActorEnableCollision(false);


    GetWorld()->GetTimerManager().SetTimer
    (
        TimerHandle, this, &ADoor::ShowActor, Timer, false
    );
}


void ADoor::ShowActor()
{
  
    SetActorHiddenInGame(false);
    SetActorEnableCollision(true);

   
    GetWorld()->GetTimerManager().SetTimer
    (
        TimerHandle, this, &ADoor::HideActor, Timer, false
    );
}


void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

