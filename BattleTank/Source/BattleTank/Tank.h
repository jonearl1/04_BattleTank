// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankTrack;
class UTankAimComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	void SetAimSolution(bool Flag);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel *BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret *TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetRightTrack(UTankTrack*TrackToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetLeftTrack(UTankTrack*TrackToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void TankFire();

protected:
	UTankAimComponent *TankAimingComponent = NULL;
//	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent *TankMovementComponent = NULL;
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Firing )
	float LaunchSpeed = 4000.0f;


	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;
	UTankBarrel *Barrel = NULL;
	double LastFireTime = 0.0;
	float ReloadTimeInSeconds = 3.0f;
	UTankTrack *LeftTrack;
	UTankTrack *RightTrack;
	
};
