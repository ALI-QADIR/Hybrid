// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDAnimInstance.h"
#include "MonkAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class HYBRID_API UMonkAnimInstance : public UPaperZDAnimInstance
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Animation Properties", meta=(AllowPrivateAccess = "true"))
	bool bIsWalking;

	UPROPERTY(BlueprintReadOnly, Category = "Animation Properties", meta=(AllowPrivateAccess = "true"))
	bool bIsAirborne;

	UPROPERTY(BlueprintReadOnly, Category = "Animation Properties", meta=(AllowPrivateAccess = "true"))
	bool bIsFalling;

	UPROPERTY()
	class AMonk* OwnerCharacter;

	UFUNCTION(BlueprintCallable, Category = "Animation Events")
	void HandlePunchImpact();
	
	UFUNCTION(BlueprintCallable, Category = "Animation Events")
	void HandleMidKickImpact();
	
	UFUNCTION(BlueprintCallable, Category = "Animation Events")
	void HandleJumpKickImpact();
	
	UFUNCTION(BlueprintCallable, Category = "Animation Events")
	void HandleHighKickImpact();
	
public:

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void SetWalkingBool(bool isWalking);

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void SetAirBorneBool(bool isAirborne);

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void SetFallingBool(bool isFalling);
	
	void SetOwningCharacter(class AMonk* OwningCharacter);
};
