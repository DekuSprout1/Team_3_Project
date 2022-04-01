// Fill out your copyright notice in the Description page of Project Settings.


#include "ParticleCollision.h"
#include "Player_Character.h"
#include "Components/BoxComponent.h"

// Sets default values
AParticleCollision::AParticleCollision()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionVolume"));
}

// Called when the game starts or when spawned
void AParticleCollision::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AParticleCollision::OnOverlapBegin);
}


// Called every frame
void AParticleCollision::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AParticleCollision::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		APlayer_Character* Char = Cast<APlayer_Character>(OtherActor);
		if (Char)
		{
			UE_LOG(LogTemp, Warning, TEXT("PARTICLES"));

		}
	}
}