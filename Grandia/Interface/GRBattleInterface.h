// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Battle/GRAttackBattleActionRequest.h"
#include "UObject/Interface.h"
#include "GRBattleInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGRBattleInterface : public UInterface
{
	GENERATED_BODY()
};

DECLARE_DELEGATE(FOnAttackFinished)

/**
 * 
 */
class GRANDIA_API IGRBattleInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void SetBattleActionRequest(class UGRBattleActionRequest* Request) = 0;
	
	virtual void SetAttackDelegate(const FOnAttackFinished& InOnAttackFinished) = 0;
	virtual void Attack(APawn* Target) = 0;

	virtual void OnAttackTarget() = 0;
};
