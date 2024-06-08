// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InfoWidget.h"
#include "MyMap.h"
#include "UserHUD.generated.h"

/**
 * 
 */
UCLASS()
class MYSLAYTHESPIRE_API AUserHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	AUserHUD();

	bool IsBattle = false;

	virtual void BeginPlay() override;

	TSubclassOf<class UUserWidget> MainHUD; 
	TSubclassOf<class UUserWidget> BaseCardClass;
};
