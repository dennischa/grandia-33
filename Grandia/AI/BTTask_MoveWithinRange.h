// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Navigation/PathFollowingComponent.h"
#include "BTTask_MoveWithinRange.generated.h"

/**
 * 
 */
UCLASS()
class GRANDIA_API UBTTask_MoveWithinRange : public UBTTaskNode
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void PostInitProperties() override;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FBlackboardKeySelector TargetKey;

	UPROPERTY(EditAnywhere, Category= "Movement")
	bool bMoveToExactLocation = false;

protected:
	UFUNCTION()
	void OnMoveCompletedHandler(FAIRequestID RequestID, EPathFollowingResult::Type Result);

	TWeakObjectPtr<UBehaviorTreeComponent> CachedOwnerComp;
};
