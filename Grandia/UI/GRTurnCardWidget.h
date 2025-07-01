// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "GRTurnCardWidget.generated.h"

/**
 * 
 */
UCLASS()
class GRANDIA_API UGRTurnCardWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY()
	TObjectPtr<class UImage> HeadImage;

	UPROPERTY()
	TObjectPtr<class UBorder> TeamColorBorder;;
};
