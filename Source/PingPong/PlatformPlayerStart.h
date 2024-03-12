// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "PlatformPlayerStart.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG_API APlatformPlayerStart : public APlayerStart
{
	GENERATED_BODY()

	bool bIsTaken = false;

public:

	bool IsTaken() const { return bIsTaken; };

	void Take() { bIsTaken = true; };
	
};
