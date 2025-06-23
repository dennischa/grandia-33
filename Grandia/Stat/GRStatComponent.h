// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameData/GRCharacterStat.h"
#include "Interface/GRCharacterStatInterface.h"
#include "GRStatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnHpZeroDelegate);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHpChangedDelegate, int32);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnStatChangedDelegate, const FGRCharacterStat&);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRANDIA_API UGRStatComponent : public UActorComponent, public IGRCharacterStatInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGRStatComponent();

	FOnHpZeroDelegate OnHpZero;
	FOnHpChangedDelegate OnHpChanged;
	FOnStatChangedDelegate OnStatChanged;

	int32 ApplyDamage(int32 InDamage);

	FORCEINLINE const FGRCharacterStat& GetCharacterStat() const { return Stat; }
	
	virtual float GetAttackRange() const override { return Stat.AttackRange; }
	virtual float GetAttackSpeed() const override { return Stat.AttackSpeed; }
	virtual int32 GetCurrentHp() const override { return CurrentHp;}

protected:
	virtual void InitializeComponent() override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	EGRCharacterId Id;
	
	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	FGRCharacterStat Stat;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat)
	int32 CurrentHp;

	void SetHp(int32 NewHp);
};
