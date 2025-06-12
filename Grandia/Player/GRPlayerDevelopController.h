// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Battle/GRBattleActionRequest.h"
#include "Player/GRPlayerController.h"
#include "GRPlayerDevelopController.generated.h"

/**
 * 
 */
UCLASS()
class GRANDIA_API AGRPlayerDevelopController : public AGRPlayerController
{
	GENERATED_BODY()

public:
	AGRPlayerDevelopController();

protected:
	virtual void BeginPlay() override;

	TSubclassOf<class UGRDevelopHUDWidget> DevelopHUDWidgetClass;

	UPROPERTY()
	TObjectPtr<class UGRDevelopHUDWidget> DevelopHUDWidget;

	UFUNCTION()
	void OnButton1Clicked();

	UFUNCTION()
	void OnBattleActionFinished(EBTNodeResult::Type Result);
};
