// Fill out your copyright notice in the Description page of Project Settings.

#include "MyUserWidget.h"
#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include <random>


bool UMyUserWidget::Initialize()
{
	Super::Initialize();

	AttackCard->OnClicked.AddDynamic(this, &UMyUserWidget::AttackCardClicked);
	HealCard->OnClicked.AddDynamic(this, &UMyUserWidget::HealCardClicked);
	MagicCard->OnClicked.AddDynamic(this, &UMyUserWidget::MagicCardClicked);
	DodgeCard->OnClicked.AddDynamic(this, &UMyUserWidget::DodgeCardClicked);

	EndMove->OnClicked.AddDynamic(this, &UMyUserWidget::EndMoveClicked);

	FText wizardHealthAsText = FText::AsNumber(WizardHP);
	Wizard_HP->SetText(wizardHealthAsText);

	FText heroHealthAsText = FText::AsNumber(HeroHP);
	Hero_HP->SetText(heroHealthAsText);

	return true;
}

void UMyUserWidget::EndMoveClicked()
{
	if (WizardCanMove) 
	{
		WizardMove();
	}

	SetCardsEnabled(true);
	WizardCanMove = true;
}

void UMyUserWidget::SetCardsEnabled(bool enable) 
{

	AttackCard->SetIsEnabled(enable);
	HealCard->SetIsEnabled(enable);
	MagicCard->SetIsEnabled(enable);
	DodgeCard->SetIsEnabled(enable);
}

void UMyUserWidget::DefineWinner()
{
	if (WizardHP <= 0)
	{
		UGameplayStatics::OpenLevel(GetWorld(), "WINMENU", true, "");
	}
	else if (HeroHP <= 0) 
	{
		UGameplayStatics::OpenLevel(GetWorld(), "LOSEMENU", true, "");
	}
}

void UMyUserWidget::AttackCardClicked()
{
	SetCardsEnabled(false);

	int damage = GenerateRandomNumber(HeroMinDamage, HeroMaxDamage);
	WizardHP -= damage;

	Wizard_HP->SetText(FText::AsNumber(WizardHP));
	Hero_CardInfo->SetText(FText::FromString(TEXT("CARD 1 PLAYED")));

	DefineWinner();
}

void UMyUserWidget::HealCardClicked()
{
	SetCardsEnabled(false);

	HeroHP += Heal;

	Hero_HP->SetText(FText::AsNumber(HeroHP));
	Hero_CardInfo->SetText(FText::FromString(TEXT("CARD 2 PLAYED")));
	DefineWinner();
}

void UMyUserWidget::MagicCardClicked()
{
	SetCardsEnabled(false);

	HeroMaxDamage += 2;
	Hero_MaxDamage->SetText(FText::AsNumber(HeroMaxDamage));
	Hero_CardInfo->SetText(FText::FromString(TEXT("CARD 3 PLAYED")));
	DefineWinner();
}

void UMyUserWidget::DodgeCardClicked()
{
	SetCardsEnabled(false);

	int chance = GenerateRandomNumber(1, 2);

	if (chance == 1) 
	{
		WizardHP -= 5;
		Wizard_HP->SetText(FText::AsNumber(WizardHP));
		WizardCanMove = false;
		Wizard_CardInfo->SetText(FText::FromString(TEXT("NOTHING PLAYED")));
	}

	Hero_CardInfo->SetText(FText::FromString(TEXT("CARD 4 PLAYED")));
	DefineWinner();
}

void UMyUserWidget::WizardMove()
{
	int randomNumber = GenerateRandomNumber(1, 3);

	if (WizardCanMove)
	{
		if (randomNumber == 1 || WizardHP < 70)
		{
			int damage = GenerateRandomNumber(WizardMinDamage, WizardMaxDamage);
			HeroHP -= damage;

			FText heroHealthAsText = FText::AsNumber(HeroHP);
			Hero_HP->SetText(heroHealthAsText);
			Wizard_CardInfo->SetText(FText::FromString(TEXT("CARD 1 PLAYED")));
		}

		else if (randomNumber == 2) 
		{
			WizardHP += 5;

			Wizard_HP->SetText(FText::AsNumber(WizardHP));
			Wizard_CardInfo->SetText(FText::FromString(TEXT("CARD 2 PLAYED")));

		}

		else if (randomNumber == 3)
		{
			WizardMaxDamage += 1;
			Wizard_MaxDamage->SetText(FText::AsNumber(WizardMaxDamage));
			Wizard_CardInfo->SetText(FText::FromString(TEXT("CARD 3 PLAYED")));
		}
	}

	DefineWinner();
}

int UMyUserWidget::GenerateRandomNumber(int a, int b)
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(a, b);

	int randomNumber = distribution(generator);
	return randomNumber;
}