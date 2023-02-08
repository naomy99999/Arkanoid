// Fill out your copyright notice in the Description page of Project Settings.


#include "PaFM_AntiHelpCapsuleCreator.h"
#include "PaFM_Capsule.h"
#include "PaFM_AntiLifeCapsule.h"
#include "PaFM_AntiEscalationCapsule.h"
#include "PaFM_AntiSpeedCapsule.h"

APaFM_Capsule* APaFM_AntiHelpCapsuleCreator::ConcoctCapsule(FString CapsulaSKU, FVector CapsuleLocation)
{
	if (CapsulaSKU.Equals("AntiLife")) {
		return GetWorld()->SpawnActor<APaFM_AntiLifeCapsule>(APaFM_AntiLifeCapsule::StaticClass(), CapsuleLocation, FRotator::ZeroRotator);

	}
	if (CapsulaSKU.Equals("AntiSpeed")) {
		return GetWorld()->SpawnActor<APaFM_AntiSpeedCapsule>(APaFM_AntiSpeedCapsule::StaticClass(), CapsuleLocation, FRotator::ZeroRotator);

	}
	if (CapsulaSKU.Equals("AntiEscalation")) {
		return GetWorld()->SpawnActor<APaFM_AntiEscalationCapsule>(APaFM_AntiEscalationCapsule::StaticClass(), CapsuleLocation, FRotator::ZeroRotator);

	}
	return nullptr;
}
