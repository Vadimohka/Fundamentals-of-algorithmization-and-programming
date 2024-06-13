// Fill out your copyright notice in the Description page of Project Settings.


#include "WinMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

bool UWinMenu::Initialize()
{
	Super::Initialize();

	ReturnToMainMenuButton->OnClicked.AddDynamic(this, &UWinMenu::ReturnButtonClicked);
	QuitWinButton->OnClicked.AddDynamic(this, &UWinMenu::QuitWinButtonClicked);

	return true;
}

void UWinMenu::ReturnButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainMenu", true, "");
}

void UWinMenu::QuitWinButtonClicked()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}