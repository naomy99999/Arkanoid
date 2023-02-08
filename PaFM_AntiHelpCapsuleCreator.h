// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaFM_CapsuleCreator.h"
#include "PaFM_AntiHelpCapsuleCreator.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API APaFM_AntiHelpCapsuleCreator : public APaFM_CapsuleCreator
{
	GENERATED_BODY()
	
public:

	//Fabricar la Capsula seleccionada
	virtual APaFM_Capsule* ConcoctCapsule(FString CapsulaSKU, FVector CapsuleLocation) override;

};
