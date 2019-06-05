// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTankController.h"

void AMyTankController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank()) {
		UE_LOG(LogTemp, Warning, TEXT("controlled %s"), *(GetControlledTank()->GetName()));
	}
}
void AMyTankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Log, TEXT("ana 7aly m4 3agbny"));
}

ATank * AMyTankController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}


