// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GRAIController.h"

#include "GRAI.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Interface/GRBattleInterface.h"

AGRAIController::AGRAIController()
{
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBAssetRef(TEXT("/Script/AIModule.BlackboardData'/Game/Grandia/AI/BB_GRCharacter.BB_GRCharacter'"));
	if (BBAssetRef.Object != nullptr)
	{
		BBAsset = BBAssetRef.Object;
	}
	
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTAssetRef(TEXT("/Game/Grandia/AI/BT_GRCharacter.BT_GRCharacter"));
	if (BTAssetRef.Succeeded())
	{
		BTAsset = BTAssetRef.Object;
	}
}

void AGRAIController::SetBattleActionRequest(UGRBattleActionRequest* Request)
{
	// Battle
	auto Battle = Cast<IGRBattleInterface>(GetPawn());
	if (Battle)
	{
		Battle->SetBattleActionRequest(Request);
	}
	
	// Request
	CurrentRequest = Request;
	
	if (UBlackboardComponent* BlackboardPtr = Blackboard.Get())
	{
		BlackboardPtr->SetValueAsObject(BBKEY_ACTION_REQUEST, Request);
	}
}

void AGRAIController::RunAI()
{
	UBlackboardComponent* BlackboardPtr = Blackboard.Get();
	if (UseBlackboard(BBAsset, BlackboardPtr))
	{
		Blackboard->SetValueAsVector(BBKEY_HOMEPOS, GetPawn()->GetActorLocation());
		
		bool RunResult = RunBehaviorTree(BTAsset);
		ensure(RunResult);
	}
}

void AGRAIController::StopAI()
{
	UBehaviorTreeComponent* BTComponent = Cast<UBehaviorTreeComponent>(BrainComponent);
	if (BTComponent)
	{
		BTComponent->StopTree();
	}
}

void AGRAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	RunAI();
}
