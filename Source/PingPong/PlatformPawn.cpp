// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
APlatformPawn::APlatformPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	PlatformBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformBody"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));


	SetRootComponent(Root);

	//Camera->bUsePawnControlRotation = false;

	//SpringArm->SetupAttachment(RootComponent);
	//SpringArm->TargetArmLength = 200.0f;
	//SpringArm->SocketOffset = FVector(0.f, 0.f, 100.f);
	PlatformBody->SetupAttachment(RootComponent);
	PlatformBody->SetRelativeLocation({ 0.f, 0.f, 0.f });

	Camera->SetupAttachment(RootComponent);
	Camera->SetRelativeLocation({ 0.f, 0.f, 0.f });

	SetReplicates(true);

}

// Called when the game starts or when spawned
void APlatformPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlatformBody->AddRelativeLocation(Velocity * 500.f * DeltaTime, true);
}

// Called to bind functionality to input
void APlatformPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlatformPawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APlatformPawn, Velocity);
	DOREPLIFETIME(APlatformPawn, Score);
	DOREPLIFETIME(APlatformPawn, EnemyScore);
}

void APlatformPawn::MoveLeft()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Moved"));
	//AddActorLocalOffset(GetActorForwardVector() * -100.f, true);
	Velocity += FVector::RightVector * -1.f;
}

void APlatformPawn::MoveRight()
{
	Velocity += FVector::RightVector;
}

uint8 APlatformPawn::GetScore() const
{
	return Score;
}

uint8 APlatformPawn::GetEnemyScore() const
{
	return EnemyScore;
}


void APlatformPawn::StopMoveLeft()
{
	Velocity -= FVector::RightVector * -1.f;
}

void APlatformPawn::StopMoveRight()
{
	Velocity -= FVector::RightVector;
}

