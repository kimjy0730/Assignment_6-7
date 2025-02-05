#include "CaveRock.h"
#include "TimerManager.h"
#include "Engine/World.h"


ACaveRock::ACaveRock()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	FSoftObjectPath MeshPath(TEXT("/Game/Resources/Props/AddModel/CaveRock_3.CaveRock_3"));
	UStaticMesh* StaticMesh = Cast<UStaticMesh>(MeshPath.TryLoad());
	if (StaticMesh)
	{
		StaticMeshComp->SetStaticMesh(StaticMesh);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Rock_Basalt.M_Rock_Basalt"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	ActorScale = FVector(0.06f);
	
	RotationSpeed = 30.0f;
	OffsetSpeed = -2500.0f;
	RandomTime = FMath::FRandRange(1.0f, 3.5f);
	PrimaryActorTick.bCanEverTick = true;

}
void ACaveRock::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();

	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&ACaveRock::StartFalling,
		RandomTime,
		false
	);
}


void ACaveRock::StartFalling()
{
	
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&ACaveRock::MoveDown,
		0.01f,  
		true   
	);
}

void ACaveRock::MoveDown()
{
	FVector CurrentLocation = GetActorLocation();

	
	if (CurrentLocation.Z >= 0.0f)
	{
		AddActorLocalOffset(FVector(0.0f, 0.0f, OffsetSpeed * GetWorld()->GetDeltaSeconds()));
	}
	else
	{

		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		GetWorld()->GetTimerManager().SetTimer
		(
			TimerHandle,
			this,
			&ACaveRock::ReturnToInitialPosition,
			0.01f,
			false
		);
	}
}

void ACaveRock::ReturnToInitialPosition()
{
	SetActorLocation(InitialLocation);

	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&ACaveRock::StartFalling,
		RandomTime,
		false 
	);
}

void ACaveRock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

