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
}
