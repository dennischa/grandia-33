// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/GRCharacterStat.h"
#include "UObject/NoExportTypes.h"
#include "Util/GRAssetManager.h"
#include "GRGameSingleton.generated.h"

/**
 * 
 */
UCLASS()
class GRANDIA_API UGRGameSingleton : public UObject
{
	GENERATED_BODY()

public:
	UGRGameSingleton();
	static UGRGameSingleton& Get();

	// Character Stat Data Section
public:
	FORCEINLINE FGRCharacterStat* GetCharacterStat(const EGRCharacterId Id) { return CharacterStatMap.Find(Id); }

	UPROPERTY()
	TObjectPtr<UGRAssetManager> AssetManager;
private:
	TMap<EGRCharacterId, FGRCharacterStat> CharacterStatMap;
};
