// Fill out your copyright notice in the Description page of Project Settings.


#include "NextWaypointCollision.h"
#include "Player_Character.h"
#include "Components/BoxComponent.h"
#include "CatAI.h"
// Sets default values
ANextWaypointCollision::ANextWaypointCollision()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CollisionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionVolume"));
}

// Called when the game starts or when spawned
void ANextWaypointCollision::BeginPlay()
{
	Super::BeginPlay();
	
    CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &ANextWaypointCollision::OnOverlapBegin);
}

// Called every frame
void ANextWaypointCollision::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANextWaypointCollision::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor)
    {
        APlayer_Character* Char = Cast<APlayer_Character>(OtherActor);
        if (Char)
        {
                Cat-> CurrentWaypoint++;
                Cat-> MoveToWaypoints();
                UE_LOG(LogTemp, Warning, TEXT("Next waypoint ++"));
                Destroy();

        }
    }
}
