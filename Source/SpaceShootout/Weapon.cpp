// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Components/InputComponent.h"

// Sets default values for this component's properties
UWeapon::UWeapon()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeapon::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UWeapon::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (fired)
	{
		fireTimer += DeltaTime;
		if (fireTimer >= fireCooldown)
		{
			fired = false;
			fireTimer = 0;
		}
	}
}

void UWeapon::Fire()
{
	if (!fired)
	{
		fired = true;
		fireEffect = true;

		UE_LOG(LogTemp, Warning, TEXT("Entre"));
		GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(viewDirection, viewRotation);
		ABullet* tempBullet = GetWorld()->SpawnActor<ABullet>(bullet, viewDirection, viewRotation);
	}
	//tempBullet->AssignOwner(myOwner);
}

void UWeapon::AssignOwner(AActor* myHolder)
{
	myOwner = myHolder;
}