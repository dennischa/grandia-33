// Copyright Epic Games, Inc. All Rights Reserved.

#include "GrandiaGameMode.h"

#include "Player/GRPlayerController.h"
#include "UObject/ConstructorHelpers.h"

AGrandiaGameMode::AGrandiaGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGRPlayerController::StaticClass();
}