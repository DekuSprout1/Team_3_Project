// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CatAI.generated.h"

UCLASS()
class TEAM_3_PROJECT_API ACatAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACatAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveToWaypoints();
    
    void DestroyMe();
    
    UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
    int CurrentWaypoint;
    
    TArray<AActor*> Waypoints;
    
private:
    
};
