// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Level_1.h"
#include "EnemyCharacter.h"
#include "CharacterHUD.h"
#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CURSACH_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AMyGameMode();

	void BeginPlay();
};
