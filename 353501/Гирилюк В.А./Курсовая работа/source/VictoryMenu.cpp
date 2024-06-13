// Fill out your copyright notice in the Description page of Project Settings.


#include "VictoryMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

bool UVictoryMenu::Initialize()
{
	Super::Initialize();

	ExitMenu->OnClicked.AddDynamic(this, &UVictoryMenu::ExitMenuButtonClicked);

	return false;
}

void UVictoryMenu::ExitMenuButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "Main_Menu", true);
}
