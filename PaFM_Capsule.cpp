// Fill out your copyright notice in the Description page of Project Settings.


#include "PaFM_Capsule.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
APaFM_Capsule::APaFM_Capsule()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CapsuleMessAsset(TEXT("StaticMesh'/Game/Assets/Meshes/Capsule.Capsule'"));

	SM_Capsule = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Capsule"));
	SM_Capsule->SetStaticMesh(CapsuleMessAsset.Object);
	SM_Capsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	RootComponent = SM_Capsule;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(11.0f, 11.0f, 11.0f));

	SM_Capsule->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	BoxCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	VelocityCapsula = 8.f;
}

// Called when the game starts or when spawned
void APaFM_Capsule::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaFM_Capsule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector MoveDirection = FVector(0.0f, 0.0f, -10.0f);//dandole una direccion de movimiento , Calcular movimiento
	const FVector Movement = MoveDirection * VelocityCapsula * DeltaTime;// la velocidad en la que se va mover

	//Si no es de tama�o cero, mueve a este actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);// la rotacion de la capsula

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, false, &Hit);

	}
}

