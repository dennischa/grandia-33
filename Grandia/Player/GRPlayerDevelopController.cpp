// Fill out your copyright notice in the Description page of Project Settings.


#include "GRPlayerDevelopController.h"

#include "AI/GRAIController.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "UI/GRDevelopHUDWidget.h"

AGRPlayerDevelopController::AGRPlayerDevelopController()
{
	static ConstructorHelpers::FClassFinder<UGRDevelopHUDWidget> DevelopHudClassRef(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Grandia/UI/WBP_Develop.WBP_Develop_C'"));

	if (DevelopHudClassRef.Class)
	{
		DevelopHUDWidgetClass = DevelopHudClassRef.Class;
	}
}

void AGRPlayerDevelopController::BeginPlay()
{
	Super::BeginPlay();
	
	if (DevelopHUDWidgetClass)
	{
		DevelopHUDWidget = CreateWidget<UGRDevelopHUDWidget>(this, DevelopHUDWidgetClass);
		
		ensure(DevelopHUDWidget);

		if (DevelopHUDWidget)
		{
			DevelopHUDWidget->AddToViewport();

			if (DevelopHUDWidget->Button1)
			{
				DevelopHUDWidget->Button1->OnClicked.AddDynamic(this, &AGRPlayerDevelopController::OnButton1Clicked);
			}
		}
	}

	ensure(DevelopHUDWidget);

	FInputModeUIOnly InputModeUIOnly;

	// UI Only 
	SetInputMode(InputModeUIOnly);
	// 커서 항상 보이게 함
	bShowMouseCursor = true;
}

void AGRPlayerDevelopController::OnButton1Clicked()
{
	if (auto* AIController = Cast<AGRAIController>(PlayerCharacter->GetController()))
	{
		UGRAttackBattleActionRequest* Request = NewObject<UGRAttackBattleActionRequest>(this);
		Request->Initialize(EnemyCharacter.Get(), FOnBattleActionFinished::CreateUObject(this, &AGRPlayerDevelopController::OnBattleActionFinished));

		AIController->SetBattleActionRequest(Request);
	}
}

void AGRPlayerDevelopController::OnBattleActionFinished(EBTNodeResult::Type Result)
{
	UE_LOG(LogTemp, Log, TEXT("Battle Action Requeset Finished. Result: %d"), (int)Result);
}


