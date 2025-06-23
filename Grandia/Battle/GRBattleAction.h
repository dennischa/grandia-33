#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"

UENUM(BlueprintType)
enum class EBattleActionType : uint8
{
	None = 0,
	Attack,
	Skill,
	Item
};

DECLARE_DELEGATE_OneParam(FOnBattleActionFinished, EBTNodeResult::Type);