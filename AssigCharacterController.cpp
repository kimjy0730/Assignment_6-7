#include "AssigCharacterController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"



AAssigCharacterController::AAssigCharacterController()
	: InputMappingContext(nullptr),
	LookAction(nullptr),
	JumpAction(nullptr),
	SprintAction(nullptr),
	MoveForwardAction(nullptr),
	MoveRightAction(nullptr)
{

}

void AAssigCharacterController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (DefaultMappingContext)
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

