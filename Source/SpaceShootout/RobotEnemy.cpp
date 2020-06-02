// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotEnemy.h"
#include "Engine/World.h"
#include "FPSController.h"
#include "Engine/EngineTypes.h"

// Sets default values
ARobotEnemy::ARobotEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARobotEnemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARobotEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (ScanForPlayer())
	{
		MoveToPlayer(DeltaTime);
	}
}

bool ARobotEnemy::ScanForPlayer()
{
	FHitResult hit;
	FVector startPoint = GetActorLocation();
	FVector forward = GetActorForwardVector();
	FVector endPosition = startPoint + (forward * viewDistance);
	FCollisionQueryParams collisionParams;
	if (GetWorld()->LineTraceSingleByChannel(hit, startPoint, endPosition, ECC_Visibility, collisionParams))
	{
		return hit.GetActor()->GetName() == "FPSController";
	}
	return false;
}

void ARobotEnemy::MoveToPlayer(float DeltaTime)
{
	if (FVector::Dist(GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation()) < fireDistance)
	{
		SetActorLocation(GetActorLocation() + GetActorForwardVector() * speed * DeltaTime);
	} else
	{
		if (fireTimer >= fireCooldown)
		{
			GetWorld()->SpawnActor<ABullet>(bullet);
			fireTimer = 0.f;
		} else
		{
			fireTimer += DeltaTime;
		}
	}
}