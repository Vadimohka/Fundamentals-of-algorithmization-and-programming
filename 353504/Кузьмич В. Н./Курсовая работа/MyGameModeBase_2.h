// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyHUD_2.h"
#include "CoreUObject.h"
#include "Misc/FileHelper.h"
#include "MyGameModeBase_2.generated.h"

/**
 * 
 */
UCLASS()
class KURSATH_API AMyGameModeBase_2 : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMyGameModeBase_2();
	int money = 0, level = 0, cardshop1 = 0, numbgame = 0;
};
