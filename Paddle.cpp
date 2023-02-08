// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"
<<<<<<< HEAD
#include "Components/BoxComponent.h"
#include <Kismet/GameplayStatics.h>

#include "PaFM_Capsule.h"

#include "Projectile.h"
#include "HelpPlatform.h"
#include "Ball.h"
#include "PaddlePlayerController.h"
=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d

// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

<<<<<<< HEAD
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PaddleMessAsset(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Paddle.SM_Paddle'"));

	SM_Paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Paddle"));
	SM_Paddle->SetStaticMesh(PaddleMessAsset.Object);
=======
	SM_Paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Paddle"));
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
	RootComponent = SM_Paddle;

	SM_Paddle->SetEnableGravity(false);
	SM_Paddle->SetConstraintMode(EDOFMode::XZPlane);
	SM_Paddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Paddle->SetCollisionProfileName(TEXT("PhisicActor"));

<<<<<<< HEAD
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(31.5f, 6.0f, 6.0f));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));

	// Weapon
	GunOffset = FVector(20.f, 0.f, 0.f);
	FireRate = 0.5f;
	ProjectileShoot = false;

	SM_Paddle->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	BoxCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
=======
	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));

>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
}

void APaddle::MoveHorizontal(float AxisValue)
{
	AddMovementInput(FVector(AxisValue, 0.0f, 0.0), 1.0f, false);
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	
<<<<<<< HEAD
	PlayerControllerREF = Cast<APaddlePlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

void APaddle::NotifyActorBeginOverlap(AActor* OtherActor)
{
	APaFM_Capsule* Capsule = Cast<APaFM_Capsule>(OtherActor);

	if (Capsule)
	{
		if (Capsule->GetCapsuleName() == "TripleBall")
		{
			Capsule->Destroy();

			PlayerControllerREF->SpawnTripleBall();
			
		}
		if (Capsule->GetCapsuleName() == "Life")
		{
			Capsule->Destroy();
		}
		if (Capsule->GetCapsuleName() == "Firing")
		{
			Capsule->Destroy();
			ProjectileShoot = true;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &APaddle::ShootProjectile, 4.0f, false);
		}
		if (Capsule->GetCapsuleName() == "Escalation")
		{
			Capsule->Destroy();
			SM_Paddle->SetRelativeScale3D(FVector(1.5f, 1.0f, 1.0f));
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &APaddle::EscalePaddle, 4.0f, false);
		}
		if (Capsule->GetCapsuleName() == "Platform")
		{
			Capsule->Destroy();
			FVector HelpPlatformLocation(0.0f,0.0f,-10.0f);
			HelpPlatform = GetWorld()->SpawnActor<AHelpPlatform>(AHelpPlatform::StaticClass(), HelpPlatformLocation, FRotator::ZeroRotator);
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &APaddle::DestroyPlatform, 4.0f, false);
		}
		if (Capsule->GetCapsuleName() == "Speed")
		{
			Capsule->Destroy();
			FloatingMovement->MaxSpeed = 800;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &APaddle::SpeedPaddle, 4.0f, false);
		}
		if (Capsule->GetCapsuleName() == "Double")
		{
			Capsule->Destroy();
			PlayerControllerREF->SpawnDoubleBall();
		}
		if (Capsule->GetCapsuleName() == "AntiLife")
		{
			Capsule->Destroy();
		}
		if (Capsule->GetCapsuleName() == "AntiSpeed")
		{
			Capsule->Destroy();
			FloatingMovement->MaxSpeed = 200;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &APaddle::SpeedPaddle, 4.0f, false);
		}
		if (Capsule->GetCapsuleName() == "AntiEscalation")
		{
			Capsule->Destroy();
			SM_Paddle->SetRelativeScale3D(FVector(0.5f, 1.0f, 1.0f));
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &APaddle::EscalePaddle, 4.0f, false);
		}
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Capsule is %s"), *Capsule->GetCapsuleName()));
	}
}

void APaddle::FireShot()
{

	FVector FireDirection(0.f, 0.f, 400.f);
	const FVector Spawn = GetActorLocation() + FVector(-30.0f, 0.0f, 0.0f);
	const FVector Spawn2 = GetActorLocation() + FVector(30.0f, 0.0f, 0.0f);
	const FRotator FireRotation = FireDirection.Rotation();

	// Spawn projectile at an offset from this pawn
	const FVector SpawnLocation = Spawn + FireRotation.RotateVector(GunOffset);

	// Spawn projectile at an offset from this pawn
	const FVector SpawnLocation2 = Spawn2 + FireRotation.RotateVector(GunOffset);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		// spawn the projectile
		World->SpawnActor<AProjectile>(SpawnLocation, FireRotation);
		World->SpawnActor<AProjectile>(SpawnLocation2, FireRotation);
	}

}


void APaddle::EscalePaddle()
{
	SM_Paddle->SetRelativeScale3D(FVector(1.0f,1.0f,1.0f));
}

void APaddle::SpeedPaddle()
{
	FloatingMovement->MaxSpeed = 450;
}

void APaddle::ShootProjectile()
{
	ProjectileShoot = false;
}

void APaddle::DestroyPlatform()
{
	HelpPlatform->Destroy();
}



=======
}

>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

<<<<<<< HEAD
	if (ProjectileShoot)
	{
		FireRate -= DeltaTime;
		if (FireRate <= 0.0f)
		{
			FireShot();
			FireRate = 0.5f;
		}
	}
=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

