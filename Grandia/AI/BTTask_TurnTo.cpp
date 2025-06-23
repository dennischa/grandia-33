// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_TurnTo.h"

#include "AIController.h"
#include "GRAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Interface/GRCharacterStatInterface.h"

UBTTask_TurnTo::UBTTask_TurnTo()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_TurnTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	
	return EBTNodeResult::InProgress;
}

void UBTTask_TurnTo::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	APawn* ControllingPawn = Cast<APawn>(OwnerComp.GetAIOwner()->GetPawn());
	if (!ControllingPawn)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	AActor* TargetActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BBKEY_TARGET));
	if (!TargetActor)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	auto Stat = Cast<IGRCharacterStatInterface>(ControllingPawn);
	if (!Stat)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	float TurnSpeed = 20.0f;

	// 목표 방향 계산
	FVector LookVector = TargetActor->GetActorLocation() - ControllingPawn->GetActorLocation();
	LookVector.Z = 0.0f;
	FRotator TargetRot = FRotationMatrix::MakeFromX(LookVector).Rotator();

	// 현재 회전 보간
	FRotator CurrentRot = ControllingPawn->GetActorRotation();
	FRotator NewRot = FMath::RInterpConstantTo(CurrentRot, TargetRot, DeltaSeconds, TurnSpeed);
	ControllingPawn->SetActorRotation(NewRot);

	// 목표 회전에 거의 도달했으면 성공 처리
	float AngleDiff = FMath::Abs((NewRot - TargetRot).Yaw);
	if (AngleDiff < AcceptableAngle)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
