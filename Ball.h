// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

<<<<<<< HEAD
class UCapsuleComponent;
=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
class UProjectileMovementComponent;
UCLASS()
class ARKANOID_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	virtual void Lauch();
	bool BallLaunched;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Ball;

<<<<<<< HEAD
	//Colision para el proyectil
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCapsuleComponent* CapsuleCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UProjectileMovementComponent* ProjectileMovement;

	float BallCode;

=======
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UProjectileMovementComponent* ProjectileMovement;

>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		UStaticMeshComponent* GetBall();

<<<<<<< HEAD
	UFUNCTION()
		FVector GetBallLocation();

	UFUNCTION()
		float GetBallCode();
=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
};
