// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Ball.h"
#include "Paddle.h"

APaddlePlayerController::APaddlePlayerController()
{
}

void APaddlePlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();

	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &APaddlePlayerController::MoveHorizontal);

	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddlePlayerController::Lanch);

<<<<<<< HEAD
	InputComponent->BindAction("Desdoblar", IE_Pressed, this, &APaddlePlayerController::Desdoblar);

=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
}

void APaddlePlayerController::SpawnNewBall()
{

	if (!MyBall) {
		MyBall = nullptr;
	}

	if (BallObj) {
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotator, SpawnInfo);
<<<<<<< HEAD
		BallContainer.Add(MyBall->GetBallCode(), MyBall);
		BallContainer.GenerateKeyArray(BallCodeContainer);
	}
}

void APaddlePlayerController::SpawnTripleBall()
{
	
	FVector SpawnLocationTripleBall = FVector(-10.0f, 0.0f, 40.0f);
	FVector DirectionImpulse = FVector(150.0f, 0.0f, 140.0f);
	for (int i=0;i<=2;i++)
	{
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocationTripleBall, SpawnRotator, SpawnInfo);
		MyBall->GetBall()->AddImpulse(DirectionImpulse, FName(), true);
		BallContainer.Add(MyBall->GetBallCode(), MyBall);
		BallContainer.GenerateKeyArray(BallCodeContainer);
		DirectionImpulse = DirectionImpulse * FVector(-1.0f, 1.0f, 1.0f);
=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
	}

}

<<<<<<< HEAD
void APaddlePlayerController::SpawnDoubleBall()
{

	FVector BallLocation = MyBall->GetActorLocation();
	FVector DirectionImpulse = FVector(150.0f, 0.0f, 140.0f);
	for (int i = 0; i <= 1; i++)
	{
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, BallLocation, SpawnRotator, SpawnInfo);
		MyBall->GetBall()->AddImpulse(DirectionImpulse, FName(), true);
		BallContainer.Add(MyBall->GetBallCode(), MyBall);
		BallContainer.GenerateKeyArray(BallCodeContainer);
		DirectionImpulse = DirectionImpulse * FVector(-1.0f, 1.0f, 1.0f);
	}
	
}


TMap<float, ABall* > APaddlePlayerController::GetBallContainer()
{
	return BallContainer;
}


void APaddlePlayerController::DestroyBall(AActor* OtherActor)
{
	class ABall* Ball = Cast<ABall>(OtherActor);
	
	BallContainer.Remove(Ball->GetBallCode());
	BallContainer.GenerateKeyArray(BallCodeContainer);
	if (BallContainer.Num() >= 1)
	{
		MyBall = BallContainer[BallCodeContainer[0]];
	}

	OtherActor->Destroy();
	
}

=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
void APaddlePlayerController::BeginPlay()
{

	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

	SpawnNewBall();

}

void APaddlePlayerController::MoveHorizontal(float AxisValue)
{

	auto MyPawn = Cast<APaddle>(GetPawn());

	if (MyPawn) {
		MyPawn->MoveHorizontal(AxisValue);
	}

}

void APaddlePlayerController::Lanch()
{
	MyBall->Lauch();
}
<<<<<<< HEAD



void APaddlePlayerController::Desdoblar()
{
	FVector BallLocation = MyBall->GetActorLocation();

	MyBall = GetWorld()->SpawnActor<ABall>(BallObj, BallLocation, SpawnRotator, SpawnInfo);

	BallContainer.Add(MyBall->GetBallCode(), MyBall);
	BallContainer.GenerateKeyArray(BallCodeContainer);

	GetWorldTimerManager().SetTimer(UnusedHandle, this, &APaddlePlayerController::Doblar, 3.0f, false);

}

void APaddlePlayerController::Doblar()
{
	DestroyBall(MyBall);
}






=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
