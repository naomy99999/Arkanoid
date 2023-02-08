// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PaB_InterfaceBoss.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPaB_InterfaceBoss : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARKANOID_API IPaB_InterfaceBoss
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//The pure virtual functions of the FloorPlan

	virtual void SetBossDesign(FString _BossDesign) = 0;
	virtual void SetShieldSystem(FString _ShieldSystem) = 0;
	virtual void SetSpawnBossDefense(FString _SpawnBossDefense) = 0;
};
