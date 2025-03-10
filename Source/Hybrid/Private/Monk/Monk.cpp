// Fill out your copyright notice in the Description page of Project Settings.


#include "Monk/Monk.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Monk/MonkController.h"
#include "Monk/MonkAnimationComponent.h"

AMonk::AMonk()
{
	PrimaryActorTick.bCanEverTick = true;
	AnimationComponent = NewObject<UMonkAnimationComponent>(this, TEXT("AnimationComponent"));
}

void AMonk::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

	AddMovementInput(FVector(0, 1, 0), MovementVector.Y);
	AddMovementInput(FVector(1, 0, 0), MovementVector.X);

	FRotator Rotation = FRotator(0, 0, 0);
	Rotation.Yaw = MovementVector.X > 0 ? 0.0f : MovementVector.X < 0 ? 180.0f : GetActorRotation().Yaw;

	SetActorRotation(Rotation);
}

void AMonk::StartWalking(const FInputActionValue& InputActionValue)
{
	AnimationComponent->SetWalkingBool(true);
}

void AMonk::StopWalking(const FInputActionValue& InputActionValue)
{
	AnimationComponent->SetWalkingBool(false);
}

void AMonk::BeginPlay()
{
	Super::BeginPlay();
}


void AMonk::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	AMonkController* MonkController = Cast<AMonkController>(Controller);

	if (EIC && MonkController)
	{
		EIC->BindAction(MonkController->MoveAction, ETriggerEvent::Triggered, this, &AMonk::Move);
		EIC->BindAction(MonkController->MoveAction, ETriggerEvent::Started, this, &AMonk::StartWalking);
		EIC->BindAction(MonkController->MoveAction, ETriggerEvent::Completed, this, &AMonk::StopWalking);

		ULocalPlayer* LocalPlayer = MonkController->GetLocalPlayer();
		if (!LocalPlayer) return;
		UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
		if (!Subsystem) return;
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(MonkController->InputMappingContext, 0);
	}
}

