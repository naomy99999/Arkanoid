// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

class UBoxComponent;
UCLASS()
class ARKANOID_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

<<<<<<< HEAD

=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Brick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* BoxCollision;

<<<<<<< HEAD
	float SpeedModifierOnBounce = 1.0f;
	bool CapsuleGenerationProbability;
	int32 CapsuleCreationOrder;
=======
	float SpeedModifierOnBounce = 1.01f;
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult);

	void DestroyBrick();

<<<<<<< HEAD
	void GenerateCapsule();


=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

<<<<<<< HEAD

=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
};
