// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/GRBattleActionRequest.h"

void UGRAttackBattleActionRequest::Initialize(AActor* InTarget, const FOnBattleActionFinished& InOnBattleActionFinished)
{
	ActionType = EBattleActionType::Attack;
	OnBattleActionFinished = InOnBattleActionFinished;
	Target = InTarget;
}
