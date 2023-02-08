// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Paddle.generated.h"

<<<<<<< HEAD
class ABall;
class UBoxComponent;
=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
class UFloatingPawnMovement;
UCLASS()
class ARKANOID_API APaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APaddle();

	virtual void MoveHorizontal(float AxisValue);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Malla para la Paleta
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Paddle;
<<<<<<< HEAD
	
	//Colision para la paleta
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* BoxCollision;
=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d

	//Movimiento para la Paleta
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* FloatingMovement;

<<<<<<< HEAD
	UFUNCTION() //Entra en la caja
		virtual void NotifyActorBeginOverlap(AActor* OtherActor) override; //Funcion virtual pura de la colision


	void FireShot();


	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;

	void EscalePaddle();
	void SpeedPaddle();
	void ShootProjectile();
	void DestroyPlatform();

	FTimerHandle UnusedHandle;

	bool ProjectileShoot;

	class AHelpPlatform* HelpPlatform;

	class APaddlePlayerController* PlayerControllerREF;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj;

	ABall* MyBall;
	FVector SpawnLocationBall = FVector(-10.0f, 0.0f, 40.0f);
	FRotator SpawnRotator = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

	FVector DirectionImpulse = FVector(140.0f, 0.0f, 130.0f);
=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
