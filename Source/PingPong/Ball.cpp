// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "PlatformPlayerController.h"
#include "PlatformPawn.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BallBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallBody"));

	BallSpeed = 500.f;
	TorqueStrength = 500.0f;

	bReplicates = true;

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

	FVector StartVector = FVector(100.0f, -100.0f, 0.0f);

	StartVector.Normalize();

	BallVelocity = StartVector * BallSpeed;

	BallBody->OnComponentHit.AddDynamic(this, &ABall::OnHit);
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(BallVelocity * DeltaTime, true);

}

void ABall::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME(ABall, BallVelocity);
	DOREPLIFETIME(ABall, BallSpeed);
	DOREPLIFETIME(ABall, TorqueStrength);
}

void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	FVector Reflection = FMath::GetReflectionVector(BallVelocity, Hit.Normal);

	BallVelocity = FVector(Reflection.X, Reflection.Y, 0.f);

	BallVelocity.Normalize();

	BallVelocity *= BallSpeed;
	
}

