// Copyright Epic Games, Inc. All Rights Reserved.

#include "stassssiiiikkkkGameMode.h"
#include "stassssiiiikkkkCharacter.h"
#include "UObject/ConstructorHelpers.h"

AstassssiiiikkkkGameMode::AstassssiiiikkkkGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
