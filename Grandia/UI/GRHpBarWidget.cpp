// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GRHpBarWidget.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "GameData/GRCharacterStat.h"
#include "Interface/GRCharacterWidgetInterface.h"

void UGRHpBarWidget::NativeConstruct()
{
	Super::NativeConstruct();

	HpBar = Cast<UProgressBar>(GetWidgetFromName("PbHpBar"));
	check(HpBar);

	HpTxt = Cast<UTextBlock>(GetWidgetFromName("TxtHpStat"));
	check(HpTxt);

	IGRCharacterWidgetInterface* CharacterWidget = Cast<IGRCharacterWidgetInterface>(OwningActor);
	//ensure(CharacterWidget);

	if (CharacterWidget)
	{
		CharacterWidget->SetUpHpBarWidget(this);
	}
}

UGRHpBarWidget::UGRHpBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	MaxHp = -1.0f;
}

void UGRHpBarWidget::UpdateStat(const FGRCharacterStat& Stat)
{
	MaxHp = Stat.MaxHp;

	UpdateHpBar(CurrentHp);
}

void UGRHpBarWidget::UpdateHpBar(int NewCurrentHp)
{
	CurrentHp = NewCurrentHp;

	ensure(MaxHp > 0);

	HpBar->SetPercent(static_cast<float>(CurrentHp) / static_cast<float>(MaxHp));

	HpTxt->SetText(FText::FromString(GetHpBarText()));
}