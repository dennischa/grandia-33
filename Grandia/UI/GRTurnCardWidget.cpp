// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GRTurnCardWidget.h"

#include "Components/Border.h"
#include "Components/Image.h"
#include "Data/GRTurnCardData.h"
#include "GameData/GRTurnInfo.h"
#include "Util/GRAssetManager.h"

void UGRTurnCardWidget::NativeConstruct()
{
	Super::NativeConstruct();

	HeadImage = Cast<UImage>(GetWidgetFromName("Head_Image"));
	ensure(HeadImage);

	TeamColorBorder = Cast<UBorder>(GetWidgetFromName("Team_Color_Border"));
	ensure(TeamColorBorder);
}

void UGRTurnCardWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	auto Data = Cast<UGRTurnCardData>(ListItemObject);

	if (!Data) return;

	if (Data->CharacterId == EGRCharacterId::Unknown)
	{
		SetVisibility(ESlateVisibility::Collapsed);
		return;
	}

	const float Flip = Data->bIsPlayer ? 1.0f : -1.0f;
	SetRenderScale(FVector2D(Flip, 1.0f));
	
	if (TeamColorBorder)
	{
		const FLinearColor TeamColor = Data->bIsPlayer
			? FLinearColor::Green : FLinearColor::Red;

		TeamColorBorder->SetBrushColor(TeamColor);
	}

	if (HeadImage)
	{
		UTexture2D* Portrait = UGRAssetManager::Get()->GetPortraitById(Data->CharacterId);
		if (Portrait)
		{
			HeadImage->SetBrushFromTexture(Portrait);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Portrait not found for CharacterId: %d"), static_cast<uint8>(Data->CharacterId));
			HeadImage->SetBrushFromTexture(nullptr); // 기본값 or 공백 처리
		}
	}
}

