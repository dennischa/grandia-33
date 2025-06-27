// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/GRBattleComponent.h"

#include "Engine/DamageEvents.h"
#include "GameFramework/Character.h"
#include "Interface/GRCharacterStatInterface.h"
#include "Widgets/Text/ISlateEditableTextWidget.h"

// Sets default values for this component's properties
UGRBattleComponent::UGRBattleComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UGRBattleComponent::InitializeComponent()
{
	Super::InitializeComponent();
}


// Called when the game starts
void UGRBattleComponent::BeginPlay()
{
	Super::BeginPlay();

	auto GRCharacter = Cast<ACharacter>(GetOwner());

	AnimInstance = GRCharacter->GetMesh()->GetAnimInstance();
	
	Stat = Cast<IGRCharacterStatInterface>(GetOwner());

	ensure(AnimInstance.Get());
	ensure(Stat.Get());
}


// Called every frame
void UGRBattleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGRBattleComponent::Attack(APawn* Target)
{
	AnimInstance.Get()->Montage_Play(AttackMontage, Stat.Get()->GetAttackSpeed());

	FOnMontageEnded EndDelegate;
	EndDelegate.BindUObject(this, &UGRBattleComponent::AttackEnd);
	AnimInstance.Get()->Montage_SetEndDelegate(EndDelegate, AttackMontage);
}

void UGRBattleComponent::OnAttackTarget()
{
	auto AttackRequest = Cast<UGRAttackBattleActionRequest>(CurrentRequest);

	if (AttackRequest)
	{
		FDamageEvent DamageEvent;
		AttackRequest->GetTarget()->TakeDamage(Stat.Get()->GetAttackDamage(), DamageEvent, GetOwner()->GetInstigatorController(), GetOwner());
	}
}

void UGRBattleComponent::AttackEnd(UAnimMontage* TargetMontage, bool IsProperlyEnded)
{
	OnAttackFinished.ExecuteIfBound();
}
