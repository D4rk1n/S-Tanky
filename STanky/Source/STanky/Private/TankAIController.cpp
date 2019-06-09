// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CTank->AimAt(GetPlayerTank()->GetActorLocation()-FVector(0,0,400));
	CTank->Fire();

}

void ATankAIController::BeginPlay()
{

	Super::BeginPlay();
	CTank = Cast<ATank>(GetPawn());
	PTank = GetPlayerTank();

}


ATank * ATankAIController::GetPlayerTank()
{
	auto Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if(!Pawn) 
	return nullptr;
	return Cast<ATank>(Pawn);
}
