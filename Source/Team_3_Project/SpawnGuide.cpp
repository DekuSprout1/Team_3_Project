// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnGuide.h"
#include "Components/BoxComponent.h"
#include "Player_Character.h"
#include "CatAI.h"

// Sets default values
ASpawnGuide::ASpawnGuide()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
    SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));

    SpawnVolume->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ASpawnGuide::BeginPlay()
{
	Super::BeginPlay();
    
    SpawnVolume->OnComponentBeginOverlap.AddDynamic(this, &ASpawnGuide::OnOverlapBegin);
}

// Called every frame
void ASpawnGuide::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnGuide::SpawnActor()
{
    if(ToSpawn)
    {
        UWorld* world = GetWorld();
        if(world)
        {
            FActorSpawnParameters spawnParams;
            spawnParams.Owner = this;
            
            FRotator rotator;
            
            FVector spawnLocation = FVector(1515, -2271, -955);
            world->SpawnActor<ACatAI>(ToSpawn, spawnLocation, rotator, spawnParams);
        }
    }
}

void ASpawnGuide::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor)
    {
        APlayer_Character* Char = Cast<APlayer_Character>(OtherActor);
        if (Char)
        {
            SpawnActor();
            UE_LOG(LogTemp, Warning, TEXT("Spawn?"));
            Destroy();

        }
    }
}
