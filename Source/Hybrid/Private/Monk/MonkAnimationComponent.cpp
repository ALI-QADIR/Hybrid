// Fill out your copyright notice in the Description page of Project Settings.


#include "Monk/MonkAnimationComponent.h"
#include "Monk/MonkAnimInstance.h"


void UMonkAnimationComponent::BeginPlay()
{
	Super::BeginPlay();
	MonkAnimInstance = Cast<UMonkAnimInstance>(GetAnimInstance());
}

void UMonkAnimationComponent::SetWalkingBool(bool bIsWalking)
{
	if (!MonkAnimInstance) return;
	MonkAnimInstance->SetWalkingBool(bIsWalking);
}

void UMonkAnimationComponent::SetAirBorneBool(bool bIsAirborne)
{
	if (!MonkAnimInstance) return;
	MonkAnimInstance->SetAirBorneBool(bIsAirborne);
}

void UMonkAnimationComponent::SetFallingBool(bool bIsFalling)
{
	if (!MonkAnimInstance) return;
	MonkAnimInstance->SetFallingBool(bIsFalling);
}
