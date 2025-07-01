// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/GRCharacterStat.h"
#include "GRTurnInfo.generated.h"

constexpr int32 TURN_LIST_NUM = 8;
constexpr int32 TURN_DELAY_TIME = 8;

/**
 * 
 */
UCLASS()
class GRANDIA_API UGRTurnInfo : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EGRCharacterId CharacterId;

	UPROPERTY()
	int32 UnitId;

	UPROPERTY()
	bool bIsPlayer;
};
