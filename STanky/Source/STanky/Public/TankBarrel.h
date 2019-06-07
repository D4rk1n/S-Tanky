// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent))
class STANKY_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public :
	void Elevate(float DPS);
	UPROPERTY(EditAnyWhere, Category = Setup)
		float MaxDPS = 20;
	UPROPERTY(EditAnyWhere, Category = Setup)
		float MaxD = 70;
	UPROPERTY(EditAnyWhere, Category = Setup)
		float MinD = 0;


};
