// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/GRCharacterStat.h"
#include "GameData/GRTurnInfo.h"
#include "GRTurnSystem.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(FOnTurnListUpdated, const TArray<UGRTurnInfo*>&);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnTurnBegin, const int32);

/**
 * 
 */
UCLASS(Blueprintable)
class GRANDIA_API UGRTurnSystem : public UObject
{
	GENERATED_BODY()

public:
	void Initialize(const TArray<UGRTurnInfo*>& InInfos);
	void AdvanceTurn();
	void RefreshTurnList();
	void RemoveUnit(int32 UnitId);
	
	FOnTurnListUpdated OnTurnListUpdated;

	FOnTurnBegin OnTurnBegin;
	
protected:
	int32 CurrentIndex = -1;
	
	UPROPERTY()
	TArray<UGRTurnInfo*> Orders;
	
	TSet<int32> RemovedUnitIds;
};

