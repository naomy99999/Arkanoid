// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball.h"
#include "InterfaceDesdoblarBall.h"
#include "PaS_Ball.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API APaS_Ball : public ABall, public IInterfaceDesdoblarBall
{
	GENERATED_BODY()
	
public:

	void DividirBall() override;

	void UnirBall() override;


protected:

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj;

	ABall* MyBall;
	FVector SpawnLocation = FVector(0.0f, 0.0f, 40.0f);
	FRotator SpawnRotator = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
};
