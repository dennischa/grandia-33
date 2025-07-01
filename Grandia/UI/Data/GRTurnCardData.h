// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/GRCharacterStat.h"
#include "GRTurnCardData.generated.h"

/**
 * 
 */
UCLASS()
class GRANDIA_API UGRTurnCardData : public UObject
{
	GENERATED_BODY()

public:
	void Initialize();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = TurnCard, meta = (AllowPrivateAccess = "true"))
	uint8 bIsPlayer : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = TurnCard, meta = (AllowPrivateAccess = "true"))
	EGRCharacterId CharacterId;
};
