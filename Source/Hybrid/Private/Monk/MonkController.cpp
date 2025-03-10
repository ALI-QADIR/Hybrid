// Fill out your copyright notice in the Description page of Project Settings.


#include "Monk/MonkController.h"
#include "InputMappingContext.h"
#include "InputAction.h"

AMonkController::AMonkController()
{
	InputMappingContext = NewObject<UInputMappingContext>(this, TEXT("Input Mapping Context"));
	MoveAction = NewObject<UInputAction>(this, TEXT("Move Action"));
}


void AMonkController::SetupInputComponent()
{
	Super::SetupInputComponent();
}


