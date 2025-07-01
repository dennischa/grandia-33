#pragma once

#include "CoreMinimal.h"

#include "GRBattleActionRequest.h"
#include "GRAttackBattleActionRequest.generated.h"

UCLASS()
class UGRAttackBattleActionRequest : public UGRBattleActionRequest
{
	GENERATED_BODY()

public:
	void Initialize(bool InShouldMoveToTarget, AActor* InTarget, const FOnBattleActionFinished& InOnBattleActionFinished);

	virtual void SetBlackBoard(UBlackboardComponent* BB) override;
};

