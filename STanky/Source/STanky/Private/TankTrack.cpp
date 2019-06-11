// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
void UTankTrack::SetThrottle(float v)
{
	UE_LOG(LogTemp, Warning, TEXT("%s throttling at %f"), *GetName(), v);
	auto ForceA= GetForwardVector() * v * Force;
	auto ForceL = GetComponentLocation();
	
	auto Root = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()); //primitive component to apply force
	Root->AddForceAtLocation(ForceA, ForceL);
}