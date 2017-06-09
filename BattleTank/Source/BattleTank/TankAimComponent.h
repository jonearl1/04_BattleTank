// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "TankAimComponent.generated.h"

class UTankBarrel;
class UTankTurret;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponent();
	void SetBarrel(UTankBarrel* BarrelToSet) { Barrel = BarrelToSet; }
	void SetTurret(UTankTurret* TurretToSet) { Turret = TurretToSet; }
	void AimAt(FVector HitLocation, float LaunchSpeed );
	void MoveBarrelTowards(FVector AimDirection);
	void SetAimSolution(bool Flag) { AimSolution = Flag; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
private:
	UTankBarrel *Barrel = NULL;
	UTankTurret *Turret = NULL;
	FVector AimDirection;
	bool AimSolution = false;
};
