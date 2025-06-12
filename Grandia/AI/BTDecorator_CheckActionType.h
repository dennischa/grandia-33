// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "Battle/GRBattleAction.h"
#include "BTDecorator_CheckActionType.generated.h"

/**
 * 
 */
UCLASS()
class GRANDIA_API UBTDecorator_CheckActionType : public UBTDecorator
{
	GENERATED_BODY()

public:
	UBTDecorator_CheckActionType();
	
	UPROPERTY(EditAnywhere, Category="Condition")
	EBattleActionType DesiredAction;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	virtual void OnNodeDeactivation(FBehaviorTreeSearchData& SearchData, EBTNodeResult::Type NodeResult) override;
};
