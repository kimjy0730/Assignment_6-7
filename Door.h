#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class ASSIGNMENT_6_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	

	ADoor();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door |Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door |Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door |Properties")
	float Timer;


	FTimerHandle TimerHandle;
	void HideActor();
	void ShowActor();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
