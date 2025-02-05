#include "AssigGameMode.h"
#include "Assig7character.h"
#include "AssigCharacterController.h"


AAssigGameMode::AAssigGameMode()
{
	DefaultPawnClass = AAssig7character::StaticClass();
	PlayerControllerClass = AAssigCharacterController::StaticClass();

	
}
