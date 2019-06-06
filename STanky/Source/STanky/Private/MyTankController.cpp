// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTankController.h"
#include "Engine/World.h"
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
	AimCrosshair();
}

void AMyTankController::AimCrosshair()
{
	if (!GetControlledTank()) return;
	FVector HitLocation;
	SightRayHit(HitLocation);
	UE_LOG(LogTemp, Warning, TEXT("Hit Location :%s"), *HitLocation.ToString());
}

ATank * AMyTankController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

bool AMyTankController::SightRayHit(FVector & Hit)
{
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	FVector2D ScreenLocation = FVector2D(CrosshairLocationX*ViewPortSizeX, CrosshairLocationY*ViewPortSizeY);
	FVector LookDirection;
	if (GetLookLocation(ScreenLocation, LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction :%s"), *LookDirection.ToString());
		if(GetLookDirection(LookDirection, Hit))
			return true;
	}
	return false;
}

bool AMyTankController::GetLookLocation(FVector2D &ScreenLocation, FVector &WDirection)
{
	FVector WLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WLocation, WDirection);

}
bool AMyTankController::GetLookDirection(FVector LookDirection, FVector &Hit)
{
	FHitResult HitActor;
	auto Start = PlayerCameraManager->GetCameraLocation();
	auto End = Start + LookDirection * LineTraceRange;
	if (GetWorld()->LineTraceSingleByChannel(HitActor, Start, End, ECollisionChannel::ECC_Visibility))
	{
		Hit = HitActor.Location	;
		return true;
	}
	else
	{
		return false;
	}

}


