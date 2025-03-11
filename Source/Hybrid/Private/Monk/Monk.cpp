// Fill out your copyright notice in the Description page of Project Settings.


#include "Monk/Monk.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Monk/MonkController.h"
#include "Monk/MonkAnimationComponent.h"

AMonk::AMonk()
{
	PrimaryActorTick.bCanEverTick = true;
	AnimationComponent = CreateDefaultSubobject<UMonkAnimationComponent>(TEXT("Animation Component"));

	MaxJumpInputHoldTime = 0.5f;
	bIsAttacking = false;
}

void AMonk::HandleMoveInput(const FInputActionValue& InputActionValue)
{
	if (bIsAttacking) return;
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

void AMonk::HandleJumpInput(const FInputActionInstance& InputActionValue)
{
	if (bIsAttacking) return;
	//ジャンプ　インプット
	isJumpPressed = InputActionValue.GetValue().Get<bool>();
	if (isJumpPressed) Jump();
	else StopJumping();
}

void AMonk::HandlePunchInput(const FInputActionInstance& InputActionValue)
{
	if (bIsAttacking || CMC->IsFalling()) return;
	PunchTriggered();
}

void AMonk::HandleKickInput(const FInputActionInstance& InputActionValue)
{
	if (bIsAttacking) return;
	if (CMC->IsFalling()) JumpKickTriggered();
	else KickTriggered();
}

void AMonk::HandleHighKickInput(const FInputActionInstance& InputActionValue)
{
	if (bIsAttacking) return;
	if (CMC->IsFalling()) JumpKickTriggered();
	else HighKickTriggered();
}

void AMonk::HandlePunchImpactNotif()
{
	UE_LOG(LogTemp, Warning, TEXT("HandlePunchImpactNotif"));
	//TODO
}

void AMonk::HandleJumpKickImpactNotif()
{
	UE_LOG(LogTemp, Warning, TEXT("HandleJumpKickImpactNotif"));
	//TODO
}

void AMonk::HandleHighKickImpactNotif()
{
	UE_LOG(LogTemp, Warning, TEXT("HandleHighKickImpactNotif"));
	//TODO
}

void AMonk::HandleMidKickImpactNotif()
{
	UE_LOG(LogTemp, Warning, TEXT("HandleMidKickImpactNotif"));
	//TODO
}

void AMonk::BeginPlay()
{
	Super::BeginPlay();
	JumpMaxHoldTime = MaxJumpInputHoldTime;
	CMC = Cast<UCharacterMovementComponent>(GetCharacterMovement());
	AnimationComponent->SetOwningActorInAnimInstance(this);
}

void AMonk::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AnimationComponent->SetAirBorneBool(CMC->IsFalling());
	bool bIsFalling = GetVelocity().Z < 0.f;
	AnimationComponent->SetFallingBool(bIsFalling);
}

void AMonk::SetIsAttacking(bool isAttacking)
{
	bIsAttacking = isAttacking; 
}

void AMonk::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	AMonkController* MonkController = Cast<AMonkController>(Controller);

	if (EIC && MonkController)
	{
		EIC->BindAction(MonkController->MoveAction, ETriggerEvent::Triggered, this, &AMonk::HandleMoveInput);
		EIC->BindAction(MonkController->MoveAction, ETriggerEvent::Started, this, &AMonk::StartWalking);
		EIC->BindAction(MonkController->MoveAction, ETriggerEvent::Completed, this, &AMonk::StopWalking);

		EIC->BindAction(MonkController->JumpAction, ETriggerEvent::Triggered, this, &AMonk::HandleJumpInput);
		EIC->BindAction(MonkController->JumpAction, ETriggerEvent::Completed, this, &AMonk::HandleJumpInput);

		EIC->BindAction(MonkController->PunchAction, ETriggerEvent::Started, this, &AMonk::HandlePunchInput);
		EIC->BindAction(MonkController->KickAction, ETriggerEvent::Started, this, &AMonk::HandleKickInput);
		EIC->BindAction(MonkController->HighKickAction, ETriggerEvent::Started, this, &AMonk::HandleHighKickInput);

		ULocalPlayer* LocalPlayer = MonkController->GetLocalPlayer();
		if (!LocalPlayer) return;
		UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
		if (!Subsystem) return;
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(MonkController->InputMappingContext, 0);
	}
}

