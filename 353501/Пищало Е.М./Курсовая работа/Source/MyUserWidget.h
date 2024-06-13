// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class SLAYTHESPIRE_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();

	//FIELDS
	int HeroHP = 100;
	int WizardHP = 100;

	int HeroMinDamage = 5;
	int HeroMaxDamage = 10;

	int WizardMinDamage = 7;
	int WizardMaxDamage = 15;

	int Heal = 11;

	bool WizardCanMove = true;

	//BUTTONS
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* EndMove;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* AttackCard;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* HealCard;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* MagicCard;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* DodgeCard;

	//TEXT
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Wizard_HP;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Hero_HP;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Hero_MinDamage;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Hero_MaxDamage;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Wizard_MinDamage;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Wizard_MaxDamage;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Wizard_CardInfo;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Hero_CardInfo;

	//FUNCTIONS
	UFUNCTION()
	void AttackCardClicked();
	UFUNCTION()
	void HealCardClicked();
	UFUNCTION()
	void MagicCardClicked();
	UFUNCTION()
	void DodgeCardClicked();
	UFUNCTION()
	void WizardMove();
	UFUNCTION()
	void EndMoveClicked();
	UFUNCTION()
	int GenerateRandomNumber(int a, int b);
	UFUNCTION()
	void SetCardsEnabled(bool enable);
	UFUNCTION()
	void DefineWinner();
};