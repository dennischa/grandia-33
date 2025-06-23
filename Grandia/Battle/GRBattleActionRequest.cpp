// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/GRBattleActionRequest.h"

#include "AI/GRAI.h"
#include "BehaviorTree/BlackboardComponent.h"

void UGRBattleActionRequest::Initialize(bool InShouldMoveToTarget, AActor* InTarget,
                                        const FOnBattleActionFinished& InOnBattleActionFinished)
{
	ActionType = EBattleActionType::None;
	
	ShouldMoveToTarget = InShouldMoveToTarget;
	OnBattleActionFinished = InOnBattleActionFinished;
	Target = InTarget;
}

void UGRBattleActionRequest::ExecuteOnBattleActionFinished(EBTNodeResult::Type Result)
{
	OnBattleActionFinished.ExecuteIfBound(Result);
}

void UGRBattleActionRequest::SetBlackBoard(UBlackboardComponent* BB)
{
	BB->SetValueAsObject(BBKEY_TARGET, Target.Get());
}
