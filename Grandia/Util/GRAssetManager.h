// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GRAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class GRANDIA_API UGRAssetManager : public UObject
{
	GENERATED_BODY()

public:
	UGRAssetManager();
	static UGRAssetManager* Get();
	
	UTexture2D* GetPortraitById(EGRCharacterId CharacterId);

private:
	UPROPERTY()
	TMap<EGRCharacterId, UTexture2D*> PortraitMap;
	bool bInitialized = false;
};
