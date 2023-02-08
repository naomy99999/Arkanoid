// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
<<<<<<< HEAD
#include "Components/CapsuleComponent.h"
=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

<<<<<<< HEAD
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMeshAsset(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Ball.SM_Ball'"));

	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Ball"));
	SM_Ball->SetStaticMesh(BallMeshAsset.Object);
=======
	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	RootComponent = SM_Ball;

>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
	SM_Ball->SetSimulatePhysics(true);
	SM_Ball->SetEnableGravity(false);
	SM_Ball->SetConstraintMode(EDOFMode::XZPlane);
	SM_Ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Ball->SetCollisionProfileName(TEXT("PhysicsActor"));
<<<<<<< HEAD
	RootComponent = SM_Ball;

	CapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collision"));
	CapsuleCollision->SetCapsuleHalfHeight(5.2f);
	CapsuleCollision->SetCapsuleRadius(5.2f);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
=======

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement "));
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d

	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.1f;
	ProjectileMovement->Friction = 0.0f;
	ProjectileMovement->Velocity.X = 0.0f;

<<<<<<< HEAD
	SM_Ball->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	CapsuleCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	BallCode = FMath::FRandRange(1, 99999);
=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
}

void ABall::Lauch()
{

	if (!BallLaunched) {
		SM_Ball->AddImpulse(FVector(140.0f, 0.0f, 130.0f), FName(), true);
		BallLaunched = true;
	}

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
<<<<<<< HEAD
=======

>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
}

UStaticMeshComponent* ABall::GetBall()
{
	return SM_Ball;
}

<<<<<<< HEAD
FVector ABall::GetBallLocation()
{
	return GetActorLocation();
}

float ABall::GetBallCode()
{
	return BallCode;
}

=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
