// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class KURSATH_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties

	AMyCharacter();
	UPROPERTY(EditDefaultsOnly, Category = "Healt")
	float health = 50.0f;
};
