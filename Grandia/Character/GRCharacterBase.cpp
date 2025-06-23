// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GRCharacterBase.h"

#include "AI/GRAIController.h"
#include "Battle/GRBattleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Stat/GRStatComponent.h"
#include "UI/GRHpBarWidget.h"

// Sets default values
AGRCharacterBase::AGRCharacterBase()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(38.f, 85.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Movement
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -85.0f), FRotator(0.0f, -90.0f, 0.0f));
	
	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	
	// Stat
	Stat = CreateDefaultSubobject<UGRStatComponent>(TEXT("Stat"));

	// Battle
	Battle = CreateDefaultSubobject<UGRBattleComponent>(TEXT("Battle"));

	// AI
	AIControllerClass = AGRAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void AGRCharacterBase::Attack()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	AnimInstance->Montage_Play(AttackMontage);
}

void AGRCharacterBase::SetUpHpBarWidget(UGRUserWidget* InUserWidget)
{
	UGRHpBarWidget* HpBarWidget = Cast<UGRHpBarWidget>(InUserWidget);

	if (HpBarWidget)
	{
		HpBarWidget->UpdateStat(Stat->GetCharacterStat());
		HpBarWidget->UpdateHpBar(GetCurrentHp());

		Stat->OnHpChanged.AddUObject(HpBarWidget, &UGRHpBarWidget::UpdateHpBar);
		Stat->OnStatChanged.AddUObject(HpBarWidget, &UGRHpBarWidget::UpdateStat);
	}
}

