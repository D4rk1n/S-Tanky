// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::AimAt(FVector  HitLocation)
{
	
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::SetBarrel(UTankBarrel * B)
{
	TankAimingComponent->SetBarrel(B);
	Barrel = B;
}

void ATank::SetTurret(UTankTurret * T)
{
	TankAimingComponent->SetTurret(T);
}

void ATank::Fire()
{
	if (!Barrel) return;
	FVector Location = Barrel->GetSocketLocation(FName("LaunchPoint")); 
	FRotator R = Barrel->GetSocketRotation(FName("LaunchPoint"));
	AProjectile* Project =(AProjectile*) GetWorld()->SpawnActor(Projectile,&Location,&R); //Casting AActor * to AProjectile *
	Project->Launch(LaunchSpeed);
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

