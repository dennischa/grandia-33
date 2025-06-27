// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotify_AttackTarget.h"

#include "Interface/GRBattleInterface.h"

void UAnimNotify_AttackTarget::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                      const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp)
	{
		auto Battle = Cast<IGRBattleInterface>(MeshComp->GetOwner());
		
		if (Battle)
		{
			Battle->OnAttackTarget();
		}
	}
}
