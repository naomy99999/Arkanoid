// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaFM_Capsule.generated.h"

class UBoxComponent;
UCLASS()
class ARKANOID_API APaFM_Capsule : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaFM_Capsule();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Capsule;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* BoxCollision;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// metodo para delvolver el nombre de la capsula
	FORCEINLINE FString GetCapsuleName() const { return CapsuleName; }


protected:
	float VelocityCapsula;
	FString CapsuleName;

};
