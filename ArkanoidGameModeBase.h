// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArkanoidGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AArkanoidGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
<<<<<<< HEAD

public:
	AArkanoidGameModeBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class ABrick* Brick;
=======
	
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
};
