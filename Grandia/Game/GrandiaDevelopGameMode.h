// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GrandiaGameMode.h"
#include "GrandiaDevelopGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GRANDIA_API AGrandiaDevelopGameMode : public AGrandiaGameMode
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	// Temp
	TObjectPtr<class UGRTurnInfo> PlayerTurn;
};
