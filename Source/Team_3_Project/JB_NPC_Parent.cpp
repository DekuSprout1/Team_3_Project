// Fill out your copyright notice in the Description page of Project Settings.


#include "JB_NPC_Parent.h"

// Sets default values
AJB_NPC_Parent::AJB_NPC_Parent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJB_NPC_Parent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJB_NPC_Parent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJB_NPC_Parent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

