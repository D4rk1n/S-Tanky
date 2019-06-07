// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	float DPS = MaxDPS * RelativeSpeed*GetWorld()->DeltaTimeSeconds;
	float NewElevation = (RelativeRotation.Pitch + DPS);
	NewElevation = FMath::Clamp<float>(NewElevation, MinD, MaxD);
	SetRelativeRotation(FRotator(NewElevation, 0, 0));
	//UE_LOG(LogTemp, Warning, TEXT("UTankBarrel at %f") ,*NeWElevation);
}
