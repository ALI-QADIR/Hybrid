// Fill out your copyright notice in the Description page of Project Settings.


#include "Monk/MonkController.h"
#include "InputMappingContext.h"
#include "InputAction.h"

AMonkController::AMonkController()
{
	InputMappingContext = NewObject<UInputMappingContext>(this, TEXT("Input Mapping Context"));
	MoveAction = NewObject<UInputAction>(this, TEXT("Move Action"));
	JumpAction = NewObject<UInputAction>(this, TEXT("Jump Action"));
	PunchAction = NewObject<UInputAction>(this, TEXT("Punch Action"));
	KickAction = NewObject<UInputAction>(this, TEXT("Kick Action"));
	KickAction = NewObject<UInputAction>(this, TEXT("High Kick Action"));
}


void AMonkController::SetupInputComponent()
{
	Super::SetupInputComponent();
}


