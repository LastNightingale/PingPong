// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlatformPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG_API APlatformPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> WidgetClass;

public:	

	virtual void SetupInputComponent() override;

	virtual void BeginPlay() override;

	void SpawnWidget();

	void MoveLeft();

	void MoveRight();

	void StopMoveLeft();

	void StopMoveRight();

	UFUNCTION(Server, Unreliable)
	void Server_MoveLeft();
	void Server_MoveLeft_Implementation();

	UFUNCTION(Server, Unreliable)
	void Server_MoveRight();
	void Server_MoveRight_Implementation();

	UFUNCTION(Server, Unreliable)
	void Server_StopMoveLeft();
	void Server_StopMoveLeft_Implementation();

	UFUNCTION(Server, Unreliable)
	void Server_StopMoveRight();
	void Server_StopMoveRight_Implementation();
	
};
