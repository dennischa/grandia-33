// Fill out your copyright notice in the Description page of Project Settings.


#include "GRPlayerDevelopController.h"

#include "AI/GRAIController.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Game/GrandiaGameMode.h"
#include "Kismet/GameplayStatics.h"
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

			DevelopHUDWidget->Button1->OnClicked.AddDynamic(this, &AGRPlayerDevelopController::OnButton1Clicked);
			DevelopHUDWidget->Button2->OnClicked.AddDynamic(this, &AGRPlayerDevelopController::OnButton2Clicked);
			
			DevelopHUDWidget->SetPlayer1(PlayerCharacter.Get());
			DevelopHUDWidget->SetEnemy(EnemyCharacter.Get());

			auto* GameMode = Cast<AGrandiaGameMode>(UGameplayStatics::GetGameMode(this));

			if (GameMode && GameMode->TurnManager)
			{
				GameMode->TurnManager->OnTurnListUpdated.AddUObject(DevelopHUDWidget, &UGRDevelopHUDWidget::OnTurnListUpdated);
				GameMode->TurnManager->RefreshTurnList();
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
	/*if (auto* AIController = Cast<AGRAIController>(PlayerCharacter->GetController()))
	{
		UGRAttackBattleActionRequest* Request = NewObject<UGRAttackBattleActionRequest>(this);
		Request->Initialize(true, EnemyCharacter.Get(), FOnBattleActionFinished::CreateUObject(this, &AGRPlayerDevelopController::OnBattleActionFinished));

		AIController->SetBattleActionRequest(Request);
	}*/

	auto* GameMode = Cast<AGrandiaGameMode>(UGameplayStatics::GetGameMode(this));

	if (GameMode && GameMode->TurnManager)
	{
		GameMode->TurnManager->AdvanceTurn();
	}
}

void AGRPlayerDevelopController::OnButton2Clicked()
{
	auto* GameMode = Cast<AGrandiaGameMode>(UGameplayStatics::GetGameMode(this));

	if (GameMode && GameMode->TurnManager)
	{
		GameMode->TurnManager->RemoveUnit(123);
	}
}

void AGRPlayerDevelopController::OnBattleActionFinished(EBTNodeResult::Type Result)
{
	UE_LOG(LogTemp, Log, TEXT("Battle Action Requeset Finished. Result: %d"), (int)Result);
}

