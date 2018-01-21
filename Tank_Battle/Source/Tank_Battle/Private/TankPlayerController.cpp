// Fill out your copyright notice in the Description page of Project Settings.

#include "public/TankPlayerController.h"


void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay Active!"));

	auto PossedTank = GetControlledTank();

	
	if (PossedTank==nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No tank possesd!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Possed actor is %s"), *PossedTank->GetName());
		
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
	
}