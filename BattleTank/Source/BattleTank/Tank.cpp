// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine.h"
#include "TankAimComponent.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankTrack.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimComponent>( FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel *BarrelToSet) 
{ 
	Barrel = BarrelToSet;
	TankAimingComponent->SetBarrel(BarrelToSet); 
}

void ATank::SetAimSolution( bool Flag )
{
	TankAimingComponent->SetAimSolution(Flag);
}

void ATank::SetTurretReference(UTankTurret *TurretToSet)
{
	TankAimingComponent->SetTurret(TurretToSet);
}

void ATank::SetLeftTrack(UTankTrack *TrackToSet)
{
	LeftTrack = TrackToSet;
}

void ATank::SetRightTrack(UTankTrack *TrackToSet)
{
	RightTrack = TrackToSet;
}

void ATank::TankFire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (isReloaded)
	{
		FVector BarrelLoc = Barrel->GetSocketLocation("Projectile");
		FRotator BarrelRot = Barrel->GetSocketRotation("Projectile");
		auto *Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, BarrelLoc, BarrelRot);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}