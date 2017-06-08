// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


ATank *ATankAIController::GetControlledTank()
{
	return(Cast<ATank>(GetPawn()));
	//return(NULL);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Possed tank BeginPlay called"));
	ATank *Tank = GetPlayerTank();
	if (Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank found Player %s"), *(Tank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank cannot find player"));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsPlayer();
}

void ATankAIController::AimTowardsPlayer( void )
{
	ATank *PlayerTank = GetPlayerTank();
	if( PlayerTank )
	{
		FVector HitLocation = PlayerTank->GetActorLocation();
		GetControlledTank()->AimAt((HitLocation));
	}
}



ATank *ATankAIController::GetPlayerTank()
{
	auto *PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		auto PlayerPawn = PlayerController->GetPawn();
		return( Cast<ATank>(PlayerPawn));
	}
	return( NULL );
}