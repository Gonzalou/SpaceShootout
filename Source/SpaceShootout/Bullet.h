// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class SPACESHOOTOUT_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABullet();
	UPROPERTY(EditAnywhere)
		float speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float damage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
		AActor* myOwner;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AssignOwner(AActor* myMaster);
};
