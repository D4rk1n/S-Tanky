// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	FRotator CurrBarrelR = Barrel->GetForwardVector().Rotation();
	FRotator AimR = AimDirection.Rotation();
	FRotator DeltaR = AimR-CurrBarrelR;
	Barrel->Elevate(5);
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
	if (!Barrel) { 
		UE_LOG(LogTemp, Error, TEXT("Couldn't Find Barrel"));
		
		return; }
	FVector LaunchVelocity;
	bool HaveAim = UGameplayStatics::SuggestProjectileVelocity(this, LaunchVelocity, Barrel->GetSocketLocation(FName("LaunchPoint")), WorldAimLocation, LSpeed, 0, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);
	if (HaveAim)
	{
		FVector AimDirection = LaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Log, TEXT("AimSolution"));
		MoveBarrel(AimDirection);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No AimSolution"));
	}
}

