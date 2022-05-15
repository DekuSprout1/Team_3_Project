// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CatAI.h"
#include "SpawnGuide.generated.h"

UCLASS()
class TEAM_3_PROJECT_API ASpawnGuide : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnGuide();
    
    UFUNCTION()
       void SpawnActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere,BlueprintReadWrite)
        class UBoxComponent* SpawnVolume;
    
    UPROPERTY(EditAnywhere,BlueprintReadWrite)
        class ACatAI* Cat;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    UFUNCTION()
        virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
