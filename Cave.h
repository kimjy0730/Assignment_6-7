#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cave.generated.h"

UCLASS()
class ASSIGNMENT_6_API ACave : public AActor
{
	GENERATED_BODY()
	
public:	

	ACave();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Cave |Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cave |Components")
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;

};
