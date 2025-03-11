// Fill out your copyright notice in the Description page of Project Settings.


#include "Monk/MonkAnimInstance.h"
#include "Monk/Monk.h"

void UMonkAnimInstance::HandlePunchImpact()
{
	OwnerCharacter->HandlePunchImpactNotif();
}

void UMonkAnimInstance::SetWalkingBool(bool isWalking)
{
	bIsWalking = isWalking;
}

void UMonkAnimInstance::SetAirBorneBool(bool isAirborne)
{
	bIsAirborne = isAirborne;
}

void UMonkAnimInstance::SetFallingBool(bool isFalling)
{
	bIsFalling = isFalling;
}

void UMonkAnimInstance::SetOwningCharacter(class AMonk* OwningCharacter)
{
	OwnerCharacter = OwningCharacter;
}

