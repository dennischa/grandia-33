// Fill out your copyright notice in the Description page of Project Settings.


#include "Stat/GRStatComponent.h"

#include "Game/GRGameSingleton.h"

// Sets default values for this component's properties
UGRStatComponent::UGRStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

int32 UGRStatComponent::ApplyDamage(int32 InDamage)
{
	const int32 PreHp  = CurrentHp;
	const int32 ActualDamage = FMath::Clamp<int32>(InDamage, 0, Stat.MaxHp);

	SetHp(PreHp - ActualDamage);

	if (CurrentHp <= 0)
	{
		OnHpZero.Broadcast();
	}
	
	return ActualDamage;
}

void UGRStatComponent::InitializeComponent()
{
	Super::InitializeComponent();
}

void UGRStatComponent::BeginPlay()
{
	Super::BeginPlay();

	Stat = *UGRGameSingleton::Get().GetCharacterStat(Id);
	SetHp(Stat.MaxHp);
}

void UGRStatComponent::SetHp(int32 NewHp)
{
	CurrentHp = FMath::Clamp<int32>(NewHp, 0, Stat.MaxHp);

	OnHpChanged.Broadcast(CurrentHp);
}
