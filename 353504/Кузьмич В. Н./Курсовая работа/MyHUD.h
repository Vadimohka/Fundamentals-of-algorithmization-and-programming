// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class KURSATH_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMyHUD();

	virtual void BeginPlay() override;

	TSubclassOf<class UUserWidget> MainHUB;
	
};

// /Script/UMGEditor.WidgetBlueprint'/Game/UI/Heal.Heal'