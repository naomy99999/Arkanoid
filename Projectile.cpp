// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Projectiles.SM_Projectile'"));

	// Create mesh component for the projectile sphere
	SM_Projectile = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Projectile"));
	SM_Projectile->SetStaticMesh(ProjectileMeshAsset.Object);
	RootComponent = SM_Projectile;

	CapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collision"));
	CapsuleCollision->SetCapsuleHalfHeight(10.0f);
	CapsuleCollision->SetCapsuleRadius(10.0f);
	CapsuleCollision->SetupAttachment(GetRootComponent());

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = SM_Projectile;
	ProjectileMovement->InitialSpeed = 500.f;
	ProjectileMovement->MaxSpeed = 500.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

