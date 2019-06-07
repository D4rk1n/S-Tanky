// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	FRotator CurrBarrelR = Barrel->GetForwardVector().Rotation();
	FRotator AimR = AimDirection.Rotation();
	FRotator DeltaR = AimR-CurrBarrelR;
	//UE_LOG(LogTemp, Log, TEXT("Pitch : %f"), DeltaR.Pitch);
	Barrel->Elevate(DeltaR.Pitch);
}

void UTankAimingComponent::MoveTurret(FVector AimDirection)
{
	FRotator CurrTurretR = Turret->GetForwardVector().Rotation();
	FRotator AimR = AimDirection.Rotation();
	FRotator DeltaR = AimR - CurrTurretR;
	//UE_LOG(LogTemp, Log, TEXT("Pitch : %f"), DeltaR.Pitch);
	Turret->Rotate(DeltaR.Yaw);
}

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrel(UTankBarrel * Barrel)
{
	this->Barrel = Barrel;
	
}

void UTankAimingComponent::SetTurret(UTankTurret * Turret)
{
	this->Turret = Turret;
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector WorldAimLocation, float LSpeed)
{
	if (!Barrel||!Turret) { 
		if (!Barrel) UE_LOG(LogTemp, Error, TEXT("Couldn't Find Barrel"));
		if(!Turret) UE_LOG(LogTemp, Error, TEXT("Couldn't Find Turret"));
		
		return; }
	FVector LaunchVelocity;
	bool HaveAim = UGameplayStatics::SuggestProjectileVelocity(this, LaunchVelocity, Barrel->GetSocketLocation(FName("LaunchPoint")), WorldAimLocation, LSpeed, 0, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);
	if (HaveAim)
	{
		FVector AimDirection = LaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
		MoveTurret(AimDirection);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No AimSolution"));
	}
}

