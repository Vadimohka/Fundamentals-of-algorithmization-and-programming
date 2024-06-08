// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "SkeletonAxe.generated.h"

/**
 * 
 */
UCLASS()
class MYSLAYTHESPIRE_API ASkeletonAxe : public AEnemy
{
	GENERATED_BODY()
	
	ASkeletonAxe();

	virtual void BeginPlay();

	virtual void Action(int Turn) override;
};
