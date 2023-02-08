// Fill out your copyright notice in the Description page of Project Settings.


#include "PaS_Ball.h"

void APaS_Ball::DividirBall()
{
	if (!MyBall) {
		MyBall = nullptr;
	}

	if (BallObj) {
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotator, SpawnInfo);
	}
}

void APaS_Ball::UnirBall()
{
	MyBall->Destroy();
}
