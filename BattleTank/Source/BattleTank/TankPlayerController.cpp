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