#include "Assig7character.h"
#include "AssigCharacterController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"





AAssig7character::AAssig7character()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	RootComponent = CapsuleComp;
	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComp"));
	SkeletalMeshComp->SetupAttachment(CapsuleComp);

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(CapsuleComp);
	SpringArmComp->TargetArmLength = 600.f;
	SpringArmComp->bUsePawnControlRotation = false;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;

	TurnSpeed = 100.f;
	LookSpeed = 100.f;
	NormalSpeed = 700.f;
	SprintSpeedMultiplier = 1.7f;
	SprintSpeed = NormalSpeed * SprintSpeedMultiplier;
	JumpForce = 600.f;
	MaxJumpHeight = 100.f;
	bIsJumping = false;
	GravityStrength = 100.f;

	CapsuleComp->SetSimulatePhysics(false);
	SkeletalMeshComp->SetSimulatePhysics(false);
}


void AAssig7character::BeginPlay()
{
	Super::BeginPlay();

}



void AAssig7character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	if (bIsJumping)
	{
		JumpForce += GravityStrength * DeltaTime; 
		NewLocation.Z += JumpForce * DeltaTime; 

	
		if (NewLocation.Z <= 0.0f)
		{
			NewLocation.Z = 0.0f;
			JumpForce = 0.0f;
			bIsJumping = false;
		}

		SetActorLocation(NewLocation);
	}
}


void AAssig7character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (AAssigCharacterController* PlayerController = Cast<AAssigCharacterController>(GetController()))
		{
			if (PlayerController->MoveForwardAction)
			{
				EnhancedInput->BindAction(PlayerController->MoveForwardAction, ETriggerEvent::Triggered, this, &AAssig7character::MoveForward);
			}
			if (PlayerController->MoveRightAction)
			{
				EnhancedInput->BindAction(PlayerController->MoveRightAction, ETriggerEvent::Triggered, this, &AAssig7character::MoveRight);
			}
			if (PlayerController->JumpAction)
			{
				EnhancedInput->BindAction(PlayerController->JumpAction, ETriggerEvent::Triggered, this, &AAssig7character::StartJump);
				EnhancedInput->BindAction(PlayerController->JumpAction, ETriggerEvent::Completed, this, &AAssig7character::StopJump);
			}
			if (PlayerController->SprintAction)
			{
				EnhancedInput->BindAction(PlayerController->SprintAction, ETriggerEvent::Triggered, this, &AAssig7character::StartSprint);
				EnhancedInput->BindAction(PlayerController->SprintAction, ETriggerEvent::Completed, this, &AAssig7character::StopSprint);
			}
			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(PlayerController->LookAction, ETriggerEvent::Triggered, this, &AAssig7character::Look);
			}
		}
	}
}
void AAssig7character::MoveForward(const FInputActionValue& value)
{
	if (!Controller) return;

	float MoveForwardInput = value.Get<float>();

	if (MoveForwardInput != 0.0f)
	{
		FVector Forward = CameraComp->GetForwardVector();
		Forward.Z = 0.0f;
		Forward.Normalize();
		AddActorLocalOffset(Forward * MoveForwardInput * NormalSpeed * GetWorld()->GetDeltaSeconds(), true);
	}
}

void AAssig7character::MoveRight(const FInputActionValue& value)
{
	float MoveRightInput = value.Get<float>();

	if (MoveRightInput != 0.0f)
	{
		FVector Right = CameraComp->GetRightVector();
		Right.Z = 0.0f; 
		Right.Normalize();
		AddActorLocalOffset(Right * MoveRightInput * NormalSpeed * GetWorld()->GetDeltaSeconds(), true);
	}
}



void AAssig7character::StartJump(const FInputActionValue& value)
{
	if (value.Get<bool>() && !bIsJumping)
	{
		JumpForce = 600.0f; 
		bIsJumping = true;
	}
}

void AAssig7character::StopJump(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
	{
		bIsJumping = false;
	}
}


void AAssig7character::StartSprint(const FInputActionValue& value)
{
	if (value.Get<bool>())
	{
		NormalSpeed = SprintSpeed;
	}
}

void AAssig7character::StopSprint(const FInputActionValue& value)
{
	if (!value.Get<bool>())
	{
		NormalSpeed = 700.0f;  
	}
}

	
void AAssig7character::Look(const FInputActionValue& value)
{
	FVector2D LookInput = value.Get<FVector2D>();

	UE_LOG(LogTemp, Warning, TEXT("Look Input: X = %f, Y = %f"), LookInput.X, LookInput.Y);
	if (LookInput.X != 0.0f) 
	{
		FRotator NewRotation = SpringArmComp->GetRelativeRotation();
		NewRotation.Yaw += LookInput.X * TurnSpeed * GetWorld()->GetDeltaSeconds();
		SpringArmComp->SetRelativeRotation(NewRotation);
	}

	if (LookInput.Y != 0.0f) 
	{
		FRotator NewRotation = SpringArmComp->GetRelativeRotation();
		NewRotation.Pitch -= LookInput.Y * LookSpeed * GetWorld()->GetDeltaSeconds();
		SpringArmComp->SetRelativeRotation(NewRotation);
	}
}



