// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GRBattleAction.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "LevelInstance/LevelInstanceTypes.h"
#include "UObject/NoExportTypes.h"
#include "GRBattleActionRequest.generated.h"

DECLARE_DELEGATE_OneParam(FOnBattleActionFinished, EBTNodeResult::Type);

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
	
	FOnBattleActionFinished OnBattleActionFinished;
	EBattleActionType ActionType;

protected:
	
	UPROPERTY()
	TWeakObjectPtr<AActor> Target;
};

UCLASS()
class UGRAttackBattleActionRequest : public UGRBattleActionRequest
{
	GENERATED_BODY()

public:
	void Initialize(AActor* InTarget, const FOnBattleActionFinished& InOnBattleActionFinished);

};

