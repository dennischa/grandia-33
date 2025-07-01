// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GRTurnManager.h"
#include "GameFramework/GameModeBase.h"
#include "GrandiaGameMode.generated.h"

UCLASS(minimalapi)
class AGrandiaGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGrandiaGameMode();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Turn, meta=(AllowPrivateAccess=true))
	TObjectPtr<UGRTurnManager> TurnManager;

protected:
	virtual void BeginPlay() override;
};



