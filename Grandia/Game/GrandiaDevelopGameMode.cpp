// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/GrandiaDevelopGameMode.h"

#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "Player/GRPlayerController.h"

void AGrandiaDevelopGameMode::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	AGRPlayerController* GRPC = Cast<AGRPlayerController>(PC);

	ensure(GRPC);
	
	for (TActorIterator<AActor> It(GetWorld()); It; ++It)
	{
		if (It->ActorHasTag("Enemy"))
		{
			AGRCharacterBase* EnemyCharacter = Cast<AGRCharacterBase>(*It);
			GRPC->SetEnemy(EnemyCharacter);
		}

		if (It->ActorHasTag("Player"))
		{
			AGRCharacterBase* PlayerCharacter = Cast<AGRCharacterBase>(*It);
			GRPC->SetPlayer(PlayerCharacter);
			
			GRPC->SetViewTarget(PlayerCharacter);
		}
	}

	PlayerTurn = NewObject<UGRTurnInfo>();
	PlayerTurn->CharacterId = EGRCharacterId::Terra;
	PlayerTurn->bIsPlayer = true;
	PlayerTurn->UnitId = 123;

	auto PlayerTurn2 = NewObject<UGRTurnInfo>();
	PlayerTurn2->CharacterId = EGRCharacterId::Terra;
	PlayerTurn2->bIsPlayer = true;
	PlayerTurn2->UnitId = 789;

	auto EnemyTurn = NewObject<UGRTurnInfo>();
	EnemyTurn->CharacterId = EGRCharacterId::Twinblast;
	EnemyTurn->bIsPlayer = false;
	EnemyTurn->UnitId = 456;

	TArray<UGRTurnInfo*> Infos {PlayerTurn, PlayerTurn2, EnemyTurn};

	TurnManager->OnTurnListUpdated.AddLambda([](const TArray<UGRTurnInfo*>& TurnList)
	{
		UE_LOG(LogTemp, Log, TEXT("TurnCardList updated! Count: %d"), TurnList.Num());
		for (int i = 0; i < TurnList.Num(); i++)
		{
			UE_LOG(LogTemp, Log, TEXT("Index-%d : %d"), i, TurnList[i]->CharacterId);
		}
	});

	TurnManager->OnTurnBegin.AddLambda([](const int32 UnitId)
	{
		UE_LOG(LogTemp, Log, TEXT("OnTurnBegin : %d"), UnitId);
	});
	
	TurnManager->Initialize(Infos);
}
