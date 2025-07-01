// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GRDevelopHUDWidget.h"

#include "GRHpBarWidget.h"
#include "Components/Button.h"
#include "Components/ListView.h"
#include "Game/GRTurnManager.h"
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

void UGRDevelopHUDWidget::SetEnemy(AActor* InEnemy)
{
	Enemy = InEnemy;

	EnemyHpBar.Get()->SetOwingActor(Enemy.Get());

	auto CharacterWidget = Cast<IGRCharacterWidgetInterface>(Enemy.Get());
	if (CharacterWidget)
	{
		CharacterWidget->SetUpHpBarWidget(EnemyHpBar.Get());
	}
}

void UGRDevelopHUDWidget::OnTurnListUpdated(const TArray<UGRTurnInfo*>& TurnInfos)
{
	UE_LOG(LogTemp, Warning, TEXT("OnTurnListUpdated"));

	TurnCardDatas.Empty();
	
	for (auto TurnInfo : TurnInfos)
	{
		auto Data = NewObject<UGRTurnCardData>(this);
		Data->bIsPlayer = TurnInfo->bIsPlayer;
		Data->CharacterId = TurnInfo->CharacterId;

		TurnCardDatas.Add(Data);
	}
	
	TurnList->SetListItems(TurnCardDatas);
}

void UGRDevelopHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	EnemyHpBar = Cast<UGRHpBarWidget>(GetWidgetFromName("Enemy_HpBar"));
	
	Button1 = Cast<UButton>(GetWidgetFromName("Button_1"));
	ensure(Button1);

	Button2 = Cast<UButton>(GetWidgetFromName("Button_2"));
	ensure(Button2);

	HpBar = Cast<UGRHpBarWidget>(GetWidgetFromName("WBP_HpBar_1"));
	ensure(HpBar);

	TurnList = Cast<UListView>(GetWidgetFromName("Turn_List"));
	ensure(TurnList);

	TurnList->SetScrollbarVisibility(ESlateVisibility::Collapsed);
}

