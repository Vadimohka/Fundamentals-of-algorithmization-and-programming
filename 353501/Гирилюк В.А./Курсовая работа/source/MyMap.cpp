// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMap.h"

bool UMyMap::Initialize()
{
	Super::Initialize();


	Floor1->OnClicked.AddDynamic(this, &UMyMap::FloorButtonClicked);

	return true;
}

void UMyMap::FloorButtonClicked()
{
	SetVisibility(ESlateVisibility::Hidden);
	InfoWidget->StartBattle();
}