// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include "InfoWidget.h"
#include "Hero.generated.h"

/**
 * 
 */
UCLASS()
class MYSLAYTHESPIRE_API AHero : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AHero();


	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data")
	UDataTable* CardDataTable;

};