// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_Attack.h"

#include "AIController.h"
#include "GRAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Interface/GRBattleInterface.h"

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	APawn* ControllingPawn = Cast<APawn>(OwnerComp.GetAIOwner()->GetPawn());
	if (ControllingPawn == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	APawn* Target = Cast<APawn>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BBKEY_TARGET));
	if (Target == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	auto Battle = Cast<IGRBattleInterface>(ControllingPawn);

	if (Battle == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	Battle->SetAttackDelegate(FOnAttackFinished::CreateLambda([&]
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}));

	Battle->Attack(Target);
	
	return EBTNodeResult::InProgress;
}
