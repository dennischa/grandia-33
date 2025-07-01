// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GRTurnCardWidget.h"

#include "Components/Border.h"
#include "Components/Image.h"
#include "Data/GRTurnCardData.h"
#include "GameData/GRTurnInfo.h"

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
	
	if (TeamColorBorder)
	{
		const FLinearColor TeamColor = Data->bIsPlayer
			? FLinearColor::Green
			: FLinearColor::Red;

		TeamColorBorder->SetBrushColor(TeamColor);
	}
}

