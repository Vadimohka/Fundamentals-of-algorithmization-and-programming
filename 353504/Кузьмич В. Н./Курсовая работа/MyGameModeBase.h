// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyUnit.h"
#include "GameFramework/GameModeBase.h"
#include "MyHUD.h"
#include "MyUserWidget.h"
#include <vector>
#include "CoreUObject.h"
#include "Misc/FileHelper.h"
#include <iostream>
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class KURSATH_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyGameModeBase();
	FString str = "";
	bool finish = false;
	bool WinHero = true;
	int HealHero();
	int HealEnemy();
	void GameOverTheHeroLost();
	void GameOverTheEnemyLost();
	virtual void BeginPlay() override;
	UMyUnit* Hero = new UMyUnit;
	UMyUnit* Enemy = new UMyUnit;
	void HeroMove();
	void EnemyMove();
	UPROPERTY(EditDefaultsOnly, Category = "Heal")
	float a = 70.0f;
	int size = 8;
	int start_size = 0;
	int magna = 0;
	int level = 0;
	int numgames = 0;
	int sizeReset = 0;
	int Deck[11];
	int Reset[11];
	int money = 0;
	unsigned int PRNG(int);
	int ind_card1 = 0, ind_card2 = 0, ind_card3 = 0;
	int ind_deck_card1 = 0, ind_deck_card2 = 0, ind_deck_card3 = 0;
	void Attack();
	void Shead();
	void Heal();
	void StrengthPotion();
	void PotionWeakness();
	void Attack_x2();
	void Heal_and_Shead();
	void PotionWeakness_and_StrengthPotion();
	void El_green();
	void El_red();
};
