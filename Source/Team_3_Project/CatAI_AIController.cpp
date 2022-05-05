// Fill out your copyright notice in the Description page of Project Settings.


#include "CatAI_AIController.h"
#include "CatAI.h"
#include "CatAI_AIController.h"


 void ACatAI_AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
    ACatAI* CatAI = Cast<ACatAI>(GetPawn());
    
    if(CatAI)
    {
        // CatAI->MoveToWaypoints();
    }
}
