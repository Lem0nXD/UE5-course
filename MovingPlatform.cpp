// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformRotate())
	{
		FVector MoveDirection = VelocityPlatform.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		VelocityPlatform = -VelocityPlatform;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += VelocityPlatform * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
}

bool AMovingPlatform::ShouldPlatformRotate()
{
	return GetDistanceMoved() > MoveDistance;
}

double AMovingPlatform::GetDistanceMoved()
{
	return FVector::Dist(GetActorLocation(),StartLocation);
}
 
void AMovingPlatform::RotatePlatform(float DeltaTime)
{

}
