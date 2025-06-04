// Copyright Epic Games, Inc. All Rights Reserved.

#include "GrandiaGameMode.h"

#include "Player/GrandiaPlayerController.h"
#include "UObject/ConstructorHelpers.h"

AGrandiaGameMode::AGrandiaGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGrandiaPlayerController::StaticClass();
}