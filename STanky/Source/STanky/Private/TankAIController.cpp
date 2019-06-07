// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

}

void ATankAIController::BeginPlay()
{

	Super::BeginPlay();
	CTank = GetControlledTank();
	PTank = GetPlayerTank();
	if(CTank)
		UE_LOG(LogTemp, Error, TEXT("AI Tank #%s"), *(CTank->GetName()));
	if (PTank)
		UE_LOG(LogTemp, Error, TEXT("Player Tank #%s"), *(PTank->GetName()));
}

ATank * ATankAIController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank()
{
	auto Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if(!Pawn) 
	return nullptr;
	return Cast<ATank>(Pawn);
}
