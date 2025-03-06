// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "PaperCharacter.h"
#include "Monk.generated.h"

/**
 * 
 */
UCLASS()
class HYBRID_API AMonk : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	
    AMonk();

	void Move(const FInputActionValue& InputActionValue);

	void StartWalking(const FInputActionValue& InputActionValue);
	void StopWalking(const FInputActionValue& InputActionValue);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	
private:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Flipbooks", meta=(AllowPrivateAccess = "true"))
	class UPaperFlipbook* IdleFlipbook;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Flipbooks", meta=(AllowPrivateAccess = "true"))
	class UPaperFlipbook* WalkFlipBook;
};
