// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlatformPawn.generated.h"

UCLASS()
class PINGPONG_API APlatformPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlatformPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* PlatformBody;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UCameraComponent* Camera;

	/*UPROPERTY(EditDefaultsOnly, Category = "Components")
	class USpringArmComponent* SpringArm;*/

	UPROPERTY(Replicated)
	FVector Velocity = FVector(0.f);

	UPROPERTY(Replicated)
	uint8 Score = 0;

	

	UPROPERTY(Replicated)
	uint8 EnemyScore = 0;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Counter")
	uint8 GetScore() const;

	UFUNCTION(BlueprintCallable, Category = "Counter")
	uint8 GetEnemyScore() const;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void MoveLeft();

	void MoveRight();

	void StopMoveLeft();

	void StopMoveRight();

	void AddScore() { Score++; };

	void AddEnemyScore() { EnemyScore++; };

};
