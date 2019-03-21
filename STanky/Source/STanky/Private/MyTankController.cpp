// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTankController.h"

void AMyTankController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank()) {
		UE_LOG(LogTemp, Warning, TEXT("controlled %s"), *(GetControlledTank()->GetName()));
	}
}

ATank * AMyTankController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}
