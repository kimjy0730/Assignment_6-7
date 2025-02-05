
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Assig7character.generated.h"

class UCapsuleComponent;	
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
struct FInputActionValue;

UCLASS()
class ASSIGNMENT_6_API AAssig7character : public APawn
{
	GENERATED_BODY()

public:

	AAssig7character();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	USkeletalMeshComponent* SkeletalMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* CameraComp;



protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(const FInputActionValue& value);
	UFUNCTION()
	void MoveRight(const FInputActionValue& value);
	UFUNCTION()
	void StartJump(const FInputActionValue& value);
	UFUNCTION()
	void StopJump(const FInputActionValue& value);
	UFUNCTION()
	void StartSprint(const FInputActionValue& value);
	UFUNCTION()
	void StopSprint(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);

private:

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnSpeed = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float LookSpeed = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float NormalSpeed;

	float SprintSpeedMultiplier;
	float SprintSpeed;
	bool bIsJumping;
	float JumpForce;
	float GravityStrength;
	float MaxJumpHeight;

};
