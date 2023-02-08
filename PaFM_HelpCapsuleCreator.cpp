// Fill out your copyright notice in the Description page of Project Settings.


#include "PaFM_HelpCapsuleCreator.h"
#include "PaFM_Capsule.h"
#include "PaFM_TripleBallCapsule.h"
#include "PaFM_EscalationCapsule.h"
#include "PaFM_LifeCapsule.h"
#include "PaFM_FiringCapsule.h"
#include "PaFM_PlatformCapsule.h"
#include "PaFM_SpeedCapsule.h"
#include "PaFM_DoubleCapsule.h"

APaFM_Capsule* APaFM_HelpCapsuleCreator::ConcoctCapsule(FString CapsulaSKU, FVector CapsuleLocation)
{
	if (CapsulaSKU.Equals("TripleBall")) {
		return GetWorld()->SpawnActor<APaFM_TripleBallCapsule>(APaFM_TripleBallCapsule::StaticClass(), CapsuleLocation, FRotator::ZeroRotator);

	}
	if (CapsulaSKU.Equals("Life")) {
		return GetWorld()->SpawnActor<APaFM_LifeCapsule>(APaFM_LifeCapsule::StaticClass(), CapsuleLocation, FRotator::ZeroRotator);

	}
	if (CapsulaSKU.Equals("Firing")) {
		return GetWorld()->SpawnActor<APaFM_FiringCapsule>(APaFM_FiringCapsule::StaticClass(), CapsuleLocation, FRotator::ZeroRotator);

	}
	if (CapsulaSKU.Equals("Escalation")) {
		return GetWorld()->SpawnActor<APaFM_EscalationCapsule>(APaFM_EscalationCapsule::StaticClass(), CapsuleLocation, FRotator::ZeroRotator);

	}
	if (CapsulaSKU.Equals("Platform")) {
		return GetWorld()->SpawnActor<APaFM_PlatformCapsule>(APaFM_PlatformCapsule::StaticClass(), CapsuleLocation, FRotator::ZeroRotator);

	}
	if (CapsulaSKU.Equals("Speed")) {
		return GetWorld()->SpawnActor<APaFM_SpeedCapsule>(APaFM_SpeedCapsule::StaticClass(), CapsuleLocation, FRotator::ZeroRotator);

	}
	if (CapsulaSKU.Equals("Double")) {
		return GetWorld()->SpawnActor<APaFM_DoubleCapsule>(APaFM_DoubleCapsule::StaticClass(), CapsuleLocation, FRotator::ZeroRotator);

	}
    return nullptr;
}
