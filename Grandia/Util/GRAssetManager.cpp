// Fill out your copyright notice in the Description page of Project Settings.


#include "Util/GRAssetManager.h"

#include "Game/GRGameSingleton.h"

UGRAssetManager::UGRAssetManager()
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> TerraPortraitTexture(TEXT("/Script/Engine.Texture2D'/Game/Grandia/UI/GraphicContent/T_Terra_Portrait.T_Terra_Portrait'"));
	if (TerraPortraitTexture.Object)
	{
		PortraitMap.Add(EGRCharacterId::Terra, TerraPortraitTexture.Object);
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D> TwinblastPortraitTexture(TEXT("/Script/Engine.Texture2D'/Game/Grandia/UI/GraphicContent/T_Twinblast_Portrait.T_Twinblast_Portrait'"));
	if (TwinblastPortraitTexture.Object)
	{
		PortraitMap.Add(EGRCharacterId::Twinblast, TwinblastPortraitTexture.Object);
	}

}

UGRAssetManager* UGRAssetManager::Get()
{
	return UGRGameSingleton::Get().AssetManager;
}


UTexture2D* UGRAssetManager::GetPortraitById(EGRCharacterId CharacterId)
{
	if (PortraitMap.Contains(CharacterId))
	{
		return PortraitMap[CharacterId];
	}

	return nullptr;
}
 