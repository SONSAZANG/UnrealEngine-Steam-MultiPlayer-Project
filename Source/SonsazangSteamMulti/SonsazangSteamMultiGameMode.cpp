// Copyright Epic Games, Inc. All Rights Reserved.

#include "SonsazangSteamMultiGameMode.h"
#include "SonsazangSteamMultiCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASonsazangSteamMultiGameMode::ASonsazangSteamMultiGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
