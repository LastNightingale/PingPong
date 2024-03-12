// Copyright Epic Games, Inc. All Rights Reserved.


#include "PingPongGameModeBase.h"
#include "EngineUtils.h"
#include "PlatformPlayerStart.h"
#include "GameFramework/GameStateBase.h"
#include "PlatformPlayerController.h"
#include "Kismet/GameplayStatics.h"

void APingPongGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void APingPongGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	PlayerNumber++;

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);


	if (PlayerNumber > 1)
	{
		if (PC)
		{
			auto Controller = Cast<APlatformPlayerController>(PC);
			Controller->SetPause(false);
		}
	}
	else
	{
		if (PC)
		{
			auto Controller = Cast<APlatformPlayerController>(PC);
			Controller->SetPause(true);			
		}
		UE_LOG(LogTemp, Warning, TEXT("Not enough players"));
	}
	
}

AActor* APingPongGameModeBase::ChoosePlayerStart_Implementation(AController* Player)
{

	for (TActorIterator<APlatformPlayerStart> Iter(GetWorld()); Iter; ++Iter)
	{
		if (!Iter->IsTaken())
		{
			Iter->Take();
			return *Iter;
		}
	}
	return nullptr;
}
