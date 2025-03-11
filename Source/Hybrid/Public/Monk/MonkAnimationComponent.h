// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDAnimationComponent.h"
#include "MonkAnimationComponent.generated.h"

/**
 * 
 */
UCLASS()
class HYBRID_API UMonkAnimationComponent : public UPaperZDAnimationComponent
{
	GENERATED_BODY()

protected:

	UPROPERTY()
	class UMonkAnimInstance* MonkAnimInstance;

	virtual void BeginPlay() override;
	
public:

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void SetWalkingBool(bool bIsWalking);

	void SetAirBorneBool(bool bIsAirborne);

	void SetFallingBool(bool bIsFalling);

	void SetOwningActorInAnimInstance(class AMonk* OwningActor);
	
};
