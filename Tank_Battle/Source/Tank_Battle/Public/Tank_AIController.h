// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "AIController.h"
#include "Tank_AIController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_BATTLE_API ATank_AIController : public AAIController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	ATank* GetControlledPawn();

	ATank* GetPlayerTank();

private:

	

	
	
};

