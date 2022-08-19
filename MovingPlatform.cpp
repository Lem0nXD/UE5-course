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
	StartLocation = GetActorLocation();
	FString Name = GetName();
	UE_LOG(LogTemp, Display, TEXT("Actor is: %s"), *Name);
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
		AddActorWorldOffset(VelocityPlatform * DeltaTime);
	}
}

bool AMovingPlatform::ShouldPlatformRotate() const
{
	return GetDistanceMoved() > MoveDistance;
}

double AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
 
void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(VelocityRotation * DeltaTime);
}
