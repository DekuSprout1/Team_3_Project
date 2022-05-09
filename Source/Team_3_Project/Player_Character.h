// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player_Character.generated.h"

UCLASS()
class TEAM_3_PROJECT_API APlayer_Character : public ACharacter
{
	GENERATED_BODY()
    
public:
	// Sets default values for this character's properties
	APlayer_Character();
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
    int walkSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
    int sprintSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
    int crouchSpeed;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
    float crouchScale;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
    FVector standScale;
    
    //throwing stuff
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterProjectile)
    bool drawingTrajectory;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterProjectile)
    FVector location;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterProjectile)
    float t;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterProjectile)
    float tt;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterProjectile)
    FVector u;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterProjectile)
    float gravity;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterProjectile)
    FVector forwardVector;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterProjectile)
    FVector myCharacter;
    
    UCharacterMovementComponent*CharacterMovement = GetCharacterMovement();
    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class USpringArmComponent* CameraBoon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* FollowCamera;
    
    void StartSprint();
    
    void StartWalkSpeed();
    
    void StartCrouch();
    
    void EndCrouch();
    
    void DrawTrajectory();
    
    void StopTrajectory();
    
    FVector GetLocation();
    
};
