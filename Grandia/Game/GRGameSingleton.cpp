// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/GRGameSingleton.h"

UGRGameSingleton::UGRGameSingleton()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DataTableRef(TEXT("/Script/Engine.DataTable'/Game/Grandia/GameData/GRCharacterStatTable.GRCharacterStatTable'"));

	if (DataTableRef.Object != nullptr)
	{
		const UDataTable* DataTable = DataTableRef.Object;
		check(DataTable->GetRowMap().Num() > 0);

		TArray<FName> RowNames =  DataTable->GetRowNames();
		for (const FName& RowName : RowNames)
		{
			const FGRCharacterStat* Row = DataTable->FindRow<FGRCharacterStat>(RowName, TEXT("Load GRCharacterStat"));

			if (Row != nullptr)
			{
				CharacterStatMap.Add(Row->CharacterId, *Row);
			}
		}
	}

	
}

UGRGameSingleton& UGRGameSingleton::Get()
{
	if (UGRGameSingleton* Singleton = CastChecked<UGRGameSingleton>(GEngine->GameSingleton))
	{
		return *Singleton;
	}

	UE_LOG(LogTemp, Error, TEXT("GameSingleton does not exist"));

	return *NewObject<UGRGameSingleton>();
}
