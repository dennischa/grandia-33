// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GRWASDPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Character/GRCharacterPlayer.h"
#include "GameFramework/Character.h"

AGRWASDPlayerController::AGRWASDPlayerController()
{
}

void AGRWASDPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		SubSystem->AddMappingContext(InputMappingContext, 0);
	}
}

void AGRWASDPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AGRWASDPlayerController::Jump);
		EnhancedInputComponent->BindAction(ShoulderMoveAction, ETriggerEvent::Triggered, this, &AGRWASDPlayerController::ShoulderMove);
		EnhancedInputComponent->BindAction(ShoulderLookAction, ETriggerEvent::Triggered, this, &AGRWASDPlayerController::ShoulderLook);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &AGRWASDPlayerController::Attack);
	}
}

void AGRWASDPlayerController::Jump()
{
	if (AGRCharacterPlayer* GRCharacterPlayer = Cast<AGRCharacterPlayer>(GetCharacter()))
	{
		GRCharacterPlayer->Jump();
	}
}

void AGRWASDPlayerController::ShoulderMove(const FInputActionValue& Value)
{
	if (AGRCharacterPlayer* GRCharacterPlayer = Cast<AGRCharacterPlayer>(GetCharacter()))
	{
		GRCharacterPlayer->ShoulderMove(Value);
	}
}

void AGRWASDPlayerController::ShoulderLook(const FInputActionValue& Value)
{
	if (AGRCharacterPlayer* GRCharacterPlayer = Cast<AGRCharacterPlayer>(GetCharacter()))
	{
		GRCharacterPlayer->ShoulderLook(Value);
	}
}

void AGRWASDPlayerController::Attack()
{
	if (AGRCharacterBase* GRCharacterBase = Cast<AGRCharacterBase>(GetCharacter()))
	{
		GRCharacterBase->Attack();
	}
}

