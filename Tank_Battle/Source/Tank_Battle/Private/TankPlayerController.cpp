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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
	
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;

	
	
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit location : %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	auto ScreenLocation = GetCrosshairScreenLocation();

	FHitResult HitResult;
	float TankRange = 1000.f;
	FVector ControlledTankLocation;
	FRotator ControlledTankRotation;

	GetPlayerViewPoint(ControlledTankLocation, ControlledTankRotation);
	FVector TankMaximumHitLocation = TankRange * ControlledTankLocation + ControlledTankLocation;


	GetWorld()->LineTraceSingleByObjectType(
		HitResult,
		ControlledTankLocation,
		TankMaximumHitLocation,
		ECollisionChannel::ECC_WorldStatic,
		FCollisionQueryParams(FName(TEXT("")), false, GetOwner())
	);

	OutHitLocation = HitResult.Location;

	// raycast from current tank
	// if hit
	//return hit location
	return HitResult.bBlockingHit;
}

FVector2D ATankPlayerController::GetCrosshairScreenLocation() const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	return FVector2D(
		ViewportSizeX*CrosshairXLocation,
		ViewportSizeY*CrosshairdYLocation
	);
	
	
}

