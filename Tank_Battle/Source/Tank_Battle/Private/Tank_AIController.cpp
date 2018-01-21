// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_AIController.h"

void ATank_AIController::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AIcontroller BeginPlay() activated"));

	auto ControlledAITank = GetControlledPawn();
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI tank reporting: Player has no tank!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI tank reporting: Player tank is %s"), *PlayerTank->GetName());
	}
	if (!ControlledAITank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI controller missing a pawn"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller is possesing %s"), *ControlledAITank->GetName());
	}

}

ATank* ATank_AIController::GetControlledPawn()
{
	return Cast<ATank>(GetPawn());
	
}

ATank* ATank_AIController::GetPlayerTank()
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


