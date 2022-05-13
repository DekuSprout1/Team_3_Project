// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "CatAI.h"
#include "CatDestrot.generated.h"


UCLASS()
class TEAM_3_PROJECT_API ACatDestrot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACatDestrot();

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
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
