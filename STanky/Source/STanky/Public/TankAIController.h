// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "Engine.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class STANKY_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	ATank* CTank=nullptr;
	ATank* PTank=nullptr;
public:
	void BeginPlay() override;
	ATank* GetControlledTank();
	ATank* GetPlayerTank();
};
