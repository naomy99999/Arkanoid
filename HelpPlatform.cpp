// Fill out your copyright notice in the Description page of Project Settings.


#include "HelpPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "PaFM_Capsule.h"

// Sets default values
AHelpPlatform::AHelpPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> HelpPlatformMessAsset(TEXT("StaticMesh'/Game/Assets/Meshes/SM_HelpPlatform.SM_HelpPlatform'"));

	SM_HelpPlatform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM HelpPlatform"));
	SM_HelpPlatform->SetStaticMesh(HelpPlatformMessAsset.Object);
	SM_HelpPlatform->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);


	RootComponent = SM_HelpPlatform;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(182.0f, 6.0f, 6.0f));
	BoxCollision->SetHiddenInGame(false);


	SM_HelpPlatform->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	BoxCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AHelpPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHelpPlatform::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult)
{
	APaFM_Capsule* Capsule = Cast<APaFM_Capsule>(OtherActor);

	if (Capsule)
	{
		Capsule->Destroy();
	}
}

// Called every frame
void AHelpPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

