// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "string"
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <vector>
#include <iostream>
#include "Misc/DateTime.h"
#include <windows.h>

AMyGameModeBase::AMyGameModeBase() : Super()
{
	HUDClass = AMyHUD::StaticClass();

	FString FilePath = TEXT("game.txt");
	int32 LineIndex = 3;
	FString FullPath = FPaths::Combine(FPaths::ProjectDir(), FilePath);
	TArray<FString> Lines;
	FFileHelper::LoadFileToStringArray(Lines, *FullPath);
	if (LineIndex >= 0 && LineIndex < Lines.Num())
	{
		FString Line = Lines[LineIndex];
		size = 8 + FCString::Atoi(*Line);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error"));
	}
	start_size = size;
}

int AMyGameModeBase::HealHero()
{
	return Hero->health;
}

int AMyGameModeBase::HealEnemy()
{
	return Enemy->health;
}

void AMyGameModeBase::GameOverTheHeroLost()
{
	if (Hero->health <= 0) {
		finish = true;
		WinHero = false;
	}
}

void AMyGameModeBase::GameOverTheEnemyLost()
{
	if (Enemy->health <= 0) {
		finish = true;
		WinHero = true;
	}
}

void AMyGameModeBase::BeginPlay()
{
	FString FilePath = TEXT("game.txt");
	int32 LineIndex = 2;
	FString FullPath = FPaths::Combine(FPaths::ProjectDir(), FilePath);
	TArray<FString> Lines;
	FFileHelper::LoadFileToStringArray(Lines, *FullPath);
	if (LineIndex >= 0 && LineIndex < Lines.Num())
	{
		FString Line = Lines[LineIndex];
		money = FCString::Atoi(*Line);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error"));
	}
	LineIndex = 1;
	if (LineIndex >= 0 && LineIndex < Lines.Num())
	{
		FString Line = Lines[LineIndex];
		level = FCString::Atoi(*Line);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error"));
	}
	LineIndex = 0;
	if (LineIndex >= 0 && LineIndex < Lines.Num())
	{
		FString Line = Lines[LineIndex];
		numgames = FCString::Atoi(*Line);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error"));
	}
	Deck[0] = 0;
	Deck[1] = 0;
	Deck[2] = 1;
	Deck[3] = 1;
	Deck[4] = 2;
	Deck[5] = 2;
	Deck[6] = 3;
	Deck[7] = 4;
	Deck[8] = 5;
	Deck[9] = 6;
	Deck[10] = 7;
	HeroMove();
}

void AMyGameModeBase::HeroMove()
{
	magna = 3;
	if (size > 3) {
		ind_deck_card1 = PRNG(size);
		ind_card1 = Deck[ind_deck_card1];
		Reset[sizeReset] = Deck[ind_deck_card1];
		sizeReset++;
		Deck[ind_deck_card1] = Deck[size - 1];
		size--;
		ind_deck_card2 = PRNG(size);
		ind_card2 = Deck[ind_deck_card2];
		Reset[sizeReset] = Deck[ind_deck_card2];
		sizeReset++;
		Deck[ind_deck_card2] = Deck[size - 1];
		size--;
		ind_deck_card3 = PRNG(size);
		ind_card3 = Deck[ind_deck_card3];
		Reset[sizeReset] = Deck[ind_deck_card3];
		sizeReset++;
		Deck[ind_deck_card3] = Deck[size - 1];
		size--;
	}
	else if (size == 3) {
		ind_deck_card1 = PRNG(size);
		ind_card1 = Deck[ind_deck_card1];
		Reset[sizeReset] = Deck[ind_deck_card1];
		sizeReset++;
		Deck[ind_deck_card1] = Deck[size - 1];
		size--;
		ind_deck_card2 = PRNG(size);
		ind_card2 = Deck[ind_deck_card2];
		Reset[sizeReset] = Deck[ind_deck_card2];
		sizeReset++;
		Deck[ind_deck_card2] = Deck[size - 1];
		size--;
		ind_deck_card3 = PRNG(size);
		ind_card3 = Deck[ind_deck_card3];
		Reset[sizeReset] = Deck[ind_deck_card3];
		sizeReset++;
		Deck[ind_deck_card3] = Deck[size - 1];
		size--;
		Deck[0] = 0;
		Deck[1] = 0;
		Deck[2] = 1;
		Deck[3] = 1;
		Deck[4] = 2;
		Deck[5] = 2;
		Deck[6] = 3;
		Deck[7] = 4;
		Deck[8] = 5;
		Deck[9] = 6;
		Deck[10] = 7;
		size = start_size;
		sizeReset = 0;
	}
	else if (size == 2) {
		ind_deck_card1 = PRNG(size);
		ind_card1 = Deck[ind_deck_card1];
		Reset[sizeReset] = Deck[ind_deck_card1];
		sizeReset++;
		Deck[ind_deck_card1] = Deck[size - 1];
		size--;
		ind_deck_card2 = PRNG(size);
		ind_card2 = Deck[ind_deck_card2];
		Reset[sizeReset] = Deck[ind_deck_card2];
		sizeReset++;
		Deck[ind_deck_card2] = Deck[size - 1];
		size--;
		ind_card3 = Reset[PRNG(sizeReset)];
		Deck[0] = 0;
		Deck[1] = 0;
		Deck[2] = 1;
		Deck[3] = 1;
		Deck[4] = 2;
		Deck[5] = 2;
		Deck[6] = 3;
		Deck[7] = 4;
		Deck[8] = 5;
		Deck[9] = 6;
		Deck[10] = 7;
		size = start_size;
		sizeReset = 0;
	}
	else if (size == 1) {
		ind_deck_card1 = PRNG(size);
		ind_card1 = Deck[ind_deck_card1];
		Reset[sizeReset] = Deck[ind_deck_card1];
		sizeReset++;
		Deck[ind_deck_card1] = Deck[size - 1];
		size--;
		ind_card2 = Reset[PRNG(sizeReset)];
		ind_card3 = Reset[PRNG(sizeReset)];
		Deck[0] = 0;
		Deck[1] = 0;
		Deck[2] = 1;
		Deck[3] = 1;
		Deck[4] = 2;
		Deck[5] = 2;
		Deck[6] = 3;
		Deck[7] = 4;
		Deck[8] = 5;
		Deck[9] = 6;
		Deck[10] = 7;
		size = start_size;
		sizeReset = 0;
	}
	else if (size == 0) {
		ind_card1 = Reset[PRNG(sizeReset)];
		ind_card2 = Reset[PRNG(sizeReset)];
		ind_card3 = Reset[PRNG(sizeReset)];
		Deck[0] = 0;
		Deck[1] = 0;
		Deck[2] = 1;
		Deck[3] = 1;
		Deck[4] = 2;
		Deck[5] = 2;
		Deck[6] = 3;
		Deck[7] = 4;
		Deck[8] = 5;
		Deck[9] = 6;
		Deck[10] = 7;
		size = start_size;
		sizeReset = 0;
	}
}

unsigned int AMyGameModeBase::PRNG(int q)
{
	static unsigned int seed = 4541;
	seed = (8253729 * seed + 2396403);
	return seed % q;
}

void AMyGameModeBase::Attack()
{
	Enemy->EnemyStrike(Hero->Attack(6));
}

void AMyGameModeBase::Shead()
{
	Hero->Shield(5);
}

void AMyGameModeBase::Heal()
{
	Hero->HealthRecovery(6);
}

void AMyGameModeBase::StrengthPotion()
{
	Hero->WeakeningProtectionFromTheEnemy(25);
}

void AMyGameModeBase::PotionWeakness()
{
	Enemy->WeakeningAttackFromTheEnemy(25);
}

void AMyGameModeBase::PotionWeakness_and_StrengthPotion()
{
	Enemy->WeakeningAttackFromTheEnemy(50);
	Hero->WeakeningProtectionFromTheEnemy(50);
}

void AMyGameModeBase::Heal_and_Shead()
{
	Hero->HealthRecovery(10);
	Hero->Shield(10);
}

void AMyGameModeBase::Attack_x2()
{
	Enemy->EnemyStrike(Hero->Attack(18));
}

void AMyGameModeBase::El_red()
{
	Enemy->EnemyStrike(Hero->Attack(40));
}

void AMyGameModeBase::El_green()
{
	Hero->HealthRecovery(30);
	Hero->Shield(30);
}

void AMyGameModeBase::EnemyMove()
{
	int q = PRNG(5);
	if (q == 0) {
		Hero->EnemyStrike(Enemy->Attack(6));
		str = "The enemy attacked";
	}
	else if (q == 1) {
		Enemy->HealthRecovery(6);
		str = "The enemy has regained health";
	}
	else if (q == 2) {
		Enemy->Shield(5);
		str = "The enemy used a shield";
	}
	else if (q == 3) {
		Enemy->WeakeningProtectionFromTheEnemy(25);
		str = "The enemy has increased his strength";
	}
	else if (q == 4) {
		Hero->WeakeningAttackFromTheEnemy(25);
		str = "The enemy reduced the hero's strength";
	}
	GameOverTheHeroLost();
	HeroMove();
}



