// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	void Tick(float DeltaTime);
	void AimTowardsPlayer(void);
	ATank *GetControlledTank(void);

	void BeginPlay(void) override;
	ATank *GetPlayerTank(void);

	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 1000.0f;
};
