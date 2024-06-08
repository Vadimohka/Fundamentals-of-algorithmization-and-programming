// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class MYSLAYTHESPIRE_API AEnemy : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	AEnemy();

	virtual void Action(int Turn);

	UPROPERTY(VisibleAnywhere)
	class UWidgetComponent* IntentionComponent;
	class UIntentionWidget* IntentionWidget;
};
