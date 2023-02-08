// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaFM_Capsule.h"
#include "PaFM_CapsuleCreator.generated.h"

UCLASS()
class ARKANOID_API APaFM_CapsuleCreator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaFM_CapsuleCreator();

	//Crear Capsula y devolverla. Es puramente virtual, por lo que no necesita una implementaci�n en esta clase
	virtual APaFM_Capsule* ConcoctCapsule(FString CapsulaSKU, FVector CapsuleLocation) PURE_VIRTUAL(APaFM_CapsuleCreator::ConcoctCapsule, return nullptr;);

	//Ordena, elabora y devuelve una Capsula de una categor�a espec�fica
	APaFM_Capsule* SetCapsule(FString CapsulaSKU,FVector CapsuleLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
