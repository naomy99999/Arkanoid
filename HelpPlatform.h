// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HelpPlatform.generated.h"

class UBoxComponent;
UCLASS()
class ARKANOID_API AHelpPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHelpPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Malla para la Paleta
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_HelpPlatform;

	//Colision para la paleta
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* BoxCollision;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
