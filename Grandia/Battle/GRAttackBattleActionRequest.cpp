#include "GRAttackBattleActionRequest.h"

void UGRAttackBattleActionRequest::Initialize(bool InShouldMoveToTarget, AActor* InTarget, const FOnBattleActionFinished& InOnBattleActionFinished)
{
	Super::Initialize(InShouldMoveToTarget, InTarget, InOnBattleActionFinished);

	ActionType = EBattleActionType::Attack;
}

void UGRAttackBattleActionRequest::SetBlackBoard(UBlackboardComponent* BB)
{
	Super::SetBlackBoard(BB);
}
