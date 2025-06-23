// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/GRCharacterBase.h"
#include "GameFramework/PlayerController.h"
#include "GRPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GRANDIA_API AGRPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	 virtual void SetEnemy(AGRCharacterBase* InEnemy) { EnemyCharacter = InEnemy;}
	 virtual void SetPlayer(AGRCharacterBase* InEnemy) { PlayerCharacter = InEnemy;}

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
	TWeakObjectPtr<AGRCharacterBase> PlayerCharacter;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
	TWeakObjectPtr<AGRCharacterBase> EnemyCharacter;
};
