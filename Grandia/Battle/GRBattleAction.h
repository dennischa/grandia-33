#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EBattleActionType : uint8
{
	None = 0,
	Attack,
	Skill,
	Item
};