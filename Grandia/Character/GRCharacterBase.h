// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/GRCharacterStatInterface.h"
#include "GRCharacterBase.generated.h"

UCLASS()
class GRANDIA_API AGRCharacterBase : public ACharacter, public IGRCharacterStatInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGRCharacterBase();

	// Attack Section
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	TObjectPtr<class UAnimMontage> AttackMontage;

	void Attack();
	virtual float GetTurnSpeed() const override;
	
	// Stat Section
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UGRStatComponent> Stat;
};
