// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Ball.h"
<<<<<<< HEAD
#include "Projectile.h"

#include "PaFM_HelpCapsuleCreator.h"
#include "PaFM_AntiHelpCapsuleCreator.h"

=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
<<<<<<< HEAD
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BrickMessAsset(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Brick.SM_Brick'"));

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Brick"));
	SM_Brick->SetStaticMesh(BrickMessAsset.Object);
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	RootComponent = SM_Brick;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));
	BoxCollision->SetHiddenInGame(false);
	

	SM_Brick->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	BoxCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	CapsuleGenerationProbability = false;
	CapsuleCreationOrder = 0;
=======

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(25.0f, 11.0f, 11.0f));

	RootComponent = BoxCollision;

>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);

}

void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult)
{

<<<<<<< HEAD
	AProjectile* Projectile = Cast<AProjectile>(OtherActor);

=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
	if (OtherActor->ActorHasTag("Ball")) {
		ABall* MyBall = Cast<ABall>(OtherActor);

		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.0f);

		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrick, 0.1f, false);
<<<<<<< HEAD

		if (CapsuleGenerationProbability)
		{
			GenerateCapsule();
		}
	}

	if (Projectile)
	{
		Projectile->Destroy();
	}
=======
	}


>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
}

void ABrick::DestroyBrick()
{
	this->Destroy();
}

<<<<<<< HEAD
void ABrick::GenerateCapsule()
{

	//Create the Shops
	APaFM_CapsuleCreator* HelpCapsuleCreator = GetWorld()->SpawnActor<APaFM_HelpCapsuleCreator>(APaFM_HelpCapsuleCreator::StaticClass());
	//Create the Shops
	APaFM_CapsuleCreator* AntiHelpCapsuleCreator = GetWorld()->SpawnActor<APaFM_AntiHelpCapsuleCreator>(APaFM_AntiHelpCapsuleCreator::StaticClass());

	APaFM_Capsule* Capsule;

	if (CapsuleCreationOrder == 1)
	{
		//Create an Outer Health Potion and log its name
		Capsule = HelpCapsuleCreator->SetCapsule("TripleBall", GetActorLocation());
	}
	if (CapsuleCreationOrder == 2)
	{
		//Create an Outer Health Potion and log its name
		Capsule = HelpCapsuleCreator->SetCapsule("Life", GetActorLocation());
	}
	if (CapsuleCreationOrder == 3)
	{
		//Create an Outer Health Potion and log its name
		Capsule = HelpCapsuleCreator->SetCapsule("Firing", GetActorLocation());
	}
	if (CapsuleCreationOrder == 4)
	{
		//Create an Outer Health Potion and log its name
		Capsule = HelpCapsuleCreator->SetCapsule("Escalation", GetActorLocation());
	}
	if (CapsuleCreationOrder == 5)
	{
		//Create an Outer Health Potion and log its name
		Capsule = HelpCapsuleCreator->SetCapsule("Speed", GetActorLocation());
	}
	if (CapsuleCreationOrder == 6)
	{
		//Create an Outer Health Potion and log its name
		Capsule = HelpCapsuleCreator->SetCapsule("Platform", GetActorLocation());
	}
	if (CapsuleCreationOrder == 7)
	{
		//Create an Outer Health Potion and log its name
		Capsule = HelpCapsuleCreator->SetCapsule("Double", GetActorLocation());
	}
	if (CapsuleCreationOrder == 8)
	{
		//Create an Outer Health Potion and log its name
		Capsule = AntiHelpCapsuleCreator->SetCapsule("AntiLife", GetActorLocation());
	}
	if (CapsuleCreationOrder == 9)
	{
		//Create an Outer Health Potion and log its name
		Capsule = AntiHelpCapsuleCreator->SetCapsule("AntiSpeed", GetActorLocation());
	}
	if (CapsuleCreationOrder == 10)
	{
		//Create an Outer Health Potion and log its name
		Capsule = AntiHelpCapsuleCreator->SetCapsule("AntiEscalation", GetActorLocation());
	}
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Capsule is %s"),*Capsule->GetCapsuleName()));
}


=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

<<<<<<< HEAD
	CapsuleGenerationProbability = FMath::FRandRange(5, 9) <=2  ? true : false;	// probabilidad de aparicion para cada capsula
	CapsuleCreationOrder = FMath::FRandRange(1, 10);
=======
>>>>>>> bb5e814f30e7367d638ef1325f43d799ed3ba20d
}

