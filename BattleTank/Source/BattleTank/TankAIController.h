// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	void Tick(float DeltaTime);

	void BeginPlay(void) override;

	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 1000.0f;
};
