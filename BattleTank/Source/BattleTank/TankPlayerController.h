// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank *GetControlledTank(void);
	
	void BeginPlay(void) override;
	void Tick(float DeltaTime);

	// Start the tank moving the barrel so that a shot would hit where the crosshair intersects the world.
	void AimTowardsCrosshair(FVector &HitLocation);

	bool GetSightRayHitLocation(FVector &HitLocation);

	FHitResult GetFirstObjectAlongRay(FVector Start, FVector End);

	UPROPERTY( EditAnywhere )
	float CrossHairXLocation = 0.5f;
	UPROPERTY( EditAnywhere )
	float CrossHairYLocation = 0.3333f;
};
