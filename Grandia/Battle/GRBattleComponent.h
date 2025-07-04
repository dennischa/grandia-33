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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	TWeakObjectPtr<class UAnimInstance> AnimInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	TObjectPtr<class UAnimMontage> AttackMontage;
	
	TWeakInterfacePtr<class IGRCharacterStatInterface> Stat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BattleAction)
	TObjectPtr<class UGRBattleActionRequest> CurrentRequest;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetBattleActionRequest(class UGRBattleActionRequest* InRequest) override { CurrentRequest = InRequest; }

	// Attack Section
public:
	virtual void SetAttackDelegate(const FOnAttackFinished& InOnAttackFinished) override { OnAttackFinished = InOnAttackFinished; }
	virtual void Attack(APawn* Target) override;
	virtual void OnAttackTarget() override;

	void AttackEnd(UAnimMontage* TargetMontage, bool IsProperlyEnded);

protected:
	FOnAttackFinished OnAttackFinished;
};
