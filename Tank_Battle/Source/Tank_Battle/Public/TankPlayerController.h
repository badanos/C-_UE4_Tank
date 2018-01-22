// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank_Battle.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Public/UObject/Class.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "public/tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()

class TANK_BATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	void BeginPlay() override;

	void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation=.5f;
	
	UPROPERTY(EditAnywhere)
	float CrosshairdYLocation=.3f;


private:

	// moves tank barrel towards crosshair
	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	// returns the location of crosshair according to viewport size

	FVector2D GetCrosshairScreenLocation() const;
	
};
