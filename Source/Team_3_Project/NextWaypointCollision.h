// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NextWaypointCollision.generated.h"

UCLASS()
class TEAM_3_PROJECT_API ANextWaypointCollision : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANextWaypointCollision();

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Particle Collision")
        class UBoxComponent* CollisionVolume;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CatAI")
    class ACatAI* Cat;
    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UFUNCTION()
        virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
