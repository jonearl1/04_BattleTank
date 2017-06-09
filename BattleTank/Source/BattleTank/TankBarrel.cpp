// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate( float RelativeSpeed)
{
	//clamp(-1.0f, 1.0f, RelativeSpeed);
	//UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate Called" ) );
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->GetDeltaSeconds();
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(Elevation, 0.0f, 0.0f ));
}