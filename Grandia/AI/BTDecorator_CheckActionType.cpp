// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTDecorator_CheckActionType.h"

#include "GRAI.h"
#include "Battle/GRBattleActionRequest.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTDecorator_CheckActionType::UBTDecorator_CheckActionType()
{
	bNotifyDeactivation = true;
}

bool UBTDecorator_CheckActionType::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const auto Request = Cast<UGRBattleActionRequest>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BBKEY_ACTION_REQUEST));

	if (Request)
	{
		UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();

		Request->SetBlackBoard(BB);
	}
	
	return Request != nullptr ? Request->GetActionType() == DesiredAction : false;
}  

void UBTDecorator_CheckActionType::OnNodeDeactivation(FBehaviorTreeSearchData& SearchData, EBTNodeResult::Type NodeResult)
{
	Super::OnNodeDeactivation(SearchData, NodeResult);

	UBlackboardComponent* BB = SearchData.OwnerComp.GetBlackboardComponent();
	UGRBattleActionRequest* Request = Cast<UGRBattleActionRequest>(BB->GetValueAsObject(BBKEY_ACTION_REQUEST));

	if (Request)
	{
		Request->ExecuteOnBattleActionFinished(NodeResult);
		BB->ClearValue(BBKEY_ACTION_REQUEST);
	}
}
