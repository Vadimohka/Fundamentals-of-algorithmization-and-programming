// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD_2.generated.h"

/**
 * 
 */
UCLASS()
class KURSATH_API AMyHUD_2 : public AHUD
{
	GENERATED_BODY()

public:
	AMyHUD_2();

	virtual void BeginPlay() override;

	TSubclassOf<class UUserWidget> MainHUB;
	
};
