// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PaddlePlayerController.generated.h"

/**
 * 
 */
class ABall;
UCLASS()
class ARKANOID_API APaddlePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	APaddlePlayerController();

	UFUNCTION()
		virtual void SetupInputComponent() override;

	void SpawnNewBall();

<<<<<<< HEAD
	void SpawnTripleBall();

	void SpawnDoubleBall();

	TMap<float, ABall*> GetBallContainer();


	void DestroyBall(AActor* OtherActor);

=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
protected:

	virtual void BeginPlay() override;

	void MoveHorizontal(float AxisValue);


	void Lanch();

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj;

	ABall* MyBall;
<<<<<<< HEAD
	FVector SpawnLocation = FVector(0.0f, 0.0f, 40.0f);
	FRotator SpawnRotator = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;


	TMap<float ,ABall* > BallContainer;
	TArray<float> BallCodeContainer;

	///////Examen De verano/////////////

	void Desdoblar();
	void Doblar();

	FTimerHandle UnusedHandle;

	//////////////////////////////////
=======
	FVector SpawnLocation = FVector(10.0f, 0.0f, 40.0f);
	FRotator SpawnRotator = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
};
