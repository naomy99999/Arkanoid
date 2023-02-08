// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceDesdoblarBall.h"
#include "PaS_DesdoblarBall.generated.h"

UCLASS()
class ARKANOID_API APaS_DesdoblarBall : public AActor
{
	GENERATED_BODY()
	
private:

	IInterfaceDesdoblarBall* DesdoblarBall;

public:	
	// Sets default values for this actor's properties
	APaS_DesdoblarBall();

	// metodo para Desdoblar la pelota (Dividir en dos)
	void DesDoblarBall(AActor* MyBall);
	// metodo para doblar la pelota (Unir)
	void DoblarBall();
};
