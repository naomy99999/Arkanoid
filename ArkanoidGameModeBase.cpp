// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArkanoidGameModeBase.h"

<<<<<<< HEAD
#include "Brick.h"


AArkanoidGameModeBase::AArkanoidGameModeBase()
{
}

void AArkanoidGameModeBase::BeginPlay()
{
	






	/////////////////////// Spawn Matriz de Bricks ////////////////// 

	FVector SpawnBrick(-137.0f, 0.0f, 350.0f);
	FVector SumadorEjeX(55.0f, 0.0f, 0.0f);
	FVector AuxSpawn(0.0f, 0.0f, 0.0f);
	FVector RestadorEjeZ(0.0f, 0.0f, 26.0f);
	FRotator Rotacion(0.0f, 0.0f, 0.0f);
	//Color = "Green";
	for (int i = 0; i <= 5; i++)
	{
		AuxSpawn = SpawnBrick;
		for (int j = 0; j <= 4; j++)
		{
			Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), SpawnBrick, Rotacion);
			//Brick->SetColorBrick(Color);
			SpawnBrick = SpawnBrick - RestadorEjeZ;
			//PaddleController->Contador++;
		}
		SpawnBrick = AuxSpawn;
		SpawnBrick = SpawnBrick + SumadorEjeX;
	}

	////////////////////////////////////////////////////////////////////////////
}
=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
