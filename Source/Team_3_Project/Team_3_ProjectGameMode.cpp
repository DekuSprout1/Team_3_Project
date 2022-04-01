// Copyright Epic Games, Inc. All Rights Reserved.

#include "Team_3_ProjectGameMode.h"
#include "Team_3_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATeam_3_ProjectGameMode::ATeam_3_ProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
