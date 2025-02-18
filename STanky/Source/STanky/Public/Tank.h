// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class AProjectile;

UCLASS()
class STANKY_API ATank : public APawn
{
	GENERATED_BODY()
private:
	UTankBarrel * Barrel;
	float ReloadTime;
	double LastFireTime;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponent = nullptr;
	UFUNCTION(BlueprintCallable , Category = Setup)
		void SetBarrel(UTankBarrel* B);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurret(UTankTurret* T);
	UPROPERTY(EditAnyWhere, Category = Firing)
		float LaunchSpeed = 100000;
	UPROPERTY(EditAnyWhere, Category = Firing)
		TSubclassOf<AProjectile>  Projectile = nullptr;
public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector HitLocation);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable, Category = Input)
		void Fire();
	

};

