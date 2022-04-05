// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Character.h"



// Sets default values
APlayer_Character::APlayer_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    walkSpeed = 300;
    sprintSpeed = 600;

	//create camera boon
	CameraBoon = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoon"));
	CameraBoon->SetupAttachment(RootComponent);
	CameraBoon->TargetArmLength = 400.0f;
	CameraBoon->TargetOffset = FVector(0.f, 0.f, 100.f);
	CameraBoon->bEnableCameraLag = true;
	CameraBoon->bEnableCameraRotationLag = true;
	CameraBoon->CameraLagSpeed = 10.f;
	CameraBoon->bUsePawnControlRotation = false; //rotate the arm with the controller


	//create a follow camera attached to the boon
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoon, USpringArmComponent::SocketName); //attaching the samera to the boon
	FollowCamera->bUsePawnControlRotation = false; //camera does not rotate relative to the arm
	FollowCamera->FieldOfView = 25.f;//changes fov 
}

// Called when the game starts or when spawned
void APlayer_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayer_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayer_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    
    InputComponent->BindAction("Sprint", IE_Pressed, this, &APlayer_Character::StartSprint);
    InputComponent->BindAction("Sprint", IE_Released, this, &APlayer_Character::EndSprint);
}

void APlayer_Character::StartSprint()
{
    CharacterMovement->MaxWalkSpeed = sprintSpeed;
}
 
void APlayer_Character::EndSprint()
{
    CharacterMovement->MaxWalkSpeed = walkSpeed;
}
