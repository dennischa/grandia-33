#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GRCharacterStat.generated.h"


UENUM(BlueprintType)
enum class EGRCharacterId : uint8
{
	Unknown = 0,
	Terra = 1,
	Twinblast = 2,
};


USTRUCT(BlueprintType)
struct FGRCharacterStat : public FTableRowBase
{
	GENERATED_BODY()

public:
	FGRCharacterStat() : CharacterId(EGRCharacterId::Unknown), MaxHp(0.0f), Attack(0.0f), AttackRange(0.0f), AttackSpeed(0.0f), MovementSpeed(0.0f) {}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	EGRCharacterId CharacterId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	int32 MaxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	int32 Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float AttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float AttackSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float MovementSpeed;
};
