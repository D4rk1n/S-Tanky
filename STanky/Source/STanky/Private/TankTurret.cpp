// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	float DPS = MaxDPS * RelativeSpeed*GetWorld()->DeltaTimeSeconds;
	float NewRotation = (RelativeRotation.Yaw + DPS);
	//NewRotation = FMath::Clamp<float>(NewRotation, MinD, MaxD);
	SetRelativeRotation(FRotator(0, NewRotation,0));
}