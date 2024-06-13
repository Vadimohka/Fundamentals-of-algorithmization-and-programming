// Fill out your copyright notice in the Description page of Project Settings.


#include "IntentionWidget.h"
#include "Components/TextBlock.h"

bool UIntentionWidget::Initialize()
{
	Super::Initialize();
	return false;
}

void UIntentionWidget::UpdateIntention(int damage)
{
	IntentionTextBlock->SetText(FText::FromString(FString::Printf(TEXT("%d"), damage)));
}
