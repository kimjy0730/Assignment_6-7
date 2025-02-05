#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AssigCharacterController.generated.h"


class UInputMappingContext;
class UInputAction;


UCLASS()
class ASSIGNMENT_6_API AAssigCharacterController : public APlayerController
{
	GENERATED_BODY()
	

public:
	AAssigCharacterController();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SprintAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveForwardAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveRightAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* DefaultMappingContext;
	

protected:
	virtual void BeginPlay() override;
};
