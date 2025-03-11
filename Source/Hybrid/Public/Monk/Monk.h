// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "PaperCharacter.h"
#include "Monk.generated.h"

struct FInputActionInstance;
/**
 * 
 */
UCLASS()
class HYBRID_API AMonk : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	
    AMonk();

	void HandleMoveInput(const FInputActionValue& InputActionValue);

	void StartWalking(const FInputActionValue& InputActionValue);
	void StopWalking(const FInputActionValue& InputActionValue);
	void HandleJumpInput(const FInputActionInstance& InputActionValue);
	void HandlePunchInput(const FInputActionInstance& InputActionValue);

	void HandlePunchImpactNotif();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Flipbooks", meta=(AllowPrivateAccess = "true"))
	class UMonkAnimationComponent* AnimationComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Flipbooks", meta=(AllowPrivateAccess = "true"))
	float MaxJumpInputHoldTime;

	UPROPERTY()
	UCharacterMovementComponent* CMC;

	UFUNCTION(BlueprintImplementableEvent, Category = "Input Events")
	void PunchTriggered();
	
	UFUNCTION(BlueprintCallable, Category = "State Events")
	void SetIsAttacking(bool isAttacking);

	
	bool isJumpPressed;
	bool bIsAttacking;
};
