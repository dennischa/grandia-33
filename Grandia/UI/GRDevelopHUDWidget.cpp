// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GRDevelopHUDWidget.h"

#include "Components/Button.h"

void UGRDevelopHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button1 = Cast<UButton>(GetWidgetFromName("Button_1"));
	ensure(Button1);
}

