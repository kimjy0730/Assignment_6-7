
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stone.generated.h"

UCLASS()
class ASSIGNMENT_6_API AStone : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AStone();

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stone |Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stone |Components")
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
