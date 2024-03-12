// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformPlayerController.h"
#include "PlatformPawn.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "PingPongGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void APlatformPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MoveLeft", IE_Pressed, this, &APlatformPlayerController::MoveLeft);
	InputComponent->BindAction("MoveRight", IE_Pressed, this, &APlatformPlayerController::MoveRight);
	InputComponent->BindAction("MoveLeft", IE_Released, this, &APlatformPlayerController::StopMoveLeft);
	InputComponent->BindAction("MoveRight", IE_Released, this, &APlatformPlayerController::StopMoveRight);
}

void APlatformPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SpawnWidget();
}

void APlatformPlayerController::SpawnWidget()
{
	if (IsLocalController())
	{
		UUserWidget* Widget = CreateWidget<UUserWidget>(this, WidgetClass);
		Widget->AddToViewport();		
	}
}


void APlatformPlayerController::MoveLeft()
{

	Server_MoveLeft();

	GetPawn<APlatformPawn>()->MoveLeft();
	

}

void APlatformPlayerController::MoveRight()
{
	Server_MoveRight();

	GetPawn<APlatformPawn>()->MoveRight();
}

void APlatformPlayerController::StopMoveLeft()
{
	Server_StopMoveLeft();

	GetPawn<APlatformPawn>()->StopMoveLeft();
}

void APlatformPlayerController::StopMoveRight()
{
	Server_StopMoveRight();

	GetPawn<APlatformPawn>()->StopMoveRight();
}

void APlatformPlayerController::Server_MoveLeft_Implementation()
{
	GetPawn<APlatformPawn>()->MoveLeft();
}

void APlatformPlayerController::Server_MoveRight_Implementation()
{
	GetPawn<APlatformPawn>()->MoveRight();
}

void APlatformPlayerController::Server_StopMoveLeft_Implementation()
{
	GetPawn<APlatformPawn>()->StopMoveLeft();
}

void APlatformPlayerController::Server_StopMoveRight_Implementation()
{
	GetPawn<APlatformPawn>()->StopMoveRight();
}
