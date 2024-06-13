// Fill out your copyright notice in the Description page of Project Settings.


#include "LoseMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

bool ULoseMenu::Initialize()
{
	Super::Initialize();

	ReturnToMainMenuLose->OnClicked.AddDynamic(this, &ULoseMenu::ReturnToMainMenuLoseClicked);
	QuitLoseButton->OnClicked.AddDynamic(this, &ULoseMenu::QuitLoseButtonClicked);

	return true;
}

void ULoseMenu::ReturnToMainMenuLoseClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainMenu", true, "");
}

void ULoseMenu::QuitLoseButtonClicked()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}