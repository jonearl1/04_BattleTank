// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TankAimComponent.h"
#include "Tank.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimComponent>();

	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector HitLoc;
	AimTowardsCrosshair(HitLoc);
}

void ATankPlayerController::AimTowardsCrosshair(FVector &HitLocation)
{
	if (!GetPawn())
		return;

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimComponent>();
	if (!ensure(AimingComponent)) { return; }

	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		AimingComponent->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation)
{
	int ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	FVector2D ScreenLocation;
	ScreenLocation.X = CrossHairXLocation * ViewPortSizeX;
	ScreenLocation.Y = CrossHairYLocation * ViewPortSizeY;

	FVector WorldLocation, WorldDirection;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection);

	FVector EndPos = WorldLocation + WorldDirection * 50000.0f;

	FHitResult Result = GetFirstObjectAlongRay(WorldLocation, EndPos);
	if (Result.IsValidBlockingHit())
	{
		HitLocation = Result.Location;
		return(true);
	}
	return(false);
}


FHitResult ATankPlayerController::GetFirstObjectAlongRay( FVector Start, FVector End )
{
	/// see what we hit
	FHitResult Result;
	FCollisionQueryParams TraceQParams(FName(TEXT("")), false, GetOwner());
	FCollisionObjectQueryParams ObjectQParams(ECollisionChannel::ECC_Pawn | ECollisionChannel::ECC_WorldDynamic | ECollisionChannel::ECC_WorldStatic);

	//FVector CameraWorldPos = GetWorld()->getca
	GetWorld()->LineTraceSingleByChannel(Result, Start, End, ECollisionChannel::ECC_Visibility, TraceQParams);
	return(Result);
}