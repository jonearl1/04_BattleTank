// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimComponent.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	MoveToActor(PlayerTank, AcceptanceRadius);

	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimComponent>();

	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	AimingComponent->Fire(); 
}