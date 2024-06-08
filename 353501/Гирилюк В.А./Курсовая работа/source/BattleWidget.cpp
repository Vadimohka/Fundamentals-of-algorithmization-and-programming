// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Overlay.h"
#include "Components/HorizontalBox.h"
#include "BaseCard.h"
#include "CardHand.h"
#include "InfoWidget.h"

bool UBattleWidget::Initialize()
{
	Super::Initialize();

	EndTurnButton->OnClicked.AddDynamic(this, &UBattleWidget::EndTurnButtonClicked);

	return true;
}

void UBattleWidget::EndTurnButtonClicked()
{
	WBP_CardHand->CardBox->ClearChildren();
	for(int i = 0; i < 5; i++){
		UBaseCard* Card = (UBaseCard*)CreateWidget(GetWorld(), BaseCardClass);
		if (Card) {
			WBP_CardHand->CardBox->AddChild(Card);
			Card->InfoWidget = InfoWidget;
			Card->AddToViewport();
		}
	}	
	InfoWidget->EndTurn();
	UpdateEnergy(3, 3);
}

void UBattleWidget::StartBattle()
{
	for (int i = 0; i < 5; i++) {
		UBaseCard* Card = (UBaseCard*)CreateWidget(GetWorld(), BaseCardClass);
		if (Card) {
			WBP_CardHand->CardBox->AddChild(Card);
			Card->InfoWidget = InfoWidget;
			Card->AddToViewport();
		}
	}
	UpdateEnergy(3, 3);
}

void UBattleWidget::UpdateEnergy(int CurEnergy, int MaxEnergy)
{
	EnergyText->SetText(FText::FromString(FString::Printf(TEXT("%d/%d"), CurEnergy, MaxEnergy)));
}
