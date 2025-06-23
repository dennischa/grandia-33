// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GRUserWidget.h"
#include "GameData/GRCharacterStat.h"
#include "GRHpBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class GRANDIA_API UGRHpBarWidget : public UGRUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UGRHpBarWidget(const FObjectInitializer& ObjectInitializer);

	void UpdateStat(const FGRCharacterStat& Stat);
	void UpdateHpBar(int NewCurrentHp);

	FString GetHpBarText();

protected:
	UPROPERTY()
	TObjectPtr<class UProgressBar> HpBar;

	UPROPERTY()
	TObjectPtr<class UTextBlock> HpTxt;

	UPROPERTY()
	int32 CurrentHp;

	UPROPERTY()
	int32 MaxHp;
};

inline FString UGRHpBarWidget::GetHpBarText()
{
	return FString::Printf(TEXT("%d/%d"), CurrentHp, MaxHp);
}
