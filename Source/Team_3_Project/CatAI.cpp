// Fill out your copyright notice in the Description page of Project Settings.


#include "CatAI.h"
#include "CatAI_Waypoint.h"
#include "Kismet/GameplayStatics.h"
#include "CatAI_AIController.h"

// Sets default values
ACatAI::ACatAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACatAI::BeginPlay()
{
	Super::BeginPlay();
	
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACatAI_Waypoint::StaticClass(), Waypoints);
    MoveToWaypoints();
}

// Called every frame
void ACatAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACatAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACatAI::MoveToWaypoints()
{
    ACatAI_AIController* CatAIController = Cast<ACatAI_AIController>(GetController());
    
    if(CatAIController)
    {
        if(CurrentWaypoint <= Waypoints.Num())
        {
            for(AActor* Waypoint : Waypoints)
            {
                ACatAI_Waypoint* WaypointItr = Cast<ACatAI_Waypoint>(Waypoint);
                
                if(WaypointItr)
                {
                    if(WaypointItr->GetWaypointOrder()==CurrentWaypoint)
                    {
                       CatAIController->MoveToActor(WaypointItr, 2.f, false);
                       // CurrentWaypoint++;
                        break;
                        
                    }
                }
            }
        }
    }
}
