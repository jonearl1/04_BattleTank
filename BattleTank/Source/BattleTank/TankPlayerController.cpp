// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



ATank *ATankPlayerController::GetControlledTank()
{
	return( Cast<ATank>(GetPawn()));
	//return(NULL);
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Possed tank BeginPlay called"));
	ATank *Tank = GetControlledTank();
	if (Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank found %s"), *(Tank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank not found" ));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector HitLoc;
	AimTowardsCrosshair(HitLoc);
}

void ATankPlayerController::AimTowardsCrosshair(FVector &HitLocation)
{
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt((HitLocation));
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation)
{
	ATank *Tank = GetControlledTank();
	if (!Tank)
		return(false);

	//FVector PlayerPos = GetActorLocation();

	//FVector TankPos = Tank->GetActorLocation();

	int ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	FVector2D ScreenLocation;
	ScreenLocation.X = CrossHairXLocation * ViewPortSizeX;
	ScreenLocation.Y = CrossHairYLocation * ViewPortSizeY;

	FVector WorldLocation, WorldDirection;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection);

	FVector EndPos = WorldLocation + WorldDirection * 50000.0f;

	FHitResult Result = GetFirstObjectAlongRay(WorldLocation, EndPos);
	HitLocation = Result.Location;
	return(true);
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