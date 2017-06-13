// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	FString Name = GetName();
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	FString Name = GetName();
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}


void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();
	auto MoveVelNormal = MoveVelocity.GetSafeNormal();
	auto TankForward = GetOwner()->GetActorForwardVector();

	float ForwardThrow = FVector::DotProduct(TankForward, MoveVelNormal);
	IntendMoveForward(ForwardThrow);
	UE_LOG(LogTemp, Warning, TEXT( "%s vectoring to %s"), *TankName, *(MoveVelNormal.ToString() ));
}