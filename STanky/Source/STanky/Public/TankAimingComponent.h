// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Kismet/GameplayStatics.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"
#include"Engine/Classes/Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STANKY_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()


private:
	UTankBarrel * Barrel;
	UTankTurret * Turret;
	void MoveBarrel(FVector AimDirection);
	void MoveTurret(FVector AimDirection);
public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void SetBarrel(UTankBarrel* Barrel);
	void SetTurret(UTankTurret* Turret);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AimAt(FVector WorldAim, float LSpeed);
		
};
