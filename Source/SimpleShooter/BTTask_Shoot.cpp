// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "AIController.h"
#include "SimpleShooterCharacter.h"


UBTTask_Shoot::UBTTask_Shoot()
{
    NodeName = TEXT("PlayerShoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    ASimpleShooterCharacter* Character = Cast<ASimpleShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
    if (Character == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    Character->AIShoot();

    return EBTNodeResult::Succeeded;
}