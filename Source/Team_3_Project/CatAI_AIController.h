// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CatAI_AIController.generated.h"

/**
 * 
 */
UCLASS()
class TEAM_3_PROJECT_API ACatAI_AIController : public AAIController
{
	GENERATED_BODY()
	
    void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
};
