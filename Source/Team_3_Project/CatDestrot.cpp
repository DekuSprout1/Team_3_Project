// Fill out your copyright notice in the Description page of Project Settings.


#include "CatDestrot.h"
#include "Components/BoxComponent.h"

// Sets default values
ACatDestrot::ACatDestrot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CollisionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionVolume"));
    
}

// Called when the game starts or when spawned
void ACatDestrot::BeginPlay()
{
	Super::BeginPlay();
	
    CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &ACatDestrot::OnOverlapBegin);
}

// Called every frame
void ACatDestrot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACatDestrot::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor)
    {
        ACatAI* Char = Cast<ACatAI>(OtherActor);
        if (Char)
        {
                UE_LOG(LogTemp, Warning, TEXT("Next waypoint ++"));
                Destroy(Char);
        }
    }
};
