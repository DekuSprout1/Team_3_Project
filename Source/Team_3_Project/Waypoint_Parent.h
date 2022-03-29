// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Waypoint_Parent.generated.h"

/**
 * 
 */
UCLASS()
class TEAM_3_PROJECT_API AWaypoint_Parent : public AStaticMeshActor
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	int GetWaypointOrder();

private:
		UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		int WaypointOrder;
};
