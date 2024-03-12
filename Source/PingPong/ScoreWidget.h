// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "ScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG_API UScoreWidget : public UWidgetComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* PlayerScore;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* EnemyScore;
	
};
