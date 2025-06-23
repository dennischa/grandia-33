// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GRDevelopHUDWidget.h"

#include "GRHpBarWidget.h"
#include "Components/Button.h"
#include "Interface/GRCharacterWidgetInterface.h"

void UGRDevelopHUDWidget:: SetPlayer1(AActor* NewPlayer)
{
	Player1 = NewPlayer;

	HpBar.Get()->SetOwingActor(Player1.Get());
	
	auto CharacterWidget = Cast<IGRCharacterWidgetInterface>(Player1.Get());
	if (CharacterWidget)
	{
		CharacterWidget->SetUpHpBarWidget(HpBar.Get());
	}
}

void UGRDevelopHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	Button1 = Cast<UButton>(GetWidgetFromName("Button_1"));
	ensure(Button1);

	HpBar = Cast<UGRHpBarWidget>(GetWidgetFromName("WBP_HpBar_1"));
	ensure(HpBar);
}

