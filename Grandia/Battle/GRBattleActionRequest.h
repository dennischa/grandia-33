// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GRBattleAction.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "GRBattleActionRequest.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class UGRBattleActionRequest : public UObject
{
	GENERATED_BODY()

public:
	FORCEINLINE EBattleActionType GetActionType() const { return ActionType; }
	FORCEINLINE AActor* GetTarget() const { return Target.Get(); }

	void ExecuteOnBattleActionFinished(EBTNodeResult::Type Result);

	virtual void SetBlackBoard(UBlackboardComponent* BB);
	
protected:
	virtual void Initialize(bool InShouldMoveToTarget, AActor* InTarget, const FOnBattleActionFinished& InOnBattleActionFinished);
	
	UPROPERTY()
	TWeakObjectPtr<AActor> Target;

	FOnBattleActionFinished OnBattleActionFinished;

	EBattleActionType ActionType;

	bool ShouldMoveToTarget;
};

