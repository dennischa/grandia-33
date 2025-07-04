// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GRCharacterStatInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGRCharacterStatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GRANDIA_API IGRCharacterStatInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual float GetAttackRange() const = 0;
	virtual float GetAttackSpeed() const = 0;
	virtual int32 GetAttackDamage() const = 0;
	virtual int32 GetCurrentHp() const = 0;
};
