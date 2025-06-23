// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Battle/GRBattleComponent.h"
#include "GameData/GRCharacterStat.h"
#include "GameFramework/Character.h"
#include "Interface/GRBattleInterface.h"
#include "Interface/GRCharacterStatInterface.h"
#include "Interface/GRCharacterWidgetInterface.h"
#include "Stat/GRStatComponent.h"
#include "GRCharacterBase.generated.h"

UCLASS()
class GRANDIA_API AGRCharacterBase : public ACharacter, public IGRCharacterStatInterface, public IGRBattleInterface, public IGRCharacterWidgetInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGRCharacterBase();

	// Attack Section
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	TObjectPtr<class UAnimMontage> AttackMontage;

	void Attack();
	
	// Stat Section
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UGRStatComponent> Stat;
	
	virtual IGRCharacterStatInterface* GetStat() const { return  Stat; }
	
	virtual float GetAttackRange() const override { return GetStat()->GetAttackRange(); }
	virtual float GetAttackSpeed() const override { return GetStat()->GetAttackSpeed(); }
	virtual int32 GetCurrentHp() const override { return GetStat()->GetCurrentHp(); }

	// Battle Secion
public:
	virtual void SetAttackDelegate(const FOnAttackFinished& InOnAttackFinished) override { GetBattle()->SetAttackDelegate(InOnAttackFinished); }
	virtual void Attack(APawn* Target) override { GetBattle()->Attack(Target); }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Battle, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UGRBattleComponent> Battle;

	virtual IGRBattleInterface* GetBattle() { return Battle;}

public:
	virtual void SetUpHpBarWidget(UGRUserWidget* InUserWidget) override;
};
