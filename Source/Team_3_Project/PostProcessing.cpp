// Fill out your copyright notice in the Description page of Project Settings.


#include "PostProcessing.h"

// Sets default values
APostProcessing::APostProcessing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APostProcessing::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APostProcessing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

