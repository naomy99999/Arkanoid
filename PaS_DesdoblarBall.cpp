 // Fill out your copyright notice in the Description page of Project Settings.


#include "PaS_DesdoblarBall.h"

// Sets default values
APaS_DesdoblarBall::APaS_DesdoblarBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APaS_DesdoblarBall::DesDoblarBall(AActor* MyBall)
{
	DesdoblarBall = Cast<IInterfaceDesdoblarBall>(MyBall);

	if (!DesdoblarBall)
	{
		UE_LOG(LogTemp, Error, TEXT("AlterShoot(): ¡El actor no es una estrategia de ChangeWeapon! ¿Estás seguro de que el actor implementa esa interfaz? "));
	}
}

void APaS_DesdoblarBall::DoblarBall()
{
	if (!DesdoblarBall)
	{
		UE_LOG(LogTemp, Error, TEXT("Change(): ChangeWeapon es NULL, asegúrese de que esté inicializado."));
		return;
	}
	DesdoblarBall->DividirBall();
}





