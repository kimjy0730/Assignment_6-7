#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gear.generated.h"

UCLASS()
class ASSIGNMENT_6_API AGear : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AGear();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gear|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gear|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gear|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
