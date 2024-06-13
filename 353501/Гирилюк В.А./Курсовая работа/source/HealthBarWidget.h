// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYSLAYTHESPIRE_API UHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* HealthText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* DefText;

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthBar;
public:
	void UpdateCurrentMaxHP(int MaxHP, int CurrentHP);

	void SetDefence(int Def);
};
