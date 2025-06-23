// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_MoveWithinRange.h"

#include "AIController.h"
#include "GRAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Interface/GRCharacterStatInterface.h"

EBTNodeResult::Type UBTTask_MoveWithinRange::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	APawn* ControllingPawn = Cast<APawn>(OwnerComp.GetAIOwner()->GetPawn());

	AAIController* Controller = Cast<AAIController>(ControllingPawn->GetController());

	if (Controller == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	FVector TargetLocation;
	float Range = -1.0f;
	
	if (TargetKey.SelectedKeyName == BBKEY_TARGET)
	{
		APawn* Target = Cast<APawn>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BBKEY_TARGET));
		TargetLocation = Target->GetActorLocation();

		auto Stat = Cast<IGRCharacterStatInterface>(ControllingPawn);
		Range = Stat->GetAttackRange() / 2;
	}
	else if (TargetKey.SelectedKeyName == BBKEY_HOMEPOS)
	{
		TargetLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(BBKEY_HOMEPOS);
	}

	float AcceptableDistance = bMoveToExactLocation ? -1.0f : Range;

	Controller->MoveToLocation(TargetLocation, AcceptableDistance);
	Controller->ReceiveMoveCompleted.AddDynamic(this, &UBTTask_MoveWithinRange::OnMoveCompletedHandler);

	CachedOwnerComp = &OwnerComp;
	
	return EBTNodeResult::InProgress;
}

void UBTTask_MoveWithinRange::PostInitProperties()
{
	Super::PostInitProperties();

	//TargetKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_MoveWithinRange, TargetKey), AActor::StaticClass());
}


void UBTTask_MoveWithinRange::OnMoveCompletedHandler(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	if (auto OwnerComp = CachedOwnerComp.Get())
	{
		// 델리게이트 해제
		if (AAIController* Controller = Cast<AAIController>(OwnerComp))
		{
			Controller->ReceiveMoveCompleted.RemoveDynamic(this, &UBTTask_MoveWithinRange::OnMoveCompletedHandler);
		}

		// 이동 성공 여부 체크
		if (Result == EPathFollowingResult::Success)
		{
			FinishLatentTask(*OwnerComp, EBTNodeResult::Succeeded);
		}
		else
		{
			FinishLatentTask(*OwnerComp, EBTNodeResult::Failed);
		}
	}
	
	else
	{
		UE_LOG(LogTemp, Error, TEXT("CachedOwnerComp has not been set"));
	}
}
