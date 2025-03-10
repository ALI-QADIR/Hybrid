// Fill out your copyright notice in the Description page of Project Settings.


#include "Monk/MonkAnimInstance.h"


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

