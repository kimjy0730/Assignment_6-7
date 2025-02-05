#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotateFloor.generated.h"

UCLASS()
class ASSIGNMENT_6_API ARotateFloor : public AActor
{
	GENERATED_BODY()
	
public:	

	ARotateFloor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RotateFloor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateFloor|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateFloor|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
