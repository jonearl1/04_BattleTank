// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"



void UTankTurret::RotateTurret(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	//UE_LOG(LogTemp, Warning, TEXT("RotateTurret Called" ) );
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->GetDeltaSeconds();
	auto RawNewRotation = RelativeRotation.Yaw + ElevationChange;
	//auto NewRotation = FMath::Clamp<float>(RawNewRotation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(0.0f, RawNewRotation, 0.0f));
}
