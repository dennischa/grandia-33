// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GRDevelopHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class GRANDIA_API UGRDevelopHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<class UButton> Button1;
	
	void SetPlayer1(AActor* NewPlayer);
	void SetEnemy(AActor* InEnemy);

protected:
	virtual void NativeConstruct() override;

	// Enemy Section
	UPROPERTY()
	TWeakObjectPtr<AActor> Enemy;
	
	UPROPERTY()
	TObjectPtr<class UGRHpBarWidget> EnemyHpBar;

	// Player Section
	
	UPROPERTY()
	TWeakObjectPtr<AActor> Player1;
	
	UPROPERTY()
	TObjectPtr<class UGRHpBarWidget> HpBar;
};
