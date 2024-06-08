// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCard.h"
#include <random>
#include "Hero.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Math/RandomStream.h"
#include "Kismet/GameplayStatics.h"

bool UBaseCard::Initialize()
{
	Super::Initialize();


	ActiveButton->OnClicked.AddDynamic(this, &UBaseCard::CardClicked);
	return false;
}

void UBaseCard::NativeConstruct()
{
	Super::NativeConstruct();

	if(RandomNumber()% 2 == 1) {
		Cur_CardInfo = CardDataTable->FindRow<FCardInfo>(FName("Strike"), FString("Strike"), true);
	}
	else {
		Cur_CardInfo = CardDataTable->FindRow<FCardInfo>(FName("Defend"), FString("Defend"), true);
	}
	CardNameText->SetText(FText::FromString(Cur_CardInfo->CardName));
	CardCostText->SetText(FText::FromString(FString::Printf(TEXT("%d"), Cur_CardInfo->CardCost)));
	CardType->SetText(FText::FromString(Cur_CardInfo->CardType));
	CardDescriptionText->SetText(FText::FromString(Cur_CardInfo->CardDescription));
	CardImage->SetBrushFromSoftTexture(Cur_CardInfo->CardImage);
}

void UBaseCard::CardClicked()
{
	InfoWidget->CardChoose(this);
}

int UBaseCard::RandomNumber()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> distrib(1, 100);

	return distrib(gen);
}
