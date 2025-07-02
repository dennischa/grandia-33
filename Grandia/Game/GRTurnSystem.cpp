// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/GRTurnSystem.h"

void UGRTurnSystem::Initialize(const TArray<UGRTurnInfo*>& InInfos)
{
	Orders.Empty();
	RemovedUnitIds.Empty();
	
	for (int32 i = 0; i < TURN_LIST_NUM; i++)
	{
		for (int32 j = 0; j < InInfos.Num(); j++)
		{
			Orders.Add(InInfos[j]);
		}
	}
	
	CurrentIndex = -1;
	
	RefreshTurnList();
}

void UGRTurnSystem::AdvanceTurn()
{
	int Count = 0;
	const int32 MaxCount = Orders.Num();

	while (Count < MaxCount)
	{
		CurrentIndex = (CurrentIndex + 1) % MaxCount;
		UGRTurnInfo* Info = Orders[CurrentIndex];

		if (!RemovedUnitIds.Contains(Info->UnitId))
		{
			OnTurnBegin.Broadcast(Info->UnitId);
			break;
		}
	}

	RefreshTurnList();
}

void UGRTurnSystem::RefreshTurnList()
{
	TArray<UGRTurnInfo*> TurnList;
	const int32 MaxCount = Orders.Num();
	int32 Index = CurrentIndex == -1 ? 0 : CurrentIndex;
	int32 Count = 0;

	while ( TurnList.Num() < TURN_LIST_NUM && Count < MaxCount)
	{
		Count++;
		
		Index = Index % MaxCount;
		UGRTurnInfo* Info = Orders[Index];

		if (RemovedUnitIds.Contains(Info->UnitId))
		{
			Index++;
			continue;
		}

		TurnList.Add(Info);
		Index++;
	}

	if (TurnList.Num() > 0)
	{
		OnTurnListUpdated.Broadcast(TurnList);
	}
}

// 캐릭터 사망 시, 턴 제거
void UGRTurnSystem::RemoveUnit(int32 UnitId)
{
	RemovedUnitIds.Add(UnitId);

	RefreshTurnList();
}