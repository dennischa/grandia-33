// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Battle/GRBattleActionRequest.h"
#include "GRAIController.generated.h"

/**
 * 
 */
UCLASS()
class GRANDIA_API AGRAIController : public AAIController
{
	GENERATED_BODY()

public:
	AGRAIController();
	
	void SetBattleActionRequest(UGRBattleActionRequest* Request);
	void RunAI();
	void StopAI();

protected:
	virtual void OnPossess(APawn* InPawn) override;

private:
	UPROPERTY()
	TObjectPtr<class UBlackboardData> BBAsset;

	UPROPERTY()
	TObjectPtr<class UBehaviorTree> BTAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BattleAction|Request", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UGRBattleActionRequest> CurrentRequest;
};
