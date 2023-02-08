// Fill out your copyright notice in the Description page of Project Settings.


#include "PaFM_CapsuleCreator.h"

// Sets default values
APaFM_CapsuleCreator::APaFM_CapsuleCreator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APaFM_CapsuleCreator::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APaFM_CapsuleCreator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

APaFM_Capsule* APaFM_CapsuleCreator::SetCapsule(FString CapsulaSKU, FVector CapsuleLocation)
{
	APaFM_Capsule* Capsule = ConcoctCapsule(CapsulaSKU, CapsuleLocation);

	return Capsule;

}
