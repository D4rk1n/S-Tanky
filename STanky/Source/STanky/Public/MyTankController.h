// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyTankController.generated.h"

/**
 * 
 */
UCLASS()
class STANKY_API AMyTankController : public APlayerController
{
	GENERATED_BODY()
		UPROPERTY( EditAnywhere)
			float CrosshairLocationX = .5;
	    UPROPERTY(EditAnywhere)
			float CrosshairLocationY = 1.0/3.0;
		UPROPERTY(EditAnywhere)
			float LineTraceRange = 1e6;
		void BeginPlay() override;
		void Tick(float DeltaTime) override;
		void AimCrosshair();
		ATank* GetControlledTank();
		bool SightRayHit(FVector &Hit);

		bool GetLookLocation(FVector2D &ScreenLocation, FVector &WDirection);

		bool GetLookDirection(FVector LookDirection, FVector & Hit);
	
};
