#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StoneDoor.generated.h"

UCLASS()
class ASSIGNMENT_6_API AStoneDoor : public AActor
{
	GENERATED_BODY()

private:
	bool MoveStoneLocation;
	float Direction;

public:	
	AStoneDoor();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "StoneDoor|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StoneDoor|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StoneDoor|Properties")
	float RotationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StoneDoor|Properties")
	float OffsetSpeed;


	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
