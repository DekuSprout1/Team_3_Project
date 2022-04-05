// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "CatAI_Waypoint.generated.h"

/**
 * 
 */
UCLASS()
class TEAM_3_PROJECT_API ACatAI_Waypoint : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
    
    int GetWaypointOrder();
        
private:
    UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
    int WaypointOrder;
};
