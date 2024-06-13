// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBarWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

bool UHealthBarWidget::Initialize()
{
	Super::Initialize();



	return true;
}

void UHealthBarWidget::UpdateCurrentMaxHP(int MaxHP, int CurrentHP)
{
	HealthText->SetText(FText::FromString(FString::Printf(TEXT("%d/%d"), CurrentHP, MaxHP)));
	HealthBar->SetPercent(((float)CurrentHP) / MaxHP);
}

void UHealthBarWidget::SetDefence(int Def)
{
	DefText->SetText(FText::FromString(FString::Printf(TEXT("%d"), Def)));
}
