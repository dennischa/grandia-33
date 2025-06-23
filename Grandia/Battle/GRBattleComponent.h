// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interface/GRBattleInterface.h"
#include "UObject/WeakInterfacePtr.h"
#include "GRBattleComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRANDIA_API UGRBattleComponent : public UActorComponent, public IGRBattleInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGRBattleComponent();

protected:
	virtual void InitializeComponent() override;
	
	// Called when the game starts
	virtual void BeginPlay() override;

	TWeakObjectPtr<class UAnimInstance> AnimInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	TObjectPtr<class UAnimMontage> AttackMontage;

	TWeakInterfacePtr<class IGRCharacterStatInterface> Stat;
	

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Attack Section
public:
	virtual void SetAttackDelegate(const FOnAttackFinished& InOnAttackFinished) override { OnAttackFinished = InOnAttackFinished; }
	virtual void Attack(APawn* Target) override;

	void AttackEnd(UAnimMontage* TargetMontage, bool IsProperlyEnded);

protected:
	FOnAttackFinished OnAttackFinished;
};
